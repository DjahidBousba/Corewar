/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** parse_params.c
*/

#include "../include/asm.h"

int check_nb_params(asm_t *assembly, char **line)
{
    int i = 0; int tmp = 0;

    for (; line[i]; i++);
    tmp = i;
    assembly->start = 1;
    for (int j = 0; line[0][j]; j += 1) {
        if (line[0][j] == LABEL_CHAR) {
            i = tmp - 1;
            assembly->start = 2;
        }
    }
    return (i - 1);
}

void parse_register(asm_t *assembly, char **line, int from, VAR)
{
    if ((op_tab[j].type[i] & T_REG) == T_REG) {
        if (check_register(line[from]) == 1) {
            assembly->good_param += 1;
            assembly->nbr = check_nbr_bytes(line, line[from], 1);
            assembly->file[IDX]->bytes += assembly->nbr;
            stock_register(assembly, line[from]);
        }
    }
}

void parse_direct(asm_t *assembly, char **line, int from, VAR)
{
    if ((op_tab[j].type[i] & T_DIR) == T_DIR) {
        if (check_direct(line[from]) == 1) {
            assembly->good_param += 1;
            assembly->nbr = check_nbr_bytes(line, line[from], DIR_SIZE);
            assembly->file[IDX]->bytes += assembly->nbr;
            stock_direct(assembly, line[from], assembly->nbr);
        }
    }
}

void parse_indirect(asm_t *assembly, char **line, int from, VAR)
{
    if ((op_tab[j].type[i] & T_IND) == T_IND) {
        if (check_indirect(line[from]) == 1) {
            assembly->good_param += 1;
            assembly->nbr = check_nbr_bytes(line, line[from], IND_SIZE);
            assembly->file[IDX]->bytes += assembly->nbr;
            stock_indirect(assembly, line[from], assembly->nbr);
        }
    }
}

void check_params(asm_t *assembly, char **line, int j)
{
    int nb = check_nb_params(assembly, line);
    int from = assembly->start;

    (op_tab[j].nbr_args != nb) ? assembly->file[IDX]->error = 84 : 0;
    for (int i = 0; i < nb; i += 1, from += 1) {
        parse_register(assembly, line, from, j, i);
        parse_direct(assembly, line, from, j, i);
        parse_indirect(assembly, line, from, j, i);
        (assembly->good_param == 0) ? assembly->file[IDX]->error = 84 : 0;
        assembly->good_param = 0;
    }
    assembly->nbr = 0;
}