/*
** EPITECH PROJECT, 2025
** bootstrap csfml killian
** File description:
** create.c
*/

#include "../include/my.h"

static bool create_window(game_t *game)
{
    sfVideoMode mode = {800, 600, 32};

    game->window = sfRenderWindow_create(mode, "MoneyRush", sfDefaultStyle,
        NULL);
    if (!game->window)
        return false;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return true;
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    init(game);
    if (!create_background(game) || !create_duck(game) ||
        !create_window(game) || !create_clock(game))
        return NULL;
    return game;
}
