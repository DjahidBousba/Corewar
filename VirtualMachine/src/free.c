/*
** EPITECH PROJECT, 2018
** VM
** File description:
** free.c
*/

#include "../include/my.h"

void free_all(vm_t *vm)
{
    int i = 0;

    while (i != vm->nb_champ) {
        free(vm->champ[i]->reg);
        free(vm->champ[i]);
        i++;
    }
    while (i != (vm->nb_champ * 10000)) {
        free(vm->champ[i]->reg);
        free(vm->champ[i]);
        i++;
    }
    free(vm->champ);
    free(vm->arena);
    free(vm);
}

void free_error(vm_t *vm)
{
    int i = 0;

    while (i != vm->nb_champ) {
        free(vm->champ[i]);
        i++;
    }
    free(vm->champ);
}