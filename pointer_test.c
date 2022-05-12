#include <stdio.h>

int test0() {
  float a = 3.7;
  // Trailing 0's if output len is less than 6; + means print sign of number;
  // .2 means decimal positions
  printf("Value of a is %0+6.2f\n", a);
  // # prints 0x; 0 puts leading zeros if output string length is less than 10
  // (note that 0x string is also counted, 2 chars); x is for hex string
  printf("Address of a is %#010x\n", &a);
  // This is the true value, the value above is just to show the syntax of
  // printf for hex values and it really depends on the number of characters
  // in the real address
  printf("... or even better, it is %0p\n", &a);

  float *ptr = &a;
  printf(" through the pointer, should be the same as above\n");
  printf("Value of a is %0+6.2f\n", *ptr);
  printf("Address of a is %p\n", ptr);
  printf("Address of the pointer to a is %p\n", &ptr);
}

void test1_1(int a) {
  a = 7;
  printf("Inside test1_1 a is %d\n", a);
}

void test1_2(int *a) {
  *a = 7;
  printf("Inside test1_1 a is %d\n", *a);
}

int test1() {
  printf("Showing pass by value vs reference (i.e. pointer value)\n");
  int a = 5;
  printf("Inside test 1 a is %d\n", a);
  test1_1(a);
  printf("After call to test1_1 a is %d\n", a);
  test1_2(&a);
  printf("After call to test1_2 a is %d\n", a);
}

int main(int argc, char *argv[]) {
  test0();
  printf("***********");
  test1();
  return 0;
}
