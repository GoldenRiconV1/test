/*
** EPITECH PROJECT, 2025
** bootstrap csfml killian
** File description:
** game.c
*/

#include "../include/my.h"

float get_elapsed_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;

    return seconds;
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        manage_events(game);
        sfRenderWindow_drawSprite(game->window, game->background_sprite, NULL);
        if (game->start_btn_sprite != NULL) {
            sfRenderWindow_drawSprite(game->window, game->start_btn_sprite, NULL);
        }
        if (game->duck_sprite != NULL)
            sfRenderWindow_drawSprite(game->window, game->duck_sprite, NULL);
        sfRenderWindow_display(game->window);
        handle_duck(game);
    }
}
