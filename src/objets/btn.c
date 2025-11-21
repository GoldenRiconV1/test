/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** exit_btn.c
*/

#include "../../include/my.h"

bool create_start_btn(game_t *game)
{
    char *path = "assets/images/start_btn.png";
    sfVector2f offset = {281.0, 107.0};

    game->btn->start_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->btn->start_btn_texture)
        return false;
    game->btn->start_btn_sprite = sfSprite_create();
    if (!game->btn->start_btn_sprite)
        return false;
    sfSprite_setTexture(game->btn->start_btn_sprite,
        game->btn->start_btn_texture, sfTrue);
    sfSprite_move(game->btn->start_btn_sprite, offset);
    return true;
}

bool create_restart_btn(game_t *game)
{
    char *path = "assets/images/restart_btn.png";
    sfVector2f offset = {281.0, 107.0};

    game->btn->restart_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->btn->restart_btn_texture)
        return false;
    game->btn->restart_btn_sprite = sfSprite_create();
    if (!game->btn->restart_btn_sprite)
        return false;
    sfSprite_setTexture(game->btn->restart_btn_sprite,
        game->btn->restart_btn_texture, sfTrue);
    sfSprite_move(game->btn->restart_btn_sprite, offset);
    return true;
}

bool create_exit_btn(game_t *game)
{
    char *path = "assets/images/exit_btn.png";
    sfVector2f offset = {281.0, 257.0};

    game->btn->exit_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->btn->exit_btn_texture)
        return false;
    game->btn->exit_btn_sprite = sfSprite_create();
    if (!game->btn->exit_btn_sprite)
        return false;
    sfSprite_setTexture(game->btn->exit_btn_sprite,
        game->btn->exit_btn_texture, sfTrue);
    sfSprite_move(game->btn->exit_btn_sprite, offset);
    return true;
}
