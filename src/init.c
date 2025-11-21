/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** init.c
*/

#include "../include/my.h"

static void malloc_struct(game_t *game)
{
    game->d = malloc(sizeof(duck_t));
    game->btn = malloc(sizeof(btn_t));
    game->m = malloc(sizeof(mouse_t));
    game->s = malloc(sizeof(score_t));
}

static void init_duck(game_t *game)
{
    game->d->duck_sprite = NULL;
    game->d->duck_texture = NULL;
    game->d->duck_speed = 0.5;
    game->d->duck_pos.x = 0.0;
    game->d->duck_pos.y = 0.0;
    game->d->duck_rect.height = 0;
    game->d->duck_rect.width = 0;
    game->d->duck_rect.left = 0;
    game->d->duck_rect.top = 0;
}

static void init_btn(game_t *game)
{
    game->btn->start_btn_sprite = NULL;
    game->btn->start_btn_texture = NULL;
    game->btn->restart_btn_sprite = NULL;
    game->btn->restart_btn_texture = NULL;
    game->btn->exit_btn_sprite = NULL;
    game->btn->exit_btn_texture = NULL;
}

static void init_general(game_t *game)
{
    game->state = START_MENU;
    game->window = NULL;
    game->background_sprite = NULL;
    game->background_texture = NULL;
    game->clock = NULL;
    game->s->score = 0;
    game->m->cursor_sprite = NULL;
    game->m->cursor_texture = NULL;
}

static void init_input(game_t *game)
{
    game->m->mouse_pos.x = 0;
    game->m->mouse_pos.y = 0;
    game->m->mouse_clicked = false;
    game->m->escape_clicked = false;
}

static void init_text(game_t *game)
{
    game->s->score_text = NULL;
    game->s->font = NULL;
    game->s->score_text_str = NULL;
}

static void init_sound(game_t *game)
{
    game->pop_sound_buffer = NULL;
    game->pop_sound = NULL;
    game->music = NULL;
}

void init(game_t *game)
{
    malloc_struct(game);
    init_duck(game);
    init_btn(game);
    init_general(game);
    init_input(game);
    init_text(game);
    init_sound(game);
}
