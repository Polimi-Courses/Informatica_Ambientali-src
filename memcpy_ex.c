#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *s = "Hello world";
  char *s2 = (char *)malloc(sizeof(char) * strlen(s));

  memcpy(s2, s, strlen(s) / 2);
  printf("%p --> %s\n", s, s);
  printf("%p --> %s\n", s2, s2);

  int is1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *is2 = (int *)malloc(sizeof(int) * 10);
  memcpy(is2, is1 + 3, 4 * sizeof(int));
  for (int i = 0; i < 4; ++i) {
    printf("%d ", is2[i]);
  }
  printf("\n");
  return 0;
}
