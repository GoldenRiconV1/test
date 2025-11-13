/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** pause.c
*/

#include "../../include/my.h"

void pause_menu(game_t *game)
{
    sfVector2f offset = {281.0, 257.0};

    // sfRenderWindow_drawSprite(game->window, game->restart_btn_sprite, NULL);
    // sfSprite_move(game->start_btn_sprite, offset);
    sfRenderWindow_drawSprite(game->window, game->start_btn_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->exit_btn_sprite, NULL);
    check_click_btn(game);
}
