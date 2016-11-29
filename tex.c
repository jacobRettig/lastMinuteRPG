#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <webp/decode.h>
#include <stdint.h>
#include <gl/gl.h>

/*initalizes the texture system by allocatting the first element of the
 linked list on the heap*/
void tex_init(tex_t **tex){
	*tex = calloc(1,sizeof(tex_t));
	(*tex)->t = -1;
}

/*frees all memory that the texture system ever allocated (the entire system
 is stored on the heap, so all of it is deleted here)*/
void tex_shutdown(tex_t *tex){
	if(tex){
		tex_shutdown(tex->next);
		glDeleteTextures(1,&tex->t);
		free(tex);
	}
}

/*loads a .webp image into the texture system and returns a handle to it. the
 parameter tex must be the root node of the texture system.*/
uint32_t tex_load_webp(tex_t *tex, const char *filename){

	if(!tex){
		return 0;
	}
	
	while(tex->next){
		if(tex->t == -1){
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
		return 0;
	}

	fseek(fp, 0, SEEK_END);
	data_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	data = malloc(data_size);
	fread(data, data_size, 1, fp);

	fclose(fp);

	int width, height;
	void* dec_data = WebPDecodeRGBA(data, data_size, &width, &height);
	free(data);

	glGenTextures(1, &tex->t);
	glBindTexture(GL_TEXTURE_2D, tex->t);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dec_data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	free(dec_data);

	return tex->t;
}

void tex_flip(){
	
	glMatrixMode(GL_TEXTURE);
	glScalef(1.0f,-1.0f,1.0f);
	glMatrixMode(GL_MODELVIEW);

}
