/*
** EPITECH PROJECT, 2018
** word_array
** File description:
** test
*/

#include "../include/my.h"

char *get_str(char *path, char sep, int init)
{
    static int i = 0;
    char *pos;
    int k = i;
    int j = 0;

    if (init == 1) {
        i = 0;
        k = 0;
    }
    for (; i <= my_strlen(path) && path[i] && path[i] != sep; i++);
    pos = malloc(sizeof(char) * (i - k + 1));
    if (pos == NULL)
        exit(84);
    i = k;
    for (; i <= my_strlen(path) && path[i] && path[i] != sep; i++, j++)
        pos[j] = path[i];
    i++;
    pos[j] = '\0';
    return (pos);
}

int get_nb_str(char *path, char sep)
{
    int i = 0;
    int nb = 0;

    while (path[i] != '\0') {
        if (path[i] == sep)
            nb++;
        i++;
    }
    return (nb);
}

char **my_str_to_word_tab(char *str, char sep)
{
    char *pos = get_str(str, sep, 1);
    char **tab;
    int i = 0;
    int nb = get_nb_str(str, sep) + 1;

    tab = malloc(sizeof(char *) * (nb + 1));
    if (tab == NULL)
        exit(84);
    while (i != nb - 1) {
        tab[i] = pos;
        pos = get_str(str, sep, 0);
        i++;
    }
    tab[i] = pos;
    tab[i + 1] = NULL;
    return (tab);
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
