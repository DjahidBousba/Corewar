/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** disp_name.c
*/

#include "../include/my.h"

void name_djahid(void)
{
    int x = 80;
    int y = 120;

    attron(COLOR_PAIR(2));
    mvprintw(x, y, "  _____  _       _     _     _ ");
    mvprintw(x + 1, y, " |  __ \\(_)     | |   (_)   | |");
    mvprintw(x + 2, y, " | |  | |_  __ _| |__  _  __| |");
    mvprintw(x + 3, y, " | |  | | |/ _` | '_ \\| |/ _` |");
    mvprintw(x + 4, y, " | |__| | | (_| | | | | | (_| |");
    mvprintw(x + 5, y, " |_____/| |\\__,_|_| |_|_|\\__,_|");
    mvprintw(x + 6, y, "       _/ |                   ");
    mvprintw(x + 7, y, "      |__/                   ");
    mvprintw(x + 9, y, " ____                  _           ");
    mvprintw(x + 10, y, "|  _ \\                | |         ");
    mvprintw(x + 11, y, "| |_) | ___  _   _ ___| |__   __ _");
    mvprintw(x + 12, y, "|  _ < / _ \\| | | / __| '_ \\ / _` |");
    mvprintw(x + 13, y, "| |_) | (_) | |_| \\__ \\ |_) | (_| |");
    mvprintw(x + 14, y, "|____/ \\___/ \\__,_|___/_.__/ \\__,_|");
    attroff(COLOR_PAIR(2));
}

void name_hugo(void)
{
    int x = 80;
    int y = 20;

    attron(COLOR_PAIR(1));
    mvprintw(x, y + 8, " _    _                 ");
    mvprintw(x + 1, y + 8, "| |  | |                ");
    mvprintw(x + 2, y + 8, "| |__| |_   _  __ _  ___");
    mvprintw(x + 3, y + 8, "|  __  | | | |/ _` |/ _ \\");
    mvprintw(x + 4, y + 8, "| |  | | |_| | (_| | (_) |");
    mvprintw(x + 5, y + 8, "|_|  |_|\\__,_|\\__, |\\___/");
    mvprintw(x + 6, y + 8, "               __/ |    ");
    mvprintw(x + 7, y + 8, "              |___/");
    mvprintw(x + 9, y, "  _____             _ _   _           _");
    mvprintw(x + 10, y, " / ____|           | | | (_)         (_)");
    mvprintw(x + 11, y, "| |  __ _   _  __ _| | |_ _  ___ _ __ _ ");
    mvprintw(x + 12, y, "| | |_ | | | |/ _` | | __| |/ _ \\ '__| |");
    mvprintw(x + 13, y, "| |__| | |_| | (_| | | |_| |  __/ |  | |");
    mvprintw(x + 14, y, " \\_____|\\__,_|\\__,_|_|\\__|_|\\___|_|  |_|");
    attroff(COLOR_PAIR(1));
}

void name_lucas(void)
{
    int x = 80;
    int y = 320;

    attron(COLOR_PAIR(4));
    mvprintw(x, y + 4, " _                        ");
    mvprintw(x + 1, y + 4, "| |                       ");
    mvprintw(x + 2, y + 4, "| |    _   _  ___ __ _ ___ ");
    mvprintw(x + 3, y + 4, "| |   | | | |/ __/ _` / __|");
    mvprintw(x + 4, y + 4, "| |___| |_| | (_| (_| \\__ \\");
    mvprintw(x + 5, y + 4, "|______\\__,_|\\___\\__,_|___/");
    mvprintw(x + 9, y, " _______                        _  ");
    mvprintw(x + 10, y, "|__   __|                      | | ");
    mvprintw(x + 11, y, "   | | ___  _ __ _ __ ___ _ __ | |_ ");
    mvprintw(x + 12, y, "   | |/ _ \\| '__| '__/ _ \\ '_ \\| __|");
    mvprintw(x + 13, y, "   | | (_) | |  | | |  __/ | | | |_ ");
    mvprintw(x + 14, y, "   |_|\\___/|_|  |_|  \\___|_| |_|\\__|");
    attroff(COLOR_PAIR(4));
}

void name_laurent(void)
{
    int x = 80;
    int y = 230;

    attron(COLOR_PAIR(3));
    mvprintw(x, y + 2, " _                                _ ");
    mvprintw(x + 1, y + 2, "| |                              | |");
    mvprintw(x + 2, y + 2, "| |     __ _ _   _ _ __ ___ _ __ | |_");
    mvprintw(x + 3, y + 2, "| |    / _` | | | | '__/ _ \\ '_ \\| __|");
    mvprintw(x + 4, y + 2, "| |___| (_| | |_| | | |  __/ | | | |_ ");
    mvprintw(x + 5, y + 2, "|______\\__,_|\\__,_|_|  \\___|_| |_|\\__|");
    mvprintw(x + 9, y, "  _____  __          _                    ");
    mvprintw(x + 10, y, " / ____|/ _|        | |                  ");
    mvprintw(x + 11, y, "| (___ | |_ ___ _ __| | __ _ __________ _ ");
    mvprintw(x + 12, y, " \\___ \\|  _/ _ \\ '__| |/ _` |_  /_  / _` |");
    mvprintw(x + 13, y, " ____) | ||  __/ |  | | (_| |/ / / / (_| |");
    mvprintw(x + 14, y, "|_____/|_| \\___|_|  |_|\\__,_/___/___\\__,_|");
    attroff(COLOR_PAIR(3));
}

void disp_all_name(void)
{
    name_djahid();
    name_hugo();
    name_lucas();
    name_laurent();
    refresh();
}