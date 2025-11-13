/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** check_click_btn.c
*/

#include "../../include/my.h"

void check_click_btn(game_t *game)
{
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
