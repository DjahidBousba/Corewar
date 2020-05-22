/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** sti_instruction.c
*/

#include "../include/my.h"

int second_param_sti(vm_t *vm, int j, char *bin, param_t *param)
{
    int i = 3;

    param->param2 = 0;
    if (bin[1] == '1' && bin[2] == '0') {
        param->param2 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[1] == '1' && bin[2] == '1') {
        param->param2 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[1] == '0' && bin[2] == '1') {
        param->param2 = vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1];
        i += 1;
    }
    return (i);
}

int last_param_sti(vm_t *vm, int j, char *bin, int i, param_t *param)
{
    param->param3 = 0;
    if (bin[3] == '1' && bin[4] == '0') {
        param->param3 = convert_2bytes_in_int(vm, vm->champ[j]->pc + i);
        i += 2;
    }
    if (bin[3] == '0' && bin[4] == '1') {
        param->param3 = (vm->champ[j]->reg[vm->arena[vm->champ[j]->pc + i] - 1]);
        i += 1;
    }
    return (i);
}

int check_param_sti(vm_t *vm, int j, param_t *param, int coding_byte)
{
    char *bin = my_convert_nb_base(coding_byte, 2);
    int i = 0;

    if (my_strlen(bin) < 7)
        return (-1);
    param->param1 = 0;
  /*  if ((vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE]) > REG_NUMBER
    || vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE] < 0)
        return (-1);*/
    param->param1 = vm->champ[j]->reg[vm->arena[(vm->champ[j]->pc + 2) % MEM_SIZE] - 1];
    i = second_param_sti(vm, j, bin, param);
   /* if (i == -1)
        return (-1);*/
    i = last_param_sti(vm, j, bin, i, param);
    free(bin);
    return (i);
}

void sti(vm_t *vm, int j)
{
    int i = 0;
    int add = 0;
    param_t *param = malloc(sizeof(param_t));

    if (vm->champ[j]->pause == -1)
        vm->champ[j]->pause = 25;//op_tab[10].nbr_cycles - 1;
    if (vm->champ[j]->pause == 0) {
        i = check_param_sti(vm, j, param, vm->arena[(vm->champ[j]->pc + 1) % MEM_SIZE]);
      /*  if (i == -1) {
            vm->champ[j]->pc += 6;
            return;
        }*/
       /* if (j == 3)  {
            my_putchar('(');
            my_put_nbr(param->param2);
            my_putchar('-');
            my_put_nbr(param->param3);
            my_putchar(')');
        }*/
        add = (vm->champ[j]->pc + ((param->param2 + param->param3) % IDX_MOD)) % MEM_SIZE;
        convert_int_in_4bytes(vm, add, param->param1, j);
        vm->champ[j]->pause = -1;
        vm->champ[j]->pc += i;
        vm->champ[j]->pc %= MEM_SIZE;
    }
    free(param);
}