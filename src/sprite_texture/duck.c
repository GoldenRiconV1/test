/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** duck.c
*/

#include "../../include/my.h"


bool create_duck(game_t *game)
{
    char *path = "assets/images/duck.png";
    sfVector2f offset;

    srand(time(NULL));
    offset.x = 0.0;
    offset.y = rand() % (600 - DUCK_HEIGHT);
    game->duck_texture = sfTexture_createSrgbFromFile(path, NULL);
    if (!game->duck_texture)
        return false;
    game->duck_sprite = sfSprite_create();
    if (!game->duck_sprite)
        return false;
    game->duck_rect.height = DUCK_HEIGHT;
    game->duck_rect.width = DUCK_WIDTH / DUCK_STATES;
    game->duck_rect.left = 0;
    game->duck_rect.top = 0;
    sfSprite_move(game->duck_sprite, offset);
    sfSprite_setTexture(game->duck_sprite, game->duck_texture, sfTrue);
    sfSprite_setTextureRect(game->duck_sprite, game->duck_rect);
    return true;
}
