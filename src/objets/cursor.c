/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** cursor.c
*/

#include "../../include/my.h"

bool create_cursor(game_t *game)
{
    char *path = "assets/images/cursor.png";

    game->cursor_sprite = sfSprite_create();
    if (game->cursor_sprite == NULL)
        return false;
    game->cursor_texture = sfTexture_createSrgbFromFile(path, NULL);
    if (game->cursor_texture == NULL)
        return false;
    sfSprite_setTexture(game->cursor_sprite, game->cursor_texture, sfTrue);
    if (game->cursor_texture == NULL)
        return false;
    return true;
}

static void move_cursor(game_t *game)
{
    sfVector2f offset = {0, 0};

    offset.x = game->mouse_pos.x - 45;
    offset.y = game->mouse_pos.y - 45;
    if (game->cursor_sprite == NULL)
        return;
    sfSprite_setPosition(game->cursor_sprite, offset);
}

void handle_cursor(game_t *game)
{
    if (game->cursor_sprite == NULL)
        return;
    move_cursor(game);
}
