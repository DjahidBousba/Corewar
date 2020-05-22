/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** my_power.c
*/

#include "../include/my.h"

int my_power(int nb, int power)
{
    int result = nb;

    if (power == 0 || nb == 1) {
        return (result);
    }
    while (power != 1) {
        result = result * nb;
        power--;
    }
    return (result);
}