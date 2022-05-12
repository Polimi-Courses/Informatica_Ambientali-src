#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Basic pointers
 */

void bla(int x) {
  x = 7;
  printf("bla: a = %d\n", x);
  printf("bla: %p\n", &x);
}

void boh(int *x) {
  *x = 7;
  printf("boh: a = %d\n", *x);
  printf("boh: %p\n", x);
}

void test1() {
  int a = 5;
  int *ptr = &a;

  printf("test1: ptr = %p--> a = %d\n", ptr, *ptr);
  printf("***********\n");

  bla(a);
  printf("test1, after bla: a = %d\n", a);
  printf("***********\n");

  boh(&a);
  printf("test1, after boh: a = %d\n", a);
  printf("***********\n");

  int **ptr2 = &ptr;
  printf("test1: ptr2 = %p --> ptr1 = %p --> %d\n", ptr2, *ptr2, **ptr2);
  printf("***********\n");
}
/*
 * Pointer and array
 */

void test1a() {
  printf("test1a:\n");
  const int n = 10;
  int a[n]; // a contains address of a[0], i.e (a == &a[0])
  printf("indirizzo a %p\n", a);

  // how to iterate an array
  for (int i = 0; i < n; i++)
    a[i] = i; // a[i] is exactly the same as *(a + i)
  // i = i+1; i, i = i+1

  printf("Pointers arithmetic\n");
  for (int *ptr = a; ptr < a + n; ++ptr)
    printf("%p --> %d\n", ptr, *ptr);
  printf("***********\n");

  // dynamic arrays
  // Just to simulate a random integer
  time_t t;
  srand((unsigned)time(&t));
  int n2 = rand() % 20;
  //

  printf("test1a: size of dynamic array is %d\n", n2);
  int *a2 = (int *)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; ++i) {
    *(a2 + i) = i * 3;
    printf("%p --> %d\n", (a2 + i), *(a2 + i));
  }
  printf("***********\n");
}

/*
 * Pointers to struct
 */
typedef struct {
  int x;
  float y;
  unsigned z;
  char c[20];
} AStruct_t;

void foo(AStruct_t as) {
  as.x = 3;
  printf("foo: size of as is %u\n", sizeof(as));
}

void bar(AStruct_t *as) {
  as->x = 3; // (*as).x
  printf("bar: size of as is %u\n", sizeof(as));
}

void test2() {
  AStruct_t as = {1, 2.3, 4, "blablablab"};
  foo(as);
  printf("test2, after foo: %d\n", as.x);
  printf("***********\n");
  bar(&as);
  printf("test2, after bar: %d\n", as.x);
  printf("***********\n");
}
/*
 * sizeof collapsing
 */
void kit(char *s) { printf("kit: %u\n", sizeof(s)); }

void test3() {
  char s[20] = "Hello";
  kit(s);
  printf("test3: %u\n", sizeof(s));
  printf("***********\n");
}

/*
 * Dynamic creation of a struct, wrong, bcz of local pointer
 */

AStruct_t *build_struct_wrong(int x, float y, unsigned z, char *c) {
  AStruct_t as = {x, y, z, *c};
  return &as;
}

void test4_wrong() {
  AStruct_t *as = build_struct_wrong(5, 3.7, 4, "Hello world");
  printf("test4_wrong: %d\n", as->x);
}

/*
 * Dynamic creation of a struct, right
 */
AStruct_t *build_struct(int x, float y, unsigned z, char *c) {
  AStruct_t *as = (AStruct_t *)malloc(sizeof(AStruct_t));
  as->x = x;
  as->y = y;
  as->z = z;
  strncpy(as->c, c, 20);
  return as;
}

void test4() { AStruct_t *as = build_struct(5, 3.7, 4, "Hello world"); }

/*
 * Dynamic creation of an array of structs
 */

void test5() {
  const int n = 10;
  AStruct_t **ass = (AStruct_t **)malloc(sizeof(AStruct_t *) * n);
  for (int i = 0; i < n; ++i) {
    ass[i] = build_struct(i, i * 3.3, i * 10 + 1, "Hello");
  }
  printf("Struct number 5: %d %.3f %u %s\n", ass[5]->x, ass[5]->y, ass[5]->z,
         ass[5]->c);
  printf("****************\n");
}

/*
 * Convert string to struct
 */
void test6() {
  const char *tmp = "5 3.5 4 blablabla";

  AStruct_t *as = (AStruct_t *)malloc(sizeof(AStruct_t));

  sscanf(tmp, "%d %f %u %s", &(as->x), &(as->y), &(as->z), as->c);
  printf("Struct : %d %.3f %u %s\n", as->x, as->y, as->z, as->c);
  printf("****************\n");
}

int main(int argc, char *argv[]) {
  /* test1(); */
  /* test1a(); */
  /* test2(); */
  test3();
  /* test4_wrong(); */
  /* test4(); */
  /* test5(); */
  /* test6(); */
  return 0;
}
