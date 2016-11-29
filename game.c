#include "tex.h"
#include "game.h"
#include "draw.h"
#include "sys.h"
#include "input.h"
#include "sprite2.h"
#include <math.h>

#define PLAYER_W 0.2f
#define PLAYER_H 0.4f

#define PLAYER_VEL 2.0f

/*initialzies the game_t structure, which containes all information about the
 game.*/
void game_init(game_t *game, tex_t *tex_root){


	game->tex[0] = tex_load_webp(tex_root,"mouse.webp");
	game->tex[1] = tex_load_webp(tex_root,"player.webp");
	
	game->font[0] = tex_load_webp(tex_root,"font0.webp");
	game->font[1] = tex_load_webp(tex_root,"font1.webp");

	//game->player_x = game->player_y = 2.0f;
	game->s = genRandom();

	tex_flip();
}

/*the actual game loop. contains a handle to the video system, the texture 
 system, and the time it took to draw the last frame (used in physics
 calcuations)*/
void game_loop(game_t *game,tex_t *tex_root,input_t input, float tstep){

	if(input.ks[LEFT_ARROW]){
		game->player_pos.x -= PLAYER_VEL * tstep;
	}
	if(input.ks[RIGHT_ARROW]){
		game->player_pos.x += PLAYER_VEL * tstep;
	}
	if(input.ks[UP_ARROW]){
		game->player_pos.y += PLAYER_VEL * tstep;
	}
	if(input.ks[DOWN_ARROW]){
		game->player_pos.y -= PLAYER_VEL * tstep;
	}

	draw_clear();
	
	draw_tex(game->tex[0],(vec2_t){0.0f,0.0f},(vec2_t){4.0f,3.0f},DEFAULT_TEXCOORDS);
	draw_tex(game->tex[1],game->player_pos, (vec2_t){game->player_pos.x + PLAYER_W,game->player_pos.y + PLAYER_H},DEFAULT_TEXCOORDS);
	drawSprite(&game->s,tstep);
}

