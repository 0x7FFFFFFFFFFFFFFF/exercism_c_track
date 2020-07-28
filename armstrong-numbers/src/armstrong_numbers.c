#include <stdio.h>
#include <math.h>
#include "armstrong_numbers.h"

#define array_size 20

bool is_armstrong_number(int n) {
	int digits[array_size];
	for(int i = 0; i < array_size; i++) {
		digits[i] = 0;
	}

	int number_of_digits = 0;
	int sum = 0;
	int original_number = n;

	int digits_write_to = 0;

	while(n > 0) {
		digits[digits_write_to++] = n % 10;
		number_of_digits++;
		n /= 10;
	}
		
	for(int i = 0; i < number_of_digits; i++) {
		sum += pow(digits[i], number_of_digits);
	}
	return sum == original_number;
}
