/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** off_t_to_str.c
*/

#include "../include/my.h"

char *time_t_to_str(off_t time)
{
    char *result = malloc(sizeof(char) * 13);
    char *ctime_str;

    ctime_str = ctime(&time);
    for (int i = 0; i < 12; i++)
        result[i] = ctime_str[i + 4];
    result[12] = '\0';
    return result;
}
