/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_ls_core.c
*/

#include "include/my.h"
#include <sys/stat.h>

void list_directory(flags_t *flag, char *path, int *error_status)
{
    file_data_t file_data;
    char ***array = handle_basic_array(&file_data, flag, path, error_status);
    struct stat path_stat;
    char ***processed_array;

    if (array == NULL)
        return;
    stat(path, &path_stat);
    processed_array = basic_array(flag, array);
    if (flag->t_flags)
        processed_array = handle_t(processed_array,
            my_arraylen(processed_array));
    handle_flags(flag, processed_array);
    if (flag->R_flags && S_ISDIR(path_stat.st_mode))
        handle_r_upcase(flag, processed_array, path, error_status);
    free(array);
    free(processed_array);
}

static void list_files(flags_t *flag, has_file_flag_t *has_file_flag)
{
    file_data_t file_data;
    char ***array = handle_file_args(has_file_flag, &file_data);

    if (array == NULL)
        return;
    if (flag->t_flags)
        array = handle_t(array, my_arraylen(array));
    handle_flags(flag, array);
}

static void print_header(int i, sorted_args_t *s_args, flags_t *flag,
    has_file_flag_t *has_file_flag)
{
    if (has_file_flag->nbr_file > 1 || flag->R_flags) {
        if (i > 0 || s_args->files.nbr_file > 0)
            my_putchar('\n');
        mini_printf("%s:\n", s_args->dirs.path[i]);
    }
}

void my_ls(flags_t *flag, has_file_flag_t *has_file_flag,
    sorted_args_t *s_args, int *err)
{
    if (s_args->files.nbr_file > 0)
        list_files(flag, &s_args->files);
    for (int i = 0; i < s_args->dirs.nbr_file; i++) {
        print_header(i, s_args, flag, has_file_flag);
        list_directory(flag, s_args->dirs.path[i], err);
    }
}
