#include "spell_lib.h"

int parseDict(char *pathname, char ***output) {

  int count = 0;
  char c, ch;
  FILE *ip = fopen(pathname, "r");
  if (ip == NULL) {
    printf("input file can't be opened");
    exit(-1);
  }

  for (c = getc(ip); c != EOF; c = getc(ip)) {
    if (c == '\n') {
      count = count + 1;
    }
  }

  char **str_arry = malloc((sizeof(char *) * count));
  str_arry[count] = NULL;

  FILE *second_ip = fopen(pathname, "r");
  char word[100];
  for (int i = 0; i < count; i++) {
    str_arry[i] = malloc(sizeof(char *));
    fscanf(second_ip, "%s", word);
    strcpy(str_arry[i], word);
  }
  *output = str_arry;

  // printing it test
  // for (int i = 0; i < 3; i++) {
  //   printf("%s\n", str_arry[i]);
  // }

  fclose(ip);
  fclose(second_ip);
  return count;
}

int wordSearch(char *word, char **dict, int dictSize) {
  // like do-g
  int has_non_letter_inside = 0;

  if (dictSize == 0 || dictSize < 0) {
    printf("the size of the dictionary is bad");
    exit(-1);
  }

  for (int i = 0; i < strlen(word); i++) {

    if (isalpha(word[i]) == 0) {
      has_non_letter_inside = 1;
    } else if (has_non_letter_inside == 1) {
      return 0;
    }
  }

  char temp[50] = "";
  word = strtok(word, " .,/*&^%$#!@()1234567890~-+|[]{}\n\t");
  for (int i = 0; i < dictSize; i++) {

    strcpy(temp, dict[i]);
    if (strcasecmp(word, temp) == 0)
      return 1;
  }

  return 0;
}

int bad_word(char *word, int line, FILE *out) {
  int did_or_not;
  if (out == NULL) {
    printf("somthing wrong with the output file");
    exit(-1);
  }

  did_or_not =
      fprintf(out, "Unknown word %s found in the line %d of the input file\n",
              word, line);

  if (did_or_not < 0) {
    return did_or_not = 0;
  } else {
    return did_or_not = 1;
  }
  // some retunr should be before closing
  return 1;
}