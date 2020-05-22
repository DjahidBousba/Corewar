/*
** EPITECH PROJECT, 2018
** VM
** File description:
** get_info_champ.c
*/

#include "../include/my.h"

void find_champ(char **av, vm_t *vm)
{
    int i = 0;
    char *rev;

    vm->nb_champ = 0;
    for (; av[i] != NULL; i++) {
        rev = my_revstr(av[i]);
        if (my_strncmp(rev, "roc.", 4) == 0)
            vm->nb_champ++;
        my_revstr(av[i]);
    }
    if (vm->nb_champ <= 1) {
        my_putstr("Not enough champions\n");
        free(vm);
        exit(1);
    }
    if (vm->nb_champ > 4) {
        my_putstr("Too many champions\n");
        free(vm);
        exit(1);
    }
}

int check_other_nb(int j, vm_t *vm)
{
    int i = 0;

    while (i != vm->nb_champ) {
        if (j == vm->champ[i]->nb)
            return (1);
        i++;
    }
    return (0);
}

void set_nb_champ(vm_t *vm, int j, int nb)
{
    if (nb < 1 || nb > 4) {
        my_putstr("-n argument is invalid.\n");
        my_putstr("Enter a number between 1 and 4.\n");
        free_error(vm);
        exit(1);
    }
    if (check_other_nb(nb, vm) == 1) {
        my_putstr("Double definition of prog_number\n");
        free_error(vm);
        exit(1);
    }
    vm->champ[j]->nb = nb;
}

void set_adress_champ(vm_t *vm, int j, int nb)
{
    vm->champ[j]->adress = nb;
}

char *get_champ_name(vm_t *vm, int i)
{
    int j = 4;
    int k = 0;
    char *name;

    for (j = 4; vm->champ[i]->header[j] != '\0'; j++);
    if ((name = malloc(sizeof(char) * j + 1)) == NULL)
        exit(84);
    for (j = 4, k = 0; vm->champ[i]->header[j] != '\0'; j++, k++)
        name[k] = vm->champ[i]->header[j];
    name[k] = '\0';
    i++;
    return (name);
}