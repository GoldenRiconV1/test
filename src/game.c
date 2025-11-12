/*
** EPITECH PROJECT, 2025
** GraphicalC
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
        if (game->state != PLAYING)
            handle_menu(game);
        else
            handle_play(game);
        sfRenderWindow_display(game->window);
    }
}
