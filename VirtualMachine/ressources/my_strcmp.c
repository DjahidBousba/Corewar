/*
** EPITECH PROJECT, 2018
** VM
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return (0);
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
}