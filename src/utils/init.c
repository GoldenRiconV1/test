/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** init.c
*/

#include "../../include/include.h"

void init(data_t *data, int argc, char **argv)
{
    data->command = malloc(sizeof(char *) * argc);
    data->flags = EMPTY;
    data->argc = argc;
    data->argv = argv;
    data->user_name = NULL;
    data->groupe_name = NULL;
}
