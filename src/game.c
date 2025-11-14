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

static void get_duck_pos(game_t *game)
{
    if (game->duck_sprite == NULL)
        return;
    game->duck_pos = sfSprite_getPosition(game->duck_sprite);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        manage_events(game);
        get_duck_pos(game);
        sfRenderWindow_drawSprite(game->window, game->background_sprite, NULL);
        if (game->state != PLAYING)
            handle_menu(game);
        else
            handle_play(game);
        sfRenderWindow_display(game->window);
    }
}
