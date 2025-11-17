/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** include.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef enum flag_e {
    U_FLAG,
    G_FLAG,
    U_AND_G_FLAG,
    EMPTY
} flag_t;

typedef struct data_s {
    int argc;
    char **argv;
    char **command;
    int command_size;
    char *user_name;
    char *groupe_name;
    unsigned int uid;
    unsigned int gid;
    int attemps;
    flag_t flags;
} data_t;

void init(data_t *data, int argc, char **argv);

bool parser(data_t *data);
#endif
