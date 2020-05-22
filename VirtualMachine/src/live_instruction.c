/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** live_instruction.c
*/

#include "../include/my.h"

int find_champ_alive(vm_t *vm, int pc)
{
    int i = 0;

    for (; i != 3; pc++, pc %= MEM_SIZE, i++) {
        if (vm->arena[pc] != 0)
            return (-1);
    }
    if (vm->arena[pc] > 4 || vm->arena[pc] < 0)
        return (-1);
    for (i = 0; i != vm->nb_champ; i++) {
        if (vm->champ[i]->nb == vm->arena[pc])
            return (i);
    }
    if (i == vm->nb_champ)
        return (-1);
    return (0);
}

void live_instr(vm_t *vm, int j, int i)
{
    if (vm->nbr_live >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_live = 0;
    }
    if (vm->champ[i]->real != -1)
        vm->champ[vm->champ[i]->real]->live = 1;
    else
        vm->champ[i]->live = 1;
    if (vm->g == 0 && vm->champ[j]->dead == 0) {
        my_putstr("The player ");
        my_put_nbr(vm->champ[i]->nb);
        my_putstr(" (");
        my_putstr(vm->champ[i]->name);
        my_putstr(") is alive.\n");
        vm->last_live = i;
    }
}

void live(vm_t *vm, int j)
{
    int live = 0;
    int pc = vm->champ[j]->pc + 1;
    int i = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[0].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = find_champ_alive(vm, pc % MEM_SIZE);
        if (i != -1) {
            vm->nbr_live++;
            live_instr(vm, j, i);
        }
        vm->champ[j]->pc += 5;
        vm->champ[j]->pc %= MEM_SIZE;
        vm->champ[j]->pause = -1;
    }
}