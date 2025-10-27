/*
** EPITECH PROJECT, 2025
** G-PSU-100-LYN-1-1-myls-7
** File description:
** my_ls.c
*/

#include "../include/my.h"

static int dir_len(void)
{
    int array_len = 0;
    char **array;
    int str_len = 0;
    struct dirent *entry;
    DIR *dir_stream = opendir(".");

    if (dir_stream == NULL) {
        perror("my_ls: cannot open directory");
        return 84;
    }
    entry = readdir(dir_stream);
    while (entry != NULL) {
        array_len++;
        entry = readdir(dir_stream);
    }
    closedir(dir_stream);
    return array_len;
}

static char **dir_to_array(int array_len, int str_len)
{
    char **array;
    struct dirent *entry;
    DIR *dir_stream = opendir(".");

    dir_stream = opendir(".");
    array = malloc(sizeof(char *) * (array_len + 1));
    if (dir_stream == NULL) {
        perror("my_ls: cannot open directory");
        return NULL;
    }
    entry = readdir(dir_stream);
    for (int i = 0; entry != NULL; i++) {
        str_len = my_strlen(entry->d_name);
        array[i] = malloc(sizeof(char) * (str_len + 1));
        my_strcpy(array[i], entry->d_name);
        entry = readdir(dir_stream);
    }
    array[array_len] = NULL;
    closedir(dir_stream);
    return array;
}

static char **sort_array(char **array, int len_array)
{
    int j = 0;
    char *elem;

    for (int i = 1; i < len_array; i++) {
        elem = array[i];
        j = i - 1;
        while (j >= 0 && my_strcmp(array[j], elem) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = elem;
    }
    return array;
}

char **handle_array(void)
{
    int array_len = dir_len();
    char **array = dir_to_array(array_len, 0);

    return sort_array(array, array_len);
}
