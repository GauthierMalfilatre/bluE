/*
** EPITECH PROJECT, 2024
** BLUE_CHECKS_FILES
** File description:
** Check .blue config files
*/
#include "../../include/blue.h"

int check_if_folder(char *folder)
{
    struct stat s;

    if (lstat(folder, &s) == -1 || !S_ISDIR(s.st_mode)) {
        return -1;
    }
    return 0;
}

int check_if_file(char *file)
{
    struct stat s;

    if (lstat(file, &s) == -1 || !S_ISREG(s.st_mode)) {
        return -1;
    }
    return 0;
}
