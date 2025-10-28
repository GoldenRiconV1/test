/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_ls.c
*/

#include "../include/my.h"

static char **create_result_array(char **array)
{
    int s_index = 0;
    char **size_array;
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][0] == '.')
            s_index++;
    }
    size_array = malloc(sizeof(char *) * (my_arraylen(array) - s_index + 1));
    if (size_array == NULL)
        return NULL;
    for (int i = 0; i < my_arraylen(array); i++) {
        if (array[i][0] != '.') {
            size_array[j] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
            my_strcpy(size_array[j], array[i]);
            j++;
        }
    }
    size_array[j] = NULL;
    return size_array;
}

char **basic_ls_array(flags_t *flag, char **array)
{
    char **result_array;

    if (flag->a_flags == 0) {
        result_array = create_result_array(array);
        return result_array;
    }
    return array;
}
