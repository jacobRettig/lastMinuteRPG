#pragma once
#include <stdint.h>

#define LEFT_ARROW VK_LEFT
#define RIGHT_ARROW VK_RIGHT
#define UP_ARROW VK_UP
#define DOWN_ARROW VK_DOWN

typedef struct input_s{
	uint8_t ks[256];

}input_t;

void in_update(input_t *input);
