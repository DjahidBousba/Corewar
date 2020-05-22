/*
** EPITECH PROJECT, 2018
** Virtual_Machine
** File description:
** convert_bin.c
*/

#include "../include/my.h"

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