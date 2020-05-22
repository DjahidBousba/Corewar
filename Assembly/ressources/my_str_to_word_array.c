/*
** EPITECH PROJECT, 2018
** utils3.c
** File description:
** test
*/

#include "../include/ressources.h"

int check_char(char c, int i)
{
    if (i == 1) {
        if (c >= 32 && c <= 126)
            return (1);
    }
    if (i == 2) {
        if (c >= 32 && c <= 126 && c != 58)
            return (1);
    }
    return (0);
}

int count_string(char *str)
{
    int	i = 0;
    int	nb = 0;
    while (str[i] != '\0') {
        if (check_char(str[i], 1) == 1 && check_char(str[i + 1], 1) != 1)
            nb++;
        if (str[i] == '\n' && str[i + 1] == '\n')
            nb++;
        i++;
    }
    return (nb);
}

int count_char(char *str, int i)
{
    while (str[i] != '\0') {
        if (check_char(str[i], 1) != 1)
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_array(char *str)
{
    int	i = 0; int j = 0; int k = 0;
    int	nb = count_string(str);
    char **tab;

    if ((tab = malloc(sizeof(char*) * (nb + 1))) == NULL)
        return (NULL);
    while (j < nb) {
        k = 0;
        if ((tab[j] = malloc(sizeof(char) * count_char(str, i) + 2)) == NULL)
            return (NULL);
        while (str[i] != '\0' && check_char(str[i], 1) == 1) {
            tab[j][k] = str[i];
            k++; i++;
        }
        tab[j][k] = '\0';
        i++; j++;
        k = 0;
    }
    tab[j] = NULL;
    return (tab);
}
