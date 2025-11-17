/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** main.c
*/

#include "../include/include.h"

int main(int argc, char **argv)
{
    data_t *data = malloc(sizeof(data_t));

    init(data, argc, argv);
    data->command_size = argc;
    if (!data)
        return 84;
    if (!parser(data))
        return 84;
    free(data->command);
    free(data);
    return 0;
}
