/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** exit_btn.c
*/

#include "../../include/my.h"

bool create_exit_btn(game_t *game)
{
    char *path = "assets/images/exit_btn.png";
    sfVector2f offset = {281.0, 257.0};

    game->exit_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->exit_btn_texture)
        return false;
    game->exit_btn_sprite = sfSprite_create();
    if (!game->exit_btn_sprite)
        return false;
    sfSprite_setTexture(game->exit_btn_sprite, game->exit_btn_texture,
        sfTrue);
    sfSprite_move(game->exit_btn_sprite, offset);
    return true;
}

bool create_start_btn(game_t *game)
{
    char *path = "assets/images/start_btn.png";
    sfVector2f offset = {281.0, 107.0};

    game->start_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->start_btn_texture)
        return false;
    game->start_btn_sprite = sfSprite_create();
    if (!game->start_btn_sprite)
        return false;
    sfSprite_setTexture(game->start_btn_sprite, game->start_btn_texture,
        sfTrue);
    sfSprite_move(game->start_btn_sprite, offset);
    return true;
}
