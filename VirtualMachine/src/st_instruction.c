/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** st_instruction.c
*/

#include "../include/my.h"

int second_param_st(vm_t *vm, int j, char *bin, param_t *param)
{
    int i = 3;

    if (bin[1] == '1' && bin[2] == '1') {
        param->param2 = convert_2bytes_in_int(vm, (vm->champ[j]->pc + i) % MEM_SIZE);
        i += 2;
    }
    if (bin[1] == '0' && bin[2] == '1') {
        param->param2 = vm->champ[j]->reg[vm->arena[(vm->champ[j]->pc + i) % MEM_SIZE] - 1];
        i += 1;
    }
    return (i);
}

int check_param_st(vm_t *vm, int coding_byte, int j, param_t *param)
{
    int i = 0;
    char *bin = my_convert_nb_base(coding_byte, 2);

    if (vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE] > REG_NUMBER ||
    vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE] < 0)
        return (-1);
    param->param1 = vm->champ[j]->reg[vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE] - 1];
    i = second_param_st(vm, j, bin, param);
    return (i);
}

void st(vm_t *vm, int j)
{
    param_t *param = malloc(sizeof(param_t));
    int i = 0;
    int nb = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[2].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_st(vm, vm->arena[(vm->champ[j]->pc + 1)], j, param);
        if (i == -1) {
            vm->champ[j]->pc += 1;
            return;
        }
        if (i == 5) {
            nb = vm->champ[j]->pc + param->param2 % IDX_MOD;
            convert_int_in_4bytes(vm, nb, param->param1, j);
        }
        if (i == 4) {
            nb = vm->arena[vm->champ[j]->pc + i - 1] - 1;
            vm->champ[j]->reg[nb] = param->param1;
        }
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += (i);
    }
    free(param);
}