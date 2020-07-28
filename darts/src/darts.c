#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t p) {
	double d = sqrt(p.x * p.x + p.y * p.y);
	uint8_t result = 0;

	if(d > 10) {
	}
	else if(d > 5) {
		result += 1;
	}
	else if(d > 1) {
		result += 5;
	}
	else {
		result += 10;
	}

	return result;
}
