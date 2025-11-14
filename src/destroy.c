/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** destroy.c
*/

#include "../include/my.h"

static void destroy_window(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
}

static void destroy_background(game_t *game)
{
    if (game->background_texture)
        sfTexture_destroy(game->background_texture);
    if (game->background_sprite)
        sfSprite_destroy(game->background_sprite);
}

void static destroy_duck(game_t *game)
{
    if (game->duck_sprite) {
        sfSprite_destroy(game->duck_sprite);
        game->duck_sprite = NULL;
    }
    if (game->duck_texture) {
        sfTexture_destroy(game->duck_texture);
        game->duck_texture = NULL;
    }
}

static void destroy_clock(game_t *game)
{
    if (game->clock)
        sfClock_destroy(game->clock);
}

static void destroy_start_btn(game_t *game)
{
    if (game->start_btn_sprite) {
        sfSprite_destroy(game->start_btn_sprite);
        game->start_btn_sprite = NULL;
    }
    if (game->start_btn_texture) {
        sfTexture_destroy(game->start_btn_texture);
        game->start_btn_texture = NULL;
    }
}

static void destroy_restart_btn(game_t *game)
{
    if (game->restart_btn_sprite) {
        sfSprite_destroy(game->restart_btn_sprite);
        game->restart_btn_sprite = NULL;
    }
    if (game->restart_btn_texture) {
        sfTexture_destroy(game->restart_btn_texture);
        game->restart_btn_texture = NULL;
    }
}

static void destroy_exit_btn(game_t *game)
{
    if (game->exit_btn_sprite) {
        sfSprite_destroy(game->exit_btn_sprite);
        game->exit_btn_sprite = NULL;
    }
    if (game->exit_btn_texture) {
        sfTexture_destroy(game->exit_btn_texture);
        game->exit_btn_texture = NULL;
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
    if (game->score_text) {
        sfText_destroy(game->score_text);
        game->score_text = NULL;
    }
    if (game->font) {
        sfFont_destroy(game->font);
        game->font = NULL;
    }
    if (game->score_text_str)
        free(game->score_text_str);
}

void destroy_game(game_t *game)
{
    destroy_window(game);
    destroy_background(game);
    destroy_duck(game);
    destroy_btn(game);
    destroy_clock(game);
    destroy_text(game);
    free(game);
}
