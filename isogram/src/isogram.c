#include "isogram.h"
#include <stddef.h>
#include <string.h>

#define data_size 256

bool is_isogram(const char s[]) {
	if(!s)
		return false;

	int data[data_size];
	// Init data array to 0
	for(int i = 0; i < data_size; i++) {
		data[i] = 0;
	}

	size_t len = strlen(s);
	for(size_t i = 0; i < len; i++) {
		char c = s[i];
		if(c == ' ' || c == '-')
			continue;
		if(c >= 65 && c <=90)
			c += 32;
		data[(int)c]++;
		if(data[(int)c] > 1)
			return false;
	}
	return true;
}
