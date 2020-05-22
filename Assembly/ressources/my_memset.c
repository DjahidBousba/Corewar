/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** my_memset.c
*/

#include "../include/ressources.h"

char *my_memset(char *str, char mem, int len)
{
    str = malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
        str[i] = mem;
    return (str);
}