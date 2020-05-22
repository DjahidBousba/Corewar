/*
** EPITECH PROJECT, 2019
** utils3.c
** File description:
** test
*/

#include "../include/ressources.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (; n > 0; ++s1, ++s2, --n)
        if (*s1 != *s2)
            return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
        else if (*s1 == '\0')
            return (0);
    return (0);
}

char *my_int_to_char(int nb)
{
    int nb2; int nb3 = nb;
    char *res; int i = 0; int j = 0;

    for (; nb3 != 0; nb3 = (nb3 - (nb3 % 10)) / 10, j++);
    res = malloc(sizeof(char) * (j + 1));
    if (nb == 0)
        res[i] = '0';
    while (nb != 0) {
        if (nb >= 0 && nb < 10)
            res[i] = nb + 48;
        if (nb > 9) {
            nb2 = nb % 10;
            res[i] = nb2 + 48;
            i++;
        }
        nb = (nb - (nb % 10)) / 10;
    }
    res[i + 1] = '\0';
    my_revstr(res);
    return (res);
}

char *adapt_delims(void)
{
    char *str = malloc(sizeof(char) * 4);

    str[0] = ' ';
    str[1] = '\t';
    str[2] = SEPARATOR_CHAR;
    str[3] = '\0';
    return (str);
}

char **my_list_in_tab(list_t *list, int len)
{
    char **tab_left = malloc(sizeof(char*) * (len + 1));
    int i = 0; int j = 0; object_t *tmp = list->premier;

    while (tmp) {
        tab_left[i] = malloc(sizeof(char) * (my_strlen(tmp->string) + 1));
        while (tmp->string[j] != '\0') {
            tab_left[i][j] = tmp->string[j];
            j++;
        }
        tab_left[i][j] = '\0';
        j = 0;
        i++;
        tmp = tmp->suivant;
    }
    tab_left[i] = NULL;
    return (tab_left);
}
