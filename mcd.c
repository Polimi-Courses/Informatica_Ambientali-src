#include "util_conversion.h"
#include <assert.h>
#include <stdio.h>

int mcd(int x, int y) {
  if (y == x)
    return x;
  if (y > x)
    return mcd(x, y - x);
  return mcd(x - y, x);
}

int main(int argc, char *argv[]) {
  assert(argc == 3);

  long x, y;
  if (!parse_unsigned_long(argv[1], &x))
    exit(EXIT_FAILURE);
  if (!parse_unsigned_long(argv[2], &y))
    exit(EXIT_FAILURE);
  printf("%d\n", mcd(x, y));

  return 0;
}
