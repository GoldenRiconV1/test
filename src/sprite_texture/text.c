/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** text.c
*/

#include "../../include/my.h"

bool create_text(game_t *game)
{
    game->score_text = sfText_create();
    if (!game->score_text)
        return false;
    game->font = sfFont_createFromFile("../../assets/font/BRLNSDB.TTF");
    if (!game->font)
        return false;
    sfText_setString(game->score_text, "const char *string");
    sfText_setFont(game->score_text, game->font);
    sfText_setCharacterSize(game->score_text, 50);
    return true;
}
