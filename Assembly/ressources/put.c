/*
** EPITECH PROJECT, 2019
** put
** File description:
** test
*/

#include "../include/ressources.h"

char putchar_hexa_min(int nb)
{
    char res;

    if (nb == 10)
        res = 'a';
    if (nb == 11)
        res = 'b';
    if (nb == 12)
        res = 'c';
    if (nb == 13)
        res ='d';
    if (nb == 14)
        res = 'e';
    if (nb == 15)
        res = 'f';
    return (res);
}

void my_put_nbr_base_min(unsigned int nb, int base)
{
    int k = 0;
    int r = 0;
    char *res = malloc(nb);

    while (nb != 0) {
        r = nb % base;
        nb = nb / base;
        if (r >= 10)
            res[k] = putchar_hexa_min(r);
        if (r < 10)
            res[k] = r + 48;
        k++;
    }
    my_revstr(res);
    my_putstr(res);
}

char putchar_hexa_maj(int nb)
{
    char res;

    if (nb == 10)
        res = 'A';
    if (nb == 11)
        res = 'B';
    if (nb == 12)
        res = 'C';
    if (nb == 13)
        res ='D';
    if (nb == 14)
        res = 'E';
    if (nb == 15)
        res = 'F';
    return (res);
}

void my_put_nbr_base_maj(unsigned int nb, int base)
{
    int k = 0;
    int r = 0;
    char *res = malloc(nb);

    while (nb != 0) {
        r = nb % base;
        nb = nb / base;
        if (r >= 10)
            res[k] = putchar_hexa_maj(r);
        if (r < 10)
            res[k] = r + 48;
        k++;
    }
    my_revstr(res);
    my_putstr(res);
}

unsigned int my_put_nbr_un(unsigned int nb)
{
    if (nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_put_nbr_un(nb / 10);
        my_put_nbr_un(nb % 10);
    }
    return (0);
}