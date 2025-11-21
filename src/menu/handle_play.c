/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_play.c
*/

#include "../../include/my.h"

void handle_play(game_t *game)
{
    my_format_score(game->score_text_str, game->score);
    if (game->score_text != NULL) {
        sfText_setString(game->score_text, game->score_text_str);
        sfRenderWindow_drawText(game->window, game->score_text, NULL);
    }
    handle_cursor(game);
    if (game->duck_struct->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->duck_struct->duck_sprite,
            NULL);
    handle_duck(game);
    if (game->cursor_sprite != NULL) {
        sfRenderWindow_drawSprite(game->window, game->cursor_sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
}
