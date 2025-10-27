/*
** EPITECH PROJECT, 2025
** G-CPE-100-LYN-1-1-cpoolday07-8
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #define INT_MAX 2147483647
    #define INT_MIN (-2147483648)

    #include <unistd.h>
    #include <stdlib.h>

typedef struct flags_s {
    int a_flags;
    int l_flags;
    int R_flags;
    int d_flags;
    int t_flags;
} flags_t;

int parser(int argc, char **argv, flags_t *flag);


#endif
