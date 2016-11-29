#pragma once
#include <stdint.h>

#define RELATIVE_W 4.0f
#define RELATIVE_H 3.0f
#define DEFAULT_TEXCOORDS (vec2_t){0.0f,0.0f},(vec2_t){1.0f,1.0f}

typedef union{
	struct {float x,y;};
	float a[2];
}vec2_t;

void draw_tex(uint32_t tex_id, vec2_t v1, vec2_t v2, vec2_t t1, vec2_t t2);
void draw_string(uint32_t font[2], char *string, double x, double y, double size);
	void draw_char(char c, double x, double y, double size, uint32_t font[2]);
