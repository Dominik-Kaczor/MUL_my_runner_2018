/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef NAME_H_
#define NAME_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <unistd.h>
#include "my_runner.h"

void my_putchar(char c);
int my_putstr(char const *str);
void descrip(void);
void creation(sprites_t *sprites, events_t *events, math_t *math, int i);
void display_sprites(sfRenderWindow *window, sprites_t *sprites,math_t *math,
                     events_t *events);
void moving_sprites(events_t *events, math_t *math);
void initialisation_position(math_t *math);
void music(events_t *events);
void change_rect(int offset, int max_value, math_t *math, events_t *events);
void close_window(sfRenderWindow *window, sprites_t *sprites,
                  events_t *events);

#endif /* NAME_H_ */
