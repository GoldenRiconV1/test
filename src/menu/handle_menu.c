/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** handle_menu.c
*/

#include "../../include/my.h"

void handle_menu(game_t *game)
{
    if (game->state == START_MENU)
        start_menu(game);
}
