#pragma once
#include <stdint.h>
#include <windows.h>
#include <gl/gl.h>
#define VID_BPP 3

typedef struct tex_s{
	struct tex_s *next;
	GLuint t;
}tex_t;

void tex_init(tex_t **tex);
void tex_shutdown(tex_t *tex);
uint32_t tex_load_webp(tex_t *tex, const char *filename);
void tex_flip();
