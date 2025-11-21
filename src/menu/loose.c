/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** loose.c
*/

#include "../../include/my.h"

void loose_menu(game_t *game)
{
    if (game->btn->restart_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->btn->restart_btn_sprite, NULL);
    if (game->btn->exit_btn_sprite != NULL)
        sfRenderWindow_drawSprite(game->window,
            game->btn->exit_btn_sprite, NULL);
    check_click_btn(game);
}
