/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** init.c
*/

#include "../../include/my.h"

void init(data_t *data, int argc, char **argv)
{
    data->command = malloc(sizeof(char *) * argc);
    // data->put_password = malloc(sizeof(char *) * 4);
    // data->put_password[0] = malloc(sizeof(char *) + 1);
    // data->put_password[1] = malloc(sizeof(char *) + 1);
    // data->put_password[2] = malloc(sizeof(char *) + 1);
    // data->put_password[3] = NULL;
    data->flags = EMPTY;
    data->argc = argc;
    data->argv = argv;
    data->user_name = NULL;
    data->groupe_name = NULL;
    data->uid = -2;
    data->gid = -2;
}
