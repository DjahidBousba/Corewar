/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** stock_number.c
*/

#include "../include/asm.h"

int stock_number_direct(char *param)
{
    int len = my_strlen(param); int i = 1; int j = 0;
    int nb = 0; char *result_nb = malloc(sizeof(char) * len);

    for (; param[i]; i += 1, j += 1)
        result_nb[j] = param[i];
    result_nb[j] = '\0';
    nb = my_getnbr(result_nb);
    return (nb);
}

int stock_number_indirect(char *param)
{
    int len = my_strlen(param); int i = 0; int j = 0;
    int nb = 0; char *result_nb = malloc(sizeof(char) * (len + 1));

    if (param[0] != LABEL_CHAR) {
        for (; param[i]; i += 1, j += 1)
            result_nb[j] = param[i];
        result_nb[j] = '\0';
    }
    nb = my_getnbr(result_nb);
    return (nb);
}

void add_hexa(char *tmp, asm_t *assembly, char *final_hexa)
{
    int i = 0; int j = 0; unsigned char c;

    for (i = 0, j = 0; final_hexa[i]; i++, j++) {
        tmp[j] = final_hexa[i];
        if (i % 2 != 0) {
            tmp[2] = '\0';
            c = hexa_to_dec(tmp);
            add_link_last2(assembly->file[IDX]->instru, c);
            j = -1;
        }
    }
}

void write_hexa_prog_size(char *tmp, asm_t *assembly, char *final_hexa)
{
    int i = 0; int j = 0; unsigned char c;

    for (i = 0, j = 0; final_hexa[i]; i++, j++) {
        tmp[j] = final_hexa[i];
        if (i % 2 != 0) {
            tmp[2] = '\0';
            c = hexa_to_dec(tmp);
            write(assembly->file[IDX]->fd, &c, 1);
            j = -1;
        }
    }
}