/*
** EPITECH PROJECT, 2025
** GraphicalC
** File description:
** main.c
*/

#include "../include/my.h"

static void print_help(void)
{
    printf("MoneyRush - A Duck Hunting Game\n\n"
        "DESCRIPTION:\n"
        "    'MoneyRush' is a game where you hunt ducks.\n"
        "    Click on the ducks as they fly across the "
        "screen to score points.\n"
        "    The game ends if a duck successfully crosses "
        "the entire screen.\n\n"
        "AVAILABLE USER INPUTS:\n\n"
        "    [MOUSE LEFT CLICK]\n"
        "        - In Menus: Interact with 'Start', "
        "'Restart', and 'Exit' buttons.\n"
        "        - In Game: Click to shoot a duck.\n\n"
        "    [KEYBOARD]\n"
        "        - 'Escape' (Echap): Toggles the pause menu on "
        "or off during the game.\n\n"
        "    [WINDOW]\n"
        "        - Close Button: Quits the game.\n");
}

int main(int argc, char **argv)
{
    game_t *game;

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    if (argc == 1) {
        game = create_game();
        if (!game)
            return 84;
        game_loop(game);
        destroy_game(game);
        return 0;
    }
    return 84;
}
