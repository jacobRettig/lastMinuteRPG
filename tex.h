#pragma once
#include <stdint.h>
#define VID_BPP 3

#define red (color_t){0,0,255}
#define blue (color_t){255,0,0}
#define green (color_t){0,255,0}
#define white (color_t){255,255,255}
#define black (color_t){0,0,0}
#define cyan (color_t){255,255,0}
#define yellow (color_t){0,255,255}
#define purple (color_t){255,0,255}
#define random (color_t){rand()%256,rand()%256,rand()%256}

typedef struct tex_s{
	struct tex_s *next;
	uint16_t w,h;
	uint8_t *bmp;
}tex_t;

typedef union{
	struct{uint8_t b,g,r;};
	uint8_t c[VID_BPP];
} color_t;

void tex_init(tex_t **tex);
void tex_shutdown(tex_t *tex);
tex_t *tex_load_webp(tex_t *tex, const char *filename);
