/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** bytes.c
*/

#include "../include/asm.h"

int check_nbr_bytes(char **line, char *the_line, int nbr)
{
    char *instru = NULL; int tmp = 0;

    if (nbr == 1)
        return (nbr);
    for (int i = 0; line[i]; i++)
        for (int j = 0; op_tab[j].mnemonique != 0; j += 1)
            (my_strcmp(line[i], op_tab[j].mnemonique) == 0) \
            ? (instru = line[i], tmp = i) : 0;
    if (my_strcmp(instru, "fork") == 0 || my_strcmp(instru, "lfork") == 0)
        nbr = 2;
    (my_strcmp(instru, "zjmp") == 0) ? nbr = 2 : 0;
    if ((my_strcmp(instru, "ldi") == 0 || my_strcmp(instru, "lldi") == 0) &&
    (my_strcmp(the_line, line[tmp + 1]) == 0 ||
    my_strcmp(the_line, line[tmp + 2]) == 0))
        nbr = 2;
    if (my_strcmp(instru, "sti") == 0 && (my_strcmp(line[tmp + 2], the_line)
    == 0 || my_strcmp(line[tmp + 3], the_line) == 0))
        nbr = 2;
    return (nbr);
}

void calc_coding_bytes(char *instru, char **line, asm_t *assembly)
{
    int i = 0; int nbr = 0; char *dec = NULL;
    char *bin = malloc(sizeof(char) * ((MAX_ARGS_NUMBER * 2) + 1));

    for (; line[i]; i++)
        if (my_strcmp(line[i], instru) == 0)
            break;
    for (i++; line[i]; i++, nbr++) {
        (check_direct(line[i]) == 1) ? \
        (bin[nbr] = '1', nbr++, bin[nbr] = '0') : 0;
        (check_indirect(line[i]) == 1) ? \
        (bin[nbr] = '1', nbr++, bin[nbr] = '1') : 0;
        (check_register(line[i]) == 1) ? \
        (bin[nbr] = '0', nbr++, bin[nbr] = '1') : 0;
    }
    for (; nbr < (MAX_ARGS_NUMBER * 2); nbr++)
        bin[nbr] = '0';
    bin[nbr] = '\0';
    dec = convert_char_bin_to_dec(bin, my_strlen(bin));
    add_link_last2(assembly->file[IDX]->instru, my_getnbr(dec));
}

int coding_bytes(char *instru, asm_t *assembly, int value, char **line)
{
    int i = 2;

    for (int j = 0; op_tab[j].mnemonique; j++)
        if (value != -1 && my_strcmp(op_tab[j].mnemonique, instru) == 0)
            add_link_last2(assembly->file[IDX]->instru, op_tab[j].code);
    (my_strcmp(instru, "zjmp") == 0) ? i = 1 : 0;
    (my_strcmp(instru, "live") == 0) ? i = 1 : 0;
    (my_strcmp(instru, "fork") == 0) ? i = 1 : 0;
    (my_strcmp(instru, "lfork") == 0) ? i = 1 : 0;
    if (value != -1)
        assembly->file[IDX]->bytes += i;
    if (value != -1 && i == 2)
        calc_coding_bytes(instru, line, assembly);
    return (i);
}