/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** menu.c
*/

#include "../include/my.h"

void all_letter(void)
{
    refresh();
    usleep(1000000);
    letter_c();
    refresh();
    usleep(1000000);
    letter_o();
    refresh();
    usleep(1000000);
    letter_r();
    refresh();
    usleep(1000000);
    letter_e();
    refresh();
    usleep(1000000);
    letter_w();
    refresh();
    usleep(1000000);
    letter_a();
    refresh();
    usleep(1000000);
}

void wait_a_key(int color)
{
    int x = LINES / 2;
    int y = COLS / 2 - 35;

    attron(COLOR_PAIR(color));
    mvprintw(x - 1, y, " __");
    mvprintw(x, y, "|__)  _  _  _  _    _   _       |   _      |_  _     _ |_  _   _ |_");
    mvprintw(x + 1, y, "|    |  (- _) _)   (_| | ) \\/   |( (- \\/   |_ (_)   _) |_ (_| |  |_ ");
    mvprintw(x + 2, y, "                           /          /");
    attroff(COLOR_PAIR(color));
}

void menu()
{
    int key = -1;
    int i = 0;
    int color = 13;

    nodelay(stdscr, true);
    all_letter();
    letter_r2();
    refresh();
    all_dragon();
    disp_all_name();
    while (key == ERR) {
        wait_a_key(color);
        key = getch();
        i++;
        if (i % 2 == 0)
            color = 13;
        else
            color = 14;
        usleep(100000);
    }
}