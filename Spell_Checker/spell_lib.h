#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseDict(char *pathname, char ***output);

int wordSearch(char *word, char **dict, int dictSize);

int bad_word(char *word, int line, FILE *out);