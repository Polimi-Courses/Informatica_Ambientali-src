#include "util_conversion.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

float power_of_iterative(float base, int exp) {
  assert(exp >= 0);

  float tot = 1;
  for (int i = 0; i < exp; ++i) {
    tot *= base;
  }
}

float power_of_recursive(float base, int exp) {
  if (exp <= 0)
    return 1;
  if (exp == 1)
    return base;
  return base * power_of_recursive(base, exp - 1);
}

int main(int argc, char *argv[]) {
  assert(argc == 3);
  float b;
  if (!parse_float(argv[1], &b)) {
    fprintf(stderr, "Could not convert '%s' to long\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  long e;
  if (!parse_unsigned_long(argv[2], &e)) {
    fprintf(stderr, "Could not convert '%s' to long\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  printf("Base %f, exp %d, solution %.3f\n", b, e, power_of_iterative(b, e));
  printf("Base %f, exp %d, solution %.3f\n", b, e, power_of_recursive(b, e));

  return 0;
}
