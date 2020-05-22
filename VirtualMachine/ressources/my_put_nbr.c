/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** PTDR
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
