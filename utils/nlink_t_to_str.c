/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** int_to_str.c
*/

#include "../include/my.h"

static char *put_nlink_t_to_array(unsigned long n, int len, char *nlink_t_str)
{
    nlink_t_str = malloc(sizeof(char) * (len + 1));
    if (nlink_t_str == NULL)
        return NULL;
    nlink_t_str[len] = '\0';
    if (n == 0)
        nlink_t_str[0] = '0';
    else {
        while (n > 0) {
            len--;
            nlink_t_str[len] = (char)('0' + (n % 10));
            n /= 10;
        }
    }
    return nlink_t_str;
}

char *nlink_t_to_str(nlink_t link_count)
{
    unsigned long n = (unsigned long)link_count;
    unsigned long temp = n;
    int len = 0;
    char *nlink_t_str;

    if (n == 0)
        len = 1;
    else {
        while (temp > 0) {
            temp /= 10;
            len++;
        }
    }
    return put_nlink_t_to_array(n, len, nlink_t_str);
}
