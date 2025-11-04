// /*
// ** EPITECH PROJECT, 2025
// ** G-PSU-100-LYN-1-1-myls-7
// ** File description:
// ** d.c
// */

// #include "../include/my.h"

// static char **my_strdup_tab(char **tab)
// {
//     int count = 0;
//     char **new_tab;

//     while (tab[count] != NULL)
//         count++;
//     new_tab = malloc(sizeof(char *) * (count + 1));
//     if (!new_tab)
//         return NULL;
//     for (int i = 0; i < count; i++)
//         new_tab[i] = my_strdup(tab[i]);
//     new_tab[count] = NULL;
//     return new_tab;
// }

// char ***handle_d(char ***array, has_file_flag_t *has_file_flag)
// {
//     char ***n_array = malloc(sizeof(char **) * (has_file_flag->nbr_file + 1));
//     int j = 0;

//     if (!n_array)
//         return NULL;
//     for (int k = 0; has_file_flag->path[k] != NULL; k++) {
//         for (int i = 0; array[i] != NULL; i++) {
//             if (my_strcmp(array[i][6], has_file_flag->path[k]) == 0) {
//                 n_array[j] = my_strdup_tab(array[i]);
//                 j++;
//                 break;
//             }
//         }
//     }
//     n_array[j] = NULL;
//     return n_array;
// }
