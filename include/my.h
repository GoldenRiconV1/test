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
    char **put_password;
} data_t;

typedef struct parser_s {
    char *buf;
    char ***array;
    int str_len;
    int buf_idx;
} parser_t;

void free_prog(data_t *data);
void free_struct_s(parser_t *s);

void init(data_t *data, int argc, char **argv);
bool load_file_and_fill_buf(data_t *data, parser_t *s, char *filepath);
bool file_parser(data_t *data, parser_t *s, int nbr_arg);
bool get_uid_from_file(data_t *data);
bool get_gid_from_file(data_t *data);
char *strdup(const char *c);

bool parser(data_t *data);

void read_in_stdin(data_t *data);

#endif
