/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** add_sub_inst.c
*/

#include "../include/my.h"

int check_reg(vm_t *vm, int j)
{
    if (vm->arena[vm->champ[j]->pc + 2] > REG_NUMBER ||
    (vm->arena[vm->champ[j]->pc + 2] - 1) < 0) {
        vm->champ[j]->pc += 1;
        vm->champ[j]->carry = 0;
        return (1);
    }
    if (vm->arena[vm->champ[j]->pc + 3] > REG_NUMBER ||
    (vm->arena[vm->champ[j]->pc + 3] - 1) < 0) {
        vm->champ[j]->pc += 1;
        vm->champ[j]->carry = 0;
        return (1);
    }
    if (vm->arena[vm->champ[j]->pc + 4] > REG_NUMBER ||
    (vm->arena[vm->champ[j]->pc + 4] - 1) < 0) {
        vm->champ[j]->pc += 1;
        vm->champ[j]->carry = 0;
        return (1);
    }
    return (0);
}

void add(vm_t *vm, int j)
{
    int i = 0;
    int op1 = 0;
    int op2 = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[3].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        vm->champ[j]->carry = 1;
        if (check_reg(vm, j) == 1)
            return;
        op1 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 2] - 1];
        op2 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 3] - 1];
        vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 4] - 1] = op1 + op2;
        vm->champ[j]->pc += 5;
        vm->champ[j]->pc %= MEM_SIZE;
        vm->champ[j]->pause = -1;
    }
}

void sub(vm_t *vm, int j)
{
    int i = 0;
    int op1 = 0;
    int op2 = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[4].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        if (check_reg(vm, j) == 1)
            return;
        vm->champ[j]->carry = 1;
        op1 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 2] - 1];
        op2 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 3] - 1];
        vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + 4] - 1] = op1 - op2;
        vm->champ[j]->pc += 5;
        vm->champ[j]->pc %= MEM_SIZE;
        vm->champ[j]->pause = -1;
    }
}