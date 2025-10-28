/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_flags.c
*/

#include "../include/my.h"

void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag, char **array)
{
    char **ls_array = basic_ls_array(&flag, array);

    if (flag->a_flags == 1) {
            for (int i = 0; i < my_arraylen(array); i++)
                mini_printf("%s\n", array[i]);
        } else {
            for (int i = 0; i < my_arraylen(ls_array); i++)
                mini_printf("%s\n", ls_array[i]);
        }
}
