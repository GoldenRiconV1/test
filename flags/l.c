/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** l.c
*/

#include "../include/my.h"

static char ***apply_padding(char ***array, int len_size_m, int count)
{
    char **buf;

    buf = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        buf[i] = malloc(sizeof(char) * (len_size_m + 1));
        if (!buf[i])
            return NULL;
        for (int j = 0; j < (len_size_m - my_strlen(array[i][4])); j++)
            buf[i][j] = ' ';
        for (int j = 0; j < my_strlen(array[i][4]); j++)
            buf[i][(len_size_m - my_strlen(array[i][4])) + j] = array[i][4][j];
        buf[i][len_size_m] = '\0';
        free(array[i][4]);
        array[i][4] = buf[i];
    }
    return array;
}

char ***apply_padding_part_2(char ***array)
{
    int len_size_m = 0;
    int temps = 0;
    int count = 0;

    for (count = 0; array[count] != NULL; count++) {
        temps = my_strlen(array[count][4]);
        if (temps > len_size_m) {
            len_size_m = temps;
        }
    }
    return apply_padding(array, len_size_m, count);
}
