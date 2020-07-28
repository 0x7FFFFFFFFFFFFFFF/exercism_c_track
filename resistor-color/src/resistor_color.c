#include "resistor_color.h"
#include <stdlib.h>

int color_code(resistor_band_t r) {
	return r;
}


resistor_band_t* colors() {
	resistor_band_t* p = (resistor_band_t*) malloc(10 * sizeof(resistor_band_t));
	for(int i = 0; i <10; i++) {
		p[i] = i;
	}
	return p;
}
