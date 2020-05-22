/*
** EPITECH PROJECT, 2018
** Visual Studio Live Share (Workspace)
** File description:
** linked_lists.c
*/

#include "../include/ressources.h"

list_t *init(char *str)
{
    list_t *list = malloc(sizeof(*list));
    object_t *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
        exit(84);
    element->string = str;
    element->suivant = NULL;
    list->premier = element;
    list->dernier = element;
    return (list);
}

int display_lists(list_t *list)
{
    int i = 0;
    object_t *actuel = NULL;

    if (list == NULL)
    {
        my_putchar('\n');
        return (0);
    }
    actuel = list->premier;
    if (actuel == NULL)
    {
        my_putchar('\n');
        return (0);
    }
    while (actuel != NULL)
    {
        my_putstr(actuel->string);
        my_putstr("\n");
        i++;
        actuel = actuel->suivant;
    }
    return (0);
}

void add_link_last(list_t *list, char *str)
{
    object_t *actuel = list->premier;
    object_t *nouveau;

    while (actuel->suivant != NULL)
        actuel = actuel->suivant;
    nouveau = malloc(sizeof(*nouveau));
    if (list == NULL || nouveau == NULL)
        exit(84);
    nouveau->string = str;
    list->dernier->suivant = nouveau;
    list->dernier = nouveau;
    nouveau->suivant = NULL;
}