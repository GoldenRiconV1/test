/*
** EPITECH PROJECT, 2025
** G-CPE-110-LYN-1-1-settingup-6
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #define INT_MAX 2147483647
    #define INT_MIN (-2147483648)

typedef struct max_s {
    int size;
    int row;
    int col;
} max_t;

void parser(int argc, char **argv);
void handle_max_square_size(char **map_lines);

char **read_file_content(const char *filepath);
int my_strlen(char const *str);
void print_map(char **map);
int my_getnbr(char const *str);

#endif
