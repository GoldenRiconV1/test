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
    for (int i = 0; data->put_password[i] != NULL; i++)
        free(data->put_password[i]);
    free(data->put_password);
    free(data);
}
