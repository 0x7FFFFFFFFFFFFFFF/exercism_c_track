#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t x[]) {
	resistor_value_t result;
	result.unit = OHMS;
	int n = (int)((x[0]*10 + x[1]) * pow(10, x[2]));
	result.value = n;

	if(n >= 1000) {
		result.unit = KILOOHMS;
		result.value = (int)(n / 1000);
	}
	return result;
}
