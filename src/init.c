/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** init.c
*/

#include "../include/my.h"

static void init_duck(game_t *game)
{
    game->duck_struct = malloc(sizeof(game->duck_struct));
    game->duck_struct->duck_sprite = NULL;
    game->duck_struct->duck_texture = NULL;
    game->duck_struct->duck_speed = 0.5;
    game->duck_struct->duck_pos.x = 0.0;
    game->duck_struct->duck_pos.y = 0.0;
    game->duck_struct->duck_rect.height = 0;
    game->duck_struct->duck_rect.width = 0;
    game->duck_struct->duck_rect.left = 0;
    game->duck_struct->duck_rect.top = 0;
}

static void init_btn(game_t *game)
{
    game->start_btn_sprite = NULL;
    game->start_btn_texture = NULL;
    game->restart_btn_sprite = NULL;
    game->restart_btn_texture = NULL;
    game->exit_btn_sprite = NULL;
    game->exit_btn_texture = NULL;
}

static void init_general(game_t *game)
{
    game->state = START_MENU;
    game->window = NULL;
    game->background_sprite = NULL;
    game->background_texture = NULL;
    game->clock = NULL;
    game->score = 0;
    game->cursor_sprite = NULL;
    game->cursor_texture = NULL;
}

static void init_input(game_t *game)
{
    game->mouse_pos.x = 0;
    game->mouse_pos.y = 0;
    game->mouse_clicked = false;
    game->escape_clicked = false;
}

static void init_text(game_t *game)
{
    game->score_text = NULL;
    game->font = NULL;
    game->score_text_str = NULL;
}

static void init_sound(game_t *game)
{
    game->pop_sound_buffer = NULL;
    game->pop_sound = NULL;
    game->music = NULL;
}

void init(game_t *game)
{
    init_duck(game);
    init_btn(game);
    init_general(game);
    init_input(game);
    init_text(game);
    init_sound(game);
}
