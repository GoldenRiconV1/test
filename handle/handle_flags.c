/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_flags.c
*/

#include "../include/my.h"

static void free_array_only(char ***array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != NULL; j++)
            free(array[i][j]);
        free(array[i]);
    }
    free(array);
}

static char ***send_good_array(char ***array, has_file_flag_t *has_file_flag,
    flags_t *flag)
{
    char ***result_array = array;
    int size_array;
    char ***d_array;

    if (!(flag->a_flags) && has_file_flag->nbr_file == 0)
        result_array = basic_array(flag, has_file_flag, array);
    if (flag->d_flags) {
        d_array = handle_d(result_array, has_file_flag);
        if (result_array != array)
            free_array_only(result_array);
        result_array = d_array;
    }
    size_array = my_arraylen(result_array);
    if (flag->t_flags)
        result_array = handle_t(result_array, size_array);
    return result_array;
}

void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag,
    file_data_t *file_data, char ***array)
{
    char ***ls_array = send_good_array(array, has_file_flag, flag);

    if (ls_array == NULL)
        return;
    if (flag->l_flags) {
        if (ls_array == NULL)
            return;
        if (!(flag->d_flags))
            mini_printf("total : %d\n", flag->blocks / 2);
        for (int i = 0; ls_array[i] != NULL; i++) {
            mini_printf("%s %s %s %s %s %s %s\n",
                ls_array[i][0], ls_array[i][1], ls_array[i][2],
                ls_array[i][3], ls_array[i][4], ls_array[i][5],
                ls_array[i][6]);
        }
    } else {
        for (int i = 0; ls_array[i] != NULL; i++)
            mini_printf("%s\n", ls_array[i][6]);
    }
    if (ls_array != array)
        free(ls_array);
}
