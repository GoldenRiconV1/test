/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** generate_map.c
*/

#include "include/my.h"

static void free_map(char **map, int nb_lines)
{
    for (int k = 0; k < nb_lines; k++)
        free(map[k]);
    free(map);
}

static void fill_line(char *map_line, int size, char *patern, int *index)
{
    int patern_len = my_strlen(patern);

    for (int j = 0; j < size; j++) {
        if (*index >= patern_len)
            *index = 0;
        map_line[j] = patern[*index];
        (*index)++;
    }
    map_line[size] = '\0';
}

static int handle_lines(char **map, int size, char *patern)
{
    int index = 0;

    for (int i = 1; i <= size; i++) {
        map[i] = malloc(sizeof(char) * (size + 1));
        if (map[i] == NULL) {
            free_map(map, i);
            return 84;
        }
        fill_line(map[i], size, patern, &index);
    }
    map[size + 1] = NULL;
    return 0;
}

char **generate_map(char *size_char, char *patern)
{
    char **map;
    int size = my_getnbr(size_char);

    if (size <= 0 || my_strlen(patern) == 0)
        return NULL;
    map = malloc(sizeof(char *) * (size + 2));
    if (map == NULL)
        return NULL;
    map[0] = malloc(sizeof(char) * (my_strlen(size_char) + 1));
    if (map[0] == NULL) {
        free(map);
        return NULL;
    }
    my_strcpy(map[0], size_char);
    if (handle_lines(map, size, patern) == 84) {
        return NULL;
    }
    return map;
}
