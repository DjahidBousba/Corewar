/*
** EPITECH PROJECT, 2018
** tkt
** File description:
** read_file.c
*/

#include "../include/my.h"

char *my_read_function(char *file)
{
    struct stat st;
    char *buffer;
    int fd = open(file, O_RDONLY);
    int val;

    if (fd < 0)
        exit(84);
    if (stat(file, &st) < 0)
        exit(84);
    buffer = malloc(st.st_size + 1);
    if (buffer == NULL)
        exit(84);
    val = read(fd, buffer, st.st_size);
    if (val < 0)
        exit(84);
    buffer[val] = '\0';
    return (buffer);
}
