#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  printf("RAND_MAX = %d\n", RAND_MAX);
  time_t t;

  srand((unsigned)time(&t));
  printf("time %d\n", t);

  printf("Getting random %100 values\n");
  for (int i = 0; i < 20; ++i)
    printf("%d\n", rand() % 100);

  return 0;
}
