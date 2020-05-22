/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** parse_instructions.c
*/

#include "../include/asm.h"

int check_where_instru(char *line, int i, int j, asm_t *assembly)
{
    int k = 0;

    if (my_strcmp(line, op_tab[j].mnemonique) == 0) {
        if (i > 1)
            assembly->file[IDX]->error = 84;
        k++;
    }
    return (k);
}

char *found_instru(char **line, asm_t *assembly)
{
    int i = 0; char *instru = NULL; int j = 0; int k = 0;

    for (; line[i]; i++)
        for (j = 0; op_tab[j].mnemonique; j++) {
            k = check_where_instru(line[i], i, j, assembly);
            (k != 0) ? instru = line[i] : 0;
        }
    return (instru);
}

void check_instructions(asm_t *assembly, char **line)
{
    char *instru = NULL;

    instru = found_instru(line, assembly);
    if (instru == NULL)
        return;
    assembly->file[IDX]->bytes_instru = assembly->file[IDX]->bytes;
    coding_bytes(instru, assembly, IDX, line);
    for (int j = 0; op_tab[j].mnemonique != 0; j += 1)
        if (my_strcmp(instru, op_tab[j].mnemonique) == 0)
            check_params(assembly, line, j);
    free(instru);
}

void put_and_check_instru_in_tab(asm_t *assembly, char **all_file, int i)
{
    int k = 0; int j = 0; char **line = NULL;

    line = my_str_to_word_tab(all_file[i], adapt_delims());
    for (j = 0, k = 0; line[j]; j++) {
        (line[j][0] == COMMENT_CHAR) ? k++ : 0;
        (k > 0) ? line[j] = NULL : 0;
    }
    check_double_label(assembly, line);
    if (check_error(line) != 1)
        check_instructions(assembly, line);
    assembly->start = 1;
}

void parse_instructions(asm_t *assembly, char **all_file)
{
    for (int i = 0; all_file[i]; i += 1) {
        if (all_file && all_file[i][0] != '\0')
            put_and_check_instru_in_tab(assembly, all_file, i);
    }
}