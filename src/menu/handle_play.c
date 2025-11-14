/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_play.c
*/

#include "../../include/my.h"

void handle_play(game_t *game)
{
    game->score_text_str = malloc(sizeof(char *) + 1);
    if (game->score_text_str == NULL)
        free(game->score_text_str);
    sprintf(game->score_text_str, "Score : %d", game->score);
    if (game->duck_sprite != NULL)
        sfRenderWindow_drawSprite(game->window, game->duck_sprite, NULL);
    handle_duck(game);
    sfText_setString(game->score_text, game->score_text_str);
}
