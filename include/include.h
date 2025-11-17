/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-mysudo-39
** File description:
** include.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

typedef struct data_s {
    char *command;
} data_t;

bool parser(int argc, char **argv);
#endif
