/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_file_args.c
*/
#include "../include/my.h"

static void get_single_file_info(const char *path, file_data_t *file_data)
{
    struct stat file_stats;

    if (stat(path, &file_stats) == -1) {
        put_default_data(file_data, (char *)path);
        return;
    }
    file_data->name = my_strdup(path);
    put_type_perm_file_data(file_data, &file_stats);
    assign_stats(file_data, &file_stats);
}

char ***handle_file_args(has_file_flag_t *has_file_flag, file_data_t *file_data)
{
    char ***array = malloc(sizeof(char **) * (has_file_flag->nbr_file + 1));
    int file_idx = 0;

    if (!array)
        return NULL;
    for (int i = 0; has_file_flag->path[i] != NULL; i++) {
        get_single_file_info(has_file_flag->path[i], file_data);
        array[file_idx] = create_l_array(file_data);
        file_idx++;
    }
    array[file_idx] = NULL;
    return array;
}
