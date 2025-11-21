/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15 [WSL: Ubuntu-24.04]
** File description:
** my_format_score.c
*/

#include "../../include/my.h"

void my_format_score(char *dest, int score)
{
    char *score_str;
    char *prefix = "Score : ";
    int i = 0;

    my_strcpy(dest, prefix);
    while (dest[i])
        i++;
    score_str = unsigned_int_to_str((unsigned int)score);
    if (score_str == NULL)
        return;
    my_strcpy(dest + i, score_str);
    free(score_str);
}
