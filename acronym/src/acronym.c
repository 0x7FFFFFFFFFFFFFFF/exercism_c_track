#include "acronym.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


char *abbreviate(const char *input) {
    // Deal with corner cases
    if (!input || strlen(input) == 0)
        return NULL;

    // Create a duplicate string, as the one passed in is not modifiable
    // +1 is for the string terminator \0
    char *input_dup = malloc(strlen(input) + 1);
    strcpy(input_dup, input);

    // We will use the input length multiple times later. So it will be slightly faster to save it in a variable. 
    long unsigned int len = strlen(input_dup);

    // We assume the max length of the acronym is 100 characters
    char data[100];

    // Initialize data
    for (int i = 0; i < 100; i++)
        data[i] = '\0';

    // The first character of the input string is always included in the acronym
    char tmp = input_dup[0];

    // If the character is a lower char, make it upper case
    if (tmp >= 'a' && tmp <= 'z')
        tmp -= 32;

    // Store the char in our acronym data array
    data[0] = tmp;

    // Next position that we will put character in in the data array
    int result_index = 1;

    char *start;
    long unsigned int next_index = 0;
    while ((start = strpbrk(input_dup, " -"))) {
        next_index = (start - input_dup) / sizeof(char) + 1;
        if (next_index <= (len - 1)) {
            tmp = input_dup[next_index];
            input_dup[next_index - 1] = 'x';
            // Change lower case to upper if necessary
            if (tmp >= 'a' && tmp <= 'z')
                tmp -= 32;
            data[result_index++] = tmp;
        }
    }

    int result_len = 0;
    for (int i = 0;; i++)
        if (data[i] != '\0')
            result_len++;
        else
            break;
    char *result = malloc(result_len * sizeof(char) + 1);
    for (long unsigned int i = 0; i < result_len * sizeof(char) + 1; ++i) {
        result[i] = '\0';
    }
    for (int i = 0; i < result_len; i++)
        result[i] = data[i];
    free(input_dup);
    return result;
}

