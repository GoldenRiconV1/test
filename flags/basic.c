/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** l_ls.c
*/

#include "../include/my.h"
#include <pwd.h>
#include <grp.h>

static char get_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        return '-';
    if (S_ISDIR(mode))
        return 'd';
    if (S_ISLNK(mode))
        return 'l';
    if (S_ISBLK(mode))
        return 'b';
    if (S_ISCHR(mode))
        return 'c';
    if (S_ISFIFO(mode))
        return 'p';
    if (S_ISSOCK(mode))
        return 's';
    return '\0';
}

static char get_user_perm(mode_t mode)
{
    if (mode & S_ISUID)
        return (mode & S_IXUSR) ? 's' : 'S';
    return (mode & S_IXUSR) ? 'x' : '-';
}

static char get_grp_perm(mode_t mode)
{
    if (mode & S_ISGID)
        return (mode & S_IXGRP) ? 's' : 'S';
    return (mode & S_IXGRP) ? 'x' : '-';
}

static char get_other_perm(mode_t mode)
{
    if (mode & __S_ISVTX)
        return (mode & S_IXOTH) ? 's' : 'S';
    return (mode & S_IXOTH) ? 'x' : '-';
}

static char *put_type_perm_file_data(file_data_t *file_data,
    struct stat *file_stats)
{
    file_data->type_perm = malloc(sizeof(char) * 11);
    file_data->type_perm[0] = get_file_type(file_stats->st_mode);
    file_data->type_perm[1] = (file_stats->st_mode & S_IRUSR) ? 'r' : '-';
    file_data->type_perm[2] = (file_stats->st_mode & S_IWUSR) ? 'w' : '-';
    file_data->type_perm[3] = get_user_perm(file_stats->st_mode);
    file_data->type_perm[4] = (file_stats->st_mode & S_IRGRP) ? 'r' : '-';
    file_data->type_perm[5] = (file_stats->st_mode & S_IWGRP) ? 'w' : '-';
    file_data->type_perm[6] = get_grp_perm(file_stats->st_mode);
    file_data->type_perm[7] = (file_stats->st_mode & S_IROTH) ? 'r' : '-';
    file_data->type_perm[8] = (file_stats->st_mode & S_IWOTH) ? 'w' : '-';
    file_data->type_perm[9] = get_other_perm(file_stats->st_mode);
    file_data->type_perm[10] = '\0';
    return file_data->type_perm;
}

static void assign_stats(file_data_t *file_data,
    struct stat *file_stats)
{
    struct passwd *user = getpwuid(file_stats->st_uid);
    struct group *grp = getgrgid(file_stats->st_gid);

    if (user != NULL)
        file_data->user_name = my_strdup(user->pw_name);
    else
        file_data->user_name = unsigned_int_to_str(file_stats->st_uid);
    if (grp != NULL)
        file_data->group_name = my_strdup(grp->gr_name);
    else
        file_data->group_name = unsigned_int_to_str(file_stats->st_gid);
    file_data->hard_link = nlink_t_to_str(file_stats->st_nlink);
    file_data->size = off_t_to_str(file_stats->st_size);
    file_data->time = time_t_to_str(file_stats->st_mtime);
}

void get_file_info(struct dirent *entry, file_data_t *file_data,
    const char *base_path)
{
    struct stat file_stats;
    char *fp = malloc(my_strlen(base_path) + my_strlen(entry->d_name) + 2);

    if (fp == NULL)
        return;
    my_strcpy(fp, base_path);
    if (base_path[my_strlen(base_path) - 1] != '/')
        my_strcat(fp, "/");
    my_strcat(fp, entry->d_name);
    if (stat(fp, &file_stats) == -1) {
        put_default_data(file_data, entry->d_name);
        perror("my_ls");
        free(fp);
        return;
    }
    free(fp);
    file_data->name = my_strdup(entry->d_name);
    put_type_perm_file_data(file_data, &file_stats);
    assign_stats(file_data, &file_stats);
}

static char ***apply_padding(char ***array, int len_size_m, int count)
{
    char **buf;

    buf = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        buf[i] = malloc(sizeof(char) * (len_size_m + 1));
        if (!buf[i])
            return NULL;
        for (int j = 0; j < (len_size_m - my_strlen(array[i][4])); j++)
            buf[i][j] = ' ';
        for (int j = 0; j < my_strlen(array[i][4]); j++)
            buf[i][(len_size_m - my_strlen(array[i][4])) + j] = array[i][4][j];
        buf[i][len_size_m] = '\0';
        free(array[i][4]);
        array[i][4] = buf[i];
    }
    free(buf);
    return array;
}

static char ***array_with_padding(char ***array)
{
    int len_size_m = 0;
    int temps = 0;
    int count = 0;

    for (count = 0; array[count] != NULL; count++) {
        temps = my_strlen(array[count][4]);
        if (temps > len_size_m) {
            len_size_m = temps;
        }
    }
    return apply_padding(array, len_size_m, count);
}

char ***basic_array(flags_t *flag, has_file_flag_t *has_file_flag,
    char ***array)
{
    char ***result_array;

    if (flag->a_flags) {
        return array_with_padding(array);
    }
    result_array = create_result_array(array, has_file_flag);
    return array_with_padding(result_array);
}
