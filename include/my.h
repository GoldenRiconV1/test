/*
** EPITECH PROJECT, 2025
** myls
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <time.h>
    #define DUCK_WIDTH 11220
    #define DUCK_HEIGHT 110
    #define DUCK_STATES 102
    #define REFRESH_SECONDS 0.02

typedef struct game_s
{
    sfRenderWindow *window;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfTexture *duck_texture;
    sfSprite *duck_sprite;
    sfIntRect duck_rect;
    sfClock *clock;

} game_t;

game_t *create_game(void);
void destroy_game(game_t *game);
void game_loop(game_t *game);
void manage_events(game_t *game);
void init(game_t *game);

bool create_background(game_t *game);
bool create_clock(game_t *game);
bool create_duck(game_t *game);

void destroy_duck(game_t *game);

#endif
