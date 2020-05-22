/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** error.c
*/

#include "../include/asm.h"

void check_valid_label(char c, asm_t *assembly)
{
    int k = 0;

    for (int j = 0; LABEL_CHARS[j]; j++)
        if (c == LABEL_CHARS[j] || c == LABEL_CHAR)
            k++;
    if (k == 0)
        assembly->file[IDX]->error = 84;
}

int check_double_label2(asm_t *assembly, int i, char **line)
{
    char **line_tmp = NULL; int k = 0;

    if (assembly->file[IDX]->all_file[i][0] != '\0') {
        line_tmp = my_str_to_word_tab(assembly->file[IDX]->all_file[i],
        adapt_delims());
        for (int j = 0; line_tmp[j]; j += 1)
            (line && line[0] && my_strcmp(line[0], line_tmp[j]) == 0) \
            ? k += 1 : 0;
    }
    return (k);
}

void check_double_label(asm_t *assembly, char **line)
{
    int i = 0; int k = 0;

    for (; line && line[0] && line[0][k]; k++);
    if (line && line[0] && line[0][k - 1] != LABEL_CHAR)
        return;
    else {
        for (int j = 0; line && line[0] && line[0][j]; j++)
            check_valid_label(line[0][j], assembly);
        if (assembly->file[IDX]->error == 84)
            return;
    }
    k = 0;
    for (; assembly->file[IDX]->all_file[i]; i++)
        k += check_double_label2(assembly, i, line);
    (k > 1) ? assembly->file[IDX]->error = 84 : 0;
}

int check_valid_instru(char *line)
{
    int i = 0;

    if (line == NULL)
        return (i);
    for (int j = 0; op_tab[j].mnemonique != 0; j += 1)
        (my_strcmp(line, op_tab[j].mnemonique) == 0) ? i = 1 : 0;
    return (i);
}

int check_error(char **line)
{
    int error = 0;

    if (line == NULL || line[0] == NULL)
        return (1);
    if (line[0][0] == '\0' || line[0][0] == COMMENT_CHAR)
        error = 1;
    if (my_strcmp(NAME_CMD_STRING, line[0]) == 0 ||
    my_strcmp(COMMENT_CMD_STRING, line[0]) == 0)
        error = 1;
    return (error);
}