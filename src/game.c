/*
** EPITECH PROJECT, 2025
** bootstrap csfml killian
** File description:
** game.c
*/

#include "../include/my.h"

static float get_elapsed_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;

    return seconds;
}

static void refresh_duck_sprite(game_t *game)
{
    float seconds = get_elapsed_time(game);

    if (seconds >= REFRESH_SECONDS) {
        game->duck_rect.left += DUCK_WIDTH / DUCK_STATES;
        if (game->duck_rect.left >= DUCK_WIDTH)
            game->duck_rect.left = 0;
        sfSprite_setTextureRect(game->duck_sprite, game->duck_rect);
        sfClock_restart(game->clock);
    }
}

static void move_duck(game_t *game)
{
    sfVector2f offset;

    offset.x = 0.5;
    offset.y = 0.0;
    sfSprite_move(game->duck_sprite, offset);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        manage_events(game);
        sfRenderWindow_clear(game->window, sfRed);
        sfRenderWindow_drawSprite(game->window, game->background_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->duck_sprite, NULL);
        sfRenderWindow_display(game->window);
        get_elapsed_time(game);
        refresh_duck_sprite(game);
        move_duck(game);
    }
}
