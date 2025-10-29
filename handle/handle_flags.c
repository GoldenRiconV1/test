/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_flags.c
*/

#include "../include/my.h"

// A faire : Ici pour les combinaisons de flags
// static char **

void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag, char ***array)
{
    // char **ls_array = basic_ls_array(flag, array);
    char ***ls_array = basic_ls_array(flag, array);

    if (flag->a_flags){
        for (int i = 0; i < dir_len(); i++)
            my_putstr(array[i][6]);
        }
    // else if(flag->l_flags)
    //     for (int i = 0; i < dir_len(); i++)
    //         print_array(ls_l_array[i])
    else {
        for (int i = 0; i < dir_len(); i++)
            my_putstr(ls_array[i][6]);
    }
}
