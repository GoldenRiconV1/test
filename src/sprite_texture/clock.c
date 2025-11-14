/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** clock.c
*/

#include "../../include/my.h"

bool create_clock(game_t *game)
{
    game->clock = sfClock_create();
    if (!game->clock)
        return false;
    return true;
}
