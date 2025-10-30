/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** lexicographic_cmp.c
*/

#include "../include/my.h"

int lexicographic_cmp(const char *a, const char *b)
{
    int i = 0;
    unsigned char ca;
    unsigned char cb;

    while (a[i] && b[i]) {
        ca = char_to_lower(a[i]);
        cb = char_to_lower(b[i]);
        if (ca != cb)
            return (ca - cb);
        i++;
    }
    return (char_to_lower(a[i]) - char_to_lower(b[i]));
}
