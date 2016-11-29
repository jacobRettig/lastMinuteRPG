#include "draw.h"
#include "sys.h"
#include <windows.h>
#include <gl/gl.h>
#include <stdint.h>

void draw_tex(uint32_t tex_id, vec2_t v1, vec2_t v2, vec2_t t1, vec2_t t2){
	
	glBindTexture(GL_TEXTURE_2D,tex_id);

	
	
	glBegin(GL_POLYGON);

	glTexCoord2f(t1.x,t1.y); glVertex2f(v1.x,v1.y);
	glTexCoord2f(t1.x,t2.y); glVertex2f(v1.x,v2.y);
	glTexCoord2f(t2.x,t2.y); glVertex2f(v2.x,v2.y);
	glTexCoord2f(t2.x,t1.y); glVertex2f(v2.x,v1.y);

	glEnd();
}

void draw_clear(){
	
	glClearColor(0, 0, 0, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
/*
void draw_char(vec2_t pos,float size,uint32_t font, char c){
//ratios: 8x12
	// x = c * 


}
