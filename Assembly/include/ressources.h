/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** ressources.h
*/

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
#include "../../OP/op.h"

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

typedef struct object_s object_t;
struct object_s
{
    char *string;
    object_t *suivant;
};

typedef struct list_s list_t;
struct list_s
{
    object_t *premier;
    object_t *dernier;
};

typedef struct object2_s object2_t;
struct object2_s
{
    unsigned char c;
    object2_t *suivant;
};

typedef struct list2_s list2_t;
struct list2_s
{
    object2_t *premier;
    object2_t *dernier;
};

//GNL
char *get_next_line(int fd);

//LINKED LISTS
list_t *init(char *str);
int display_lists(list_t *list);
void add_link_last(list_t *list, char *str);
list2_t *init2(unsigned char code);
int display_lists2(list2_t *list);
void add_link_last2(list2_t *list, unsigned char code);
char **my_list_in_tab(list_t *list, int len);

//CONVERT
char putchar_hexa_min(int nb);
int hexa_to_dec(char *hexa);
int nb_power(int nb, int power);
void my_put_nbr_base_min(unsigned int nb, int base);
char convert_hexa_min(int nb);
char *convert_base(unsigned int nb, int base);
char putchar_hexa_maj(int nb);
char *cut_hexa(char *hexa, int len);
void my_put_nbr_base_maj(unsigned int nb, int base);
unsigned int my_put_nbr_un(unsigned int nb);
char *convert_char_bin_to_dec(char *bin, int len);
int convert_bin(int bin);

//UTILS
char *adapt_delims(void);
char **my_str_to_word_array(char *str);
char **my_str_to_word_tab(char *str, char *delims);
char **str_to_word_tab2(char *str, char delim);
void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char *src);
int my_getnbr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_int_to_char(int nb);
char *my_memset(char *str, char mem, int len);

#endif /* !RESSOURCES_H_ */