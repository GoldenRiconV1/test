/*
** EPITECH PROJECT, 2025
** G-CPE-101-LYN-1-1-myprintf-18 [WSL: Ubuntu-24.04]
** File description:
** float_special
*/

#include "../include/my.h"

int print_special_float_value(double value, int uppercase, int *count)
{
    if (value != value) {
        *count += uppercase ? my_putstr("NAN") : my_putstr("nan");
        return 1;
    }
    if (value == 1.0 / 0.0) {
        *count += uppercase ? my_putstr("INF") : my_putstr("inf");
        return 1;
    }
    if (value == -1.0 / 0.0) {
        *count += uppercase ? my_putstr("-INF") : my_putstr("-inf");
        return 1;
    }
    return 0;
}
