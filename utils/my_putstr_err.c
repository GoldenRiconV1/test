/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_putstr_err.c
*/

#include "../include/my.h"

int my_putstr_err(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return 0;
}
