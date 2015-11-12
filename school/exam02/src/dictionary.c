#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

Dictionary *initDictionary(){
  Dictionary *dictionary = malloc(sizeof(Dictionary));
  dictionary->wordsListIndex = 0;
  dictionary->wordsListCapacity = 10;
  dictionary->wordsList = malloc(sizeof(char*) * 10);
  return dictionary;
}

void addWordToDictionary(Dictionary *dictionary, char *word){
  if(dictionary->wordsListIndex >= dictionary->wordsListCapacity - 2){
    dictionary->wordsListCapacity *= 2;
    dictionary->wordsList = realloc(dictionary->wordsList, sizeof(char*) * dictionary->wordsListCapacity);
  }
  char *mallocedWord = malloc(strlen(word));
  memcpy(mallocedWord, word, strlen(word) + 1);
  dictionary->wordsList[dictionary->wordsListIndex++] = mallocedWord;
}

void freeDictionary(Dictionary *dictionary){
  for(int i = 0; i < dictionary->wordsListIndex; i++){
    free(dictionary->wordsList[i]);
  }
  free(dictionary->wordsList);
  free(dictionary);
}
