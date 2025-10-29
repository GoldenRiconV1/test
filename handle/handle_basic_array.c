/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** handle_basic_array.c
*/

#include "../include/my.h"

static char **dir_to_array(int array_len, int str_len)
{
    char **array;
    struct dirent *entry;
    DIR *dir_stream = opendir(".");

    array = malloc(sizeof(char *) * (array_len + 1));
    if (dir_stream == NULL) {
        perror("my_ls: cannot open directory");
        return NULL;
    }
    entry = readdir(dir_stream);
    for (int i = 0; entry != NULL; i++) {
        // get_file_info(entry);
        str_len = my_strlen(entry->d_name);
        array[i] = malloc(sizeof(char) * (str_len + 1));
        my_strcpy(array[i], entry->d_name);
        entry = readdir(dir_stream);
    }
    array[array_len] = NULL;
    closedir(dir_stream);
    return array;
}

static char **sort_basic_array(char **array, int len_array)
{
    int j = 0;
    char *elem;

    for (int i = 1; i < len_array; i++) {
        elem = array[i];
        j = i - 1;
        while (j >= 0 && lexicographic_cmp(array[j], elem) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = elem;
    }
    return array;
}

char **handle_basic_array(void)
{
    int array_len = dir_len();
    char **array = dir_to_array(array_len, 0);

    return sort_basic_array(array, array_len);
}
