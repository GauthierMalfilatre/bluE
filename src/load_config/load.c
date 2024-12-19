/*
** EPITECH PROJECT, 2024
** BLUE_LOAD_CONFIGFILES
** File description:
** Load and redirect .blue config files
*/
#include "../../include/blue.h"

int load_config_files(void)
{
    if (check_if_folder("blueconfig") == -1) {
        my_printf("No folder named blueconfig\n");
    }
    kronkerize_all("blueconfig");
    if (check_if_file(KBPATH("actors")) != -1) {
        load_actors();
    }
    return 0;
}