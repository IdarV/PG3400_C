#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct{
  int wordsListIndex;
  int wordsListCapacity;
  char **wordsList;
} Dictionary;

Dictionary *initDictionary();
void addWordToDictionary(Dictionary *dictionary, char *word);
void freeDictionary(Dictionary *dictionary);

#endif
