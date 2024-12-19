/*
** EPITECH PROJECT, 2024
** BLUE_ENGINE
** File description:
** Just a testing file to check if blue engine works
*/

#include "../include/blue.h"

int main(int argc, char *const *argv)
{
    
    load_config_files();

    return 0;

    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode) {800, 600,
        32}, "bluE test", sfClose, 0);
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}
