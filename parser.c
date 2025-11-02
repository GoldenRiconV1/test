/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** parser.c
*/

#include "include/my.h"
// #include <errno.h>

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

static int count_file_args(int argc, char **argv)
{
    int count = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            count++;
    }
    return count;
}

static void file_exists(const char *filepath, has_file_flag_t *has_flag)
{
    struct stat buffer;

    if (stat(filepath, &buffer) == 0) {
        printf("'%s' existe\n", filepath);
        has_flag->path = malloc(sizeof(char) * my_strlen(filepath));
        my_strcpy(has_flag->path[0], filepath);
        has_flag->nbr_file += 1;
    } else
        mini_printf("erreur file\n");
}

static void free_path_if(has_file_flag_t *has_file_flag, int path_found)
{
    if (path_found && has_file_flag->path != NULL)
        free(has_file_flag->path);
}

void parser(int argc, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag)
{
    int file_arg_count = count_file_args(argc, argv);
    int current_file = 0;

    has_file_flag->nbr_file = file_arg_count;
    has_file_flag->has_file = (file_arg_count > 0); //chelou
    has_file_flag->path = malloc(sizeof(char *) * (file_arg_count + 1));
    if (!has_file_flag->path)
        return;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            count_flags(i, argv, flag, has_file_flag);
        } else {
            has_file_flag->path[current_file] = my_strdup(argv[i]);
            current_file++;
        }
    }
    has_file_flag->path[current_file] = NULL;
    if (file_arg_count == 0) {
        free(has_file_flag->path);
        has_file_flag->path = malloc(sizeof(char *) * 2);
        has_file_flag->path[0] = my_strdup(".");
        has_file_flag->path[1] = NULL;
    }
}
