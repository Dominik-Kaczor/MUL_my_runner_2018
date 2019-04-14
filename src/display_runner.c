/*
** EPITECH PROJECT, 2019
** display_runner
** File description:
** display
*/

#include "../include/my.h"
#include "../include/my_runner.h"

void display_map_b(sfRenderWindow *window, sprites_t *sprites,
                   math_t *math, events_t *events)
{
    sfSprite_setPosition(sprites->sprite_r, math->vector_r);
    sfRenderWindow_drawSprite(window, sprites->sprite_r, NULL);
    if (math->vector_r.x == math->vector_t.x
        && math->vector_r.y <= math->vector_t.y + 50
        && math->vector_r.y >= math->vector_t.y - 50
        || events->map[events->block] == '\n'
        || events->map[events->block] == '\0')
        events->close = 1;
}

void display_sprites_map(sfRenderWindow *window, sprites_t *sprites,
                         math_t *math, events_t *events)
{
    if (events->map[events->block] == '1' && events->generation == 0) {
        events->f_spam = 4;
        events->generation = 1;
        math->vector_r.y = 770;
    }
    if (events->map[events->block] == '0' && events->generation == 0) {
        events->f_spam = 4;
        events->generation = 1;
        math->vector_r.y = 2770;
    }
    if (events->spam == 2 && events->f_spam == 4) {
        math->vector_r.x = 2000;
        events->f_spam = 3;
    }
    if (math->vector_r.x == -100 && events->f_spam == 3) {
        events->generation = 0;
        events->f_spam = 0;
        events->block++;
    }
    display_map_b(window, sprites, math, events);
}

void display_sprites_rocket(sfRenderWindow *window, sprites_t *sprites,
                            math_t *math, events_t *events)
{
    if (events->spam == 1 && events->f_spam == 0) {
        math->vector_r.x = 2000;
        events->f_spam = 1;
    }
    if (math->vector_r.x == -100 && events->f_spam == 1)
        events->f_spam = 0;
    sfSprite_setPosition(sprites->sprite_r, math->vector_r);
    sfRenderWindow_drawSprite(window, sprites->sprite_r, NULL);
    if (math->vector_r.x == math->vector_t.x
        && math->vector_r.y <= math->vector_t.y + 50
        && math->vector_r.y >= math->vector_t.y - 50)
        events->close = 1;
}

void display_sprites_b(sfRenderWindow *window, sprites_t *sprites,
                       math_t *math, events_t *events)
{
    sfSprite_setPosition(sprites->sprite_b, math->vector_b2);
    sfRenderWindow_drawSprite(window, sprites->sprite_b, NULL);
    sfSprite_setPosition(sprites->sprite_c, math->vector_c1);
    sfRenderWindow_drawSprite(window, sprites->sprite_c, NULL);
    sfSprite_setPosition(sprites->sprite_c, math->vector_c2);
    sfRenderWindow_drawSprite(window, sprites->sprite_c, NULL);
    sfSprite_setPosition(sprites->sprite_t, math->vector_t);
    sfSprite_setTextureRect(sprites->sprite_t, math->rect);
    sfRenderWindow_drawSprite(window, sprites->sprite_t, NULL);
    sfText_setString(sprites->text, events->score);
    sfRenderWindow_drawText(window, sprites->text, NULL);
    if (events->spam == 1)
        display_sprites_rocket(window, sprites, math, events);
    if (events->spam == 2)
        display_sprites_map(window, sprites, math, events);
}

void display_sprites(sfRenderWindow *window, sprites_t *sprites,
                     math_t *math, events_t *events)
{
    moving_sprites(events, math);
    initialisation_position(math);
    sfSprite_setPosition(sprites->sprite_a, math->vector_a1);
    sfRenderWindow_drawSprite(window, sprites->sprite_a, NULL);
    sfSprite_setPosition(sprites->sprite_a, math->vector_a2);
    sfRenderWindow_drawSprite(window, sprites->sprite_a, NULL);
    sfSprite_setPosition(sprites->sprite_d, math->vector_d1);
    sfRenderWindow_drawSprite(window, sprites->sprite_d, NULL);
    sfSprite_setPosition(sprites->sprite_d, math->vector_d2);
    sfRenderWindow_drawSprite(window, sprites->sprite_d, NULL);
    sfSprite_setPosition(sprites->sprite_b, math->vector_b1);
    sfRenderWindow_drawSprite(window, sprites->sprite_b, NULL);
    display_sprites_b(window, sprites, math, events);
}
