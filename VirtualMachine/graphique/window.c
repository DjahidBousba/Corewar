/*
** EPITECH PROJECT, 2018
** corewar_ncurses
** File description:
** window.c
*/

#include "../include/my.h"

void draw_first_champ(vm_t *vm)
{
    WINDOW *win = NULL;
    int y = 45 / 2 - my_strlen(vm->champ[0]->name) / 2;

    win = newwin(15, 45, 15, 300);
    refresh();
    box(win, 0, 0);
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 2, y, "%s", vm->champ[0]->name);
    wattroff(win, COLOR_PAIR(1));
    mvwprintw(win , 5, 1, "Number : %d", vm->champ[0]->nb);
    mvwprintw(win, 7, 1, "Nb of processes : %d", vm->champ[0]->proc);
    mvwprintw(win, 9, 1, "Statue : ");
    if (vm->champ[0]->dead == 0) {
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 9, 10, "Alive");
        wattroff(win, COLOR_PAIR(3));
    } else {
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win , 9, 10, "Dead ");
        wattroff(win, COLOR_PAIR(1));
    }
    wrefresh(win);
}

void draw_second_champ(vm_t *vm)
{
    WINDOW *win = NULL;
    int y = 45 / 2 - my_strlen(vm->champ[1]->name) / 2;

    win = newwin(15, 44, 30, 300);
    refresh();
    box(win, 0, 0);
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 2, y, "%s", vm->champ[1]->name);
    wattroff(win, COLOR_PAIR(2));
    mvwprintw(win , 5, 1, "Number : %d", vm->champ[1]->nb);
    mvwprintw(win, 7, 1, "Nb of processes : %d", vm->champ[1]->proc);
    mvwprintw(win, 9, 1, "Statue : ");
    if (vm->champ[1]->dead == 0) {
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 9, 10, "Alive");
        wattroff(win, COLOR_PAIR(3));
    } else {
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win , 9, 10, "Dead ");
        wattroff(win, COLOR_PAIR(1));
    }
    wrefresh(win);
}

void draw_third_champ(vm_t *vm)
{
    WINDOW *win = NULL;
    int y = 45 / 2 - my_strlen(vm->champ[2]->name) / 2;

    win = newwin(15, 45, 45, 300);
    refresh();
    box(win, 0, 0);
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 2, y, "%s", vm->champ[2]->name);
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win , 5, 1, "Number : %d", vm->champ[2]->nb);
    mvwprintw(win, 7, 1, "Nb of processes : %d", vm->champ[2]->proc);
    mvwprintw(win, 9, 1, "Statue : ");
    if (vm->champ[2]->dead == 0) {
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 9, 10, "Alive");
        wattroff(win, COLOR_PAIR(3));
    } else {
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win , 9, 10, "Dead ");
        wattroff(win, COLOR_PAIR(1));
    }
    wrefresh(win);
}

void draw_fourth_champ(vm_t *vm)
{
    WINDOW *win = NULL;
    int y = 45 / 2 - my_strlen(vm->champ[3]->name) / 2;

    win = newwin(15, 44, 60, 300);
    refresh();
    box(win, 0, 0);
    wattron(win, COLOR_PAIR(4));
    mvwprintw(win, 2, y, "%s", vm->champ[3]->name);
    wattroff(win, COLOR_PAIR(4));
    mvwprintw(win , 5, 1, "Number : %d", vm->champ[3]->nb);
    mvwprintw(win, 7, 1, "Nb of processes : %d", vm->champ[3]->proc);
    mvwprintw(win, 9, 1, "Statue : ");
    if (vm->champ[3]->dead == 0) {
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 9, 10, "Alive");
        wattroff(win, COLOR_PAIR(3));
    } else {
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win , 9, 10, "Dead ");
        wattroff(win, COLOR_PAIR(1));
    }
    wrefresh(win);
}

void draw_all_info(vm_t *vm)
{
    draw_first_champ(vm);
    draw_second_champ(vm);
    if (vm->nb_champ > 2)
        draw_third_champ(vm);
    if (vm->nb_champ > 3)
        draw_fourth_champ(vm);
    refresh();
}

void information(vm_t *vm)
{
    int idx = 0; int x = COLS / 4;

    if (vm->champ[0]->dead == 0)
        draw_champ(1, 1, vm->ncurse->deco);
    else
        draw_champ(1, 10, vm->ncurse->deco);
    if (vm->champ[1]->dead == 0)
        draw_champ((x * 2) - 80, 2, vm->ncurse->deco);
    else
        draw_champ((x * 2) - 80, 10, vm->ncurse->deco);
    if (vm->champ[2]->dead == 0 && vm->nb_champ > 2)
        draw_champ((x * 3) - 65, 3, vm->ncurse->deco);
    else
        draw_champ((x * 3) - 65, 10, vm->ncurse->deco);
    if (vm->champ[3]->dead == 0 && vm->nb_champ > 3)
        draw_champ((x * 4) - 52, 4, vm->ncurse->deco);
    else
        draw_champ((x * 4) - 52, 10, vm->ncurse->deco);
    wrefresh(vm->ncurse->deco);
    draw_all_info(vm);
}

void create_vm_window(ncurse_t *ncurse)
{
    WINDOW *win = NULL;
    int i = ncurse->x_max / 4;

    ncurse->x = 0;
    ncurse->y = 0;
    win = newwin(66, 291, ncurse->x + 10, 1);
    ncurse->x++;
    ncurse->y = 2;
    refresh();
    box(win, 0, 0);
    ncurse->win[0] = win;
    wrefresh(win);
}