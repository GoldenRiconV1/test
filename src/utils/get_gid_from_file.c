/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** get_gid_from_file.c
*/

#include "../../include/my.h"

struct s {
    char *buf;
    char ***array;
    int str_len;
    int buf_idx;
    int line;
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

static void fill_str_array(struct s *s, int i)
{
    s->array[i] = malloc(sizeof(char *) * 5);
    for (int j = 0; j < 4; j++) {
        s->str_len = 0;
        while (s->buf[s->buf_idx + s->str_len] != ':'
            && s->buf[s->buf_idx + s->str_len] != '\n'
            && s->buf[s->buf_idx + s->str_len] != '\0')
            s->str_len++;
        s->array[i][j] = malloc(sizeof(char) * (s->str_len + 1));
        strncpy(s->array[i][j], &s->buf[s->buf_idx], s->str_len);
        s->array[i][j][s->str_len] = '\0';
        s->buf_idx += s->str_len;
        if (s->buf[s->buf_idx] != '\0')
            s->buf_idx++;
    }
    s->array[i][4] = NULL;
}

static void init_s(struct s *s, char ***array)
{
    s->array = array;
    s->str_len = 0;
    s->buf_idx = 0;
    s->line = 0;
}

static bool group_file_parser(data_t *data, struct s *s)
{
    char ***array;

    array = malloc(sizeof(char **) * (s->line + 1));
    init_s(s, array);
    s->line = count_line(s->buf);
    for (int i = 0; i < s->line; i++)
        fill_str_array(s, i);
    array[s->line] = NULL;
    printf("line: %i\n", s->line);
    printf("array[0]: [%s], [%s], [%s], [%s], [%s]\n", array[1][0], array[1][1], array[1][2], array[1][3], array[1][4]);
    printf("array[0]: [%s], [%s], [%s], [%s], [%s]\n", array[78][0], array[78][1], array[78][2], array[78][3], array[78][4]);
    return true;
}

static bool fill_buf(data_t *data, struct s *s)
{
    struct stat file_stats;
    char *filepath = "/etc/group";

    if (stat(filepath, &file_stats) == -1)
        return false;
    s->buf = malloc(sizeof(char) * (file_stats.st_size + 1));
    if (s->buf == NULL)
        return false;
    if (!fill_buffer_from_file(filepath, s->buf, file_stats.st_size))
        return false;
    return true;
}

bool get_gid_from_file(data_t *data)
{
    struct s *s = malloc(sizeof(struct s));

    fill_buf(data, s);
    group_file_parser(data, s);
    for (int i = 0; i < s->line - 1; i++) {
        if (strcmp(s->array[i][0], data->groupe_name) == 0)
            data->gid = atoi(s->array[i][2]);
        else
            data->gid = -1;
    }
    free(s->buf);
    free(s->array);
    free(s);
    if (data->gid == -1)
        return false;
    return true;
}
