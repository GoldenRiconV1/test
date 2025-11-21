/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** start.c
*/

#include "../../include/my.h"

void start_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->btn->start_btn_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->btn->exit_btn_sprite, NULL);
    check_click_btn(game);
    reset_duck(game);
}
