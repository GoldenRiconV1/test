/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** auth.c
*/

#include "../include/my.h"

void read_in_stdin(data_t *data)
{
    int i = 0;

    for (int j = 0; j < 3; j++) {
        read(0, data->put_password[j], sizeof(char *));
        if (strcmp(data->put_password[j], "ab\n") == 0)
            break;
        fprintf(stderr, "[my_sudo] password for [%s] :", data->user_name);
    }
    // while (data->put_password[0][i] != '\n')
    //     i++;
    // data->put_password[0][i] = '\0';
    // i = 0;
    printf("stdin 1: %s\n", data->put_password[0]);
    printf("stdin 2: %s\n", data->put_password[1]);
    printf("stdin 3: %s\n", data->put_password[2]);
}
