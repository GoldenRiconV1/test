/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** put_default_data.c
*/

#include "../include/my.h"

void put_default_data(file_data_t *file_data, char *d_name)
{
    file_data->name = my_strdup(d_name);
    file_data->type_perm = my_strdup("?");
    file_data->user_name = my_strdup("?");
    file_data->group_name = my_strdup("?");
    file_data->hard_link = my_strdup("?");
    file_data->size = my_strdup("?");
    file_data->time = my_strdup("?");
    return;
}
