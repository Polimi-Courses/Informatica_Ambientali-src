/*
  Just a simple example to show that when managing variable-length
  multi-dimensional arrays, we're better using array pointers to avoid mistakes
  and not slow performance down
 */
#include <stdio.h>
#include <stdlib.h>

void test1() {
  // pointer to an int; base type is int
  int *ptr;

  // array of ints; base type is array of 10 ints
  int arr[10];

  // pointer to array of 10 ints
  int(*arr_ptr)[10];

  // points to element 0 of the array
  ptr = arr;

  // points to the whole array
  arr_ptr = &arr;

  printf("Here output is the same\n");
  printf("ptr = %p, arr_ptr = %p\n", ptr, arr_ptr);
  printf("But if we increment both (i.e. ++)\n");
  ptr++;
  arr_ptr++;
  printf("ptr = %p, arr_ptr = %p\n", ptr, arr_ptr);
}

int main(int argc, char *argv[]) {
  test1();
  return 0;
}
