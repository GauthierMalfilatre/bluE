/*
** EPITECH PROJECT, 2024
** BLUE_KRONKERIZER
** File description:
** Check the extension of a file
*/
#include "../../include/blue.h"
#include "kronkerizer.h"

int check_ext(char *filename, char *ext)
{
    if (!my_strstr(filename, ".")) {
        return 0;
    }
    return !my_strcmp(my_strstr(filename, "."), ext);
}
