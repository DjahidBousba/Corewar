/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** and_instruction.c
*/

#include "../include/my.h"

int first_param(vm_t *vm, int j, param_t *param, char *bin)
{
    int i = 2;

    param->param1 = 0;
    if (bin && (my_strlen(bin) > 8 && my_strlen(bin) < 7))
        return (-1);
    if (bin[0] == '1' && my_strlen(bin) == 7) {
        if (vm->arena[vm->champ[j]->pc + i] > REG_NUMBER)
            return (-1);
        param->param1 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1];
        i += 1;
    }
    if (bin[0] == '1' && bin[1] == '0' && my_strlen(bin) == 8) {
        param->param1 = convert_4bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 4;
    }
    if (bin[0] == '1' && bin[1] == '1' && my_strlen(bin) == 8) {
        param->param1 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    return (i);
}

int check_param_bin(vm_t *vm, int j, param_t *param, int coding_byte)
{
    char *bin = my_convert_nb_base(coding_byte, 2);
    int i = first_param(vm, j, param, bin);
    int k = 2;

    param->param2 = 0;
    if (i == -1) {
        free(bin);
        return (-1);
    }
    if (i == 3)
        k = 1;
    if (bin[k] == '0' && bin[k + 1] == '1') {
        if (vm->arena[vm->champ[j]->pc + i] > REG_NUMBER
        || vm->arena[vm->champ[j]->pc + i] < 0) {
            free(bin);
            return (-1);
        }
        param->param2 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1];
        i += 1;
    }
    if (bin[k] == '1' && bin[k + 1] == '0') {
        param->param2 = convert_4bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 4;
    }
    if (bin[k] == '1' && bin[k + 1] == '1') {
        param->param2 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    //free(bin);
    return (i);
}

int and_loop(char *p1, char *p2, char *result)
{
    int i = 0;
    int res = 0;

    for (my_revstr(p1), my_revstr(p2); p1[i] != '\0' && p2[i] != '\0'; i++) {
        if (p1[i] == '1' && p2[i] == '1')
            result[i] = '1';
        else
            result[i] = '0';
    }
    result[i] = '\0';
    my_revstr(result);
    res = my_getnbr(result);
    free(result);
    free(p1);
    free(p2);
    return (res);
}

int and_operation(param_t *param)
{
    char *p1 = my_convert_nb_base(param->param1, 2);
    char *p2 = my_convert_nb_base(param->param2, 2);
    char *result;
    int res = 0;

    if (my_strcmp(p1, "00") != 0 && my_strcmp(p2, "00") == 0) {
        free(p1);
        return (0);
    }
    if (my_strcmp(p1, "00") == 0 && my_strcmp(p2, "00") != 0) {
        free(p2);
        return (0);
    }
    if (my_strlen(p1) <= my_strlen(p2))
        result = malloc(sizeof(char) * my_strlen(p1) + 1);
    else
        result = malloc(sizeof(char) * my_strlen(p2) + 1);
    res = and_loop(p1, p2, result);
    return (res);
}

void and(vm_t *vm, int j)
{
    int i = 0;
    param_t *param = malloc(sizeof(param_t));
    int result;
    int rg = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[5].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_bin(vm, j, param, vm->arena[vm->champ[j]->pc + 1]);
        vm->champ[j]->carry = 1;
        if (i == -1) {
            vm->champ[j]->pc += 1;
            vm->champ[j]->carry = 0;
            return;
        }
        rg = vm->arena[vm->champ[j]->pc + i] - 1;
        result = and_operation(param);
        vm->champ[j]->reg[rg] = result;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += (i + 1);
    }
    free(param);
}