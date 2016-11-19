#pragma once
#include "timer.h"
#include <windows.h>

#define GF_MAINLOOP 1 << 0
#define GF_RESIZE 1 << 1

typedef struct sys_s{
	HWND hw;
	BITMAPINFO bmi;
	HDC dc;
}sys_t;

void sys_init(sys_t *sys, vid_t *vid);
void sys_shutdown(sys_t *sys);
void sys_update(sys_t *sys, vid_t *vid, timer_t *timer);
void sys_swapbuffers(sys_t *sys,vid_t *vid);
