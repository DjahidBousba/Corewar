/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** my_strdup.c
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len + 1));

    my_strcpy(result, str);
    return (result);
}