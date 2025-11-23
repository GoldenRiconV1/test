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
    if (data->put_password)
        free(data->put_password);
    if (data->user_name)
        free(data->user_name);
    if (data->my_user_name)
        free(data->my_user_name);
    if (data->group_name)
        free(data->group_name);
    if (data->my_group_name)
        free(data->my_group_name);
    if (data->get_hashed_pass)
        free(data->get_hashed_pass);
    if (data->in_group) {
        for (int i = 0; data->in_group[i] != NULL; i++)
            free(data->in_group[i]);
        free(data->in_group);
    }
    free(data);
}
