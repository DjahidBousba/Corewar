/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** find_next_pc.c
*/

#include "../include/my.h"

int find_nxt_pc(int coding_byte)
{
    char *bin = my_convert_nb_base(coding_byte, 2);
    int i = 0;
    int size = 0;

    if (my_strlen(bin) == 7 && bin[i] == '1') {
        size += 1;
        i++;
    }
    while (i != my_strlen(bin)) {
        if (bin[i] == '0' && bin[i + 1] == '1')
            size += 1;
        if (bin[i] == '1' && bin[i + 1] == '1')
            size += 2;
        if (bin[i] == '1' && bin[i + 1] == '0')
            size += 2;
        i += 2;
    }
    free(bin);
    return (size);
}