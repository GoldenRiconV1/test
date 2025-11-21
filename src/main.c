/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** main.c
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    data_t *data = malloc(sizeof(data_t));

    if (!data)
        return 84;
    init(data, argc, argv);
    if (!parser(data)) {
        free_prog(data);
        return 84;
    }
    if (data->flags == H_FLAG) {
        free_prog(data);
        return 0;
    }
    if (!auth(data))
        return 84;
    free_prog(data);
    return 0;
}
