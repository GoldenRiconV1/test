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
    #define GAME_WIDTH 800
    #define GAME_HEIGHT 600
    #define DUCK_WIDTH 11220
    #define DUCK_HEIGHT 110
    #define DUCK_STATES 102
    #define REFRESH_SECONDS 0.02

typedef enum game_state_e
{
    START_MENU,
    PLAYING,
    PAUSED,
    LOOSE
} game_state_t;

typedef struct game_s
{
    game_state_t state;
    sfRenderWindow *window;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfTexture *duck_texture;
    sfSprite *duck_sprite;
    sfTexture *start_btn_texture;
    sfSprite *start_btn_sprite;
    sfTexture *restart_btn_texture;
    sfSprite *restart_btn_sprite;
    sfTexture *exit_btn_texture;
    sfSprite *exit_btn_sprite;
    sfIntRect duck_rect;
    sfClock *clock;
    int score;
    float duck_speed;
    sfVector2i mouse_pos;
    sfVector2f duck_pos;
    bool mouse_clicked;
    bool escape_clicked;
} game_t;

game_t *create_game(void);
void destroy_game(game_t *game);
void game_loop(game_t *game);
void manage_events(game_t *game);
void init(game_t *game);

bool create_background(game_t *game);
bool create_clock(game_t *game);
bool create_duck(game_t *game);
void reset_duck(game_t *game);
float get_elapsed_time(game_t *game);

bool create_start_btn(game_t *game);
bool create_restart_btn(game_t *game);
bool create_exit_btn(game_t *game);
void check_click_btn(game_t *game);

void start_menu(game_t *game);
void loose_menu(game_t *game);
void pause_menu(game_t *game);

void handle_menu(game_t *game);
void handle_play(game_t *game);
void handle_duck(game_t *game);

#endif
