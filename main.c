#include "vid.h"
#include "sys.h"
#include "timer.h"
#include "tex.h"
#include "game.h"

uint8_t gflags = GF_MAINLOOP;	

int main(int argc, char **argv){

	vid_t vid = (vid_t){0};
	vid_init(&vid);

	sys_t sys = (sys_t){0};
	sys_init(&sys,&vid);

	timer_t timer = (timer_t){0};
	timer_init(&timer,&vid);

	tex_t *tex = NULL;
	tex_init(&tex);

	while(gflags & GF_MAINLOOP){

		Sleep(1);
		timer_update(&timer);

		if(timer.tstep >= timer.min_tstep){
			sys_update(&sys,&vid,&timer);

			game(&vid,tex,timer.tstep);

			sys_swapbuffers(&sys,&vid);
			timer.tstep -= timer.min_tstep;
			if(timer.tstep > timer.min_tstep){
				timer.tstep = 0;
			}
		}
	}

	sys_shutdown(&sys);
	vid_shutdown(&vid);
	tex_shutdown(tex);
}
