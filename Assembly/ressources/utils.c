/*
** EPITECH PROJECT, 2018
** utils
** File description:
** test
*/

#include "../include/ressources.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int w = 0;

    while (str[w] != '\0') {
        my_putchar(str[w]);
        w = w + 1;
    }
    return (0);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}

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

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    char letter;

    while (a <= b) {
        letter = str[a];
        str[a] = str[b];
        str[b] = letter;
        a = a + 1;
        b = b - 1;
    }
    return (str);
}
