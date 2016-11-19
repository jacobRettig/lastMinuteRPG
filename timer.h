#pragma once

#include "vid.h"
#include <windows.h>

#define TIMER_CPS 60

typedef struct timer_s{

	LARGE_INTEGER old_time_64;
	LARGE_INTEGER new_time_64;

	float old_time;
	float new_time;
	float freq;
	float tstep;
	float min_tstep;
}timer_t;

void timer_init(timer_t *timer, vid_t *vid);
void timer_update(timer_t *timer);
