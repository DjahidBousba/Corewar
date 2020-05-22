/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main.c
*/

#include "../include/asm.h"

int main(int ac, char **av)
{
    asm_t *assembly = malloc(sizeof(asm_t));

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        my_help(av);
    corewar(ac, av, assembly);
    return (assembly->error);
}