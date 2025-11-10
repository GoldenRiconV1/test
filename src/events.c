/*
** EPITECH PROJECT, 2025
** bootstrap csfml killian
** File description:
** events.c
*/

#include "../include/my.h"

static void close_window(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}

static void get_mouse_click_pos(game_t *game, sfEvent event)
{
    game->mouse_pos.x = 0;
    game->mouse_pos.y = 0;
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft)
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
}

static void get_duck_pos(game_t *game)
{
    if (game->duck_sprite == NULL)
        return;
    game->duck_pos = sfSprite_getPosition(game->duck_sprite);
}

void manage_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(game, event);
        get_mouse_click_pos(game, event);
        get_duck_pos(game);
    }
}
