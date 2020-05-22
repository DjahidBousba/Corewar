/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar.c
*/

#include "../include/asm.h"

void corewar(int ac, char **av, asm_t *assembly)
{
    init_file_struct(assembly, av);
    error_handling(ac, av, assembly);
    for (int i = 1; av[i]; i += 1) {
        IDX = (i - 1);
        if (assembly->file[IDX]->error == 0)
            parse_file(assembly, av[i], av);
        else
            assembly->error = assembly->file[IDX]->error;
        free_structure_file(assembly);
    }
    free_structure_asm(assembly);
}