/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** create_result_array.c
*/

#include "../include/my.h"

char ***create_result_array(char ***array)
{
    int s_index = 0;
    char ***size_array;
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][6] != NULL && array[i][6][0] == '.')
            s_index++;
    }
    size_array = malloc(sizeof(char **) * (dir_len() - s_index + 1));
    if (size_array == NULL)
        return NULL;
    for (int i = 0; i < dir_len(); i++) {
        if (array[i][6] != NULL && array[i][6][0] != '.') {
            size_array[j] = array[i];
            j++;
        }
    }
    size_array[j] = NULL;
    return size_array;
}