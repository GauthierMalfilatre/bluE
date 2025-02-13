/*
** EPITECH PROJECT, 2024
** MY_STRSTR
** File description:
** Find and return an string after the first occurence of another str
*/
#include "my.h"

static int check_out(char *str, char const *to_find, int i, int j)
{
    if (j == my_strlen(to_find)) {
        return 1;
    }
    if (str[i] != to_find[j]) {
        return 0;
    }
    return check_out(str, to_find, i + 1, j + 1);
}

static int length_occurence(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_out(str, to_find, i, 0)) {
            return i;
        }
    }
    return -1;
}

char *my_strstr(char *str, char const *to_find)
{
    if (length_occurence(str, to_find) != -1) {
        return &str[length_occurence(str, to_find)];
    }
    return (void *) 0;
}
