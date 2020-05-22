/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** label.c
*/

#include "../include/asm.h"

char *found_label(char *param, int check)
{
    int i = 0; int j = 0;
    char *label = malloc(sizeof(char) * my_strlen(param));

    if (check == 1)
        i = 1;
    else if (check == 2)
        i = 2;
    for (; param[i]; i++, j++)
        label[j] = param[i];
    label[j] = ':';
    j++;
    label[j] = '\0';
    return (label);
}

int check_bytes_params(char *instru, char **line_tmp)
{
    int j = 0; int nbr = 0;

    for (; my_strcmp(instru, line_tmp[j]) != 0; j++);
    for (j++; line_tmp[j]; j++) {
        if (line_tmp[j][0] == 'r')
            nbr += check_nbr_bytes(line_tmp, line_tmp[j], 1);
        else if (line_tmp[j][0] == DIRECT_CHAR)
            nbr += check_nbr_bytes(line_tmp, line_tmp[j], DIR_SIZE);
        else
            nbr += check_nbr_bytes(line_tmp, line_tmp[j], IND_SIZE);
    }
    return (nbr);
}

void count_label_distance(char *label, asm_t *assembly, int i)
{
    char **line_tmp = NULL; int k = 0; int z = 0; char *instru = NULL;

    line_tmp = my_str_to_word_tab(assembly->file[IDX]->all_file[i],
    adapt_delims());
    for (z = 0, k = 0; line_tmp[z]; z++) {
        (line_tmp[z][0] == COMMENT_CHAR) ? k++ : 0;
        (k > 0) ? line_tmp[z] = NULL : 0;
    }
    for (z = 0; line_tmp[z]; z++)
        if (my_strcmp(label, line_tmp[z]) == 0) {
            assembly->check_label++;
            assembly->distance -= assembly->file[IDX]->bytes_instru;
            return;
        }
    instru = found_instru(line_tmp, assembly);
    if (instru) {
        assembly->distance += coding_bytes(instru, assembly, -1, line_tmp);
        assembly->distance += check_bytes_params(instru, line_tmp);
    }
    return;
}

int calculate_distance_label(asm_t *assembly, char *param, int check)
{
    int i = 0;
    char *label = found_label(param, check);

    for (; assembly->file[IDX]->all_file[i]; i++) {
        if (assembly->file[IDX]->all_file[i][0] != '\0')
            count_label_distance(label, assembly, i);
        if (assembly->check_label != 0) {
            assembly->check_label = 0;
            return (assembly->distance);
        }
    }
    assembly->file[IDX]->error = 84;
    return (0);
}
