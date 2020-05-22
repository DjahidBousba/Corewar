/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** help.c
*/

#include "../include/asm.h"

void my_help(char **av)
{
    my_putstr("USAGE\n");
    my_putstr("        ");
    my_putstr(av[0]);
    my_putstr(" file_name[.s]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("        file_name      file in assembly language");
    my_putstr(" to be converted into file_name.cor, an ");
    my_putstr("executable in the Virtual Machine.\n");
    exit(0);
}