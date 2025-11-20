/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** map.c
*/

#include "../include/my.h"

static int check_map_with_actual_row(char **map, int nbr_rows)
{
    int actual_rows = 0;

    if (nbr_rows < 1)
        return 0;
    if (map[1] == NULL)
        return 0;
    for (int i = 1; map[i] != NULL; i++)
        actual_rows++;
    if (actual_rows != nbr_rows)
        return 0;
    return 1;
}

static int check_size_chara(char **map, int i, int len_col)
{
    if (my_strlen(map[i]) != len_col)
        return 0;
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] != '.' && map[i][j] != 'o')
            return 0;
    }
    return 1;
}

int check_map(char **map)
{
    int len_col = 0;
    int nbr_rows = 0;
    int actual_rows = 0;

    if (map == NULL || map[0] == NULL || !(is_nbr(map[0])))
        return 0;
    nbr_rows = my_getnbr(map[0]);
    if (!(check_map_with_actual_row(map, nbr_rows)))
        return 0;
    len_col = my_strlen(map[1]);
    if (len_col == 0)
        return 0;
    for (int i = 1; i <= nbr_rows; i++) {
        if (!(check_size_chara(map, i, len_col)))
            return 0;
    }
    return 1;
}
