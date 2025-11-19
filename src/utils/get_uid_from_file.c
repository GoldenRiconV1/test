/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** get_uid_from_file.c
*/

#include "../../include/my.h"

struct array_s {
    char *buf;
    char ***array;
    int str_len;
};

static int count_line(char *buf)
{
    int line = 0;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n')
            line++;
    }
    return line;
}

static void fill_str_array(struct array_s *array_s, int i)
{
    int cursor = 0;

    array_s->array[i] = malloc(sizeof(char *) * 8);
    for (int j = 0; j < 7; j++) {
        array_s->str_len = 0;
        while (array_s->buf[cursor + array_s->str_len] != ':' &&
            array_s->buf[cursor + array_s->str_len] != '\n' && array_s->buf[cursor + array_s->str_len] != '\0')
            array_s->str_len++;
        array_s->array[i][j] = malloc(sizeof(char) * (array_s->str_len + 1));
        strncpy(array_s->array[i][j], &array_s->buf[cursor], array_s->str_len);
        array_s->array[i][j][array_s->str_len] = '\0';
        cursor += array_s->str_len;
        if (array_s->buf[cursor] != '\0')
            cursor++;
    }
    array_s->array[i][7] = NULL;
}

static bool passwd_file_parser(data_t *data, char *buf)
{
    int line = count_line(buf);
    char ***array;
    struct array_s *array_s;
    int str_len = 0;

    array = malloc(sizeof(char **) * (line + 1));
    array_s->array = array;
    array_s->buf = buf;
    array_s->str_len = 0;
    for (int i = 0; i < line; i++) {
        fill_str_array(array_s, i);
    }
    array[line] = NULL;
    printf("line: %i\n", line);
    printf("array[0]: [%s], [%s], [%s], [%s], [%s], [%s], [%s]\n", array[0][0], array[0][1], array[0][2], array[0][3], array[0][4], array[0][5], array[0][6]);
    printf("array[49]: [%s], [%s], [%s], [%s], [%s], [%s], [%s]\n", array[49][0], array[49][1], array[49][2], array[49][3], array[49][4], array[49][5], array[49][6]);
    return true;
}

bool get_uid_from_file(data_t *data)
{
    struct stat file_stats;
    char *filepath = "/etc/passwd";
    char *buf_user;

    if (stat(filepath, &file_stats) == -1)
        return false;
    buf_user = malloc(sizeof(char) * (file_stats.st_size + 1));
    if (buf_user == NULL)
        return false;
    if (!fill_buffer_from_file(filepath, buf_user, file_stats.st_size))
        return false;
    passwd_file_parser(data, buf_user);
    free(buf_user);
    return true;
}
