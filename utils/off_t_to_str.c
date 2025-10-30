/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** off_t_to_str.c
*/

#include "../include/my.h"

static char *put_off_t_to_array(long long n, long long temp, int len,
    int is_negative)
{
    char *off_t_str = malloc(sizeof(char) * (len + 1));

    if (off_t_str == NULL)
        return NULL;
    off_t_str[len] = '\0';
    temp = n;
    if (temp == 0) {
        off_t_str[0] = '0';
    } else {
        while (temp > 0) {
            len--;
            off_t_str[len] = (char)('0' + (temp % 10));
            temp /= 10;
        }
    }
    if (is_negative)
        off_t_str[0] = '-';
    return off_t_str;
}

char *off_t_to_str(off_t value)
{
    long long n = (long long)value;
    long long temp;
    int len = 0;
    int is_negative = 0;

    if (n < 0) {
        is_negative = 1;
        n = -n;
        len = 1;
    }
    temp = n;
    if (temp == 0)
        len = 1;
    else {
        while (temp > 0) {
            temp /= 10;
            len++;
        }
    }
    return put_off_t_to_array(n, temp, len, is_negative);
}
