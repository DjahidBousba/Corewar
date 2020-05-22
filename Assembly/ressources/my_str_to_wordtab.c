/*
** EPITECH PROJECT, 2019
** my_str_to_wordtab
** File description:
** my_str_to_wordtab
*/

#include "../include/ressources.h"

int strtwt_free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; ++i)
        free(tab[i]);
    free(tab);
    return (0);
}

int strtwt_space_index(char *str)
{
    int i = -1;

    while (str[++i] != ' ' && str[i] != '\0');
    return (i);
}

int strtwt_is_delim(char c, char *delims)
{
    for (int i = 0; i < my_strlen(delims); ++i) {
        if (c == delims[i])
            return (1);
    }
    return (0);
}

char *strtwt_epur_str(char *str, char *delims)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (len + 1));
    int ps = 0;
    int j = 0;
    int eof = len - 1;

    for (int i = 0; i < len + 1; ++i)
        res[i] = 0;
    for (; eof >= 0 && strtwt_is_delim(str[eof], delims); --eof);
    for (int i = 0; i < len; ++i) {
        if (strtwt_is_delim(str[i], delims))
            ps += 1;
        else
            ps = 0;
        if (ps == 1 && i > 0 && i <= eof)
            res[j++] = ' ';
        else if (ps == 0)
            res[j++] = str[i];
    }
    return (res);
}

char **my_str_to_word_tab(char *str, char *delims)
{
    char **res = NULL;
    char *epur = strtwt_epur_str(str, delims);
    int elems = 0;
    int shift = 0;

    for (int i = 0; epur[i] != '\0'; ++i)
        if (epur[i] == ' ')
            elems += 1;
    elems += 1;
    res = malloc(sizeof(char *) * (elems + 1));
    res[elems] = NULL;
    for (int i = 0; i < elems; ++i) {
        res[i] = my_strdup(epur + shift);
        res[i][strtwt_space_index(res[i])] = '\0';
        shift += strtwt_space_index(res[i]) + 1;
    }
    free(epur);
    return (res);
}
