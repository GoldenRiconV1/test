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

    game->m->cursor_sprite = sfSprite_create();
    if (game->m->cursor_sprite == NULL)
        return false;
    game->m->cursor_texture = sfTexture_createSrgbFromFile(path, NULL);
    if (game->m->cursor_texture == NULL)
        return false;
    sfSprite_setTexture(game->m->cursor_sprite, game->m->cursor_texture,
        sfTrue);
    if (game->m->cursor_texture == NULL)
        return false;
    return true;
}

static void move_cursor(game_t *game)
{
    sfVector2f offset = {0, 0};

    offset.x = game->m->mouse_pos.x - 45;
    offset.y = game->m->mouse_pos.y - 45;
    if (game->m->cursor_sprite == NULL)
        return;
    sfSprite_setPosition(game->m->cursor_sprite, offset);
}

void handle_cursor(game_t *game)
{
    if (game->m->cursor_sprite == NULL)
        return;
    move_cursor(game);
}
