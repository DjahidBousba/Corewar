/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** linked_lists.c
*/
#include "../include/my.h"

list_t *init(vm_t *vm, int j)
{
    int i = 0;
    list_t *list = malloc(sizeof(*list));
    object_t *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
        exit(84);
    element->nb = vm->champ[j]->nb;
    element->name = vm->champ[j]->name;
    element->carry = vm->champ[j]->carry;
    element->reg = vm->champ[j]->reg;
    element->pause = vm->champ[j]->pause;
    element->real = j;
    element->next = NULL;
    list->first = element;
    list->last = element;
    return (list);
}

void add_link_last(list_t *list, vm_t *vm, int j)
{
    int i = 0;
    object_t *actuel = list->first;
    object_t *nouveau = NULL;

    while (actuel->next != NULL)
        actuel = actuel->next;
    nouveau = malloc(sizeof(*nouveau));
    if (list == NULL || nouveau == NULL)
        exit(84);
    nouveau->nb = vm->champ[j]->nb;
    nouveau->name = vm->champ[j]->name;
    nouveau->carry = vm->champ[j]->carry;
    nouveau->reg = vm->champ[j]->reg;
    nouveau->pause = vm->champ[j]->pause;
    nouveau->real = j;
    list->last->next = nouveau;
    list->last = nouveau;
    nouveau->next = NULL;
}