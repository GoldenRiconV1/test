/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** init.c
*/

#include "../include/my.h"

void init(game_t *game)
{
    game->window = NULL;
    game->background_texture = NULL;
    game->background_sprite = NULL;
    game->clock = NULL;
    game->duck_sprite = NULL;
    game->duck_texture = NULL;
    game->duck_speed = 0.5;
    game->duck_kill = 0;
    game->mouse_pos.x = 0;
    game->mouse_pos.y = 0;
    game->duck_pos.x = 0.0;
    game->duck_pos.y = 0.0;
}
