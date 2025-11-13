/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** main.c
*/

#include "../include/my.h"

int main(void)
{
    game_t *game = create_game();

    if (!game)
        return 84;
    game_loop(game);
    destroy_game(game);
    return 0;
}
