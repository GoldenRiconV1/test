/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** parser.c
*/

#include "include/my.h"
#include <stdio.h>

void flags_asigment(flags_t *flag)
{
    flag->a_flags = 0;
    flag->l_flags = 0;
    flag->R_flags = 0;
    flag->d_flags = 0;
    flag->t_flags = 0;
    flag->has_flags = 0;
}

void parser(int argc, char **argv, flags_t *flag)
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-a") != 0 && my_strcmp(argv[i], "-l") != 0
            && my_strcmp(argv[i], "-R") != 0 && my_strcmp(argv[i], "-d") != 0
            && my_strcmp(argv[i], "-t") != 0)
            return;
        if (my_strcmp(argv[i], "-a") == 0)
            flag->a_flags = 1;
        if (my_strcmp(argv[i], "-l") == 0)
            flag->l_flags = 1;
        if (my_strcmp(argv[i], "-R") == 0)
            flag->R_flags = 1;
        if (my_strcmp(argv[i], "-d") == 0)
            flag->d_flags = 1;
        if (my_strcmp(argv[i], "-t") == 0)
            flag->t_flags = 1;
    }
    if (flag->a_flags == 1 || flag->l_flags == 1 || flag->R_flags == 1
        || flag->d_flags == 1 || flag->t_flags == 1)
        flag->has_flags = 1;
}
