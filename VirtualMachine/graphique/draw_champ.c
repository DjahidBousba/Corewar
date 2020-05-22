/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** draw_champ.c
*/

#include "../include/my.h"

void draw_down_champ(int y, WINDOW *deco)
{
    mvwprintw(deco, 12, y, "                 |      |  |      |");
    mvwprintw(deco, 13, y, "         ___     |      |  |      |     ___");
    mvwprintw(deco, 14, y, "     _,-\",  \",   '_     |  |     _'   ,\"  ,\"-,_");
    mvwprintw(deco, 15, y, "   _(  \\  \\   \\\"=--\"-.  |  |  ");
    mvwprintw(deco, 15, y + 30, ".-\"--=\"/   /  /  )_");
    mvwprintw(deco, 16, y, " ,\"  \\  \\  \\   \\      \"-'--'-");
    mvwprintw(deco, 16, y + 29, "\"      /   /  /  /  \".");
    mvwprintw(deco, 17, y, "!     \\  \\  \\   \\              ");
    mvwprintw(deco, 17, y + 31, "    /   /  /  /     !");
    mvwprintw(deco, 18, y, ":      \\  \\  \\   \\             ");
    mvwprintw(deco, 18, y + 31, "   /   /  /  /      :");
}

void draw_champ(int y, int c, WINDOW *deco)
{
    wattron(deco, COLOR_PAIR(c));
    mvwprintw(deco, 1, y, "                   _.--.    .--._");
    mvwprintw(deco, 2, y, "                 .\"  .\"      \".  \".");
    mvwprintw(deco, 3, y, "                ;  .\"    /\\    \".  ;");
    mvwprintw(deco, 4, y, "                ;  '._,-/  \\-,_.`  ;");
    mvwprintw(deco, 5, y, "                \\  ,`  / /\\ \\  `,  /");
    mvwprintw(deco, 6, y, "                 \\/    \\/  \\/    \\/");
    mvwprintw(deco, 7, y, "                 ,=_    \\/\\/    _=,");
    mvwprintw(deco, 8, y, "                 |  \"_   \\/   _\"  |");
    mvwprintw(deco, 9, y, "                 |_   '\"-..-\"'   _|");
    mvwprintw(deco, 10, y, "                 | \"-.        .-\" |");
    mvwprintw(deco, 11, y, "                 |    \"\\    /\"    |");
    draw_down_champ(y, deco);
    wattroff(deco, COLOR_PAIR(c));
}