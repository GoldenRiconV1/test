/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** free_memory.c
*/

#include "../include/my.h"

void free_array_content(char ***array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; j < 7; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

static void sorted_args_is_null(sorted_args_t *sorted_args)
{
    if (sorted_args->files.path != NULL) {
        for (int i = 0; sorted_args->files.path[i] != NULL; i++)
            free(sorted_args->files.path[i]);
        free(sorted_args->files.path);
    }
    if (sorted_args->dirs.path != NULL) {
        for (int i = 0; sorted_args->dirs.path[i] != NULL; i++)
            free(sorted_args->dirs.path[i]);
        free(sorted_args->dirs.path);
    }
}

void free_program_data(has_file_flag_t *all_args, sorted_args_t *sorted_args)
{
    if (all_args != NULL && all_args->path != NULL) {
        for (int i = 0; all_args->path[i] != NULL; i++) {
            free(all_args->path[i]);
        }
        free(all_args->path);
    }
    if (sorted_args != NULL)
        sorted_args_is_null(sorted_args);
}
