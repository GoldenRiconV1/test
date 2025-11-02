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
    file_data_t file_data;
    char ***array;

    structs_assignment(&flag, &has_file_flag);
    parser(argc, argv, &flag, &has_file_flag);
    if (has_file_flag.nbr_file > 0)
        array = handle_file_args(&has_file_flag, &file_data);
    else
        array = handle_basic_array(&file_data, &flag, &has_file_flag);
    if (array == NULL) {
        free(has_file_flag.path);
        return 84;
    }
    handle_flags(&flag, &has_file_flag, &file_data, array);
    my_free(array, &has_file_flag);
    return 0;
}
