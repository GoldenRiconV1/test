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
    if (game->d->duck_sprite == NULL)
        return;
    game->d->duck_pos = sfSprite_getPosition(game->d->duck_sprite);
}

void game_loop(game_t *game)
{
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    while (sfRenderWindow_isOpen(game->window)) {
        game->m->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        manage_events(game);
        get_duck_pos(game);
        sfRenderWindow_drawSprite(game->window, game->background_sprite, NULL);
        handle_menu(game);
        sfRenderWindow_display(game->window);
    }
}
