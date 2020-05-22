/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** convert_base.c
*/

#include "../include/my.h"

char convert_hexa_min(int nb)
{
    char res;

    if (nb == 10)
        res = 'a';
    if (nb == 11)
        res = 'b';
    if (nb == 12)
        res = 'c';
    if (nb == 13)
        res = 'd';
    if (nb == 14)
        res = 'e';
    if (nb == 15)
        res = 'f';
    return (res);
}

char *convert_base(unsigned int nb, int base)
{
    int k = 0;
    int r = 0;
    char *res = malloc(nb);

    while (nb != 0) {
        r = nb % base;
        nb = nb / base;
        if (r >= 10)
            res[k] = convert_hexa_min(r);
        if (r < 10)
            res[k] = r + 48;
        k++;
    }
    res[k] = '\0';
    my_revstr(res);
    return (res);
}