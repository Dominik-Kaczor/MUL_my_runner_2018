/*
** EPITECH PROJECT, 2018
** tools_runner
** File description:
** runner
*/

#include "../include/my.h"
#include "../include/my_runner.h"

void descrip(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_runner map.txt\n\n\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -i                launch the game in infinity mode.\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  SPACE_KEY        jump.\n");
}

void music(events_t *events)
{
    events->music_jump = sfMusic_createFromFile("sound/jump.ogg");
    events->music = sfMusic_createFromFile("sound/sound.ogg");
    sfMusic_setLoop(events->music, sfTrue);
    sfMusic_play(events->music);
}
