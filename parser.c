/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** parser.c
*/

#include "include/my.h"
#include <stdio.h>

int parser(int argc, char **argv, flags_t *flag)
{
    flag->a_flags = 0;
    flag->l_flags = 0;
    flag->R_flags = 0;
    flag->d_flags = 0;
    flag->t_flags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == "-a")
            flag->a_flags = 1;
        if (argv[i] == "-l")
            flag->l_flags = 1;
        if (argv[i] == "-R")
            flag->R_flags = 1;
        if (argv[i] == "-d")
            flag->d_flags = 1;
        if (argv[i] == "-t")
            flag->t_flags = 1;
    }
    printf("a : %i, l : %i, R : %i, d : %i, t : %i\n", flag->a_flags,
        flag->l_flags, flag->R_flags, flag->d_flags, flag->t_flags);
    return 0;
}
