/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** text.c
*/

#include "../../include/my.h"

bool create_text_score(game_t *game)
{
    sfVector2f position = {359.0, 0.0};

    game->score_text = sfText_create();
    if (!game->score_text)
        return false;
    game->font = sfFont_createFromFile("assets/font/BRLNSDB.TTF");
    if (!game->font)
        return false;
    game->score_text_str = malloc(sizeof(char) * 32);
    if (!game->score_text_str)
        return false;
    sfText_setFont(game->score_text, game->font);
    sfText_setCharacterSize(game->score_text, 25);
    sfText_setPosition(game->score_text, position);
    return true;
}
