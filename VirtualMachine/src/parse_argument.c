/*
** EPITECH PROJECT, 2018
** VM
** File description:
** parse_argument.c
*/

#include "../include/my.h"

char *get_header(vm_t *vm, int j)
{
    int name_len = PROG_NAME_LENGTH + 1;
    int comment_len = COMMENT_LENGTH + 1;
    int len = 0;
    int fd = 0;
    char *header;

    while (name_len % 4 != 0)
        name_len++;
    while (comment_len % 4 != 0)
        comment_len++;
    len = name_len + comment_len + 8;
    fd = open(vm->champ[j]->file_name, O_RDONLY);
    if ((header = malloc(sizeof(char) * len)) == NULL)
        exit(84);
    read(fd, header, len);
    return (header);
}

void set_name_and_file(char *file, vm_t *vm, int j)
{
    vm->champ[j]->file_name = my_revstr(file);
    vm->champ[j]->header = get_header(vm, j);
    vm->champ[j]->name = get_champ_name(vm, j);
    vm->champ[j]->ct = get_all_file(vm, j);
    vm->champ[j]->bytecode = get_bytecode(vm, j);
}

int check_parameter(char *str)
{
    int i = 0;

    if (my_strcmp(str, "-dump") == 0)
        i = 1;
    if (my_strcmp(str, "-n") == 0)
        i = 1;
    if (my_strcmp(str, "-a") == 0)
        i = 1;
    if (my_strcmp(str, "-g") == 0)
        i = 1;
    return (i);
}

void bad_parameter(char *str, vm_t *vm)
{
    int i = check_parameter(str);

    if (i != 1 && str[0] == '-') {
        my_putstr(str);
        my_putstr(": Bad option\n");
        free_error(vm);
        exit(1);
    }
}

int parse_argument(char **av, vm_t *vm)
{
    int i = 0;
    int j = 0;
    char *rev;

    for (i = 0; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 0)
            vm->cycle_nb = my_getnbr(av[i + 1]);
        if (my_strcmp(av[i], "-n") == 0)
            set_nb_champ(vm, j, my_getnbr(av[i + 1]));
        if (my_strcmp(av[i], "-a") == 0)
            set_adress_champ(vm, j, my_getnbr(av[i + 1]));
        if (my_strcmp(av[i], "-g") == 0)
            vm->g = 1;
        bad_parameter(av[i], vm);
        rev = my_revstr(av[i]);
        if (my_strncmp(rev, "roc.", 4) == 0) {
            set_name_and_file(av[i], vm, j);
            j++;
        }
    }
    error_header(vm);
    return (0);
}