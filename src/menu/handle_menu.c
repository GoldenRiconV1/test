/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_menu.c
*/

#include "../../include/my.h"

void handle_menu(game_t *game)
{
    if (game->state == START_MENU) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        start_menu(game);
    }
    if (game->state == PAUSED) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        pause_menu(game);
    }
    if (game->state == LOOSE) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        loose_menu(game);
    }
    if (game->state == PLAYING)
        handle_play(game);
}
