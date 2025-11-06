/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** l_ls.c
*/

#include "../include/my.h"

static int put_maj_min_int_size(char *maj, char *min,
    file_data_t *file_data)
{
    int i = 0;
    int len_maj = my_strlen(maj);
    int len_min = my_strlen(min);

    for (i = 0; maj[i] != '\0'; i++)
        file_data->size[i] = maj[i];
    file_data->size[len_maj] = ',';
    file_data->size[len_maj + 1] = ' ';
    i += 2;
    for (int j = 0; min[j] != '\0'; j++) {
        file_data->size[i] = min[j];
        i++;
    }
    return i;
}

static void size_or_maj_min(char *maj, char *min, struct stat *file_stats,
    file_data_t *file_data)
{
    int total_size = 0;
    int len_maj = my_strlen(maj);
    int len_min = my_strlen(min);

    if (S_ISCHR(file_stats->st_mode) || S_ISBLK(file_stats->st_mode)) {
        file_data->size = malloc(sizeof(char) * (len_maj + 2 + len_min + 1));
        if (file_data->size == NULL)
            return;
        total_size = put_maj_min_int_size(maj, min, file_data);
        file_data->size[total_size] = '\0';
        free(maj);
        free(min);
    } else {
        file_data->size = off_t_to_str(file_stats->st_size);
        free(maj);
        free(min);
    }
}

void assign_stats(file_data_t *file_data,
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
    size_or_maj_min(unsigned_int_to_str(gnu_dev_major(file_stats->st_rdev)),
        unsigned_int_to_str(gnu_dev_minor(file_stats->st_rdev)), file_stats,
        file_data);
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

char ***basic_array(flags_t *flag, char ***array)
{
    char ***result_array;

    if (flag->a_flags)
        return array_with_padding(array);
    result_array = create_result_array(array);
    return array_with_padding(result_array);
}
