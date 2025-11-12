/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** init.c
*/

#include "../include/my.h"

static void init_duck(game_t *game)
{
    game->duck_sprite = NULL;
    game->duck_texture = NULL;
    game->duck_speed = 0.5;
    game->duck_pos.x = 0.0;
    game->duck_pos.y = 0.0;
    game->duck_rect.height = 0;
    game->duck_rect.width = 0;
    game->duck_rect.left = 0;
    game->duck_rect.top = 0;
}

static void init_btn(game_t *game)
{
    game->btn_rect.start.height = 0;
    game->btn_rect.start.width = 0;
    game->btn_rect.start.left = 0;
    game->btn_rect.start.top = 0;
}

static void init_general(game_t *game)
{
    game->state = START_MENU;
    game->window = NULL;
    game->background_texture = NULL;
    game->background_sprite = NULL;
    game->clock = NULL;
    game->score = 0;
}

static void init_mouse(game_t *game)
{
    game->mouse_pos.x = 0;
    game->mouse_pos.y = 0;
    game->mouse_clicked = false;
}

void init(game_t *game)
{
    init_duck(game);
    init_btn(game);
    init_general(game);
    init_mouse(game);
}
