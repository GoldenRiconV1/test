/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** args_manager.c
*/

#include "include/my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static void print_error(const char *path)
{
    my_putstr_err("my_ls: cannot access '");
    my_putstr_err(path);
    my_putstr_err("': ");
    my_putstr_err(strerror(errno));
    my_putstr_err("\n");
}

static void add_path_to_sorted_list(const char *path,
    sorted_args_t *sorted_args, flags_t *flags, int *error_status)
{
    struct stat path_stat;

    if (stat(path, &path_stat) == -1) {
        print_error(path);
        *error_status = 84;
        return;
    }
    if (S_ISDIR(path_stat.st_mode) && !flags->d_flags) {
        sorted_args->dirs.path[sorted_args->dirs.nbr_file] = my_strdup(path);
        sorted_args->dirs.nbr_file++;
    } else {
        sorted_args->files.path[sorted_args->files.nbr_file] = my_strdup(path);
        sorted_args->files.nbr_file++;
    }
}

void sort_arguments(has_file_flag_t *all_args, sorted_args_t *s_args,
    flags_t *flags, int *error_status)
{
    s_args->files.path = malloc(sizeof(char *) * (all_args->nbr_file + 1));
    s_args->dirs.path = malloc(sizeof(char *) * (all_args->nbr_file + 1));
    s_args->files.nbr_file = 0;
    s_args->dirs.nbr_file = 0;
    for (int i = 0; all_args->path[i] != NULL; i++)
        add_path_to_sorted_list(all_args->path[i], s_args, flags,
            error_status);
    s_args->files.path[s_args->files.nbr_file] = NULL;
    s_args->dirs.path[s_args->dirs.nbr_file] = NULL;
}
