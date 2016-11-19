#pragma once

#include "tex.h"
#include <stdint.h>

#define VID_DEFAULT_W 640
#define VID_DEFAULT_H 480
#define VID_BPP 3

typedef struct vid_s{
	uint16_t w,h;
	uint16_t real_w,real_h;
	uint8_t *bmp;

	//uint8_t *buffer_blank;
}vid_t;

typedef union{
	struct{uint16_t x,y;};
	uint16_t v[2];	
}vec2_t;

void vid_init(vid_t *vid);
void vid_shutdown(vid_t *vid);
void vid_draw_tex(vid_t *vid, tex_t *tex, vec2_t v1);
void vid_clear_color(vid_t *vid, color_t c);
void vid_clear_shade(vid_t *vid,uint8_t shade);
