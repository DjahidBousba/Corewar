/*
** EPITECH PROJECT, 2018
** CPE_corewar_2019
** File description:
** parse_file.c
*/

#include "../include/asm.h"

char *check_unknown_char(char *str)
{
    int i = 0; int tmp = 0;
    char *nw_str = NULL; int j = 0;

    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    tmp = i;
    for (i = 0; str[i]; i++);
    nw_str = malloc(sizeof(char) * ((i - tmp) + 1));
    if (!nw_str)
        exit(84);
    for (i = tmp; str[i]; i += 1, j += 1)
        nw_str[j] = str[i];
    nw_str[j] = '\0';
    return (nw_str);
}

char *parse_result(char *str, asm_t *assembly)
{
    char *result = NULL; int i = 0; int j = 0; int tmp = 0;

    for (; str[i] && str[i] != '"'; i++);
    if (str[i] == '\0')
        assembly->file[IDX]->error = 84;
    i++;
    for (tmp = i; str[i] && str[i] != '"'; i++, j++);
    if (str[i] != '"' || (str[i + 1] != '\0' && str[i + 1] != ' ' &&
    str[i + 1] != '\t'))
        assembly->file[IDX]->error = 84;
    result = malloc(sizeof(char) * (j + 1));
    for (i = tmp, j = 0; str[i] && str[i] != '"'; i++, j++)
        result[j] = str[i];
    result[j] = '\0';
    return (result);
}

void parse_file(asm_t *assembly, char *file, char **av)
{
    int fd = open(file, O_RDONLY); int size = lseek(fd, 0, SEEK_END);
    char *buff = malloc(sizeof(char) * (size + 1));

    fd = open(file, O_RDONLY);
    if (read(fd, buff, size + 1) < 0)
        exit(84);
    assembly->file[IDX]->all_file = str_to_word_tab2(buff, '\n');
    parse_header(assembly, assembly->file[IDX]->all_file);
    parse_instructions(assembly, assembly->file[IDX]->all_file);
    if (assembly->file[IDX]->error == 0) {
        create_file(av, assembly);
        if (assembly->file[IDX]->error == 0) {
            write_header(assembly);
            write_all_instruction(assembly);
        }
    }
    else
        assembly->error = 84;
}