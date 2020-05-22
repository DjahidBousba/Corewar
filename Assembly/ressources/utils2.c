/*
** EPITECH PROJECT, 2019
** utils2.c
** File description:
** test
*/

#include "../include/ressources.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (str == NULL)
        exit(84);
    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; src[j] != '\0'; i++, j++)
        str[i] = src[j];
    str[i] = '\0';
    return (str);
}

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len + 1));

    my_strcpy(result, str);
    return (result);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}

int my_getnbr(char *str)
{
    int nb = 0; int sign = 1;
    int i = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '+')
            sign = 1;
        else
            sign = -1;
        i = i + 1;
        nb = nb * sign;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = str[i] - 48 + (nb * 10);
            i = i + 1;
        }
        else
            return (nb * sign);
    }
    return (nb * sign);
}

int my_strcmp(char *s1, char *s2)
{
    for (; *s1 == *s2; ++s1, ++s2)
        if (*s1 == '\0')
            return (0);
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
}
