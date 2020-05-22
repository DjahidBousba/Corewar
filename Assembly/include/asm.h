/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** asm.h
*/

#ifndef MY_H_
#define MY_H_

#include "ressources.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include "ressources.h"

/*STRUCTURES*/
typedef struct s_file {
    char *file;
    char *name;
    char *comment;
    int bytes;
    int error;
    int fd;
    char **all_file;
    char *my_file;
    list2_t *instru;
    int bytes_instru;
}file_t;

typedef struct s_asm {
    file_t **file;
    int nb_file;
    int idx;
    int distance;
    int good_param;
    int check_name;
    int check_comment;
    int check_label;
    int nbr;
    int start;
    int error;
}asm_t;

/* MACRO */
#define IDX (assembly->idx)
#define NAME (assembly->file[IDX]->name)
#define COMMENT (assembly->file[IDX]->comment)
#define FD (assembly->file[IDX]->fd)
#define VAR int j, int i

void parse_delims(char *str, char *delims);

//COREWAR
void corewar(int ac, char **av, asm_t *assembly);

//INIT
void init_struct(asm_t *assembly);
void init_file_struct(asm_t *assembly, char **av);

//HELP
void my_help(char **av);

//ERROR HANDLING
int check_error(char **line);
void error_handling(int ac, char **av, asm_t *assembly);

//CREATE_FILES
void create_file(char **av, asm_t *assembly);
char *my_file_name(char *av);
char *parse_result(char *str, asm_t *assembly);

/*PARAMETERS*/
void parse_indirect(asm_t *assembly, char **line, int from, int j, int i);
void parse_direct(asm_t *assembly, char **line, int from, int j, int i);
void parse_register(asm_t *assembly, char **line, int from, int j, int i);
int check_number(char *str, int i);
int recup_nb_reg(char *str);
int check_in_str(char *str, int i);
int compare_label_chars(char *str, int i);
int check_nb_params(asm_t *assembly, char **line);
void check_params(asm_t *assembly, char **line, int j);

/* WRITE IN FILE*/
void write_prog_size(asm_t *assembly);
void write_all_instruction(asm_t *assembly);
void write_header(asm_t *assembly);

/*INSTRUCTION*/
void write_hexa_prog_size(char *tmp, asm_t *assembly, char *final_hexa);
void add_hexa(char *tmp, asm_t *assembly, char *final_hexa);
int check_where_instru(char *line, int i, int j, asm_t *assembly);
void put_and_check_instru_in_tab(asm_t *assembly, char **all_file, int i);
void check_instructions(asm_t *assembly, char **line);
char *found_instru(char **line, asm_t *assembly);
void parse_instructions(asm_t *assembly, char **all_file);
int check_valid_instru(char *line);

/* STOCK */
void stock_register(asm_t *assembly, char *param);
void stock_direct(asm_t *assembly, char *param, int nbr);
void stock_indirect(asm_t *assembly, char *param, int nbr);
void stock_two_bytes(asm_t *assembly, int value);
void stock_four_bytes(asm_t *assembly, int value);
int stock_number_indirect(char *param);
int stock_number_direct(char *param);

/* HEADER */
void check_error_comment(asm_t *assembly, char **all_file, int j);
void check_error_name(asm_t *assembly, char **all_file, int j);
void parse_header(asm_t *assembly, char **all_file);
void parse_file(asm_t *assembly, char *file, char **av);
void my_magic_number(asm_t *assembly);
char *check_unknown_char(char *str);

/* REGISTER */
int check_register(char *str);
int check_direct(char *str);
int check_indirect(char *str);

/* LABEL */
void count_label_distance(char *label, asm_t *assembly, int i);
void check_double_label(asm_t *assembly, char **line);
void check_valid_label(char c, asm_t *assembly);
char *found_label(char *param, int check);
int calculate_distance_label(asm_t *assembly, char *param, int check);

//BYTES
int check_bytes_params(char *instru, char **line_tmp);
void calc_coding_bytes(char *instru, char **line, asm_t *assembly);
int check_nbr_bytes(char **line, char *the_line, int nbr);
int coding_bytes(char *instru, asm_t *assembly, int value, char **line);

//FREE
void free_tab(char **tab);
void free_struct(file_t **file, int len);
void free_list(list_t *list);
void free_structure_asm(asm_t *assembly);
void free_structure_file(asm_t *assembly);

#endif