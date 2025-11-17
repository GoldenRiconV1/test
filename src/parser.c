/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** parser.c
*/

#include "../include/include.h"

bool parser(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ug] [command [args ...]]\n");
        return true;
    }
    if (argc > 3)
        return false;
    if (argc == 3 && strcmp(argv[1], "-u") == 0)
        return false;
    return false;
}
