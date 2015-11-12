#ifndef FILEREADER_HEADER
#define FILEREADER_HEADER

#include "arrayList.h"

char *readKeyFile(char *filename);
char *readFile(char *filename);
void ReadKeyFiles(ArrayList *arrayList, char *keyFilesFolder);

#endif
