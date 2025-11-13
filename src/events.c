/*
** EPITECH PROJECT, 2025
** GraphicalC
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
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        game->mouse_clicked = true;
    }
}

static void keyboard_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->state == PLAYING) {
        game->state = PAUSED;
        game->escape_clicked = true;
    }
    // if (game->escape_clicked && sfKeyboard_isKeyPressed(sfKeyEscape)) {
    //     game->state = PLAYING;
    //     game->escape_clicked = false;
    // }
}

void manage_events(game_t *game)
{
    sfEvent event;

    game->mouse_clicked = false;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        keyboard_event(game);
        close_window(game, event);
        get_mouse_click_pos(game, event);
    }
}
