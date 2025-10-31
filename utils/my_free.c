/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** free.c
*/

#include "../include/my.h"

void free_array(char ***array, has_file_flag_t *has_file_flag)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i][0]);
        free(array[i][1]);
        free(array[i][4]);
        free(array[i][5]);
        free(array[i][6]);
        free(array[i]);
    }
    free(array);
}
