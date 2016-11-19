#include "tex.h"
#include "vid.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <webp/decode.h>
#include <stdint.h>

void tex_init(tex_t **tex){
	*tex = calloc(1,sizeof(tex_t));
}

void tex_shutdown(tex_t *tex){
	if(tex){
		tex_shutdown(tex->next);
		if(tex->bmp){
			free(tex->bmp);
		}
		free(tex);
	}
}

void tex_flip_bmp(uint8_t *bmp,uint16_t w,uint16_t h){
	
	size_t line_width = w * VID_BPP;
	size_t size = w * h * VID_BPP;

	void *temp = malloc(line_width);

	for(uint32_t i = 1; i < (h / 2); i++){

		memcpy(temp,bmp + (i * line_width),line_width);

		memcpy(bmp + (i * line_width),(bmp + size) - (i * line_width), line_width);

		memcpy((bmp + size) - (i * line_width), temp, line_width);
	}
	
	free(temp);
}

tex_t *tex_load_webp(tex_t *tex, const char *filename){

	if(!tex){
		return NULL;
	}
	
	while(tex->next){
		if(!tex->bmp){
			goto found_early;
		}
		tex = tex->next;
	}

	tex->next = calloc(1,sizeof(tex_t));
	tex = tex->next;

found_early: ;

	size_t data_size = 0;
	void *data = NULL;

	FILE *fp = fopen(filename, "rb");
	if (!fp){
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	data_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	data = malloc(data_size);
	fread(data, data_size, 1, fp);

	fclose(fp);

	int width, height;
	uint8_t *dec_data = WebPDecodeBGR(data, data_size, &width, &height);
	free(data);

	tex_flip_bmp(dec_data,width,height);

	tex->bmp = dec_data;
	tex->w = width;
	tex->h = height;

	return tex;
}
