/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** instruction16.c
*/

#include "../include/my.h"

void aff(vm_t *vm, int j)
{
    int ch = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[15].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        ch = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 2] - 1];
        if (vm->g == 0)
            my_putchar(ch % 255);
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += 3;
        vm->champ[j]->pc %= MEM_SIZE;
    }
}