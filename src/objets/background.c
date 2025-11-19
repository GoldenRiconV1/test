/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** background.c
*/

#include "../../include/my.h"

bool create_background(game_t *game)
{
    char *path = "assets/images/background.png";

    game->background_texture = sfTexture_createSrgbFromFile(path, NULL);
    if (!game->background_texture)
        return false;
    game->background_sprite = sfSprite_create();
    if (!game->background_sprite)
        return false;
    sfSprite_setTexture(game->background_sprite,
        game->background_texture, sfTrue);
    return true;
}
