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

static sfVector2i get_mouse_click_pos(game_t *game, sfEvent event)
{
    sfVector2i mouse_pos;

    mouse_pos.x = 0;
    mouse_pos.y = 0;
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        return mouse_pos;
    }
    return mouse_pos;
}

static void duck_pos(game_t *game, sfEvent event)
{
    sfVector2f duck_pos;
    sfVector2i mouse_pos = get_mouse_click_pos(game, event);

    duck_pos = sfSprite_getPosition(game->duck_sprite);
    printf("%f %f\n", duck_pos.x, duck_pos.y);
    printf("%d %d\n", mouse_pos.x, mouse_pos.y);
    if (mouse_pos.x >= duck_pos.x
        && mouse_pos.x <= duck_pos.x + DUCK_WIDTH / DUCK_STATES
        && mouse_pos.y >= duck_pos.y
        && mouse_pos.y <= duck_pos.y + DUCK_HEIGHT)
        destroy_duck(game);
}

void manage_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(game, event);
        get_mouse_click_pos(game, event);
        duck_pos(game, event);
    }
}
