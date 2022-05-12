#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

void test_queue() {
  List *list = NULL;
  printf("Pushing\n");
  list = push(list, 3);
  list = push(list, 4);
  list = push(list, 5);

  fprint_list(stdout, list);

  printf("\nPopping\n");
  int v;
  list = pop(list, &v);
  printf("%d\n", v);
  assert(v == 5);
  list = pop(list, &v);
  printf("%d\n", v);
  assert(v == 4);
  list = pop(list, &v);
  printf("%d\n", v);
  assert(v == 3);
  assert(list == NULL);
  fprint_list(stdout, list);
}

void test_list() {
  List *l = NULL;
  l = push(l, 10);
  l = push(l, 11);
  l = push(l, 12);
  l = push(l, 13);
  l = push(l, 14);

  int v;
  bool b;
  b = get_value_at(l, 4, &v);
  printf("%d\n", v);
  assert(v == 10);
  assert(b);

  b = get_value_at(l, 15, &v);
  assert(!b);

  fprint_list(stdout, l);
  get_value_at(l, 3, &v);
  printf("Removing element at 3, i.e. %d\n", v);
  l = remove_element_at(l, 3);
  fprint_list(stdout, l);
  printf("Removing head");
  l = remove_element_at(l, 0);
  fprint_list(stdout, l);
  printf("Removing out of index element, list shouldn't change\n");
  l = remove_element_at(l, 5);
  fprint_list(stdout, l);
  get_value_at(l, 2, &v);
  printf("Removing element at 2, i.e. %d\n", v);
  l = remove_element_at(l, 2);
  fprint_list(stdout, l);
  get_value_at(l, 2, &v);
  printf("Removing (null) tail, shouldn't change anything\n");
  l = remove_element_at(l, 2);
  fprint_list(stdout, l);

  printf("Inserting value at head\n");
  l = insert_element_at(l, 0, 3);
  fprint_list(stdout, l);

  printf("Inserting value at 1\n");
  l = insert_element_at(l, 1, 4);
  fprint_list(stdout, l);

  printf("Inserting value at 4, i.e. as last\n");
  l = insert_element_at(l, 4, 5);
  fprint_list(stdout, l);

  printf("Inserting value at 7, out of bounds\n");
  l = insert_element_at(l, 7, 5);
  fprint_list(stdout, l);
  printf("Removing whole list\n");
  l = delete_whole_list(l);
  assert(l == NULL);
}

int main(int argc, char *argv[]) {
  printf("Testing queue\n");
  test_queue();
  printf("Testing list\n");
  test_list();
  return 0;
}
