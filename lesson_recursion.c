#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int fact_w_print(int x) {
  counter++;
  for (int i = 0; i < counter; ++i)
    printf(">");
  if (x <= 1) {
    printf("Base case, returning 1\n");
    return 1;
  } else {
    printf("x = %d\n", x);
    int tmp = x * fact_w_print(x - 1);
    counter--;
    for (int i = 0; i < counter; ++i)
      printf(">");
    printf("Returning %d\n", tmp);
    return tmp;
  }
}

int fact(int x) {
  if (x <= 1)
    return 1;
  else
    return x * fact(x - 1);
}

int fibonacci(int x) {
  if (x <= 1)
    return 1;
  return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
  /* int a = fact_w_print(5); */
  /* int a = fact(5); */
  int a = fibonacci(7);
  printf("%d\n", a);
}
