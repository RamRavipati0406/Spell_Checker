#include "spell.h"

int main(int argc, char **argv) {

  int sizeOfDictinory = 0, output_true, counter;
  char c, ch;
  char **wordsarray;
  char temp[44];
  char tempforline[500][500];
  int zero_or_one = 0;
  int linenum = 1;
  // for pathstuff and for output file
  FILE *first_p = fopen(argv[2], "r");
  FILE *second_p = fopen("output.txt", "w");
  int flag2;
  int flag = fscanf(first_p, "%s", temp);
  // for line count
  FILE *third_p = fopen(argv[2], "r");
  char line[500][500];
  char fname[20];
  int i = 0;
  int tot = 0;
  char *p;
  while (fgets(line[i], 500, third_p)) {
    line[i][strlen(line[i]) - 1] = '\0';
    i++;
  }
  tot = i;
  // printf("\n The content of the file %s  are : \n",fname);

  sizeOfDictinory = parseDict(argv[1], &wordsarray);

  while (flag == 1) {

    zero_or_one = wordSearch(temp, wordsarray, sizeOfDictinory);

    if (zero_or_one == 0) {
      for (i = 0; i < tot; ++i) {
        // printf(" %s\n", line[i]);
        // Find first occurrence of s2 in s1
        p = strstr(line[i], temp);
        if (p) {
          // line stars with 1 but i from 0
          linenum = i + 1;
          break;
        }
      }
      output_true = bad_word(temp, linenum, second_p);
    }

    flag = fscanf(first_p, "%s", temp);
  }

  fclose(first_p);
  fclose(second_p);
	fclose(third_p);

  return 0;
}
