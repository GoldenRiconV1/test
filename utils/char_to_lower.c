/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** char_to_lower.c
*/

#include "../include/my.h"

int char_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}
