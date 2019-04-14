/*
** EPITECH PROJECT, 2019
** creation_runner
** File description:
** creation
*/

#include "../include/my.h"
#include "../include/my_runner.h"

void creation_time_score(sprites_t *sprites, events_t *events, math_t *math)
{
    events->clock = sfClock_create();
    sprites->font = sfFont_createFromFile("font/arial.ttf");
    sprites->text = sfText_create();
    sfText_setFont(sprites->text, sprites->font);
    sfText_setColor(sprites->text, sfWhite);
    sfText_setCharacterSize(sprites->text, 50);
    events->space = 0;
    events->down = 0;
    events->secu = 0;
    events->block = 0;
    events->generation = 0;
}

void creation_block(sprites_t *sprites, events_t *events, math_t *math)
{
    sprites->texture_r = sfTexture_createFromFile("pictures/rocket.png", NULL);
    sprites->sprite_r = sfSprite_create();
    math->vector_r.x = -50;
    math->vector_r.y = 770;
    sfSprite_setTexture(sprites->sprite_r, sprites->texture_r, sfTrue);
    creation_time_score(sprites, events, math);
    events->f_spam = 0;
}

void creation_trump(sprites_t *sprites, events_t *events, math_t *math)
{
    sprites->texture_t = sfTexture_createFromFile("pictures/trump.png", NULL);
    sprites->sprite_t = sfSprite_create();
    math->vector_t.x = 50;
    math->vector_t.y = 820;
    sfSprite_setTexture(sprites->sprite_t, sprites->texture_t, sfTrue);
    math->rect.top = 0;
    math->rect.left = 0;
    math->rect.width = 100;
    math->rect.height = 100;
    creation_block(sprites, events, math);
}

void creation_city_and_moon(sprites_t *sprites, events_t *events, math_t *math)
{
    events->score_i = 0;
    sprites->texture_c = sfTexture_createFromFile("pictures/moon.png", NULL);
    sprites->sprite_c = sfSprite_create();
    math->vector_c1.x = 0;
    math->vector_c1.y = 50;
    math->vector_c2.x = 1920;
    math->vector_c2.y = 50;
    sfSprite_setTexture(sprites->sprite_c, sprites->texture_c, sfTrue);
    sprites->texture_d = sfTexture_createFromFile("pictures/city.png", NULL);
    sprites->sprite_d = sfSprite_create();
    math->vector_d1.x = 0;
    math->vector_d1.y = 225;
    math->vector_d2.x = 3200;
    math->vector_d2.y = 225;
    sfSprite_setTexture(sprites->sprite_d, sprites->texture_d, sfTrue);
    creation_trump(sprites, events, math);
}

void creation(sprites_t *sprites, events_t *events, math_t *math, int i)
{
    if (i == 1) {
        events->spam = 1;
    }
    music(events);
    sprites->texture_a = sfTexture_createFromFile("pictures/background.jpg"
                                                  , NULL);
    sprites->sprite_a = sfSprite_create();
    math->vector_a1.x = 0;
    math->vector_a1.y = 0;
    math->vector_a2.x = 1920;
    math->vector_a2.y = 0;
    sfSprite_setTexture(sprites->sprite_a, sprites->texture_a, sfTrue);
    sprites->texture_b = sfTexture_createFromFile("pictures/ground.png", NULL);
    sprites->sprite_b = sfSprite_create();
    math->vector_b1.x = 0;
    math->vector_b1.y = 0;
    math->vector_b2.x = 1900;
    math->vector_b2.y = 0;
    sfSprite_setTexture(sprites->sprite_b, sprites->texture_b, sfTrue);
    creation_city_and_moon(sprites, events, math);
}
