/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** dragon.c
*/

#include "../include/my.h"

void up_dragon(void)
{
    int x = LINES / 2 - 25;
    int y = COLS / 2 + 95;

    mvprintw(x, y, "           /                            )");
    mvprintw(x + 1, y, "          (                             |\\");
    mvprintw(x + 2, y, "         /|                              \\\\");
    mvprintw(x + 3, y, "        //                                \\\\");
    mvprintw(x + 4, y, "       ///                                 \\|");
    mvprintw(x + 5, y, "      /( \\                                  )\\");
    mvprintw(x + 6, y, "      \\\\  \\_                               //)");
    mvprintw(x + 7, y, "       \\\\  :\\__                           ///");
    mvprintw(x + 7, y, "        \\\\     )                         // \\");
    mvprintw(x + 8, y, "         \\\\:  /                         // |/");
    mvprintw(x + 9, y, "          \\\\ / \\                       //  \\");
    mvprintw(x + 10, y, "           /)   \\     ___..-'         ((  \\_|");
    mvprintw(x + 11, y, "          //     /  .'  _.'           \\ \\  \\");
    mvprintw(x + 12, y, "         /|       \\(  _\\_____          \\ | /");
    mvprintw(x + 13, y, "        (| _ _  __/          '-.       ) /.'");
    mvprintw(x + 14, y, "         \\\\ .  '-.__ \\          \\_    / / \\");
    mvprintw(x + 15, y, "          \\\\_'.     > '-._   '.   \\  / / /");
}

void mid_dragon(void)
{
    int x = LINES / 2 - 9;
    int y = COLS / 2 + 95;

    mvprintw(x, y, "           \\ \\      \\     \\    \\   .' /.'");
    mvprintw(x + 1, y, "            \\ \\  '._ /     \\  /   / .' |");
    mvprintw(x + 2, y, "             \\ \\_     \\_   |    .'_/ __/");
    mvprintw(x + 3, y, "              \\  \\      \\_ |   / /  _/ \\_");
    mvprintw(x + 4, y, "               \\  \\       / _.' /  /     \\");
    mvprintw(x + 5, y, "               \\   |     /.'   / .'       '-,_");
    mvprintw(x + 6, y, "                \\   \\  .'   _.'_/             \\");
    mvprintw(x + 7, y, "   /\\    /\\      ) ___(    /_.'           \\    |");
    mvprintw(x + 8, y, "  | _\\__// \\    (.'      _/               |    |");
    mvprintw(x + 9, y, "  \\/_  __  /--'`    ,                   __/    /");
    mvprintw(x + 10, y, "  (_ ) /b)  \\  '.   :            \\___.-:_/ \\__/");
    mvprintw(x + 11, y, "  /:/:  ,     ) :        (      /_.'_/-' |_ _ /");
    mvprintw(x + 12, y, " /:/: __/\\ >  __,_.----.__\\    /        (/(/(/");
    mvprintw(x + 13, y, "(_(,_/V .'/--'    _/  __/ |   /");
    mvprintw(x + 14, y, " VvvV  //`    _.-' _.'     \\   \\");
    mvprintw(x + 15, y, "   n_n//     (((/->/        |   /");
    mvprintw(x + 16, y, "   '--'         ~='          \\  |");
}

void down_dragon(void)
{
    int x = LINES / 2 + 8;
    int y = COLS / 2 + 95;

    mvprintw(x, y, "                              | |_,,,");
    mvprintw(x + 1 , y, "                              \\  \\  /");
    mvprintw(x + 2, y, "                               '.__)");
}

void all_dragon(void)
{
    attron(COLOR_PAIR(12));
    up_dragon();
    mid_dragon();
    down_dragon();
    attroff(COLOR_PAIR(12));
}