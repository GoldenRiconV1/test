/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** free_prog.c
*/

#include "../../include/my.h"

void free_prog(data_t *data)
{
    free(data->command);
    free(data);
}
