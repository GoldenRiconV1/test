/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** free.c
*/

#include "../include/my.h"

static void free_array(char ***array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++) {
            free(array[i][0]);
            free(array[i][1]);
            free(array[i][2]);
            free(array[i][3]);
            free(array[i][4]);
            free(array[i][5]);
            free(array[i][6]);
            free(array[i]);
        }
        free(array);
    }
}

static void free_file(has_file_flag_t *has_file_flag)
{
    if (has_file_flag->path != NULL) {
        for (int i = 0; has_file_flag->path[i] != NULL; i++) {
            free(has_file_flag->path[i]);
        }
        free(has_file_flag->path);
    }
}

void my_free(char ***array, has_file_flag_t *has_file_flag)
{
    free_array(array);
    free_file(has_file_flag);
}
