/*
** EPITECH PROJECT, 2025
** G-CPE-101-LYN-1-1-myprintf-18
** File description:
** char.c
*/

#include "../include/my.h"

static void handle_normal_char(format_spec_t *spec, va_list args,
    int *count, int padding_len)
{
    char c = (char)va_arg(args, int);

    if (spec->flags & FLAG_MINUS) {
        *count += my_putchar(c);
        print_padding(' ', padding_len, count);
    } else {
        print_padding(' ', padding_len, count);
        *count += my_putchar(c);
    }
}

static void handle_wide_char(format_spec_t *spec, va_list args,
    int *count, int padding_len)
{
    wint_t wc = va_arg(args, wint_t);

    if (spec->flags & FLAG_MINUS) {
        my_putwchar(wc, count);
        print_padding(' ', padding_len, count);
    } else {
        print_padding(' ', padding_len, count);
        my_putwchar(wc, count);
    }
}

int handle_char(format_spec_t *spec, va_list args)
{
    int count = 0;
    int padding_len = (spec->width > 1) ? spec->width - 1 : 0;

    if (spec->length == 'l')
        handle_wide_char(spec, args, &count, padding_len);
    else
        handle_normal_char(spec, args, &count, padding_len);
    return count;
}
