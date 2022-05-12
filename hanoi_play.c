#include "hanoi.h"
#include <stdbool.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("Initializing game ...\n");
  init_game();
  bool win = false;
  char choice;
  size_t src, dst;

  do {
    print_status();
    printf("Give me the src and dst stick as numbers\n");
    scanf("%zu %zu", &src, &dst);
    if (!move(src, dst))
      printf("Invalid choice, retry\n");
    if (check_victory()) {
      printf("Congratulations, you win\n");
      print_status();
      return 0;
    }
  } while (!win);
  return 0;
}
