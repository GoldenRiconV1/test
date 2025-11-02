/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** R.c
*/

#include "../include/my.h"

static void my_ls_recursive(flags_t *flag, char *path, int *error_status)
{
    file_data_t file_data;
    char ***array;
    char ***processed_array;

    mini_printf("\n%s:\n", path);
    array = handle_basic_array(&file_data, flag, path, error_status);
    if (array == NULL)
        return;
    processed_array = basic_array(flag, array);
    if (flag->t_flags)
        processed_array = handle_t(processed_array,
            my_arraylen(processed_array));
    handle_flags(flag, processed_array);
    handle_r_upcase(flag, processed_array, path, error_status);
}

static char *if_has_slash(char *n_path, const char *base_path)
{
    if (base_path[my_strlen(base_path) - 1] != '/')
        my_strcat(n_path, "/");
    return n_path;
}

void handle_r_upcase(flags_t *flag, char ***array, const char *base_path,
    int *error_status)
{
    char *n_path;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][0][0] == 'd' && my_strcmp(array[i][6], ".") != 0
            && my_strcmp(array[i][6], "..") != 0) {
            n_path = malloc(my_strlen(base_path) + my_strlen(array[i][6]) + 2);
            if (n_path == NULL)
                return;
            my_strcpy(n_path, base_path);
            n_path = if_has_slash(n_path, base_path);
            my_strcat(n_path, array[i][6]);
            mini_printf("\n%s:\n", n_path);
            list_directory(flag, n_path, error_status);
            free(n_path);
        }
    }
}
