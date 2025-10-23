/*
** EPITECH PROJECT, 2025
** G-CPE-101-LYN-1-1-myprintf-18
** File description:
** main.c
*/

#include "include/my.h"

int main(void)
{
    int age = 10;
    int *pointeurSurAge = &age;

    printf("ceci est un test %y.\n");
    my_printf("ceci est un test %y.\n");
    return 0;
}
