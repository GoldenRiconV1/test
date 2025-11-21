/*
** EPITECH PROJECT, 2025
** G-MUL-100-LYN-1-1-myhunter-15
** File description:
** sound.c
*/

#include "../../include/my.h"

bool create_sound_pop(game_t *game)
{
    char *path = "assets/sound_music/pop.ogg";

    game->pop_sound = sfSound_create();
    if (game->pop_sound == NULL)
        return false;
    game->pop_sound_buffer = sfSoundBuffer_createFromFile(path);
    if (game->pop_sound_buffer == NULL)
        return false;
    sfSound_setBuffer(game->pop_sound, game->pop_sound_buffer);
    return true;
}

bool create_music(game_t *game)
{
    char *path = "assets/sound_music/music.ogg";

    game->music = sfMusic_createFromFile(path);
    if (game->music == NULL)
        return false;
    return true;
}

void handle_pop_sound(game_t *game)
{
    sfSound_play(game->pop_sound);
}
