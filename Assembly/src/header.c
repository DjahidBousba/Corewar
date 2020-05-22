/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** header.c
*/

#include "../include/asm.h"

void parse_header(asm_t *assembly, char **all_file)
{
    for (int j = 0; all_file[j]; j++) {
        all_file[j] = check_unknown_char(all_file[j]);
        if (all_file[j][0] != '\0') {
            check_error_name(assembly, all_file, j);
            check_error_comment(assembly, all_file, j);
        }
        if (assembly->file[IDX]->error == 84)
            return;
    }
    if (assembly->check_name > 1 || assembly->check_comment > 1) {
        if (assembly->file[IDX]->error != 84)
            my_putstr("Too much name or comment\n");
        assembly->file[IDX]->error = 84;
    }
    if (NAME == NULL || COMMENT == NULL) {
        my_putstr("Missing name or comment.\n");
        assembly->file[IDX]->error = 84;
    }
}

void my_magic_number(asm_t *assembly)
{
    char *hexa = convert_base(COREWAR_EXEC_MAGIC, 16);
    char *tmp = NULL; int i = 0; int j = 0; unsigned char c = 0;

    tmp = malloc(sizeof(char) * 3); tmp[2] = '\0';
    write(assembly->file[IDX]->fd, &c, 1);
    for (j = 0; i < 2; i++, j++)
        tmp[j] = hexa[i];
    c = hexa_to_dec(tmp);
    write(assembly->file[IDX]->fd, &c, 1);
    for (j = 0; i < 4; i++, j++)
        tmp[j] = hexa[i];
    c = hexa_to_dec(tmp);
    write(assembly->file[IDX]->fd, &c, 1);
    for (j = 0; i < 6; i++, j++)
        tmp[j] = hexa[i];
    c = hexa_to_dec(tmp);
    free(tmp);
    write(assembly->file[IDX]->fd, &c, 1);
}

void write_prog_size(asm_t *assembly)
{
    int i = 0; int nbr = 0; int len = 0;
    char *byte = NULL; char *hexa = NULL; char *final_hexa = NULL;
    char *tmp = malloc(sizeof(char) * 3);

    hexa = convert_base(assembly->file[IDX]->bytes, 16);
    len = my_strlen(hexa);
    if (len < 8) {
        for (i = 0; len < 8; len++, i++);
        byte = malloc(sizeof(char) * (i + 1));
        len = my_strlen(hexa);
        for (; len < 8; len++, nbr++)
            byte[nbr] = '0';
        byte[nbr] = '\0';
        final_hexa = my_strcat(byte, hexa);
    } else if (len > 8)
        final_hexa = cut_hexa(hexa, 8);
    else
        final_hexa = hexa;
    write_hexa_prog_size(tmp, assembly, final_hexa);
}

void write_header(asm_t *assembly)
{
    char c = 0; int i = 0;

    FD = open(assembly->file[IDX]->file, O_RDWR, 0644);
    if (FD < 0)
        exit(84);
    my_magic_number(assembly);
    write(FD, NAME, my_strlen(NAME));
    for (i = 0; i < ((PROG_NAME_LENGTH + 4) - my_strlen(NAME)); i++)
        write(FD, &c, 1);
    write_prog_size(assembly);
    c = 0;
    write(FD, COMMENT, my_strlen(COMMENT));
    for (i = 0; i < (COMMENT_LENGTH + 4) - my_strlen(COMMENT); i++)
        write(FD, &c, 1);
}