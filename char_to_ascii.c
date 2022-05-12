#include <stdio.h>

int main(int argc, char *argv[]) {
  fprintf(stdout, "Insert letter\n");
  char c;
  scanf("%c", &c);
  fprintf(stdout, "Your letter has an ASCII value of %d\n", c);
  return 0;
}
