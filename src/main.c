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

    if (!data)
        return NULL;
    if (!parser(argc, argv))
        return 84;
    return 0;
}
