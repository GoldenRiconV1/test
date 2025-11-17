/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** parser.c
*/

#include "../include/include.h"

static void u_flag(int argc, char **argv, data_t *data, int i)
{
    if (strcmp(argv[1], "-u") == 0 && i != 1) {
        data->command[i - 2] = argv[i];
        data->uid = getuid();
        printf("command: %s\n", data->command[0]);
        printf("option: %s\n", data->command[i - 2]);
        printf("uid: %u\n", data->uid);
        data->command[argc - 2] = NULL;
        data->flags = U_FLAG;
    }
}

static void g_flag(int argc, char **argv, data_t *data, int i)
{
    if (strcmp(argv[1], "-g") == 0 && i != 1) {
        data->command[i - 2] = argv[i];
        data->gid = getgid();
        printf("command: %s\n", data->command[0]);
        printf("option: %s\n", data->command[i - 2]);
        printf("gid: %u\n", data->gid);
        data->command[argc - 2] = NULL;
        data->flags = G_FLAG;
    }
}

static void u_and_g_flag(int argc, char **argv, data_t *data, int i)
{
    if ((strcmp(argv[1], "-gu") == 0 ||
            strcmp(argv[1], "-ug") == 0) && i != 1) {
        data->command[i - 2] = argv[i];
        data->uid = getuid();
        data->gid = getgid();
        printf("command: %s\n", data->command[0]);
        printf("option: %s\n", data->command[i - 2]);
        printf("uid: %u\n", data->uid);
        printf("gid: %u\n", data->gid);
        data->command[argc - 2] = NULL;
        data->flags = U_AND_G_FLAG;
    }
}

static void empty_flag(int argc, char **argv, data_t *data, int i)
{
    if (data->flags == EMPTY) {
        data->command[i - 1] = argv[i];
        printf("-empty %s\n", data->command[i - 1]);
        data->command[argc - 1] = NULL;
    }
}

static void flags(int argc, char **argv, data_t *data)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[1], "-g") == 0 && i == 1)
            i = 2;
        u_flag(argc, argv, data, i);
        g_flag(argc, argv, data, i);
        u_and_g_flag(argc, argv, data, i);
        empty_flag(argc, argv, data, i);
    }
}

bool parser(int argc, char **argv, data_t *data)
{
    int i = 0;

    if (argc <= 1)
        return false;
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ug] [command [args ...]]\n");
        return true;
    }
    flags(argc, argv, data);
    return false;
}
