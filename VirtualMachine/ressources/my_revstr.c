/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** aze
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str);
    char c;

    while (i < j) {
        j = j - 1;
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
    }
    return (str);
}
