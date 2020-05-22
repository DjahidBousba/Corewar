/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** stock.c
*/

#include "../include/asm.h"

void stock_register(asm_t *assembly, char *param)
{
    int i = 1; char *result = malloc(sizeof(char) * my_strlen(param));
    int j = 0;

    for (; param[i]; j++, i++)
        result[j] = param[i];
    result[j] = '\0';
    add_link_last2(assembly->file[IDX]->instru, my_getnbr(result));
}

void stock_four_bytes(asm_t *assembly, int value)
{
    int i = 0; int nbr = 0; int len = 0;
    char *byte = NULL; char *hexa = NULL; char *final_hexa = NULL;
    char *tmp = malloc(sizeof(char) * 3);

    hexa = convert_base(value, 16);
    len = my_strlen(hexa);
    if (len < (DIR_SIZE * 2)) {
        for (i = 0; len < (DIR_SIZE * 2); len++, i++);
        byte = malloc(sizeof(char) * (i + 1));
        len = my_strlen(hexa);
        for (; len < (DIR_SIZE * 2); len++, nbr++)
            byte[nbr] = '0';
        byte[nbr] = '\0';
        final_hexa = my_strcat(byte, hexa);
    }
    else if (len > (DIR_SIZE * 2))
        final_hexa = cut_hexa(hexa, (DIR_SIZE * 2));
    else
        final_hexa = hexa;
    add_hexa(tmp, assembly, final_hexa);
}

void stock_direct(asm_t *assembly, char *param, int nbr)
{
    int i = 0; int nb = 0; int value = 0;

    for (; param[i]; i++)
        if (param[i] == LABEL_CHAR)
            break;
    if (param[i] == '\0') {
        value = stock_number_direct(param);
        (nbr == 2) ? stock_two_bytes(assembly, value) : 0;
        (nbr == DIR_SIZE) ? stock_four_bytes(assembly, value) : 0;
    }
    else {
        nb = calculate_distance_label(assembly, param, 2);
        assembly->distance = 0;
        if (nbr == 2)
            stock_two_bytes(assembly, nb);
        else
            stock_four_bytes(assembly, nb);
    }
}

void stock_indirect(asm_t *assembly, char *param, int nbr)
{
    int i = 0; int nb = 0; int value = 0;

    for (; param[i]; i++)
        if (param[i] == LABEL_CHAR)
            break;
    if (param[i] == '\0') {
        value = stock_number_indirect(param);
        (nbr == 2) ? stock_two_bytes(assembly, value) : 0;
        (nbr == DIR_SIZE) ? stock_four_bytes(assembly, value) : 0;
    }
    else {
        nb = calculate_distance_label(assembly, param, 1);
        assembly->distance = 0;
        if (nbr == 2)
            stock_two_bytes(assembly, nb);
        else
            stock_four_bytes(assembly, nb);
    }
}

void stock_two_bytes(asm_t *assembly, int value)
{
    int i = 0; int nbr = 0; int len = 0;
    char *byte = NULL; char *hexa = NULL; char *final_hexa = NULL;
    char *tmp = malloc(sizeof(char) * 3);

    hexa = convert_base(value, 16);
    len = my_strlen(hexa);
    if (len < (IND_SIZE * 2)) {
        for (i = 0; len < (IND_SIZE * 2); len++, i++);
        byte = malloc(sizeof(char) * (i + 1));
        len = my_strlen(hexa);
        for (; len < (IND_SIZE * 2); len++, nbr++)
            byte[nbr] = '0';
        byte[nbr] = '\0';
        final_hexa = my_strcat(byte, hexa);
    }
    else if (len > (IND_SIZE * 2))
        final_hexa = cut_hexa(hexa, (IND_SIZE * 2));
    else
        final_hexa = hexa;
    add_hexa(tmp, assembly, final_hexa);
}