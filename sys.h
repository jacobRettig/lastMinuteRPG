#pragma once
#include "timer.h"
#include <windows.h>

#define GF_MAINLOOP 1 << 0
#define GF_RESIZE 1 << 1
#define GF_EDITOR 1 << 2

#define DEFAULT_W 640
#define DEFAULT_H 480

typedef struct sys_s{
	HWND hw;
	BITMAPINFO bmi;
	HDC dc;
	HGLRC rc;
}sys_t;

void sys_init(sys_t *sys);
void sys_shutdown(sys_t *sys);
void sys_update(sys_t *sys);
void sys_swapbuffers(sys_t *sys);
