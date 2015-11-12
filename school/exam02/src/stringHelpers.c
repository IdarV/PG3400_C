#include "stringHelpers.h"
#include <stdlib.h>
#include <stdio.h>

bool isInRange(int start, int end, int n) {
    for (int i = start; i <= end; i++) {
        if (n == i) {
            return true;
        }
    }
    return false;
}

// Check if the char ASCII is between [A-Za-z]
bool isLetter(char *c){
    //return (32 <= *c && 126 >= *c); // || (*c >= 'A' && *c <= 'Z'
    return (('A' <= *c && 'Z' >= *c) || ('a' <= *c && 'z' >= *c));
}

// If the char is lower than 90, its highcase
bool isHighCase(char *c){
    return 'A' <= *c && 'Z' >= *c;
}

// To make a char lowcase, add 32. This is basic ASCII.
void toLowCase(char *c){
    *c = *c + 32;
}

// d is distance
int findNextIndex(char *c, char *key, int *lastIndex, int *d) {
    int start = *lastIndex;
    if(start == -1){
        start = 0;
    }
    int looped = 0;
    int index = 0;
    char currentChar = 0;

    do {
        currentChar = key[index];

        // if currentchar and currenchar is out of range of the last char
        if (currentChar == *c && !isInRange(*lastIndex - *d, *lastIndex + *d, index)) {
            return index;
        }

        // If current char is end-of-line, reset to start of string.
        else if('\0' == currentChar){
            // (index will be incresed to 0 further down)
            index = -1;
            looped = 1;
        }

        index++;

    } while (start != index || looped == 0);

    return -1;
}
