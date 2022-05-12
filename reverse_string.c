#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char word[101];
  char reversed[101];

  printf("Give me a word (max 100 letters)\n");
  scanf("%s", &word);

  int len = strlen(word);

  for (int i = 0; i < len; ++i) {
    reversed[i] = word[len - 1 - i];
  }
  reversed[len] = '\0';

  printf("The reversed word is %s\n", reversed);

  return 0;
}
