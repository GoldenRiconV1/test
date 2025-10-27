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

    #include <dirent.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct flags_s {
    int a_flags;
    int l_flags;
    int R_flags;
    int d_flags;
    int t_flags;
    int has_flags;
} flags_t;

void parser(int argc, char **argv, flags_t *flag);
char **handle_array(void);
char **basic_ls_array(flags_t *flag, char **array);

char *my_strcpy(char *dest, char const *src);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_arraylen(char **array);

#endif
