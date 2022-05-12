#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data/es.txt"

int w_fscanf() {
  printf("******fscanf\n");
  FILE *f = fopen(FILENAME, "r");
  if (f == NULL)
    return -1;
  char s[100];
  int res;
  int counter = 0;
  while ((res = fscanf(f, "%s", s)) != EOF) {
    printf("%d %s\n", res, s);
    counter++;
  }
  printf("Exit %d %d %s\n", counter, res, s);
  fclose(f);
  return counter;
}

int w_fgets() {
  printf("**********fgets\n");
  FILE *f = fopen(FILENAME, "r");
  if (f == NULL)
    return -1;
  char line[1000];
  int counter = 0;
  while ((fgets(line, 1000, f)) != NULL) {
    printf("%s", line);
    counter++;
  }
  return counter;
}

int w_fgetc() {
  printf("**********fgetc\n");
  FILE *f = fopen(FILENAME, "r");
  if (f == NULL)
    return -1;
  int lines = 0;
  char ch;
  // Reading char by char
  while ((ch = fgetc(f)) != EOF) {
    if (ch == '\n')
      lines++;
  }
  fclose(f);
  return lines;
}

int main(int argc, char *argv[]) {
  printf("Main fscanf: %d\n", w_fscanf());
  printf("Main fgetc: %d\n", w_fgetc());
  printf("Main fgets: %d\n", w_fgets());

  return 0;
}
