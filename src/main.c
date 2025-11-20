/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** main.c
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    char **map;
    max_t max = {0, 0, 0};

    if (argc <= 1)
        return 84;
    return parser(argc, argv);
}
