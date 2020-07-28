#include "resistor_color_duo.h"

int color_code(resistor_band_t* c) {
	return c[0]*10 + c[1];
}
