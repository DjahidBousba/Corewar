/*
** EPITECH PROJECT, 2018
** corewar_ncurses
** File description:
** init.c
*/

#include "../include/my.h"

void stock_shell_infos(ncurse_t *ncurse)
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, 0);
    init_pair(2, COLOR_CYAN, 0);
    init_pair(3, COLOR_GREEN, 0);
    init_pair(4, COLOR_YELLOW, 0);
    init_pair(5, COLOR_WHITE, COLOR_RED);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_GREEN);
    init_pair(8, COLOR_WHITE, COLOR_YELLOW);
    init_pair(10, COLOR_BLACK, COLOR_BLACK);
    init_pair(11, COLOR_BLACK, COLOR_WHITE);
    init_pair(12, 13, 0);
    init_pair(13, COLOR_WHITE, 0);
    init_pair(14, COLOR_BLACK, 0);
    curs_set(FALSE);
    init_color(COLOR_BLACK, 0, 0, 0);
    getyx(stdscr, ncurse->x, ncurse->y);
    getmaxyx(stdscr, ncurse->x_max, ncurse->y_max);
    ncurse->nbr_of_case = (ncurse->x_max - ((ncurse->x_max) / (ncurse->nbr_champ + 1)) - 2);
    ncurse->nbr_of_case = ncurse->nbr_of_case * (ncurse->y_max - 2);
}

void init_ncurse_struct(vm_t *vm)
{
    vm->ncurse->x = 0;
    vm->ncurse->y = 0;
    vm->ncurse->x_max = 0;
    vm->ncurse->y_max = 0;
    vm->ncurse->nbr_champ = vm->nb_champ;
    vm->ncurse->win = malloc(sizeof(WINDOW *) * 6);
    if (vm->ncurse->win == NULL)
        exit(84);
}