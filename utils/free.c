/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** free.c
*/

#include "../include/my.h"

void free_map_generated(char **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}

void free_map_read(char **map)
{
    if (map == NULL)
        return;
    if (map[0] != NULL)
        free(map[0]);
    free(map);
}

void free_generate_null_map(char **map, int nb_lines)
{
    for (int k = 0; k < nb_lines; k++)
        free(map[k]);
    free(map);
}
