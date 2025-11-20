/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** parser.c
*/

#include "../include/my.h"

int parser(int argc, char **argv)
{
    if (argc == 3 && is_nbr(argv[1]))
        return handle_generated_map(argv);
    if (argc == 2)
        return handle_file_map(argv);
    return 84;
}
