/*
** EPITECH PROJECT, 2018
** VM
** File description:
**  get_bytecode_champ.c
*/

#include "../include/my.h"

char *get_all_file(vm_t *vm, int j)
{
    int fd = open(vm->champ[j]->file_name, O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    char *file = malloc(sizeof(char) * size + 1);

    if (file == NULL)
        exit(84);
    fd = open(vm->champ[j]->file_name, O_RDONLY);
    read(fd, file, size + 1);
    return (file);
}

char *get_bytecode(vm_t *vm, int j)
{
    int name_len = PROG_NAME_LENGTH + 1;
    int comment_len = COMMENT_LENGTH + 1;
    int len = 0;
    int fd = open(vm->champ[j]->file_name, O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    char *bytecode;
    int i = 0;
    int k = 0;

    while (name_len % 4 != 0)
        name_len++;
    while (comment_len % 4 != 0)
        comment_len++;
    len = name_len + comment_len + 8;
    if ((bytecode = malloc(sizeof(char) * size - len)) == NULL)
        exit(84);
    for (i = len, k = 0; i != size; i++, k++)
        bytecode[k] = vm->champ[j]->ct[i];
    vm->champ[j]->bt_len = size - len;
    return (bytecode);
}