/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** free_prog.c
*/

#include "../../include/my.h"

void free_prog(data_t *data)
{
    if (!data)
        return;
    if (data->command)
        free(data->command);
    free(data->put_password);
    if (data->user_name)
        free(data->user_name);
    if (data->group_name)
        free(data->group_name);
    free(data);
}
