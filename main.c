#include "draw.h"
#include "sys.h"
#include "timer.h"
#include "tex.h"
#include "game.h"
#include "input.h"

uint8_t gflags = GF_MAINLOOP;	

int main(int argc, char **argv){
	sys_t sys = (sys_t){0};
	sys_init(&sys);

	timer_t timer = (timer_t){0};
	timer_init(&timer);

	tex_t *tex = NULL;
	tex_init(&tex);

	input_t input = (input_t){0};

	game_t game = (game_t){0};
	game_init(&game,tex);

	while(gflags & GF_MAINLOOP){

		Sleep(1);
		timer_update(&timer);

		if(timer.tstep >= timer.min_tstep){
			sys_update(&sys);
			in_update(&input);

			game_loop(&game,tex,input,timer.tstep);

			sys_swapbuffers(&sys);
			timer.tstep -= timer.min_tstep;
		}
	}

	sys_shutdown(&sys);
	tex_shutdown(tex);
}
