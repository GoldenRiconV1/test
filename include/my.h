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
    #include <sys/stat.h>
    #include <stdarg.h>

typedef struct has_file_flag_s {
    int has_flags_and_files;
    int has_file;
    int has_flags;
} has_file_flag_t;

typedef struct file_s {
    char *name;
    char type;
    int inode;
    int hard_link;
    int size;
    int allocated_space;
    int *minor;
    int *major;
    int uid;
    int gid;
} file_t;

typedef struct flags_s {
    int a_flags;
    int l_flags;
    int R_flags;
    int d_flags;
    int t_flags;
} flags_t;

void parser(int argc, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag);
void flags_asigment(flags_t *flag,
    has_file_flag_t *has_file_flag);
char **handle_array(void);
char **basic_ls_array(flags_t *flag, char **array);
void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag, char **array);

int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_arraylen(char **array);
int lexicographic_cmp(const char *a, const char *b);
int char_to_lower(char c);

#endif
