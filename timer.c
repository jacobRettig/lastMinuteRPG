#include "vid.h"
#include "timer.h"

void timer_init(timer_t *timer, vid_t *vid){

	*timer = (timer_t){0};

	LARGE_INTEGER freq_query = (LARGE_INTEGER){0};

	QueryPerformanceFrequency(&freq_query);
	timer->freq = 1.0f / freq_query.QuadPart;

	QueryPerformanceCounter(&timer->old_time_64);
	timer->min_tstep = 1.0f / TIMER_CPS;
}

void timer_update(timer_t *timer){

	QueryPerformanceCounter(&timer->new_time_64);

	timer->new_time += (float)(timer->new_time_64.QuadPart - timer->old_time_64.QuadPart) * timer->freq;
	timer->tstep += timer->new_time - timer->old_time;
	timer->old_time = timer->new_time;
	timer->old_time_64 = timer->new_time_64;

}
