/*
** EPITECH PROJECT, 2018
** strtwt
** File description:
** strtwt.c
*/
#include "../include/ressources.h"

int count_to_malloc(char *str, char delim)
{
    int k = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == delim)
            k++;
    return (k + 2);
}

char **str_to_word_tab2(char *str, char delim)
{
    char **tab = malloc(sizeof(char *) * count_to_malloc(str, delim));
    int k = 0; int j = 0; int i2 = 0;

    if (tab == NULL)
        exit(84);
    for (int i = 0; str[i]; i2++) {
        k = 0;
        j = i;
        for (; str[i] && str[i] != delim; i++, k++);
        tab[i2] = malloc(sizeof(char) * (k + 1));
        if (tab[i2] == NULL)
            exit(84);
        for (i = j, k = 0; str[i] && str[i] != delim; i++, k++)
            tab[i2][k] = str[i];
        tab[i2][k] = '\0';
        if (str[i] != '\0')
            i++;
    }
    tab[i2] = NULL;
    return (tab);
}