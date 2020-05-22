/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** check_magic_number.c
*/

#include "../include/my.h"

int nb_power(int nb, int power)
{
    int i = 1;
    int nw = nb;

    if (power == 0)
        return (1);
    while (i != power) {
        nw = nw * nb;
        i++;
    }
    return (nw);
}

int hexa_to_dec(char *hexa)
{
    int i = 0;
    int dec = 0;
    int len = my_strlen(hexa);

    while (hexa[i] != '\0') {
        if (hexa[i] - 48 < 10)
            dec = (hexa[i] - 48) * nb_power(16, len - 1) + dec;
        if (hexa[i] - 48 > 10)
            dec = (hexa[i] - 87) * nb_power(16, len - 1) + dec;
        i++;
        len--;
    }
    return (dec);
}

void wrong_magic_number(char *tmp_hexa, char *magic, char *true_magic)
{
    int k = 0;
    int i = 0;
    int j = 0;

    (magic[0] != 0) ? j++ : 0;
    for (i = 0; k < 2; tmp_hexa[i] = true_magic[k], i++, k++);
    if (hexa_to_dec(tmp_hexa) != magic[1] &&
    (hexa_to_dec(tmp_hexa) - 256) != magic[1])
        j++;
    for (i = 0; k < 4; tmp_hexa[i] = true_magic[k], i++, k++);
    if (hexa_to_dec(tmp_hexa) != magic[1] &&
    (hexa_to_dec(tmp_hexa) - 256) != magic[2])
        j++;
    for (i = 0; k < 6; tmp_hexa[i] = true_magic[k], i++, k++);
    if (hexa_to_dec(tmp_hexa) != magic[1] &&
    (hexa_to_dec(tmp_hexa) - 256) != magic[3])
        j++;
    if (j != 0) {
        my_putstr("Wrong magic number\n");
        exit(1);
    }
}

int check_magic_number(vm_t *vm, int j)
{
    char *magic = malloc(sizeof(char) * 5);
    char *true_magic = NULL;
    char *tmp_hexa = malloc(sizeof(char) * 3);

    if (!magic || !tmp_hexa)
        exit(84);
    magic[0] = vm->champ[j]->header[0];
    magic[1] = vm->champ[j]->header[1];
    magic[2] = vm->champ[j]->header[2];
    magic[3] = vm->champ[j]->header[3];
    tmp_hexa[2] = '\0';
    magic[4]  = '\0';
    true_magic = convert_base(COREWAR_EXEC_MAGIC, 16);
    wrong_magic_number(tmp_hexa, magic, true_magic);
    free(magic);
    free(true_magic);
    return (4);
}