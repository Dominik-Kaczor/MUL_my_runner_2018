/*
** EPITECH PROJECT, 2018
** my_runner.h
** File description:
** my_runner
*/

#ifndef STRU_H_
#define STRU_H_

typedef struct sprites{
    sfTexture *texture_a;
    sfSprite *sprite_a;
    sfTexture *texture_b;
    sfSprite *sprite_b;
    sfTexture *texture_c;
    sfSprite *sprite_c;
    sfTexture *texture_d;
    sfSprite *sprite_d;
    sfTexture *texture_t;
    sfSprite *sprite_t;
    sfTexture *texture_r;
    sfSprite *sprite_r;
    sfFont* font;
    sfText* text;
}sprites_t;

typedef struct math{
    sfIntRect rect;
    sfVector2f vector_a1;
    sfVector2f vector_a2;
    sfVector2f vector_b1;
    sfVector2f vector_b2;
    sfVector2f vector_c1;
    sfVector2f vector_c2;
    sfVector2f vector_d1;
    sfVector2f vector_d2;
    sfVector2f vector_t;
    sfVector2f vector_r;
}math_t;

typedef struct events{
    sfClock *clock;
    sfTime time;
    float seconds;
    sfMusic *music;
    sfMusic *music_jump;
    int space;
    int down;
    int secu;
    char *score;
    int score_i;
    int spam;
    int f_spam;
    int close;
    char *map;
    int block;
    int generation;
}events_t;

#endif /* STRU_H_ */
