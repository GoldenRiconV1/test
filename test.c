/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** setting_up_solver.c
*/

#include "../include/my.h"

void change_map(char **map, coords_t *res)
{
    for (int i = res->x; i != res->x + res->size; i++) {
        for (int j = res->y; j != res->y + res->size; j++) {
            map[i][j] = 'x';
        }
    }
}

coords_t *check_coords(coords_t *res, int size, int i, int j)
{
    if (size > res->size) {
        res->size = size;
        res->x = i;
        res->y = j;
    }
    return res;
}

static int check_square_line(char **map, int x, int j, int size)
{
    // printf("size = %d\n", size);
    // printf("j = %d\n", j);
    printf("x = %d\n", x);
    for (int y = j; y < j + size; y++) {
        // printf("y = %d\n", y);
        if (map[x] == NULL)
            return 0;
        if (map[x][y] == '\0')
            return 0;
        if (map[x][y] != '.')
            return 0;
    }
    return 1;
}

int check_square(char **map, int i, int j, int size)
{
    for (int x = i; x < i + size; x++) {
        if (!check_square_line(map, x, j, size))
            return size - 1;
    }
    return check_square(map, i, j, size + 1);
}

void check_dot(char **map, coords_t *res, int cols, int i)
{
    int size = 0;

    for (int j = 0; j < cols; j++) {
        if (map[i][j] == '.') {
            size = check_square(map, i, j, 1);
            res = check_coords(res, size, i, j);
        }
    }
}

void solve_setting_up(char **map, int rows, int cols)
{
    coords_t res = {0, 0, 0};

    if (rows % 2 == 1)
        rows--;
    for (int i = 0; i < rows; i++) {
        check_dot(map, &res, cols, i);
    }
    change_map(map, &res);
}