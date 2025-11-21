/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** pause.c
*/

#include "../../include/my.h"

static void check_for_print(game_t *game)
{
    if (game->d->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->d->duck_sprite, NULL);
    if (game->btn->restart_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->btn->restart_btn_sprite, NULL);
    if (game->btn->start_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->btn->start_btn_sprite, NULL);
    if (game->btn->exit_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->btn->exit_btn_sprite, NULL);
}

void pause_menu(game_t *game)
{
    sfVector2f restart_btn_pos = {281.0, 257.0};
    sfVector2f restart_btn_pos_origin = {281.0, 107.0};
    sfVector2f exit_btn_pos = {281.0, 407.0};
    sfVector2f exit_btn_pos_origin = {281.0, 257.0};

    sfSprite_setPosition(game->btn->restart_btn_sprite, restart_btn_pos);
    sfSprite_setPosition(game->btn->exit_btn_sprite, exit_btn_pos);
    check_for_print(game);
    check_click_btn(game);
    sfSprite_setPosition(game->btn->restart_btn_sprite, restart_btn_pos_origin);
    sfSprite_setPosition(game->btn->exit_btn_sprite, exit_btn_pos_origin);
}
