/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** or_instruction.c
*/


#include "../include/my.h"

char *or_loop(char *p1, char *p2, char *result, int bigger)
{
    int i = 0;

    for (my_revstr(p1), my_revstr(p2); p1[i] != '\0' && p2[i] != '\0'; i++) {
        if (p1[i] == '1' || p2[i] == '1')
            result[i] = '1';
        else if (p1[i] == '0' && p2[i] == '0')
            result[i] = '0';
    }
    if (p1[i] == '\0')
        for (; i != bigger; result[i] = p2[i], i++);
    else
        for (; i != bigger; result[i] = p1[i], i++);
    result[i] = '\0';
    my_revstr(result);
    return (result);
}

char *or_operation(param_t *param)
{
    char *p1 = my_convert_nb_base(param->param1, 2);
    char *p2 = my_convert_nb_base(param->param2, 2);
    int bigger = 0;
    char *result;

    if (my_strlen(p1) >= my_strlen(p2)) {
        result = malloc(sizeof(char) * my_strlen(p1) + 1);
        bigger = my_strlen(p1);
    } else {
        result = malloc(sizeof(char) * my_strlen(p2) + 1);
        bigger = my_strlen(p2);
    }
    or_loop(p1, p2, result, bigger);
    free(p1);
    free(p2);
    return (result);
}

void or(vm_t *vm, int j)
{
    int i = 0;
    param_t *param = malloc(sizeof(param_t));
    char *result;
    int res = 0;
    int rg = 0;

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = op_tab[6].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_bin(vm, j, param, vm->arena[vm->champ[j]->pc + 1]);
        vm->champ[j]->carry = 1;
        if (i == -1) {
            vm->champ[j]->carry = 0;
            vm->champ[j]->pc += 1;
            return;
        }
        rg = vm->arena[vm->champ[j]->pc + i] - 1;
        result = or_operation(param);
        res = convert_bin(my_getnbr(result));
        vm->champ[j]->reg[rg] = res;
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += (i + 1);
        free(result);
    }
    free(param);
}