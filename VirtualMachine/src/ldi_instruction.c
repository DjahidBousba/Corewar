/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** ldi_instruction.c
*/

#include "../include/my.h"

int second_param_ldi(vm_t *vm, int j, char *bin, int i, param_t *param)
{
    if (bin[i - 2] == '1' && bin[i - 1] == '1') {
        param->param2 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[i - 2] == '0' && bin[i - 1] == '1') {
        param->param2 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1];
        i += 1;
    }
    return (i);
}

int first_param_ldi(vm_t *vm, int j, char *bin, param_t *param)
{
    int i = 2;

    if (bin[0] == '1' && bin[1] == '0') {
        param->param1 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[0] == '1' && bin[1] == '1') {
        param->param1 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[0] == '1' && my_strlen(bin) == 7) {
        param->param1 = (vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1]);
        i += 1;
    }
    return (i);
}

int check_param_ldi(vm_t *vm, int coding_byte, int j, param_t *param)
{
    int i = 0;
    char *bin = my_convert_nb_base(coding_byte, 2);

    i = first_param_ldi(vm, j, bin, param);
    i = second_param_ldi(vm, j, bin, i, param);
    i += 1;
    free(bin);
    return (i);
}

void ldi(vm_t *vm, int j)
{
    param_t *param = malloc(sizeof(param_t));
    int i = 0;
    int add = 0;
    int nb = 0;
    int s = 0;
    int r = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[2].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_ldi(vm, vm->arena[vm->champ[j]->pc + 1], j, param);
        add = vm->champ[j]->pc + ((param->param1) % IDX_MOD);
        s = convert_2bytes_in_int(vm, add); 
        s += param->param2;
        nb = convert_4bytes_in_int(vm, vm->champ[j]->pc + s % IDX_MOD);
        vm->champ[j]->carry = 1;
        r = vm->arena[vm->champ[j]->pc + i] - 1;
        if (r > REG_NUMBER - 1 || r < 0) {
            vm->champ[j]->pause = -1;
            vm->champ[j]->pc += i;
            vm->champ[j]->carry = 0;
            vm->champ[j]->pc %= MEM_SIZE;
            return;
        }
        vm->champ[j]->reg[r] = add;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += i;
        vm->champ[j]->pc %= MEM_SIZE;
    }
    free(param);
}

void lldi(vm_t *vm, int j)
{
    param_t *param = malloc(sizeof(param_t));
    int i = 0;
    int add = 0;
    int nb = 0;
    int s = 0;
    int r = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[13].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_ldi(vm, vm->arena[vm->champ[j]->pc + 1], j, param);
        add = vm->champ[j]->pc + ((param->param1));
        s = convert_2bytes_in_int(vm, add); 
        s += param->param2;
        nb = convert_4bytes_in_int(vm, vm->champ[j]->pc + s);
        r = vm->arena[vm->champ[j]->pc + i - 1] - 1;
        vm->champ[j]->carry = 1;
        if (r > REG_NUMBER - 1 || r < 0) {
            vm->champ[j]->pause = -1;
            vm->champ[j]->pc += i;
            vm->champ[j]->carry = 0;
            vm->champ[j]->pc %= MEM_SIZE;
            return;
        }
        vm->champ[j]->reg[r] = add;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += i;
    }
    free(param);
}