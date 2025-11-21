/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** destroy.c
*/

#include "../include/my.h"

static void destroy_general(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
    if (game->background_texture)
        sfTexture_destroy(game->background_texture);
    if (game->background_sprite)
        sfSprite_destroy(game->background_sprite);
    if (game->clock)
        sfClock_destroy(game->clock);
    if (game->m->cursor_sprite)
        sfSprite_destroy(game->m->cursor_sprite);
    if (game->m->cursor_texture)
        sfTexture_destroy(game->m->cursor_texture);
}

void static destroy_duck(game_t *game)
{
    if (game->d->duck_sprite) {
        sfSprite_destroy(game->d->duck_sprite);
        game->d->duck_sprite = NULL;
    }
    if (game->d->duck_texture) {
        sfTexture_destroy(game->d->duck_texture);
        game->d->duck_texture = NULL;
    }
}

static void destroy_start_btn(game_t *game)
{
    if (game->btn->start_btn_sprite) {
        sfSprite_destroy(game->btn->start_btn_sprite);
        game->btn->start_btn_sprite = NULL;
    }
    if (game->btn->start_btn_texture) {
        sfTexture_destroy(game->btn->start_btn_texture);
        game->btn->start_btn_texture = NULL;
    }
}

static void destroy_restart_btn(game_t *game)
{
    if (game->btn->restart_btn_sprite) {
        sfSprite_destroy(game->btn->restart_btn_sprite);
        game->btn->restart_btn_sprite = NULL;
    }
    if (game->btn->restart_btn_texture) {
        sfTexture_destroy(game->btn->restart_btn_texture);
        game->btn->restart_btn_texture = NULL;
    }
}

static void destroy_exit_btn(game_t *game)
{
    if (game->btn->exit_btn_sprite) {
        sfSprite_destroy(game->btn->exit_btn_sprite);
        game->btn->exit_btn_sprite = NULL;
    }
    if (game->btn->exit_btn_texture) {
        sfTexture_destroy(game->btn->exit_btn_texture);
        game->btn->exit_btn_texture = NULL;
    }
}

static void destroy_btn(game_t *game)
{
    destroy_start_btn(game);
    destroy_restart_btn(game);
    destroy_exit_btn(game);
}

static void destroy_text(game_t *game)
{
    if (game->s->score_text) {
        sfText_destroy(game->s->score_text);
        game->s->score_text = NULL;
    }
    if (game->s->font) {
        sfFont_destroy(game->s->font);
        game->s->font = NULL;
    }
    if (game->s->score_text_str)
        free(game->s->score_text_str);
}

static void destroy_sound_music(game_t *game)
{
    if (game->pop_sound)
        sfSound_destroy(game->pop_sound);
    if (game->pop_sound_buffer)
        sfSoundBuffer_destroy(game->pop_sound_buffer);
    if (game->music)
        sfMusic_destroy(game->music);
}

static void free_all_struct(game_t *game)
{
    free(game->d);
    free(game->btn);
    free(game->m);
    free(game->s);
}

void destroy_game(game_t *game)
{
    destroy_general(game);
    destroy_duck(game);
    destroy_btn(game);
    destroy_text(game);
    destroy_sound_music(game);
    free_all_struct(game);
    free(game);
}
