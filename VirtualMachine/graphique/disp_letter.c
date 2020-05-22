/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** disp_letter.c
*/

#include "../include/my.h"

void letter_c(void)
{
    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2 - 30, COLS / 2 - 80, "        #############");
    mvprintw(LINES / 2 - 29, COLS / 2 - 80, "     ###::::::::::::#");
    mvprintw(LINES / 2 - 28, COLS / 2 - 80, "   ##:::::::::::::::#");
    mvprintw(LINES / 2 - 27, COLS / 2 - 80, "  #:::::########::::#");
    mvprintw(LINES / 2 - 26, COLS / 2 - 80, " #:::::#       ######");
    mvprintw(LINES / 2 - 25, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 24, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 20, COLS / 2 - 80, "#:::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 - 80, " #:::::#       ######");
    mvprintw(LINES / 2 - 18, COLS / 2 - 80, "  #:::::########::::#");
    mvprintw(LINES /2 - 17, COLS / 2 - 80, "   ##:::::::::::::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 - 80, "     ###::::::::::::#");
    mvprintw(LINES / 2 - 15, COLS / 2 - 80, "        #############");
    attroff(COLOR_PAIR(1));
}

void letter_o(void)
{
    attron(COLOR_PAIR(2));
    mvprintw(LINES / 2 - 26, COLS / 2 - 59, "   ###########");
    mvprintw(LINES / 2 - 25, COLS / 2 - 59, " ##:::::::::::##");
    mvprintw(LINES / 2 - 24, COLS / 2 - 59, "#:::::::::::::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 - 59, "#:::::#####:::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 - 59, "#::::#     #::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 - 59, "#::::#     #::::#");
    mvprintw(LINES / 2 - 20, COLS / 2 - 59, "#::::#     #::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 - 59, "#::::#     #::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 - 59, "#:::::#####:::::#");
    mvprintw(LINES /2 - 17, COLS / 2 - 59, "#:::::::::::::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 - 59, " ##:::::::::::##");
    mvprintw(LINES / 2 - 15, COLS / 2 - 59, "   ###########");
    attroff(COLOR_PAIR(2));
}

void letter_r(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 - 26, COLS / 2 - 42, "#####   #########");
    mvprintw(LINES / 2 - 25, COLS / 2 - 42, "#::::###:::::::::#");
    mvprintw(LINES / 2 - 24, COLS / 2 - 42, "#:::::::::::::::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 - 42, "##::::::#####::::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 - 42, " #:::::#     #:::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 - 42, " #:::::#     #######");
    mvprintw(LINES / 2 - 20, COLS / 2 - 42, " #:::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 - 42, " #:::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 - 42, " #:::::#");
    mvprintw(LINES /2 - 17, COLS / 2 - 42, " #:::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 - 42, " #:::::#");
    mvprintw(LINES / 2 - 15, COLS / 2 - 42, " #######");
    attroff(COLOR_PAIR(3));
}

void letter_e(void)
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 - 26, COLS / 2 - 22, "    ############");
    mvprintw(LINES / 2 - 25, COLS / 2 - 22, "  ##::::::::::::##");
    mvprintw(LINES / 2 - 24, COLS / 2 - 22, " #::::::#####:::::##");
    mvprintw(LINES / 2 - 23, COLS / 2 - 22, "#::::::#     #:::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 - 22, "#:::::::#####::::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 - 22, "#:::::::::::::::::#");
    mvprintw(LINES / 2 - 20, COLS / 2 - 22, "#::::::###########");
    mvprintw(LINES / 2 - 19, COLS / 2 - 22, "#:::::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 - 22, "#::::::::#");
    mvprintw(LINES /2 - 17, COLS / 2 - 22, " #::::::::########");
    mvprintw(LINES / 2 - 16, COLS / 2 - 22, "  ##:::::::::::::#");
    mvprintw(LINES / 2 - 15, COLS / 2 - 22, "    ##############");
    attroff(COLOR_PAIR(4));
}

void letter_w(void)
{
    attron(COLOR_PAIR(2));
    mvprintw(LINES / 2 - 26, COLS / 2 - 2, "#######           #####           ");
    mvprintw(LINES / 2 - 26, COLS / 2  + 32, "#######");
    mvprintw(LINES / 2 - 25, COLS / 2 - 2, " #:::::#         #:::::#         ");
    mvprintw(LINES / 2 - 25, COLS / 2 + 31, "#:::::# ");
    mvprintw(LINES / 2 - 24, COLS / 2 - 2, "  #:::::#       #:::::::#       ");
    mvprintw(LINES / 2 - 24, COLS / 2 + 30, "#:::::#");
    mvprintw(LINES / 2 - 23, COLS / 2 - 2, "   #:::::#     #:::::::::#     ");
    mvprintw(LINES / 2 - 23, COLS / 2 + 29, "#:::::#");
    mvprintw(LINES / 2 - 22, COLS / 2 - 2, "    #:::::#   #:::::#:::::#   ");
    mvprintw(LINES / 2 - 22, COLS / 2 + 28, "#:::::#");
    mvprintw(LINES / 2 - 21, COLS / 2 - 2, "     #:::::# #:::::# #:::::# ");
    mvprintw(LINES / 2 - 21, COLS / 2 + 27, "#:::::#");
    mvprintw(LINES / 2 - 20, COLS / 2 - 2, "      #:::::#:::::#   #:::::#:::::#");
    mvprintw(LINES / 2 - 19, COLS / 2 - 2, "       #:::::::::#     ");
    mvprintw(LINES / 2 - 19, COLS / 2 + 21, "#:::::::::#");
    mvprintw(LINES / 2 - 18, COLS / 2 - 2, "        #:::::::#       #:::::::#");
    mvprintw(LINES / 2 - 17, COLS / 2 - 2, "         #:::::#         #:::::#");
    mvprintw(LINES / 2 - 16, COLS / 2 - 2, "          #:::#           #:::#");
    mvprintw(LINES / 2 - 15, COLS / 2 - 2, "           ###             ###");
    attroff(COLOR_PAIR(2));
}