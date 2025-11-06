/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** structs_assignment.c
*/

#include "../include/my.h"

void structs_assignment(flags_t *flag, has_file_flag_t *has_file_flag)
{
    flag->a_flags = 0;
    flag->l_flags = 0;
    flag->R_flags = 0;
    flag->d_flags = 0;
    flag->t_flags = 0;
    flag->blocks = 0;
    has_file_flag->has_flags = 0;
    has_file_flag->has_file = 0;
    has_file_flag->nbr_file = 0;
    has_file_flag->path = NULL;
}
