/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_play.c
*/

#include "../../include/my.h"

void handle_play(game_t *game)
{
    if (game->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->duck_sprite, NULL);
    handle_duck(game);
}
