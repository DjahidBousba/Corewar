/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** test
*/

#ifndef MY_H_
#define MY_H_

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
#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include "../../OP/op.h"

/* STRUCT GRAPHIQUE */
typedef struct ncurse_s {
    int x;
    int y;
    int x_max;
    int y_max;
    int nbr_champ;
    int nbr_of_case;
    WINDOW **win;
    WINDOW *deco;
} ncurse_t;

typedef struct object_s object_t;
struct object_s
{
    int nb;
    char *name;
    int carry;
    int *reg;
    int pause;
    int real;
    object_t *next;
};

typedef struct list_s list_t;
struct list_s
{
    object_t *first;
    object_t *last;
};


typedef struct s_champions
{
    int nb;
    int adress;
    char *header;
    char *name;
    char *file_name;
    char *bytecode;
    char *ct;
    int *reg;
    int carry;
    int pc;
    int bt_len;
    int pause;
    int live;
    int dead;
    int real;
    int proc;
}champions_t;

typedef struct s_vm
{
    champions_t **champ;
    ncurse_t *ncurse;
    list_t *champ_fork;
    int nb_champ;
    int cycle_nb;
    int nbr_live;
    int nbr_fork;
    int cycle;
    int check;
    char *arena;
    char *color;
    int cycle_to_die;
    int last_live;
    int g;
}vm_t;

typedef struct s_param
{
    int param1;
    int param2;
    int param3;
    int i;
}param_t;

//ERROR HEADER
void error_header(vm_t *vm);
int check_magic_number(vm_t *vm, int j);

//INSTRUCTION
void live(vm_t *vm, int j);
void ld(vm_t *vm, int j);
void st(vm_t *vm, int j);
void add(vm_t *vm, int j);
void sub(vm_t *vm, int j);
void and(vm_t *vm, int j);
void or(vm_t *vm, int j);
void xor(vm_t *vm, int j);
void zjmp(vm_t *vm, int j);
void ldi(vm_t *vm, int j);
void sti(vm_t *vm, int j);
void forke(vm_t *vm, int j);
void lld(vm_t *vm, int j);
void lldi(vm_t *vm, int j);
void lfork(vm_t *vm, int j);
void aff(vm_t *vm, int j);

//CONVERT_INT_IN_BYTES
void convert_int_in_4bytes(vm_t *vm, int i, int reg, int j);
int convert_4bytes_in_int(vm_t *vm, int i);
int convert_2bytes_in_int(vm_t *vm, int i);

//ARENA
void my_create_arena(vm_t *vm);
void disp_space(int k, int i);
void disp_arena(vm_t *vm);
void put_champion(vm_t *vm);

//LDI_AND_LLDI
void ldi(vm_t *vm, int j);
void lldi(vm_t *vm, int j);
int check_param_ldi(vm_t *vm, int coding_byte, int j, param_t *param);
int second_param_ldi(vm_t *vm, int j, char *bin, int i, param_t *param);
int first_param_ldi(vm_t *vm, int j, char *bin, param_t *param);

//STI
void sti(vm_t *vm, int j);
int check_param_sti(vm_t *vm, int j, param_t *param, int coding_byte);
int last_param_sti(vm_t *vm, int j, char *bin, int i, param_t *param);
int second_param_sti(vm_t *vm, int j, char *bin, param_t *param);

//LD_AND_LLD
int check_param_ld(vm_t *vm, int coding_byte, int j, param_t *param);
void ld(vm_t *vm, int j);
void lld(vm_t *vm, int j);

//LIVE
int find_champ_alive(vm_t *vm, int pc);
void live(vm_t *vm, int j);

//AND
int first_param(vm_t *vm, int j, param_t *param, char *bin);
int check_param_bin(vm_t *vm, int j, param_t *param, int coding_byte);
int and_operation(param_t *param);
void and(vm_t *vm, int j);

//ST
void st(vm_t *vm, int j);
int check_param_st(vm_t *vm, int coding_byte, int j, param_t *param);
int second_param_st(vm_t *vm, int j, char *bin, param_t *param);

//OR
char *or_loop(char *p1, char *p2, char *result, int bigger);

//ARGUMENT
char *get_champ_name(vm_t *vm, int i);
void set_name_and_file(char *file, vm_t *vm, int j);
void find_champ(char **av, vm_t *vm);
int check_other_nb(int j, vm_t *vm);
void set_adress_champ(vm_t *vm, int j, int nb);
void set_nb_champ(vm_t *vm, int j, int nb);
int parse_argument(char **av, vm_t *vm);
char *get_all_file(vm_t *vm, int j);
char *get_bytecode(vm_t *vm, int j);
int find_nxt_pc(int coding_byte);

//FREE
void free_all(vm_t *vm);
void free_error(vm_t *vm);

//UTILS
int get_lower_champ(vm_t *vm, int opt);
int convert_bin(int bin);
int my_power(int nb, int power);
int get_nb_str(char *path, char sep);
char **my_str_to_word_tab(char *str, char sep);
void free_tab(char **room);
char *my_read_function(char *file);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
int my_getnbr(char *str);
char *my_convert_nb_base(int nb, int base);
char *my_put_nb_base(unsigned int nb, int base);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);
char *convert_base(unsigned int nb, int base);

/* GRAPHIQUE */
void create_vm_window(ncurse_t *ncurse);
void set_mem(vm_t *vm);
void init_ncurse_struct(vm_t *vm);
void stock_shell_infos(ncurse_t *ncurse);
void information(vm_t *vm);
void draw_champ(int x, int y, WINDOW *deco);
void print_map1(vm_t *vm, int tmp_y);
void print_map2(vm_t *vm, int tmp_y);
void print_map3(vm_t *vm);
void menu(void);
void letter_c(void);
void letter_o(void);
void letter_r(void);
void letter_e(void);
void letter_w(void);
void letter_a(void);
void letter_r2(void);
void all_dragon(void);
void disp_all_name(void);
#endif
