/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** convert.c
*/

#include "../include/asm.h"
#include "../include/ressources.h"

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
        res ='d';
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

int nb_power(int nb, int power)
{
    int i = 1;
    int nw = nb;

    if (power == 0)
        return (1);
    while (i != power) {
        nw = nw * nb;
        i++;
    }
    return (nw);
}

int hexa_to_dec(char *hexa)
{
    int i = 0;
    int dec = 0;
    int len = my_strlen(hexa);

    while (hexa[i] != '\0') {
        if (hexa[i] - 48 < 10)
            dec = (hexa[i] - 48) * nb_power(16, len - 1) + dec;
        if (hexa[i] - 48 > 10)
            dec = (hexa[i] - 87) * nb_power(16, len - 1) + dec;
        i++;
        len--;
    }
    return (dec);
}