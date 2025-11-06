/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_flags.c
*/

#include "../include/my.h"

void handle_flags(flags_t *flag, char ***array)
{
    if (array == NULL)
        return;
    if (flag->l_flags) {
        if (!(flag->d_flags))
            mini_printf("total %d\n", flag->blocks / 2);
        for (int i = 0; array[i] != NULL; i++) {
            mini_printf("%s %s %s %s %s %s %s\n",
                array[i][0], array[i][1], array[i][2],
                array[i][3], array[i][4], array[i][5],
                array[i][6]);
        }
    } else {
        for (int i = 0; array[i] != NULL; i++)
            mini_printf("%s\n", array[i][6]);
    }
}
