#include "timer.h"

/*initalizes the timer system which is used for keeping track of how much time
 has passed for each frame, and for keeping the game loop running at the
 specified cycles per second*/
void timer_init(timer_t *timer){

	*timer = (timer_t){0};

	LARGE_INTEGER freq_query = (LARGE_INTEGER){0};

	QueryPerformanceFrequency(&freq_query);
	timer->freq = 1.0f / freq_query.QuadPart;

	QueryPerformanceCounter(&timer->old_time_64);
	timer->min_tstep = 1.0f / TIMER_CPS;
}

/*updates the timer. this needs to be called during the wait section of the
 loop to see if the process should continue or not.*/
void timer_update(timer_t *timer){

	QueryPerformanceCounter(&timer->new_time_64);

	timer->new_time += (float)(timer->new_time_64.QuadPart - timer->old_time_64.QuadPart) * timer->freq;
	timer->tstep += timer->new_time - timer->old_time;
	timer->old_time = timer->new_time;
	timer->old_time_64 = timer->new_time_64;

}
