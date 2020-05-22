/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** error_header.c
*/

#include "../include/my.h"

void check_prog_size(vm_t *vm, int j, int k)
{
    char *prog_size = malloc(sizeof(char) * 5); int i = 0; int len = 0;

    if (!prog_size)
        exit(84);
    prog_size[i] = vm->champ[j]->header[k];
    prog_size[++i] = vm->champ[j]->header[++k];
    prog_size[++i] = vm->champ[j]->header[++k];
    prog_size[++i] = vm->champ[j]->header[++k];
    prog_size[++i] = '\0';
    len += prog_size[0];
    len += prog_size[1];
    len += prog_size[2];
    len += prog_size[3];
}

void error_header(vm_t *vm)
{
    int k = 0;

    for (int j = 0; j < vm->nb_champ; j++) {
        k += check_magic_number(vm, j);
        k += ((PROG_NAME_LENGTH + 1) + (4 - ((PROG_NAME_LENGTH + 1) % 4)));
        check_prog_size(vm, j, k);
        k = 0;
    }
}
