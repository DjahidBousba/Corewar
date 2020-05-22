/*
** EPITECH PROJECT, 2018
** task02
** File description:
** copies n characters from a string into another
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; ++i)
        dest[i] = src[i];
    for (; i < n; ++i)
        dest[i] = '\0';
    return (dest);
}