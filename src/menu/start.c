/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** start.c
*/

#include "../../include/my.h"

void start_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->start_btn_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->exit_btn_sprite, NULL);
    if (game->mouse_clicked && game->mouse_pos.x >= 281
        && game->mouse_pos.x <= 518
        && game->mouse_pos.y >= 107
        && game->mouse_pos.y <= 193)
        game->state = PLAYING;
    if (game->mouse_clicked && game->mouse_pos.x >= 281
        && game->mouse_pos.x <= 518
        && game->mouse_pos.y >= 257
        && game->mouse_pos.y <= 343)
        sfRenderWindow_close(game->window);
}
