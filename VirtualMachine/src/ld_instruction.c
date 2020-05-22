/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** ld_instruction.c
*/

#include "../include/my.h"

int check_param_ld(vm_t *vm, int coding_byte, int j, param_t *param)
{
    int i = 2;
    char *bin = my_convert_nb_base(coding_byte, 2);

    if (my_strlen(bin) != 8)
        return (-1);
    if (bin[0] == '1' && bin[1] == '0') {
        param->param1 = convert_4bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 4;
    }
    if (bin[0] == '1' && bin[1] == '1') {
        param->param1 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    return (i);
}

void ld(vm_t *vm, int j)
{
    param_t *param = malloc(sizeof(param_t));
    int i = 0;
    int nb = 0;
    int reg = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[1].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        vm->champ[j]->carry = 1;
        i = check_param_ld(vm, vm->arena[vm->champ[j]->pc + 1], j, param);
        nb = convert_4bytes_in_int(vm, vm->champ[j]->pc + param->param1 % IDX_MOD);
        reg = vm->arena[vm->champ[j]->pc + i] - 1;
        if (i == -1 || reg > REG_NUMBER - 1 || reg < 0) {
            vm->champ[j]->pc += 1;
            vm->champ[j]->carry = 0;
            return;
        }
        vm->champ[j]->reg[reg] = nb;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += (i + 1);
        vm->champ[j]->pc %= MEM_SIZE;
    }
    free(param);
}

void lld(vm_t *vm, int j)
{
    param_t *param = malloc(sizeof(param_t));
    int i = 0;
    int nb = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[12].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        vm->champ[j]->carry = 1;
        i = check_param_ld(vm, vm->arena[vm->champ[j]->pc + 1], j, param);
        nb = vm->arena[vm->champ[j]->pc + i] - 1;
        vm->champ[j]->reg[nb] = param->param1;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += (i + 1);
        vm->champ[j]->pc %= MEM_SIZE;
    }
    free(param);
}