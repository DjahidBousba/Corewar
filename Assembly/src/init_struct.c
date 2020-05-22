/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init_struct.c
*/

#include "../include/asm.h"

void init_struct(asm_t *assembly)
{
    assembly->start = 1;
    assembly->error = 0;
    assembly->idx = 0;
    assembly->good_param = 0;
    assembly->nbr = 0;
    assembly->check_name = 0;
    assembly->check_comment = 0;
    assembly->distance = 0;
    assembly->check_label = 0;
}

void init_each_file(asm_t *assembly)
{
    for (int i = 0; i < assembly->nb_file; i++) {
        assembly->file[i] = malloc(sizeof(file_t));
        assembly->file[i]->name = NULL;
        assembly->file[i]->comment = NULL;
        assembly->file[i]->bytes = 0;
        assembly->file[i]->my_file = NULL;
        assembly->file[i]->all_file = NULL;
        assembly->file[i]->instru = NULL;
        assembly->file[i]->instru = init2(0);
        assembly->file[i]->error = 0;
        assembly->file[i]->bytes_instru = 0;
    }
}

void init_file_struct(asm_t *assembly, char **av)
{
    for (int i = 1; av[i]; i++)
        assembly->nb_file++;
    assembly->file = malloc(sizeof(file_t *) * assembly->nb_file);
    init_each_file(assembly);
}