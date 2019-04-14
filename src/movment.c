/*
** EPITECH PROJECT, 2019
** movment.c
** File description:
** runner
*/

#include "../include/my.h"
#include "../include/my_runner.h"

void my_put_str(events_t *events)
{
    events->score = NULL;
    int size = 0;
    int nb = events->score_i;

    while (nb != 0) {
        nb = nb / 10;
        size = size + 1;
    }
    nb = events->score_i;
    events->score = malloc(sizeof(char) * (size + 1));
    events->score[size] = '\0';
    size = size - 1;
    while (size != -1) {
        events->score[size] = (nb % 10) + 48;
        nb = nb / 10;
        size = size - 1;
    }
}

void moving_sprites(events_t *events, math_t *math)
{
    if (events->seconds > 0.001) {
        events->score_i++;
        math->vector_a1.x = math->vector_a1.x - 15;
        math->vector_a2.x = math->vector_a2.x - 15;
        math->vector_b1.x = math->vector_b1.x - 10;
        math->vector_b2.x = math->vector_b2.x - 10;
        math->vector_c1.x = math->vector_c1.x - 5;
        math->vector_c2.x = math->vector_c2.x - 5;
        math->vector_d1.x = math->vector_d1.x - 10;
        math->vector_d2.x = math->vector_d2.x - 10;
        sfClock_restart(events->clock);
    }
    my_put_str(events);
}

void initialisation_position(math_t *math)
{
    if (math->vector_a1.x < -1920)
        math->vector_a1.x = 1920;
    if (math->vector_a2.x < -1920)
        math->vector_a2.x = 1920;
    if (math->vector_b1.x < -1900)
        math->vector_b1.x = 1900;
    if (math->vector_b2.x < -1900)
        math->vector_b2.x = 1900;
    if (math->vector_c1.x < -1920)
        math->vector_c1.x = 1920;
    if (math->vector_c2.x < -1920)
        math->vector_c2.x = 1920;
    if (math->vector_d1.x < -3200)
        math->vector_d1.x = 3200;
    if (math->vector_d2.x < -3200)
        math->vector_d2.x = 3200;
}

void change_rect(int offset, int max_value, math_t *math, events_t *events)
{
        if (math->rect.left >= max_value) {
            math->rect.left = 0;
        } else
            math->rect.left += offset;
        if (events->space == 1)
            math->vector_t.y -= 20;
        if (math->vector_t.y <= 520) {
            events->space = 0;
            events->secu = 1;
        }
        if (math->vector_t.y <= 520 && events->secu == 1)
            events->down = 1;
        if (events->down == 1)
            math->vector_t.y += 20;
        if (math->vector_t.y >= 820)
            events->down = 0;
        if ((events->spam == 1 || events->spam == 2)
            && math->vector_r.x != -100)
            math->vector_r.x -= 25;
}
