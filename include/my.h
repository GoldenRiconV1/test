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

typedef struct map_data_s {
    char **map_lines;
    int **dp;
    int nb_rows;
    int nb_cols;
} map_data_t;

typedef struct max_s {
    int size;
    int row;
    int col;
} max_t;

int parser(int argc, char **argv);
char **generate_map(char *size_char, char *patern);

void max_square_size(char **map_lines);
int handle_generated_map(char **argv);
int handle_file_map(char **argv);

void free_map_generated(char **map);
void free_map_read(char **map);
void free_generate_null_map(char **map, int nb_lines);
int check_map(char **map);

char **read_file_content(const char *filepath);
int my_strlen(char const *str);
void print_map(char **map);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int is_nbr(char *str);

#endif
