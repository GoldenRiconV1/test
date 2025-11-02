/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_strdup.c
*/

#include "../include/my.h"

char *my_strdup(const char *str)
{
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!copy)
        return NULL;
    my_strcpy(copy, str);
    return copy;
}
