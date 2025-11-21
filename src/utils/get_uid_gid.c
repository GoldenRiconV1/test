/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** get_gid_from_file.c
*/

#include "../../include/my.h"

static void find_user_id(data_t *data, parser_t *s)
{
    for (int i = 0; s->array[i] != NULL; i++) {
        if (strcmp(s->array[i][0], data->user_name) == 0) {
            data->uid = atoi(s->array[i][2]);
            break;
        } else
            data->uid = -1;
    }
}

static void find_group_id(data_t *data, parser_t *s)
{
    for (int i = 0; s->array[i] != NULL; i++) {
        if (strcmp(s->array[i][0], data->groupe_name) == 0) {
            data->gid = atoi(s->array[i][2]);
            break;
        } else
            data->gid = -1;
    }
}

static void find_user_name(data_t *data, parser_t *s)
{
    for (int i = 0; s->array[i] != NULL; i++) {
        if (atoi(s->array[i][2]) == data->my_uid) {
            data->user_name = s->array[i][0];
            break;
        }
    }
}

bool get_uid_from_file(data_t *data)
{
    parser_t *s = malloc(sizeof(parser_t));
    char *filepath = "/etc/passwd";
    int nbr_arg = 7;

    load_file_and_fill_buf(data, s, filepath);
    file_parser(data, s, nbr_arg);
    find_user_name(data, s);
    if (data->flags == U_FLAG || data->flags == U_AND_G_FLAG)
        find_user_id(data, s);
    free_struct_s(s);
    if (data->uid == -1)
        return false;
    return true;
}

bool get_gid_from_file(data_t *data)
{
    parser_t *s = malloc(sizeof(parser_t));
    char *filepath = "/etc/group";
    int nbr_arg = 4;

    load_file_and_fill_buf(data, s, filepath);
    file_parser(data, s, nbr_arg);
    if (data->flags == G_FLAG || data->flags == U_AND_G_FLAG)
        find_group_id(data, s);
    free_struct_s(s);
    if (data->gid == -1)
        return false;
    return true;
}
