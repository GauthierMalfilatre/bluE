/*
** EPITECH PROJECT, 2024
** BLUE_ENGINE
** File description:
** Header file for blue engine
*/
#ifndef BLUE_ENGINE_H
    #define BLUE_ENGINE_H
    #define BLUEPATH(name) ("blueconfig/" name ".blue")
    #define KBPATH(name) ("blueconfig/" name ".kblue")
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <math.h>
    #include "my.h"

/*
** Linked list for bluE data
** 
** 0 : Textures
** 1 : Muscis
** 2 : Sounds
*/

typedef struct blue_textures_s {
    char *name;
    sfTexture *texture;
    struct blue_texture_s *next;
} blue_textures_t;

typedef struct blue_musics_s {
    char *name;
    sfMusic *music;
    struct blue_music_s *next;
} blue_musics_t;

typedef struct blue_sounds_s {
    char *name;
    sfSoundBuffer *sound_buffer;
    sfSoundBuffer *sound;
    struct blue_sounds_s *next;
} blue_sounds_t;

/*
** Types of bluE actors :
** 
** 0 : Teapot
**     Teapots are meaningless actors that behave like NPCs or chill guys.  
**     In most cases, they are created with default render and move  
**     functions, as other objects take priority instead.
**
** 1 : Player
**     Players are (in most of cases) a special single actor in the game,
**     With her own movement and render function.
**
** 2 : Jinx
**     Jinxs are basic ennemy and have their own move and render functions
**     In case of a boss or smth like that, i'd add special_jinx actor
**     (maybe something like mega_jinx or Xizer) 
*/

// Keep the code understable with enum
enum blue_actors_e {
    TEAPOT,
    PLAYER,
    JINX
};

// General actorinfos (idk if i must split actors in differents actorinfos)
typedef struct blue_actorinfos_s {
    sfSprite *sprite;
    sfClock *clock;
    int z_index;
    int life;  // HP points
    int (*move)();
    int (*render)();
} blue_actorinfos_t;

// ??? Type of infos depends on type_of (will be make in parsing configs files)
typedef struct blue_actor_s {
    char *name;
    int type_of;
    blue_actorinfos_t *infos;
    struct blue_actor_s *next;
    struct blue_actor_s *prev;
} blue_actor_t;

// Scenes linked list
typedef struct blue_scene_s {
    char *name_of;
    int (*move)();
    int (*time)();
    int (*render)();
    blue_actor_t *actors;
    struct blue_scene_s *next;
} blue_scene_t;

/*
** The entire game : it contain window, but also actual scene thanks to
** Pointers on functions (thx pierre connes)
*/
typedef struct blue_game_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *actual_scene;
    blue_scene_t *scenes;
} blue_game_t;


/*
** Functions
*/

// Kronkerize files
int kronkerize_all(char *folder);

// Loading files
int load_config_files(void);

// Actors
void load_actors(void);

// Check
int check_if_folder(char *folder);
int check_if_file(char *file);

#endif
