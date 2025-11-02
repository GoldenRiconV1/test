/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_arraylen.c
*/

#include "../include/my.h"

int my_arraylen(char ***array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}
