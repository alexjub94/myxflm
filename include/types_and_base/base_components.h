/*
** EPITECH PROJECT, 2020
** base_components.h
** File description:
** header for base_components.c
*/

#ifndef LIBCSFML_BASE_COMPONENTS_H
#define LIBCSFML_BASE_COMPONENTS_H

#include "../types.h"
#include "../custom_structs.h"

        ////////////////////////////////
        //      BASE COMPONENTS       //
        ////////////////////////////////

//
//  Collider_Component
//

struct collider_s {
    toggle_t toggle;
    toggle_t is_circle;
    sfVector2f position;
    sfVector2f dimensions;
    float radius;
    sfCircleShape *circ_collider;
    sfRectangleShape *rect_collider;
    int (* on_collison)(entity_t *self, entity_t *collider,
    game_data_t *data);
};



//
//  RenderSprite_Component
//
struct render_sprite_s {
    toggle_t toggle;
    sfSprite *sprite;
    sfTexture *texture;
};



//
//  Transform_Component
//
struct transform_s {
    toggle_t toggle;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f velocity;
    float speed;
    float rotation;
};



//
// Sound_component
//
struct sound_s {
    toggle_t toggle;
    char *name;
    char *path;
    anim type;
    sfSound *sfx;
    sfSoundBuffer *buff;
};

struct sfx_list_s {
    toggle_t toggle;
    sound_t *sfx;
    int sfx_count;
};



//
// Text_component
//
struct text_s {
    toggle_t toggle;
    sfText *text;
    sfFont *font;
    char *string;
    char *id;
    int size;
    sfVector2f pos;
    sfVector2f offset;
    toggle_t is_rslinked;
};

struct texts_s{
    toggle_t toggle;
    text_t *text;
    int count;
};



//
//  Interact_component
//
struct interact_s {
    toggle_t toggle;
    toggle_t click_right;
    toggle_t click_left;
    toggle_t is_lclick;
    toggle_t is_rclick;
};



//
//  Animation_component
//
struct animation_s {
    toggle_t toggle;
    int actual_frame;
    anim_type type;
    anim actual_anim;
    anim_t *list;
    anim_t *actual;
};

struct anim_s {
    toggle_t toggle;
    int frames_count;
    anim name;
    sfInt64 actual_time;
    frame_t *frame;
    int (* frame_action)(game_data_t *d, entity_t *e, animation_t *a);
    anim_t *next;
};

struct frame_s {
    sfIntRect crop;
    sfInt64 trigger;
};



//
//  Script Component
//
struct script_s {
    toggle_t toggle;
    toggle_t time_dependent;
    sfInt64 trigger;
    sfInt64 actual;
    char *name;
    void *data;
    int (*update)(void **d, game_data_t *g, entity_t *e);
    void (*destroy)(void **d);
    script_t *next;
};

struct script_list_s{
    toggle_t toggle;
    script_t *list;
    int count;
};





//
//  free components
//
void free_scripts(script_t *scripts);
void free_script_list(script_list_t *scripts);
void free_text(texts_t *texts);
void free_rendersprite(render_sprite_t *render);
void free_sound_list(sfx_list_t *sounds);
void free_anim_list(anim_t *animation);
void free_animation(animation_t *animation);



//
//  create components
//
components_t *malloc_components(void);

render_sprite_t *malloc_rendersprite(void);
transform_t *malloc_transform(void);
script_list_t *malloc_script_list(void);
interact_t *malloc_interact(void);
collider_t *malloc_collider(void);
animation_t *malloc_animations(void);
sfx_list_t *malloc_sfx_list(void);
texts_t *malloc_text_struct(void);

sound_t *malloc_sfx_array(int size);

script_t *malloc_script_node(void);

frame_t *malloc_frames_array(int count);
anim_t *malloc_anim_frame(void);

text_t *malloc_text_array(int size);


#endif //LIBCSFML_BASE_COMPONENTS_H
