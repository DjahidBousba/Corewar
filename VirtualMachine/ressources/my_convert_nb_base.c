/*
** EPITECH PROJECT, 2018
** base
** File description:
** put_nbr
*/

#include "../include/my.h"

int calc_loop(int nb, int base)
{
    int result;
    int i = 0;

    for (; nb != 0; i++) {
        result = nb % base;
        nb = nb / base;
    }
    return (i);
}

char *find_result(int nb, int base, char *str)
{
    int result;
    int i = 0;
    int j = 0;

    for (; nb != 0; i++) {
        result = nb % base;
        nb = nb / base;
        if (result >= 10) {
            j = result - 10;
            result = 'A' + j;
            str[i] = result;
        }
        if (result < 10)
            str[i] = result + 48;
    }
    str[i] = '\0';
    return (str);
}

char *add_zero(char *str)
{
    char *new = malloc(sizeof(char) * 3);

    if (new == NULL)
        exit(84);
    new[0] = '0';
    new[1] = str[0];
    new[2] = '\0';
    free(str);
    return (new);
}

char *my_convert_nb_base(int nb, int base)
{
    int nb_loop;
    char *str;
    char *new;

    if (nb < 0)
        nb += 256;
    if (nb != 0)
        nb_loop = calc_loop(nb, base);
    if (nb == 0)
        return (my_strdup("00"));
    if ((str = malloc(sizeof(char) * nb_loop + 1)) == NULL)
        exit(84);
    str = find_result(nb, base, str);
    if (my_strlen(str) == 1) {
        return(add_zero(str));
    }
    return (my_revstr(str));
}