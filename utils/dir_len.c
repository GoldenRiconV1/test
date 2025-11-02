/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** dir_len.c
*/

#include "../include/my.h"
#include <errno.h>
#include <string.h>

void print_error(const char *path)
{
    my_putstr_err("my_ls: cannot access '");
    my_putstr_err(path);
    my_putstr_err("': ");
    my_putstr_err(strerror(errno));
    my_putstr_err("\n");
}

int dir_len(has_file_flag_t *has_file_flag)
{
    int array_len = 0;
    struct dirent *entry;
    DIR *dir_stream = opendir(has_file_flag->path[0]);

    if (dir_stream == NULL) {
        print_error(has_file_flag->path[0]);
        return -1;
    }
    entry = readdir(dir_stream);
    while (entry != NULL) {
        array_len++;
        entry = readdir(dir_stream);
    }
    closedir(dir_stream);
    return array_len;
}
