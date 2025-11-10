/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** start.c
*/

#include "../../include/my.h"

bool create_start_btn(game_t *game)
{
    char *path = "assets/images/start_btn.png";

    game->start_btn_texture = sfTexture_createFromFile(path, NULL);
    if (!game->start_btn_texture)
        return false;
    game->start_btn_sprite = sfSprite_create();
    if (!game->start_btn_sprite)
        return false;
    return true;
}
