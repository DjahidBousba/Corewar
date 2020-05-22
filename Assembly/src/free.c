/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** free.c
*/

#include "../include/asm.h"

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_list(list_t *list)
{
    object_t *actuel = list->premier;
    object_t *tmp = NULL;

    while (actuel) {
        if (actuel->suivant) {
            tmp = actuel->suivant;
            free(actuel);
            actuel = tmp;
        }
        else {
            free(actuel);
            break;
        }
    }
    free(list);
}

void free_struct(file_t **file, int len)
{
    for (int i = 0; i < len; i++)
        free(file[i]);
    free(file);
}

void free_structure_file(asm_t *assembly)
{
    if (assembly->file[IDX]->name)
        free(assembly->file[IDX]->name);
    if (assembly->file[IDX]->file)
        free(assembly->file[IDX]->file);
    if (assembly->file[IDX]->comment)
        free(assembly->file[IDX]->comment);
    if (assembly->file[IDX]->all_file)
        free_tab(assembly->file[IDX]->all_file);
}

void free_structure_asm(asm_t *assembly)
{
    if (assembly->file)
        free_struct(assembly->file, assembly->nb_file);
}