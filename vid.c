#include "vid.h"
#include "tex.h"
#include <stdlib.h>

#define vid_size(vid) (vid->w * vid->h * VID_BPP)

void vid_draw_tex(vid_t *vid, tex_t *tex, vec2_t v1){

	uint16_t y_min = v1.y; uint16_t y_max = v1.y + tex->h;
	uint16_t x_min = v1.x; uint16_t x_max = v1.x + tex->w;

	uint32_t byte_w = vid->w * VID_BPP;
	uint32_t write_w = (x_max - x_min) * VID_BPP;

	uint32_t off_min = (y_min * byte_w) + (x_min * VID_BPP);
	uint32_t off_max = (y_max * byte_w) + (x_max * VID_BPP);

	size_t tex_size = tex->w * tex->h * VID_BPP; 
	size_t bmp_size = vid_size(vid);

	size_t bm_off = off_min; size_t tex_off = 0;

	while(bm_off < off_max && bm_off < bmp_size && tex_off < tex_size){
		
		memcpy(vid->bmp + bm_off,tex->bmp + tex_off,write_w);
		
		tex_off += write_w;
		bm_off += byte_w;
	}

}

void vid_clear_color(vid_t *vid, color_t c){
	for(size_t off = 0;off < vid_size(vid); off += VID_BPP){
		memcpy(vid->bmp + off,c.c,VID_BPP);
	}
}

void vid_clear_shade(vid_t *vid,uint8_t shade){
	memset(vid->bmp,shade,vid_size(vid));
}

void vid_init(vid_t *vid){

	vid->w = vid->real_w = VID_DEFAULT_W;
	vid->h = vid->real_h = VID_DEFAULT_H;
	
	vid->bmp = malloc(vid_size(vid));
}

void vid_shutdown(vid_t *vid){
	free(vid->bmp);
}
