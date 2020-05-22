/*
** EPITECH PROJECT, 2018
** VM
** File description:
** arena.c
*/

#include "../include/my.h"

void my_create_arena(vm_t *vm)
{
    int i = 0;

    vm->arena = malloc(sizeof(char) * MEM_SIZE + 1);
    vm->color = malloc(sizeof(char) * MEM_SIZE + 1);
    if (vm->arena == NULL || vm->color == NULL)
        exit(84);
    while (i != MEM_SIZE) {
        vm->arena[i] = 0;
        vm->color[i] = 0;
        i++;
    }
    vm->arena[i] = '\0';
    vm->color[i] = '\0';
}

void disp_space(int k, int i)
{
    int j = 0;
    int a = 0;
    char *hex;

    my_putchar('\n');
    hex = my_convert_nb_base(i + 1, 16);
    my_putstr(hex);
    j = my_strlen(hex);
    for (a = 0; a != k - j; my_putchar(' '), a++);
    my_putstr(" : ");
    free(hex);
}

void disp_arena(vm_t *vm)
{
    int i = 0;
    char *hex = my_convert_nb_base(MEM_SIZE - 32, 16);
    int j;
    int k = my_strlen(hex);
    int a = 0;

    my_putstr("0");
    for (a = 0; a != k - 1; my_putchar(' '), a++);
    my_putstr(" : ");
    free(hex);
    for (i = 0; i != MEM_SIZE; i++) {
        hex = my_convert_nb_base(vm->arena[i], 16);
        my_putstr(hex);
        if ((i + 1) % 32 != 0)
            my_putchar(' ');
        if ((i + 1) % 32 == 0 && i + 1 != MEM_SIZE)
            disp_space(k, i);
        if (my_strcmp(hex, "00") != 0)
            free(hex);
    }
    my_putchar('\n');
}

void put_champion(vm_t *vm)
{
    int i = 0;
    int j = 0;
    int idx = 0;

    while (i != vm->nb_champ) {
        idx = vm->champ[i]->adress;
        while (j != vm->champ[i]->bt_len) {
            if (vm->arena[idx] == 0) {
                vm->arena[idx] = vm->champ[i]->bytecode[j];
                vm->color[idx] = vm->champ[i]->nb;
            }
            else {
                my_putstr("Overlap detected\n");
                exit(1);
            }
            if (idx > MEM_SIZE - 2)
                idx -= MEM_SIZE;
            j++;
            idx++;
        }
        j = 0;
        i++;
    }
}