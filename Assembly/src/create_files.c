/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** create_files.c
*/

#include "../include/asm.h"

char *name_cor(char *str)
{
    char *name = malloc(sizeof(char) * (my_strlen(str) + 3));
    if (name == NULL)
        exit(84);
    int i = 0;

    for (; str[i] && str[i] != '.'; i += 1)
        name[i] = str[i];
    name[i] = str[i];
    i += 1;
    name[i] = 'c';
    i += 1;
    name[i] = 'o';
    i += 1;
    name[i] = 'r';
    i += 1;
    name[i] = '\0';
    return (name);
}

char *my_file_name(char *av)
{
    int i = 0; int j = 0; char *result = NULL;

    for (; av[i]; i++);
    for (i -= 1; i >= 0 && av[i] != '/'; i--, j++);
    result = malloc(sizeof(char) * (j + 1));
    for (i = 0; av[i]; i++);
    for (i -= 1, j = 0; i >= 0 && av[i] != '/'; i--, j++) {
        result[j] = av[i];
    }
    result[j] = '\0';
    my_revstr(result);
    return (result);
}

void create_file(char **av, asm_t *assembly)
{
    char *file_s = my_file_name(av[IDX + 1]);
    char *file_cor = NULL;

    if (file_s) {
        file_cor = name_cor(file_s);
        if (open(file_cor, O_CREAT, 0644) < 0) {
            exit(84);
        }
        assembly->file[IDX]->file = file_cor;
    }
}