/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** l.c
*/

#include "../include/my.h"

static char ***apply_padding(char ***array, int max_size_len, int count)
{
    char **space;

    space = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        space[i] = malloc(sizeof(char) * (max_size_len + 1));
        if (!space[i])
            return NULL;
        for (int j = 0; j < (max_size_len - my_strlen(array[i][4])); j++)
            space[i][j] = ' ';
        for (int j = 0; j < my_strlen(array[i][4]); j++)
            space[i][(max_size_len - my_strlen(array[i][4])) + j] = array[i][4][j];
        space[i][max_size_len] = '\0';
        array[i][4] = space[i];
        printf("taille : %i a%s\n", max_size_len, array[i][4]);
    }
    return array;
}

char ***apply_padding_part_2(char ***array)
{
    int max_size_len = 0;
    int temps = 0;
    int count = 0;

    for (count = 0; array[count] != NULL; count++) {
        temps = my_strlen(array[count][4]);
        if (temps > max_size_len) {
            max_size_len = temps;
        }
    }
    return apply_padding(array, max_size_len, count);
}

char ***l_array(flags_t *flag, char ***array)
{
    char ***result_array;

    if (flag->a_flags) {
        return array;
    }
    result_array = create_result_array(array);
    return result_array;
}
