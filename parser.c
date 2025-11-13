/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** parser.c
*/

#include "include/my.h"

static void free_map_generated(char **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}

static void free_map_read(char **map)
{
    if (map == NULL)
        return;
    if (map[0] != NULL)
        free(map[0]);
    free(map);
}

static int is_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

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

static int check_map(char **map)
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

static int handle_generated_map(char **argv)
{
    char **map = generate_map(argv[1], argv[2]);

    if (map == NULL)
        return 84;
    handle_max_square_size(map);
    print_map(map);
    free_map_generated(map);
    return 0;
}

static int handle_file_map(char **argv)
{
    char **map = read_file_content(argv[1]);

    if (map == NULL)
        return 84;
    if (!(check_map(map))) {
        free_map_read(map);
        return 84;
    }
    handle_max_square_size(map);
    print_map(map);
    free_map_read(map);
    return 0;
}

int parser(int argc, char **argv)
{
    if (argc == 3 && is_nbr(argv[1]))
        return handle_generated_map(argv);
    if (argc == 2)
        return handle_file_map(argv);
    return 84;
}
