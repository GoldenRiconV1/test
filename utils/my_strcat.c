/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_strcat.c
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(&dest[my_strlen(dest)], src);
    return dest;
}
