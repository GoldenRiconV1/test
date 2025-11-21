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

    game->s->score_text = sfText_create();
    if (!game->s->score_text)
        return false;
    game->s->font = sfFont_createFromFile("assets/font/BRLNSDB.TTF");
    if (!game->s->font)
        return false;
    game->s->score_text_str = malloc(sizeof(char) * 32);
    if (!game->s->score_text_str)
        return false;
    sfText_setFont(game->s->score_text, game->s->font);
    sfText_setCharacterSize(game->s->score_text, 25);
    sfText_setPosition(game->s->score_text, position);
    return true;
}
