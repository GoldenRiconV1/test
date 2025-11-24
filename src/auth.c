/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** auth.c
*/

#include "../include/my.h"

static void read_and_cmp_psw_in_stdin(data_t *data)
{
    size_t len = 0;
    int len_pass = 0;

    for (int i = 0; i < 3; i++) {
        if (i != 0)
            fprintf(stderr, "Sorry, try again.\n");
        fprintf(stderr, "[my_sudo] password for [%s] :\n", data->my_user_name);
        getline(&data->put_password, &len, stdin);
        len_pass = strlen(data->put_password);
        data->put_password[len_pass - 1] = '\0';
        if (strcmp(crypt(data->put_password, data->get_hashed_pass),
                data->get_hashed_pass) == 0) {
            data->good_pass = true;
            break;
        }
    }
}

static void find_user_hashed_pass(data_t *data, parser_t *s)
{
    for (int i = 0; s->array[i] != NULL; i++) {
        if (strcmp(s->array[i][0], data->my_user_name) == 0) {
            data->get_hashed_pass = my_strdup(s->array[i][1]);
            break;
        }
    }
}

static bool get_user_password(data_t *data)
{
    parser_t *s = malloc(sizeof(parser_t));
    char *filepath = "/etc/shadow";
    int nbr_arg = 9;

    if (!load_file_and_fill_buf(data, s, filepath)) {
        free(s);
        return false;
    }
    if (!file_parser(data, s, nbr_arg)) {
        free(s);
        return false;
    }
    find_user_hashed_pass(data, s);
    free_struct_s(s);
    if (data->get_hashed_pass == NULL)
        return false;
    return true;
}

static bool check_user(parser_t *s, data_t *data, int i)
{
    int len_username = strlen(data->my_user_name);

    if (strncmp(s->double_array[i], data->my_user_name, len_username) == 0
        && (s->double_array[i][len_username] == ' '
            || s->double_array[i][len_username] == '\t'))
        return true;
    return false;
}

static bool check_group(parser_t *s, data_t *data, int i)
{
    char *line = s->double_array[i];
    int len;
    char next;

    if (line[0] != '%')
        return false;
    for (int k = 0; data->in_group[k] != NULL; k++) {
        len = strlen(data->in_group[k]);
        next = line[1 + len];
        if (strncmp(line + 1, data->in_group[k], len) == 0 &&
            (next == ' ' || next == '\t' || next == '\0' || next == '\n'))
            return true;
    }
    return false;
}

static bool handle_sudoers(data_t *data)
{
    char *filepath = "/etc/sudoers";
    parser_t *s = malloc(sizeof(parser_t));
    int str_len = 0;

    if (!load_file_and_fill_buf(data, s, filepath) || !fill_double_array(s)) {
        free_struct_s(s);
        return false;
    }
    for (int i = 0; s->double_array[i] != NULL; i++) {
        if (check_user(s, data, i)) {
            printf("user a les droits\n");
            break;
        }
        if (check_group(s, data, i)) {
            printf("group a les droits\n");
            break;
        }
    }
    free_struct_s(s);
    return true;
}

bool auth(data_t *data)
{
    if (!get_user_password(data))
        return false;
    read_and_cmp_psw_in_stdin(data);
    if (data->good_pass)
        handle_sudoers(data);
    return true;
}
