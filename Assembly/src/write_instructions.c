/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** write_instructions.c
*/

#include "../include/asm.h"

void write_all_instruction(asm_t *assembly)
{
    object2_t *actuel = assembly->file[IDX]->instru->premier;

    if (assembly->file[IDX]->fd < 0)
        exit(84);
    if (actuel)
        actuel = actuel->suivant;
    for (; actuel; actuel = actuel->suivant)
        write(assembly->file[IDX]->fd, &actuel->c, 1);
}