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
    has_file_flag_t has_file_flag;
    char ***array;

    flags_asigment(&flag, &has_file_flag);
    array = handle_basic_array();
    if (argc > 1)
        parser(argc, argv, &flag, &has_file_flag);
    handle_flags(&flag, &has_file_flag, array);
    return 0;
}
