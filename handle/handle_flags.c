/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_flags.c
*/

#include "../include/my.h"

// A faire : Ici pour les combinaisons de flags
// static char **
static char ***send_good_array(char ***array, flags_t *flag)
{
    char ***result_array = array;
    int size_array = my_arraylen(array);

    if (!(flag->a_flags)) {
        result_array = basic_array(flag, array);
        size_array = my_arraylen(result_array);
    }
    if (flag->t_flags)
        result_array = handle_t(result_array, size_array);
    return result_array;
}

void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag,
    file_data_t *file_data, char ***array)
{
    char ***ls_array = send_good_array(array, flag);

    if (ls_array == NULL)
        return;
    if (flag->l_flags) {
        if (ls_array == NULL)
            return;
        mini_printf("total : %d\n", file_data->blocks / 2);
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
