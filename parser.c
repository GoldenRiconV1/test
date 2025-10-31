/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** parser.c
*/

#include "include/my.h"
// #include <errno.h>

void flags_asigment(flags_t *flag, has_file_flag_t *has_file_flag)
{
    flag->a_flags = 0;
    flag->l_flags = 0;
    flag->R_flags = 0;
    flag->d_flags = 0;
    flag->t_flags = 0;
    has_file_flag->has_flags = 0;
    has_file_flag->has_file = 0;
    has_file_flag->path = NULL;
}

static void has_flag(flags_t *flag, has_file_flag_t *has_file_flag)
{
    if (flag->a_flags == 1 || flag->l_flags == 1 || flag->R_flags == 1
        || flag->d_flags == 1 || flag->t_flags == 1)
        has_file_flag->has_flags = 1;
}

static void count_flags(int i, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag)
{
    for (int j = 1; j < my_strlen(argv[i]); j++) {
        if (argv[i][j] == 'a')
            flag->a_flags = 1;
        if (argv[i][j] == 'l')
            flag->l_flags = 1;
        if (argv[i][j] == 'R')
            flag->R_flags = 1;
        if (argv[i][j] == 'd')
            flag->d_flags = 1;
        if (argv[i][j] == 't')
            flag->t_flags = 1;
    }
    has_flag(flag, has_file_flag);
}

static void file_exists(const char *filepath, has_file_flag_t *has_flag)
{
    struct stat buffer;

    if (stat(filepath, &buffer) == 0) {
        printf("'%s' existe\n", filepath);
        has_flag->path = malloc(sizeof(char) * my_strlen(filepath));
        my_strcpy(has_flag->path, filepath);
        has_flag->nbr_file += 1;
    } else
        mini_printf("erreur file\n");
}

void parser(int argc, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag)
{
    int path_found = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            count_flags(i, argv, flag, has_file_flag);
        } else {
            if (path_found && has_file_flag->path != NULL)
                free(has_file_flag->path);
            has_file_flag->path = my_strdup(argv[i]);
            has_file_flag->has_file = 1;
            path_found = 1;
        }
    }
    if (!path_found)
        has_file_flag->path = my_strdup(".");
}
