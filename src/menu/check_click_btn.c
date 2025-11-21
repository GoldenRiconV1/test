/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** check_click_btn.c
*/

#include "../../include/my.h"

static void start_loose_check(game_t *game)
{
    if (game->m->mouse_clicked && game->m->mouse_pos.x >= 281
        && game->m->mouse_pos.x <= 518
        && game->m->mouse_pos.y >= 107
        && game->m->mouse_pos.y <= 193
        && (game->state == START_MENU || game->state == LOOSE))
        game->state = PLAYING;
    if (game->m->mouse_clicked && game->m->mouse_pos.x >= 281
        && game->m->mouse_pos.x <= 518
        && game->m->mouse_pos.y >= 257
        && game->m->mouse_pos.y <= 343
        && (game->state == START_MENU || game->state == LOOSE))
        sfRenderWindow_close(game->window);
}

static void start_btn(game_t *game)
{
    if (game->m->mouse_clicked && game->m->mouse_pos.x >= 281
        && game->m->mouse_pos.x <= 518
        && game->m->mouse_pos.y >= 107
        && game->m->mouse_pos.y <= 193
        && game->state == PAUSED)
        game->state = PLAYING;
}

static void restart_btn(game_t *game)
{
    if (game->m->mouse_clicked && game->m->mouse_pos.x >= 281
        && game->m->mouse_pos.x <= 518
        && game->m->mouse_pos.y >= 257
        && game->m->mouse_pos.y <= 343
        && game->state == PAUSED) {
        reset_duck(game);
        game->s->score = 0;
        game->state = PLAYING;
    }
}

static void exit_btn(game_t *game)
{
    if (game->m->mouse_clicked && game->m->mouse_pos.x >= 281
        && game->m->mouse_pos.x <= 518
        && game->m->mouse_pos.y >= 407
        && game->m->mouse_pos.y <= 493
        && game->state == PAUSED)
        sfRenderWindow_close(game->window);
}

void check_click_btn(game_t *game)
{
    start_btn(game);
    restart_btn(game);
    exit_btn(game);
    start_loose_check(game);
}
