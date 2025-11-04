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

typedef struct sorted_args_s {
    has_file_flag_t files;
    has_file_flag_t dirs;
} sorted_args_t;

void parser(int argc, char **argv, flags_t *flag,
    has_file_flag_t *has_file_flag);
void assign_stats(file_data_t *file_data, struct stat *file_stats);
char ***handle_file_args(has_file_flag_t *has_file_flag,
    file_data_t *file_data);
void structs_assignment(flags_t *flag, has_file_flag_t *has_file_flag);
char ***handle_basic_array(file_data_t *file_data, flags_t *flag,
    char *path, int *error_status);
char ***basic_array(flags_t *flag, char ***array);
void handle_flags(flags_t *flag, char ***array);
void get_file_info(struct dirent *entry, file_data_t *file_data,
    const char *base_path);
char ***handle_t(char ***array, int array_len);
char ***handle_d(char ***array, has_file_flag_t *has_file_flag);
void handle_r_upcase(flags_t *flag, char ***array, const char *base_path,
    int *error_status);
void list_directory(flags_t *flag, char *path, int *error_status);
char *put_type_perm_file_data(file_data_t *file_data,
    struct stat *file_stats);
void sort_arguments(has_file_flag_t *all_args, sorted_args_t *s_args,
    flags_t *flags, int *error_status);
void my_ls(flags_t *flags, has_file_flag_t *all_args,
    sorted_args_t *sorted_args, int *error_status);
void free_program_data(has_file_flag_t *all_args, sorted_args_t *sorted_args);
void free_array_content(char ***array);

char **create_l_array(file_data_t *file_data);
char ***create_result_array(char ***array);
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
int dir_len(const char *path, int *error_status);
char *my_strcat(char *dest, char const *src);
char *unsigned_int_to_str(int n);
char *my_revstr(char *str);
char *my_strdup(const char *str);
void put_default_data(file_data_t *file_data, char *d_name);

#endif
