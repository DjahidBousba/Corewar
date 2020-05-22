/*
** EPITECH PROJECT, 2018
** task06
** File description:
** same as my_strcmp but it stops at n or
** at end of line if n is greater
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (; n > 0; ++s1, ++s2, --n)
        if (*s1 != *s2)
            return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
        else if (*s1 == '\0')
            return (0);
    return (0);
}