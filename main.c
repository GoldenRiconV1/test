/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    flags_t flag;

    if (argc > 5)
        return 84;
    if (argc > 1)
        parser(argc, argv, &flag);
    return 0;
}
