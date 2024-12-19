/*
** EPITECH PROJECT, 2024
** BLUE_LOAD_CONFIGFILES
** File description:
** Load and redirect .blue config files
*/
#include "../../include/blue.h"

void load_actors(void)
{
    FILE *fp = fopen(BLUEPATH("actors"), "r");

    //while (getline())
    
    fclose(fp);
}