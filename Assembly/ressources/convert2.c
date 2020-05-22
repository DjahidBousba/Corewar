/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** convert2.c
*/

#include "../include/asm.h"
#include "../include/ressources.h"

int convert_bin(int bin)
{
    int decimal = 0;
    int j = 1;
    int r = 0;

    while (bin != 0) {
        r = bin % 10;
        bin = (bin / 10);
        decimal = decimal + (r * j);
        j = (j * 2);
    }
    return (decimal);
}

char *convert_char_bin_to_dec(char *bin, int len)
{
    char *pos = malloc(sizeof(char) * (len + 1));
    int position = 0;
    int decimal = 0;

    position = my_getnbr(bin);
    decimal = convert_bin(position);
    pos = my_int_to_char(decimal);
    return (pos);
}

char *cut_hexa(char *hexa, int len)
{
    char *result = malloc(sizeof(char) * (len + 1));
    int j = 0; int i = 0;

    hexa = my_revstr(hexa);
    for (; i < len; i++, j++)
        result[j] = hexa[i];
    result[j] = '\0';
    result = my_revstr(result);
    return (result);
}