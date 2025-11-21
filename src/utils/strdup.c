/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** strdup.c
*/

#include "../../include/my.h"

char *strdup(const char *c)
{
    char *dup = malloc(strlen(c) + 1);

    if (dup != NULL)
        strcpy(dup, c);
    return dup;
}
