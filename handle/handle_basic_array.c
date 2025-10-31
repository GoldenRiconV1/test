/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_l_array.c
*/

#include "../include/my.h"

char **create_l_array(file_data_t *file_data)
{
    char **array;

    array = malloc(sizeof(char *) * 8);
    array[0] = file_data->type_perm;
    array[1] = file_data->hard_link;
    array[2] = file_data->user_name;
    array[3] = file_data->group_name;
    array[4] = file_data->size;
    array[5] = file_data->time;
    array[6] = file_data->name;
    array[7] = NULL;
    return array;
}

static char **process_entry(struct dirent *entry, file_data_t *file_data,
    flags_t *flag)
{
    struct stat file_stats;

    if (entry->d_name[0] != '.' || flag->a_flags == 1) {
        if (stat(entry->d_name, &file_stats) == 0)
            file_data->blocks += file_stats.st_blocks;
    }
    get_file_info(entry, file_data);
    return create_l_array(file_data);
}

static char ***dir_to_l_array(file_data_t *file_data,
    int array_len, flags_t *flag, has_file_flag_t *has_file_flag)
{
    char ***array;
    struct dirent *entry;
    DIR *dir_stream = opendir(has_file_flag->path);

    array = malloc(sizeof(char **) * (array_len + 1));
    if (dir_stream == NULL || array == NULL) {
        perror("my_ls: cannot open directory or allocate memory");
        return NULL;
    }
    entry = readdir(dir_stream);
    for (int i = 0; entry != NULL && i < array_len; i++) {
        array[i] = process_entry(entry, file_data, flag);
        entry = readdir(dir_stream);
    }
    array[array_len] = NULL;
    closedir(dir_stream);
    return array;
}

char ***sort_l_array(char ***array, int len_array)
{
    int j;
    char **elem;

    for (int i = 1; i < len_array; i++) {
        elem = array[i];
        j = i - 1;
        while (j >= 0 && my_strcmp(array[j][6], elem[6]) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = elem;
    }
    return array;
}

char ***handle_basic_array(file_data_t *file_data, flags_t *flag,
    has_file_flag_t *has_file_flag)
{
    int array_len = dir_len();
    char ***array;

    array = dir_to_l_array(file_data, array_len, flag, has_file_flag);
    return sort_l_array(array, array_len);
}
