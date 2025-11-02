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
    #include <time.h>
    #include <sys/types.h>

typedef struct has_file_flag_s {
    int has_flags_and_files;
    int nbr_file;
    int has_flags;
    int has_file;
    char **path;
} has_file_flag_t;

typedef struct file_data_s {
    char *name;
    char *type_perm;
    char *hard_link;
    char *user_name;
    char *group_name;
    char *size;
    char *time;
} file_data_t;

typedef struct flags_s {
    int a_flags;
    int l_flags;
    int R_flags;
    int d_flags;
    int t_flags;
    int blocks;
} flags_t;

void parser(int argc, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag);
void assign_stats(file_data_t *file_data, struct stat *file_stats);
char ***handle_file_args(has_file_flag_t *has_file_flag,
    file_data_t *file_data);
void structs_assignment(flags_t *flag, has_file_flag_t *has_file_flag);
char ***handle_basic_array(file_data_t *file_data, flags_t *flag,
    has_file_flag_t *has_file_flag);
char ***basic_array(flags_t *flag, has_file_flag_t *has_file_flag,
    char ***array);
void handle_flags(flags_t *flag, has_file_flag_t *has_file_flag,
    file_data_t *file_data, char ***array);
void get_file_info(struct dirent *entry, file_data_t *file_data,
    const char *base_path);
char ***handle_t(char ***array, int array_len);
char ***handle_d(char ***array, has_file_flag_t *has_file_flag);
char *put_type_perm_file_data(file_data_t *file_data,
    struct stat *file_stats);

char **create_l_array(file_data_t *file_data);
char ***create_result_array(char ***array, has_file_flag_t *has_file_flag);
int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_arraylen(char ***array);
int char_to_lower(char c);
void print_array(char **array);
char *time_t_to_str(off_t time);
char *nlink_t_to_str(nlink_t link_count);
char *off_t_to_str(off_t value);
int dir_len(has_file_flag_t *has_file_flag);
char *my_strcat(char *dest, char const *src);
void my_free(char ***array, has_file_flag_t *has_file_flag);
char *unsigned_int_to_str(int n);
char *my_revstr(char *str);
char *my_strdup(const char *str);
void put_default_data(file_data_t *file_data, char *d_name);

#endif
