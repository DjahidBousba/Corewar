/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** wesh
*/

#include "../include/my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    while (str[i] && str[i] != '\n'){
        nb = (nb * 10) + (str[i] - '0');
        i = i + 1;
    }
    nb = nb * neg;
    return (nb);
}