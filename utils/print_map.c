/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** print_map.c
*/

#include "../include/my.h"

void print_map(char **map)
{
    char **map_lines = &map[1];
    int cols = my_strlen(map_lines[0]);

    if (cols == 0)
        return;
    for (int i = 0; map_lines[i] != NULL; i++) {
        write(1, map_lines[i], cols);
        write(1, "\n", 1);
    }
}
