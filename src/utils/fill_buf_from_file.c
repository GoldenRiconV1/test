/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** fill_buf_from_file.c
*/

#include "../../include/my.h"

bool fill_buffer_from_file(char *filepath, char *buf, int size)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return false;
    if (read(fd, buf, size) == -1) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
