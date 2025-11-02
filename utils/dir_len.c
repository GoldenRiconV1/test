/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** dir_len.c
*/

#include "../include/my.h"

int dir_len(has_file_flag_t *has_file_flag)
{
    int array_len = 0;
    struct dirent *entry;
    DIR *dir_stream = opendir(has_file_flag->path);

    if (dir_stream == NULL) {
        perror("my_ls: cannot open directory");
        return 84;
    }
    entry = readdir(dir_stream);
    while (entry != NULL) {
        array_len++;
        entry = readdir(dir_stream);
    }
    closedir(dir_stream);
    return array_len;
}
