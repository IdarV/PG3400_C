char *encodeWithDistance(char *keyFile, char *secretMessage, int d);
char *encode(char *keyFile, char *secretMessage);
int findNextIndex(char *c, char *keyFile, int *lastIndex, int *d);
bool isInRange(int start, int end, int n);
