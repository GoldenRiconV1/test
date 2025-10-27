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
    char **array;
    char **array2;

    if (argc > 1)
        parser(argc, argv, &flag);
    array = handle_array();
    array2 = basic_ls_array(&flag, array);
    printf("%s %s %s %s\n",
        array[0], array[1], array[2], array[3]);
    return 0;
}
