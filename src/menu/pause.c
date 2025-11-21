/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** pause.c
*/

#include "../../include/my.h"

void pause_menu(game_t *game)
{
    sfVector2f restart_btn_pos = {281.0, 257.0};
    sfVector2f restart_btn_pos_origin = {281.0, 107.0};
    sfVector2f exit_btn_pos = {281.0, 407.0};
    sfVector2f exit_btn_pos_origin = {281.0, 257.0};

    sfSprite_setPosition(game->restart_btn_sprite, restart_btn_pos);
    sfSprite_setPosition(game->exit_btn_sprite, exit_btn_pos);
    if (game->duck_struct->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->duck_struct->duck_sprite, NULL);
    if (game->restart_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->restart_btn_sprite, NULL);
    if (game->start_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->start_btn_sprite, NULL);
    if (game->exit_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->exit_btn_sprite, NULL);
    check_click_btn(game);
    sfSprite_setPosition(game->restart_btn_sprite, restart_btn_pos_origin);
    sfSprite_setPosition(game->exit_btn_sprite, exit_btn_pos_origin);
}
