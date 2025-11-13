/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** read_maps.c
*/

#include "../include/my.h"

static int count_lines(char *str)
{
    int str_len = my_strlen(str);
    int count_line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count_line += 1;
    }
    if (str_len > 0)
        count_line += 1;
    return count_line;
}

static int process_line_break(char *str, int i, char **array, int line_index)
{
    str[i] = '\0';
    if (str[i + 1] != '\0') {
        array[line_index] = &str[i + 1];
        line_index++;
    }
    return line_index;
}

static char **char_to_array(char *str)
{
    int count_line = count_lines(str);
    int line_index = 0;
    char **array = malloc(sizeof(char *) * (count_line + 1));

    if (array == NULL)
        return NULL;
    array[line_index] = str;
    line_index++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            line_index = process_line_break(str, i, array, line_index);
    }
    array[line_index] = NULL;
    return array;
}

static int fill_buffer_from_file(const char *filepath, char *buf, int size)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return -1;
    if (read(fd, buf, size) == -1) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

char **read_file_content(const char *filepath)
{
    char *buf;
    struct stat file_stats;

    if (stat(filepath, &file_stats) == -1)
        return NULL;
    buf = malloc(sizeof(char) * (file_stats.st_size + 1));
    if (buf == NULL)
        return NULL;
    if (fill_buffer_from_file(filepath, buf, file_stats.st_size) == -1) {
        free(buf);
        return NULL;
    }
    buf[file_stats.st_size] = '\0';
    if (file_stats.st_size > 0 && buf[file_stats.st_size - 1] != '\n') {
        free(buf);
        return NULL;
    }
    return char_to_array(buf);
}
