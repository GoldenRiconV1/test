/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** parser.c
*/

#include "../include/include.h"

static void u_flag(data_t *data, int i)
{
    if (strcmp(data->argv[1], "-u") == 0
        && data->flags != U_AND_G_FLAG && i != 1) {
        data->command[i - 2] = data->argv[i];
        printf("command: %s\n", data->command[0]);
        printf("option: %s\n", data->command[i - 2]);
        printf("uid: %u\n", data->uid);
        data->command[data->argc - 2] = NULL;
        data->flags = U_FLAG;
    }
}

static void g_flag(data_t *data, int i)
{
    if (strcmp(data->argv[1], "-g") == 0
        && data->flags != U_AND_G_FLAG && i != 1) {
        data->command[i - 2] = data->argv[i];
        data->gid = getgid();
        printf("command: %s\n", data->command[0]);
        printf("option: %s\n", data->command[i - 2]);
        printf("gid: %u\n", data->gid);
        data->command[data->argc - 2] = NULL;
        data->flags = G_FLAG;
    }
}

static void u_and_g_flag(data_t *data, int i)
{
    if ((strcmp(data->argv[1], "-u") == 0 && strcmp(data->argv[3], "-g") == 0)
        && i != 1) {
        data->command[i - 5] = data->argv[i];
        data->user_name = data->argv[2];
        data->groupe_name = data->argv[4];
        data->command[data->argc - 5] = NULL;
        data->flags = U_AND_G_FLAG;
    }
    if ((strcmp(data->argv[1], "-g") == 0 && strcmp(data->argv[3], "-u") == 0)
        && i != 1) {
        data->command[i - 5] = data->argv[i];
        data->user_name = data->argv[4];
        data->groupe_name = data->argv[2];
        data->command[data->argc - 5] = NULL;
        data->flags = U_AND_G_FLAG;
    }
}

static void empty_flag(data_t *data, int i)
{
    if (data->flags == EMPTY) {
        data->command[i - 1] = data->argv[i];
        printf("-empty %s\n", data->command[i - 1]);
        data->command[data->argc - 1] = NULL;
    }
}

static void flags(data_t *data)
{
    int i = 1;

    if (strcmp(data->argv[1], "-u") == 0 || strcmp(data->argv[1], "-g") == 0)
        i = 2;
    if ((strcmp(data->argv[1], "-u") == 0 && strcmp(data->argv[3], "-g") == 0)
        || (strcmp(data->argv[1], "-g") == 0 && strcmp(data->argv[3], "-u") == 0))
        i = 5;
    while (i < data->argc) {
        u_and_g_flag(data, i);
        i++;
    }
}

bool parser(data_t *data)
{
    int i = 0;

    if (data->argc <= 1)
        return false;
    if (data->argc == 2 && strcmp(data->argv[1], "-h") == 0) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ug] [command [args ...]]\n");
        return true;
    }
    flags(data);
    printf("command: %s\n", data->command[0]);
    // printf("option1: %s\n", data->command[1]);
    // printf("option2: %s\n", data->command[2]);
    // printf("user: %s\n", data->user_name);
    // printf("grp: %s\n", data->groupe_name);
    return false;
}
