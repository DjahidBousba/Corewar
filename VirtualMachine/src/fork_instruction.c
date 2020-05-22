/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** fork_instruction.c
*/

#include "../include/my.h"

void cp_reg(vm_t *vm, int i, int j)
{
    int k = 0;

    if (vm->champ[i]->reg == NULL) {
        vm->champ[i]->reg = malloc(sizeof(int) * REG_NUMBER);
            if (vm->champ[i]->reg == NULL)
                exit(84);
    }
    for (k = 0; k != REG_NUMBER; k++)
        vm->champ[i]->reg[k] = vm->champ[j]->reg[k];
}

void create_copy(vm_t *vm, int j, int index, int p)
{
    int i = vm->nb_champ + vm->nbr_fork;

    if (i == (vm->nb_champ * 10000) - 1) {
        endwin();
        my_put_nbr(vm->nbr_fork);
        exit(1);
    }
    if (p == 0)
        vm->champ[i]->pc = vm->champ[j]->pc + index % IDX_MOD;
    else
        vm->champ[i]->pc = vm->champ[j]->pc + index;
    cp_reg(vm, i, j);
    vm->champ[i]->name = my_strdup(vm->champ[j]->name);
    vm->champ[i]->nb = vm->champ[j]->nb;
    vm->champ[i]->pause = -1;
    if (vm->champ[j]->real == -1) {
        vm->champ[i]->real = j;
        vm->champ[j]->proc++;
    }   else {
        vm->champ[i]->real = vm->champ[j]->real;
        vm->champ[vm->champ[j]->real]->proc++;
    }
    vm->champ[i]->carry = vm->champ[j]->carry;
    vm->champ[i]->pause = -1;
    vm->nbr_fork += 1;
}

void forke(vm_t *vm, int j)
{
    int i = 0;
    int add = 0;
    int index = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[11].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        index = convert_2bytes_in_int(vm, vm->champ[j]->pc + 1);
        create_copy(vm, j, index, 0);
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += 3;
        vm->champ[j]->pc %= MEM_SIZE;
    }
}

void lfork(vm_t *vm, int j)
{
    int i = 0;
    int add = 0;
    int index = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[14].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        index = convert_2bytes_in_int(vm, vm->champ[j]->pc + 1);
        create_copy(vm, j, index, 1);
        vm->champ[j]->carry = 0;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += 3;
        vm->champ[j]->pc %= MEM_SIZE;
    }
}
