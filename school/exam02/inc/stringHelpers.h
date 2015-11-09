#ifndef STRINGHELPERS_HEADER
#define STRINGHELPERS_HEADER
#include <stdbool.h>

bool isInRange(int start, int end, int n);

int findNextIndex(char *c, char *keyFile, int *lastIndex, int *d);

bool isLetter(char *c);

bool isHighCase(char *c);

void toLowCase(char *c);


#endif