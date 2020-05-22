/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** print_map.c
*/

#include "../include/my.h"

void print_map1(vm_t *vm, int tmp_y)
{
    vm->ncurse->y++;
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->y = tmp_y;
    vm->ncurse->x++;
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->y++;
}

void print_map2(vm_t *vm, int tmp_y)
{
    vm->ncurse->y++;
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->y = tmp_y;
    vm->ncurse->x++;
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->y++;
}

void print_map3(vm_t *vm)
{
    vm->ncurse->y++;
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->y++;
}