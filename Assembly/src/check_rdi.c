/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** parameters.c
*/

#include "../include/asm.h"

int check_direct(char *str)
{
    if (my_strlen(str) <= 1)
        return (0);
    if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR && str[2] != '\0') {
        if (compare_label_chars(str, 2) == 0)
            return (0);
        return (1);
    }
    else if (str[0] == DIRECT_CHAR && str[1] != '\0') {
        if (check_number(str, 1) == 0)
            return (0);
        return (1);
    }
    return (0);
}

int check_indirect(char *str)
{
    if (str[0] == LABEL_CHAR && str[1] != '\0') {
        if (compare_label_chars(str, 1) == 0)
            return (0);
        return (1);
    }
    else if (str[0] != LABEL_CHAR) {
        if (check_number(str, 0) == 0)
            return (0);
        return (1);
    }
    return (0);
}

int check_register(char *str)
{
    if (str[0] == 'r') {
        if (recup_nb_reg(str) == 1)
            return (1);
        else
            return (0);
    }
    return (0);
}