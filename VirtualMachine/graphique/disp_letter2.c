/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** disp_letter2.c
*/

#include "../include/my.h"

void letter_a(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 - 26, COLS / 2 + 39, "  #############");
    mvprintw(LINES / 2 - 25, COLS / 2 + 39, "  #::::::::::::#");
    mvprintw(LINES / 2 - 24, COLS / 2 + 39, "  #########:::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 + 39, "           #::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 + 39, "    #######:::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 + 39, "  ##::::::::::::#");
    mvprintw(LINES / 2 - 20, COLS / 2 + 39, " #::::####::::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 + 39, "#::::#    #:::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 + 39, "#::::#    #:::::#");
    mvprintw(LINES / 2 - 17, COLS / 2 + 39, "#:::::####::::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 + 39, " #::::::::::##:::#");
    mvprintw(LINES / 2 - 15, COLS / 2 + 39, "  ##########  ####");
    attroff(COLOR_PAIR(3));
}

void letter_r2(void)
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 - 26, COLS / 2 + 56, "#####   #########");
    mvprintw(LINES / 2 - 25, COLS / 2 + 56, "#::::###:::::::::#");
    mvprintw(LINES / 2 - 24, COLS / 2 + 56, "#:::::::::::::::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 + 56, "##::::::#####::::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 + 56, " #:::::#     #:::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 + 56, " #:::::#     #######");
    mvprintw(LINES / 2 - 20, COLS / 2 + 56, " #:::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 + 56, " #:::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 + 56, " #:::::#");
    mvprintw(LINES / 2 - 17, COLS / 2 + 56, " #:::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 + 56, " #:::::#");
    mvprintw(LINES / 2 - 15, COLS / 2 + 56, " #######");
    attroff(COLOR_PAIR(4));
}