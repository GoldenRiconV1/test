/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** maxsquare.c
*/

#include "include/my.h"

static int minimum_in_3_int(int a, int b, int c)
{
    int temp;

    if (a < b)
        temp = a;
    else
        temp = b;
    if (c < temp)
        temp = c;
    return temp;
}

static void fill_map(char **map_lines, max_t *max)
{
    for (int i = max->row; i < max->row + max->size; i++)
        for (int j = max->col; j < max->col + max->size; j++)
            map_lines[i][j] = 'x';
}

static void free_cache(int **dp, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(dp[i]);
    free(dp);
}

static int **create_cache(int nb_rows, int nb_cols)
{
    int **dp = malloc(sizeof(int *) * nb_rows);

    if (dp == NULL)
        return NULL;
    for (int i = 0; i < nb_rows; i++) {
        dp[i] = malloc(sizeof(int) * nb_cols);
        if (dp[i] == NULL) {
            free_cache(dp, i);
            return NULL;
        }
    }
    return dp;
}

static void process_cell(int i, int j, map_data_t *data, max_t *max)
{
    if (data->map_lines[i][j] != '.') {
        data->dp[i][j] = 0;
        return;
    }
    if (i == 0 || j == 0)
        data->dp[i][j] = 1;
    else {
        data->dp[i][j] = 1 + minimum_in_3_int(data->dp[i - 1][j],
            data->dp[i][j - 1], data->dp[i - 1][j - 1]);
    }
    if (data->dp[i][j] > max->size) {
        max->size = data->dp[i][j];
        max->row = i;
        max->col = j;
    }
}

static void find_largest_square(map_data_t *data, max_t *max)
{
    for (int i = 0; i < data->nb_rows; i++) {
        for (int j = 0; j < data->nb_cols; j++)
            process_cell(i, j, data, max);
    }
}

static int get_map_rows(char **map_lines)
{
    int i = 0;

    if (map_lines == NULL)
        return 0;
    while (map_lines[i] != NULL)
        i++;
    return i;
}

static void fill_pos_update(max_t *fill_pos, max_t *max, char **map_lines)
{
    fill_pos->size = max->size;
    fill_pos->row = max->row - max->size + 1;
    fill_pos->col = max->col - max->size + 1;
    fill_map(map_lines, fill_pos);
}

void handle_max_square_size(char **map)
{
    max_t max = {0, 0, 0};
    char **map_lines = &map[1];
    int nb_rows = get_map_rows(map_lines);
    int nb_cols = 0;
    max_t fill_pos;
    map_data_t data;

    nb_cols = my_strlen(map_lines[0]);
    if (nb_cols == 0)
        return;
    data.map_lines = map_lines;
    data.nb_rows = nb_rows;
    data.nb_cols = nb_cols;
    data.dp = create_cache(nb_rows, nb_cols);
    if (data.dp == NULL)
        return;
    find_largest_square(&data, &max);
    if (max.size > 0)
        fill_pos_update(&fill_pos, &max, map_lines);
    free_cache(data.dp, nb_rows);
}
