#include "input.h"
#include "draw.h"
#include "sprite2.h"
#pragma once
typedef struct game_s{
	uint32_t tex[4];
	uint32_t font[2];
	vec2_t player_pos;

	Sprite s;
}game_t;

void game_init(game_t *game, tex_t *tex_root);
void game_loop(game_t *game,tex_t *tex_root,input_t input, float tstep);
