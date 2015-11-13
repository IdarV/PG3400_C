#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "fileReader.h"
#include "stringHelpers.h"

// Dictionary is simply a list of words
Dictionary *initDictionary(){
  Dictionary *dictionary = malloc(sizeof(Dictionary));
  dictionary->wordsListIndex = 0;
  dictionary->wordsListCapacity = 10;
  dictionary->wordsList = malloc(sizeof(char*) * 10);
  return dictionary;
}

void addWordToDictionary(Dictionary *dictionary, char *word){
  // Reallocate if we do not have sufficent space
  if(dictionary->wordsListIndex >= dictionary->wordsListCapacity - 2){
    dictionary->wordsListCapacity *= 2;
    dictionary->wordsList = realloc(dictionary->wordsList, sizeof(char*) * dictionary->wordsListCapacity + 1);
  }
  // Allocate space for word, copy it over and add it to word-list
  char *mallocedWord = malloc(strlen(word) + 1);
  memcpy(mallocedWord, word, strlen(word) + 1);
  dictionary->wordsList[dictionary->wordsListIndex++] = mallocedWord;
}

// Free all allocated space
void freeDictionary(Dictionary *dictionary){
  for(int i = 0; i < dictionary->wordsListIndex; i++){
    free(dictionary->wordsList[i]);
  }
  free(dictionary->wordsList);
  free(dictionary);
}

// Reads a file and adds it contents to a dictionary.
// The file should therefore be a dictionary
// NB. Does not care about duplicates
void fileToDictionary(Dictionary *dictionary, char *file){
  char *words = readFile(file);
  int wordsSize = strlen(words) + 1;

  char wordsCopy[wordsSize];
  strncpy(wordsCopy, words, wordsSize);
  free(words);

  char *token;
  char septs[] = "\n";

  token = strtok(wordsCopy, septs);

  // if token is not EOF (-1), add it
  while(token != NULL && token[0] != EOF){
    addWordToDictionary(dictionary, token);
    token = strtok(NULL, septs);
  }
}

// Checks if a word exists in dictionary
int wordExistsInDictionary(Dictionary *dictionary, char *word){
  for(int i = 0; i < dictionary->wordsListIndex; i++){
    if(strcmp(dictionary->wordsList[i], word) == 0){
      return 1;
    }
  }
  return 0;
}
