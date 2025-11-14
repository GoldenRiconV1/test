/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** loose.c
*/

#include "../../include/my.h"

void loose_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->restart_btn_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->exit_btn_sprite, NULL);
    check_click_btn(game);
}
