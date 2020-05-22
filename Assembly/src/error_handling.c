/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** error_handling.c
*/

#include "../include/asm.h"

void check_error_comment(asm_t *assembly, char **all_file, int j)
{
    int len2 = my_strlen(COMMENT_CMD_STRING);

    if (my_strncmp(COMMENT_CMD_STRING, all_file[j], len2) == 0) {
        assembly->check_comment += 1;
        assembly->file[IDX]->comment = parse_result(all_file[j], assembly);
        if (COMMENT == NULL)
            assembly->file[IDX]->error = 84;
        if (NAME == NULL || my_strlen(COMMENT) > COMMENT_LENGTH) {
            my_putstr("Syntax Error\n");
            assembly->file[IDX]->error = 84;
        }
    }
}

void check_error_name2(asm_t *assembly, char **all_file, int j, int len2)
{
    all_file[j + 1] = check_unknown_char(all_file[j + 1]);
    if (my_strncmp(COMMENT_CMD_STRING, all_file[j + 1], len2) != 0) {
        my_putstr("Syntax Error2\n");
        assembly->file[IDX]->error = 84;
    }
}

void check_error_name(asm_t *assembly, char **all_file, int j)
{
    int len = my_strlen(NAME_CMD_STRING);
    int len2 = my_strlen(COMMENT_CMD_STRING);

    if (my_strncmp(NAME_CMD_STRING, all_file[j], len) == 0) {
        assembly->check_name += 1;
        assembly->file[IDX]->name = parse_result(all_file[j], assembly);
        if (NAME == NULL)
            assembly->file[IDX]->error = 84;
        if (my_strlen(assembly->file[IDX]->name) > PROG_NAME_LENGTH) {
            my_putstr("Syntax Error\n");
            assembly->file[IDX]->error = 84;
        } if (all_file[j + 1] && all_file[j + 1][0] == COMMENT_CHAR)
            all_file[j + 1] = NULL;
        if (all_file[j + 1])
            check_error_name2(assembly, all_file, j, len2);
        else {
            my_putstr("Syntax Error\n");
            assembly->file[IDX]->error = 84;
        }
    }
}

int check_name(char *name)
{
    int i = 0;

    for (; name[i]; i++);
    if (name[i - 1] != 's')
        return (1);
    if (name[i - 2] != '.')
        return (1);
    return (0);
}

void error_handling(int ac, char **av, asm_t *assembly)
{
    if (ac == 1) {
        my_putstr("No input file(s).\n");
        assembly->error = 84;
    }
    for (int i = 1; av[i]; i++) {
        if (open(av[i], O_RDONLY) < 0) {
            my_putstr("It's not a file.\n");
            assembly->file[i - 1]->error = 84;
        }
        if (check_name(av[i]) == 1) {
            my_putstr("It's not an assembly file.\n");
            assembly->file[i - 1]->error = 84;
        }
    }
}