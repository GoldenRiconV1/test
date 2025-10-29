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

void get_file_info(struct dirent *entry, file_data_t *data)
{
    struct stat file_stats;
    file_data_t file_data;
    struct passwd *user_name;
    struct group *grp_name;
    char *perm_type;

    file_data.name = entry->d_name;
    stat(file_data.name, &file_stats);
    put_type_perm_file_data(&file_data, &file_stats);
    user_name = getpwuid(file_stats.st_uid);
    grp_name = getgrgid(file_stats.st_gid);
    file_data.user_name = user_name->pw_name;
    file_data.group_name = grp_name->gr_name;
    file_data.hard_link = nlink_t_to_str(file_stats.st_nlink);
    file_data.size = off_t_to_str(file_stats.st_size);
    file_data.time = time_t_to_str(file_stats.st_mtime);
    // printf("%s %s %s %s %s %s %s\n",
    //     file_data.type_perm, file_data.hard_link,
    //     file_data.user_name, file_data.group_name,
    //     file_data.size, file_data.time, file_data.name);
}

static char ***create_result_array(char ***array)
{
    int s_index = 0;
    char ***size_array;
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][6] != NULL && array[i][6][0] == '.')
            s_index++;
    }
    size_array = malloc(sizeof(char **) * (dir_len() - s_index + 1));
    if (size_array == NULL)
        return NULL;
    for (int i = 0; i < dir_len(); i++) {
        if (array[i][6] != NULL && array[i][6][0] != '.') {
            size_array[j] = array [i];
            j++;
        }
    }
    size_array[j] = NULL;
    return size_array;
}

char ***basic_ls_array(flags_t *flag, char ***array)
{
    char ***result_array;

    if (flag->a_flags) {
        return array;
    }
    result_array = create_result_array(array);
    return result_array;
}
