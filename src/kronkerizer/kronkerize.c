/*
** EPITECH PROJECT, 2024
** BLUE_KRONKERIZER
** File description:
** Kronkerize .blue files
*/
#include "../../include/blue.h"
#include "kronkerizer.h"

static int kronkerize(char *name, char *folder)
{
    char srcname[my_strlen(name) + my_strlen(folder) + 2];
    my_strcpy(srcname, folder);
    my_strcat(srcname, "/");
    my_strcat(srcname, name);

    char destname[my_strlen(srcname) + 2];
    my_strncpy(destname, srcname, my_strlen(srcname) - my_strlen("blue"));
    my_strcat(destname, "kblue");

    FILE *src = fopen(srcname, "r");
    FILE *dest = fopen(destname, "w+");

    char *buffer = NULL;
    size_t len = 0;
    for (int size = getline(&buffer, &len, src); size != -1; size = getline(&buffer, &len, src)) {
        if ((size >= 2 && my_strncmp(buffer, "##", 2))) {
            for (int i = 0; i < size; i++) {
                if (buffer[i] && buffer[i] != ' ') {
                    fprintf(dest, "%c", buffer[i]);
                }
            }
        }
    }
    free(buffer);
    fclose(src);
    fclose(dest);
    my_printf("FILE TO KRONKERIZE : %s, OUTPUT : %s\n", srcname, destname);
    return 0;
}

int kronkerize_all(char *folder)
{
    DIR *dir = opendir(folder);

    for (struct dirent *dp = readdir(dir); dp; dp = readdir(dir)) {
        if (my_strcmp(dp->d_name, ".") && my_strcmp(dp->d_name, "..") && check_ext(dp->d_name, ".blue"))
            kronkerize(dp->d_name, folder);
    }
    closedir(dir);
    return 0;
}
