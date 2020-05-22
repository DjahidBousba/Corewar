/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** zjmp_instruction.c
*/

#include "../include/my.h"

void zjmp(vm_t *vm, int j)
{
    int nb = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[8].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        if (vm->champ[j]->carry == 1) {
            nb = convert_2bytes_in_int(vm, vm->champ[j]->pc + 1);
            vm->champ[j]->pc += (nb % IDX_MOD);
        } else
            vm->champ[j]->pc += 3;
        vm->champ[j]->pause = -1;
    }
}