/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "include/my.h"
#include "include/my_runner.h"

void analyse_events(sfRenderWindow *window, sfEvent event, events_t *events)
{
    if (event.type == sfEvtClosed || events->close == 1) {
        events->close = 0;
        sfRenderWindow_close(window);
    }
    if (event.key.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.key.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
        events->space == 0 && events->down == 0) {
        events->space = 1;
        sfMusic_play(events->music_jump);
    }
}

void close_window(sfRenderWindow *window, sprites_t *sprites, events_t *events)
{
    sfMusic_stop(events->music);
    sfSprite_destroy(sprites->sprite_a);
    sfTexture_destroy(sprites->texture_a);
    sfMusic_destroy(events->music);
    sfMusic_destroy(events->music_jump);
    sfSprite_destroy(sprites->sprite_b);
    sfTexture_destroy(sprites->texture_b);
    sfSprite_destroy(sprites->sprite_c);
    sfTexture_destroy(sprites->texture_c);
    sfSprite_destroy(sprites->sprite_d);
    sfTexture_destroy(sprites->texture_d);
    sfSprite_destroy(sprites->sprite_t);
    sfTexture_destroy(sprites->texture_t);
    sfSprite_destroy(sprites->sprite_r);
    sfTexture_destroy(sprites->texture_r);
    sfRenderWindow_destroy(window);
}

void general(sprites_t *sprites, math_t *math, events_t *events, int i)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "SFML window", sfResize
                                   | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 40);
    creation(sprites, events, math, i);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, 0);
        events->time = sfClock_getElapsedTime(events->clock);
        events->seconds = events->time.microseconds/1000000.0;
        while (sfRenderWindow_pollEvent(window, &event) || events->close == 1)
            analyse_events(window, event, events);
        display_sprites(window, sprites, math, events);
        change_rect(100, 500, math, events);
        moving_sprites(events, math);
        sfRenderWindow_display(window);
    }
    close_window(window, sprites, events);
}

int check(char *av, events_t *events)
{
    struct stat s;
    stat(av, &s);
    events->map = malloc(sizeof(char) * s.st_size);
    int fd = open(av, O_RDONLY);
    if (fd == -1 || s.st_size == 0) {
        write(2, "error", 5);
        return (1);
    }
    read(fd, events->map, s.st_size);
    events->spam = 2;
    for (int k = 0; events->map[k] != '\n' && events->map[k] != '\0'; k++) {
        if (events->map[k] != '1' && events->map[k] != '0' &&
            events->map[k] != '\0' && events->map[k] != '\n') {
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    math_t math;
    sprites_t sprites;
    events_t events;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        descrip();
        return (0);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'i' && av[1][2] == '\0') {
        general(&sprites, &math, &events, 1);
        return (0);
    } else if (ac == 2) {
        if (check(av[1], &events) == 1)
            return (84);
        general(&sprites, &math, &events, 0);
        return (0);
    } else {
        write(2, "error\n", 6);
        return (84);
    }
}
