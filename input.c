#include "input.h"
#include <windows.h>
#include <ctype.h>

#define IN_KEYC 256

void in_update(input_t *input){
	for(uint16_t i = 0; i < IN_KEYC; i++){
		input->ks[i] = GetAsyncKeyState(i);
	}
}
