/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_ls.c
*/

#include "../include/my.h"

static char **create_result_array(char **array)
{
    int start_index = 0;
    char **size_array;
    int str_len = 0;
    int i = 0;
    int j = 0;

    while (i < my_arraylen(array)) {
        if (array[i][0] == '.')
            start_index += 1;
        i++;
    }
    i = 0;
    size_array = malloc(sizeof(char *) * (my_arraylen(array) - start_index));
    while (j <= i) {
        for (int k = start_index; array[k][j] != '\0'; k++)
            size_array[j] = malloc(sizeof(char) * k);
        j++;
    }
    size_array[my_arraylen(array) - start_index] = NULL;
    return size_array;
}

char **basic_ls_array(flags_t *flag, char **array)
{
    char **result_array;

    if (!(flag->a_flags)) {
        result_array = create_result_array(array);
    }
    return result_array;
}
