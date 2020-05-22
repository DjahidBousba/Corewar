/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** linked_list2.c
*/

#include "../include/ressources.h"

list2_t *init2(unsigned char code)
{
    list2_t *list = malloc(sizeof(*list));
    object2_t *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
        exit(84);
    element->c = code;
    element->suivant = NULL;
    list->premier = element;
    list->dernier = element;
    return (list);
}

int display_lists2(list2_t *list)
{
    int i = 0; object2_t *actuel = NULL;

    if (list == NULL) {
        my_putchar('\n');
        return (0);
    }
    actuel = list->premier;
    if (actuel == NULL) {
        my_putchar('\n');
        return (0);
    }
    while (actuel != NULL) {
        my_put_nbr(actuel->c);
        my_putstr("\n");
        i++;
        actuel = actuel->suivant;
    }
    return (0);
}

void add_link_last2(list2_t *list, unsigned char code)
{
    object2_t *actuel = list->premier; object2_t *nouveau = NULL;

    while (actuel->suivant != NULL)
        actuel = actuel->suivant;
    nouveau = malloc(sizeof(*nouveau));
    if (list == NULL || nouveau == NULL)
        exit(84);
    nouveau->c = code;
    list->dernier->suivant = nouveau;
    list->dernier = nouveau;
    nouveau->suivant = NULL;
}