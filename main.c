/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    flags_t flags;
    has_file_flag_t all_args;
    sorted_args_t sorted_args;
    int error_status = 0;

    structs_assignment(&flags, &all_args);
    parser(argc, argv, &flags, &all_args);
    sort_arguments(&all_args, &sorted_args, &flags, &error_status);
    my_ls(&flags, &all_args, &sorted_args, &error_status);
    my_free(NULL, &all_args);
    my_free(NULL, &sorted_args.files);
    my_free(NULL, &sorted_args.dirs);
    return error_status;
}
