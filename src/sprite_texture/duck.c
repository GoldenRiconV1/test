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
    offset.x = - DUCK_WIDTH / DUCK_STATES;
    offset.y = rand() % (GAME_HEIGHT - DUCK_HEIGHT);
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

static void refresh_duck_sprite(game_t *game)
{
    float seconds = get_elapsed_time(game);

    if (game->duck_sprite == NULL)
        return;
    if (seconds >= REFRESH_SECONDS) {
        game->duck_rect.left += DUCK_WIDTH / DUCK_STATES;
        if (game->duck_rect.left >= DUCK_WIDTH)
            game->duck_rect.left = 0;
        sfSprite_setTextureRect(game->duck_sprite, game->duck_rect);
        sfClock_restart(game->clock);
    }
}

static void change_speed(game_t *game)
{
    if (!(game->score % 5) && game->duck_speed != 6)
        game->duck_speed += 0.5;
}

static void reset_duck(game_t *game)
{
    sfVector2f offset;

    offset.x = - DUCK_WIDTH / DUCK_STATES;
    offset.y = rand() % (GAME_HEIGHT - DUCK_HEIGHT);
    sfSprite_setPosition(game->duck_sprite, offset);
    game->duck_rect.left = 0;
    sfSprite_setTextureRect(game->duck_sprite, game->duck_rect);
}

static void move_duck(game_t *game)
{
    sfVector2f offset = {game->duck_speed, 0.0};

    if (game->duck_sprite == NULL)
        return;
    sfSprite_move(game->duck_sprite, offset);
}

void handle_duck(game_t *game)
{
    if (game->duck_sprite == NULL)
        return;
    refresh_duck_sprite(game);
    move_duck(game);
    printf("score: %i, speed: %.1f\n", game->score, game->duck_speed);
    if (game->mouse_clicked == true
        && game->mouse_pos.x >= game->duck_pos.x
        && game->mouse_pos.x <= game->duck_pos.x + DUCK_WIDTH / DUCK_STATES
        && game->mouse_pos.y >= game->duck_pos.y
        && game->mouse_pos.y <= game->duck_pos.y + DUCK_HEIGHT) {
        reset_duck(game);
        game->score += 1;
        change_speed(game);
    }
    if (game->duck_pos.x >= 800) {
        game->state = LOOSE;
        reset_duck(game);
    }
}
