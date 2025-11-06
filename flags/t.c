/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** t.c
*/

#include "../include/my.h"

static int get_month_part2(char *array)
{
    if (array[0] == 'J' && array[1] == 'u' && array[2] == 'l')
        return 7;
    if (array[0] == 'A' && array[1] == 'u' && array[2] == 'g')
        return 8;
    if (array[0] == 'S' && array[1] == 'e' && array[2] == 'p')
        return 9;
    if (array[0] == 'O' && array[1] == 'c' && array[2] == 't')
        return 10;
    if (array[0] == 'N' && array[1] == 'o' && array[2] == 'v')
        return 11;
    if (array[0] == 'D' && array[1] == 'e' && array[2] == 'c')
        return 12;
    return 0;
}

static int get_month(char *array)
{
    if (array[0] == 'J' && array[1] == 'a' && array[2] == 'n')
        return 1;
    if (array[0] == 'F' && array[1] == 'e' && array[2] == 'b')
        return 2;
    if (array[0] == 'M' && array[1] == 'a' && array[2] == 'r')
        return 3;
    if (array[0] == 'A' && array[1] == 'p' && array[2] == 'r')
        return 4;
    if (array[0] == 'M' && array[1] == 'a' && array[2] == 'y')
        return 5;
    if (array[0] == 'J' && array[1] == 'u' && array[2] == 'n')
        return 6;
    return get_month_part2(array);
}

static int time_to_int(char *array)
{
    int month = (get_month(array));
    int day = 0;
    int hour = 0;
    int min = 0;

    if (array[4] == ' ')
        day = array[5] - '0';
    else
        day = (array[4] - '0') * 10 + (array[5] - '0');
    hour = (array[7] - '0') * 10 + (array[8] - '0');
    min = (array[10] - '0') * 10 + (array[11] - '0');
    return ((month * 31 + day) * 24 + hour) * 60 + min;
}

static char ***sorted_by_time(char ***array, int len_array)
{
    int j;
    char **elem;
    int time_elem = 0;

    for (int i = 1; i < len_array; i++) {
        elem = array[i];
        time_elem = time_to_int(elem[5]);
        j = i - 1;
        while (j >= 0 && time_to_int(array[j][5]) < time_elem) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = elem;
    }
    return array;
}

char ***handle_t(char ***array, int array_len)
{
    return sorted_by_time(array, array_len);
}
