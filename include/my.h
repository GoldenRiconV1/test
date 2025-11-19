/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>

typedef enum flag_e {
    H_FLAG,
    U_FLAG,
    G_FLAG,
    U_AND_G_FLAG,
    EMPTY
} flag_t;

typedef struct data_s {
    int argc;
    char **argv;
    char **command;
    char *user_name;
    char *groupe_name;
    unsigned int my_uid;
    unsigned int my_gid;
    int uid;
    int gid;
    int attemps;
    flag_t flags;
} data_t;

void init(data_t *data, int argc, char **argv);
void free_prog(data_t *data);
bool fill_buffer_from_file(const char *filepath, char *buf, int size);
bool get_uid_from_file(data_t *data);
bool get_gid_from_file(data_t *data);

bool parser(data_t *data);
#endif
