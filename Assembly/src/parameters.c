/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** parameters.c
*/

#include "../include/asm.h"

int recup_nb_reg(char *str)
{
    int j = 0; int error = 0; int nb = 0;
    char *number = malloc(sizeof(char) * my_strlen(str));

    for (int i = 1; str[i]; i += 1, j += 1)
        number[j] = str[i];
    number[j] = '\0';
    for (j = 0; number[j]; j += 1) {
        if (number[j] < '0' || number[j] > '9')
            error = 1;
    }
    if (error != 1) {
        nb = my_getnbr(number);
        if (nb >= 0 && nb <= REG_NUMBER)
            return (1);
    }
    return (0);
}

int check_number(char *str, int i)
{
    for (; str[i]; i += 1) {
        if ((str[i] < 48 || str[i] > 57) && str[i] != '-') {
            return (0);
        }
    }
    return (1);
}

int check_in_str(char *str, int i)
{
    char *str2 = LABEL_CHARS; int j = 0;

    for (j = 0; str2[j]; j += 1) {
        if (str[i] == str2[j])
            break;
    }
    if (str2[j] == '\0')
        return (0);
    return (1);
}

int compare_label_chars(char *str, int i)
{
    for (; str[i]; i += 1) {
        if (check_in_str(str, i) == 0)
            return (0);
    }
    return (1);
}