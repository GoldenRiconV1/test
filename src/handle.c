/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** handle.c
*/

#include "../include/my.h"

int handle_generated_map(char **argv)
{
    char **map = generate_map(argv[1], argv[2]);

    if (map == NULL)
        return 84;
    max_square_size(map);
    print_map(map);
    free_map_generated(map);
    return 0;
}

int handle_file_map(char **argv)
{
    char **map = read_file_content(argv[1]);

    if (map == NULL)
        return 84;
    if (!(check_map(map))) {
        free_map_read(map);
        return 84;
    }
    max_square_size(map);
    print_map(map);
    free_map_read(map);
    return 0;
}
