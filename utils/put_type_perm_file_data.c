/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** put_type_perm_file_data.c
*/

#include "../include/my.h"

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
    if (mode & S_ISVTX)
        return (mode & S_IXOTH) ? 't' : 'T';
    return (mode & S_IXOTH) ? 'x' : '-';
}

char *put_type_perm_file_data(file_data_t *file_data,
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
