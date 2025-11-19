/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** get_uid_from_file.c
*/

#include "../../include/my.h"

static bool passwd_file_parser(data_t *data, char *buf)
{
    int user_name_len = strlen(data->user_name);
    int line = 0;
    int str_len = 0;
    char ***array;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n')
            line++;
    }
    array = malloc(sizeof(char *) * line);
    array[line] = NULL;
    for (int i = 0; i < line; i++) {
        array[i] = malloc(sizeof(char *) * 7 + 1);
        for (int j = 0; buf[j] != '\n'; j++) {
            if (buf[j] == ':')
                str_len++;
            str_len++;
            strncpy(array[i], buf, str_len);
        }
        array[i][7] = NULL;
    }

    printf("line: %i\n", line);
    printf("array: [%s], [%s], [%s], [%s], [%s], [%s], [%s]\n", array[0], array[1], array[2], array[3], array[4], array[5], array[6]);
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
    printf("%s", buf_user);
    passwd_file_parser(data, buf_user);
    free(buf_user);
    return true;
}
