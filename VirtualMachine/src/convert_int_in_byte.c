/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** convert_int_in_byte.c
*/

#include "../include/my.h"

void convert_int_in_4bytes(vm_t *vm, int i, int reg, int j)
{
    int k = 3;
    int nb = 0;

    i %= MEM_SIZE;
    if (i < 0)
        i += MEM_SIZE;
    while (k != 0) {
        nb = reg / my_power(256, k);
        if (nb > 127)
            nb -= 255;
        if (reg > my_power(256, k))
            vm->arena[i] = nb;
        else
            vm->arena[i] = 0;
        vm->color[i] = vm->champ[j]->nb;
        i++;
        i %= MEM_SIZE;
        if (i < 0)
            i += MEM_SIZE;
        k--;
    }
    vm->arena[i] = reg;
    vm->color[i] = vm->champ[j]->nb;
}

int convert_4bytes_in_int(vm_t *vm, int i)
{
    int *adress = malloc(sizeof(int) * 4);
    int j = 0;
    long int result = 0;
    int res = 0;

    while (j != 4) {
        adress[j] = vm->arena[(i + j) % MEM_SIZE];
        if (adress[j] < 0)
            adress[j] += 256;
        j++;
    }
    result += adress[0] * my_power(256, 3);
    result += adress[1] * my_power(256, 2);
    result += adress[2] * 256;
    result += adress[3];
    if (result > (4294967296 / 2))
        result -= 4294967296;
    res = result;
    return (res);
}

int convert_2bytes_in_int(vm_t *vm, int i)
{
    int result = 0;
    int adress = vm->arena[i % MEM_SIZE];
    int adress2 = vm->arena[(i + 1) % MEM_SIZE];

    if (adress < 0)
        adress += 256;
    if (adress2 < 0)
        adress2 += 256;
    result = adress * 256;
    result += adress2;
    if (result > (65536 / 2))
        result -= 65536;
    return (result);
}

