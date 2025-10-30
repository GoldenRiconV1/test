/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** free.c
*/

#include "../include/my.h"

void free_array(char ***array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; j < 7; j++)
            free(array[i][j]);
        free(array[i]);
    }
    free(array);
}
