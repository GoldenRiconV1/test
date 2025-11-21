/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** auth.c
*/

#include "../include/my.h"

static void read_in_stdin(data_t *data)
{
    size_t len = 0;

    for (int i = 0; i < 3; i++) {
        if (i != 0)
            fprintf(stderr, "Sorry, try again.\n");
        fprintf(stderr, "[my_sudo] password for [%s] :", data->user_name);
        getline(&data->put_password, &len, stdin);
        if (strcmp(data->put_password, "ab\n") == 0) {
            printf("good_pass\n");
            break;
        }
    }
}

static void find_user_hashed_pass(data_t *data, parser_t *s)
{
    for (int i = 0; s->array[i] != NULL; i++) {
        if (strcmp(s->array[i][0], data->user_name) == 0) {
            data->get_hashed_pass = my_strdup(s->array[i][1]);
            break;
        }
    }
    printf("hashed pass: %s\n", data->get_hashed_pass);
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

bool auth(data_t *data)
{
    if (!get_user_password(data))
        return false;
    printf("test : %s", crypt("password", "j9T"));
    return true;
}
