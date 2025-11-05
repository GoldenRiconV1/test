/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** generate_map.c
*/

#include "include/my.h"

char **generate_map(char *size_char, char *patern)
{
    char **map;
    int index = 0;
    int size = my_getnbr(size_char);
    int patern_len = my_strlen(patern);

    map = malloc(sizeof(char *) * size + 1);
    if (map == NULL)
        return NULL;
    map[0] = malloc(sizeof(char) * my_strlen(size_char));
    map[0] = size_char;
    for (int i = 1; i != size; i++) {
        map[i] = malloc(sizeof(char) * size);
        for (int j = 0; j != size; j++) {
            if (index >= patern_len)
                index = 0;
            map[i][j] = patern[index];
            index++;
        }
    }
    return map;
}
