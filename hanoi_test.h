#include "hanoi.h"

void test() {
  init_game();
  print_status();
  int j = -1;
  int size = -1;
  bool x = get_top_disc_position_size(0, &j, &size);
  printf("%d:", x);
  x ? printf(" %d %d\n", j, size) : printf("\n");

  x = get_top_disc_position_size(1, &j, &size);
  printf("%d:", x);
  x ? printf(" %d %d\n", j, size) : printf("\n");

  x = get_top_disc_position_size(2, &j, &size);
  printf("%d:", x);
  x ? printf(" %d %d\n", j, size) : printf("\n");

  x = get_top_disc_position_size(3, &j, &size);
  printf("%d:", x);
  x ? printf(" %d %d\n", j, size) : printf("\n");
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
