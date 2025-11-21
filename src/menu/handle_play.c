/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_play.c
*/

#include "../../include/my.h"

void handle_play(game_t *game)
{
    my_format_score(game->s->score_text_str, game->s->score);
    if (game->s->score_text != NULL) {
        sfText_setString(game->s->score_text, game->s->score_text_str);
        sfRenderWindow_drawText(game->window, game->s->score_text, NULL);
    }
    handle_cursor(game);
    if (game->d->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->d->duck_sprite,
            NULL);
    handle_duck(game);
    if (game->m->cursor_sprite != NULL) {
        sfRenderWindow_drawSprite(game->window, game->m->cursor_sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
}
