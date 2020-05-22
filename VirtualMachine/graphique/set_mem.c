/*
** EPITECH PROJECT, 2018
** corewar_ncurses
** File description:
** simualation_memoire.c
*/

#include "../include/my.h"

int check_pc(vm_t *vm, int i)
{
    int j = 0;

    while (j != vm->nb_champ + vm->nbr_fork) {
        if (vm->champ[j]->pc == i)
            return (1);
        j++;
    }
    return (0);
}

void print_the_byte(vm_t *vm, int i)
{
    char *hexa = NULL;

    hexa = my_convert_nb_base(vm->arena[i], 16);
    if (check_pc(vm, i) == 0)
        attron(COLOR_PAIR(vm->color[i]));
    if (check_pc(vm, i) == 1 && vm->color[i] != 0)
        attron(COLOR_PAIR(vm->color[i] + 4));
    printw("%s", hexa);
    if (check_pc(vm, i) == 0)
        attroff(COLOR_PAIR(vm->color[i]));
    if (check_pc(vm, i) == 1 && vm->color[i] != 0)
        attroff(COLOR_PAIR(vm->color[i] + 4));
    vm->ncurse->y++;
    move(vm->ncurse->x, vm->ncurse->y);
}

void welcome_message(void)
{
    int x = 1;
    int y = /*COLS / 2 - 61*/0;

    init_pair(20, 11, 0);
    attron(COLOR_PAIR(20));
    mvprintw(x, y, "          _______  _        _______  _______  _______  _______   _________ _______             _______  _        _      ");
    mvprintw(x + 1, y, "|\\     /|(  ____ \\( \\      (  ____ \\(  ___  )(       )(  ____ \\  \\__   __/(  ___  )  |\\     /|(  ____ \\( \\      ( \\     ");
    mvprintw(x + 2, y, "| )   ( || (    \\/| (      | (    \\/| (   ) || () () || (    \\/     ) (   | (   ) |  | )   ( || (    \\/| (      | (    ");
    mvprintw(x + 3, y, "| | _ | || (__    | |      | |      | |   | || || || || (__         | |   | |   | |  | (___) || (__    | |      | |    ");
    mvprintw(x + 4, y, "| |( )| ||  __)   | |      | |      | |   | || |(_)| ||  __)        | |   | |   | |  |  ___  ||  __)   | |      | | ");
    mvprintw(x + 5, y, "| || || || (      | |      | |      | |   | || |   | || (           | |   | |   | |  | (   ) || (      | |      | | ");
    mvprintw(x + 6, y, "| () () || (____/\\| (____/\\| (____/\\| (___) || )   ( || (____/\\     | |   | (___) |  | )   ( || (____/\\| (____/\\| (____/\\");
    mvprintw(x + 7, y, "(_______)(_______/(_______/(_______/(_______)|/     \\|(_______/     )_(   (_______)  |/     \\|(_______/(_______/(_______/");
    attroff(COLOR_PAIR(20));
}

void set_mem(vm_t *vm)
{
    int tmp_x = vm->ncurse->x;
    int tmp_y = vm->ncurse->y;

    welcome_message();
    move(vm->ncurse->x, vm->ncurse->y);
    printw(" ");
    vm->ncurse->x += 10;
    vm->ncurse->y++;
    move(vm->ncurse->x, vm->ncurse->y);
    for (int i = 0; i < MEM_SIZE; i++) {
        print_the_byte(vm, i);
        if (i != 0 && vm->ncurse->x == tmp_x && i % 95 == 0)
            print_map1(vm, tmp_y);
        else if (i != 0 && i != 96 && (i + 1) % 96 == 0)
            print_map2(vm, tmp_y);
        else
            print_map3(vm);
        move(vm->ncurse->x, vm->ncurse->y);
    }
    vm->ncurse->x = tmp_x;
    vm->ncurse->y = tmp_y;
}
