#include "double_linked_list.h"
#include <assert.h>
#include <stdio.h>

void fprint_list_int(List *list) {
  fprintf(stdout, "HEAD | ");
  for (ListNode *n = list->head; n; n = n->next)
    fprintf(stdout, "%d -> ", *((int *)n->value));
  fprintf(stdout, "| NULL\n");
}

int *alloc_int(int val) {
  int *n = (int *)malloc(sizeof(int));
  *n = val;
  return n;
}

int main(int argc, char *argv[]) {
  List *l = create_empty_list();

  int n = get_size(l);
  assert(n == 0);
  printf("size %d\n", n);

  printf("Prepending 3 element\n");
  prepend(l, alloc_int(10));
  prepend(l, alloc_int(11));
  prepend(l, alloc_int(12));

  n = get_size(l);
  printf("size %d\n", n);
  assert(n == 3);

  printf("Appending 3 element\n");
  append(l, alloc_int(9));
  append(l, alloc_int(8));
  append(l, alloc_int(7));

  n = get_size(l);
  printf("size %d\n", n);
  assert(n == 6);

  fprint_list_int(l);
  printf("Inserting element at last position\n");
  insert_at(l, n, alloc_int(100));
  fprint_list_int(l);

  printf("Inserting element at first position\n");
  insert_at(l, 0, alloc_int(200));
  fprint_list_int(l);

  printf("Inserting element at overflow position\n");
  insert_at(l, 1000, alloc_int(44));
  fprint_list_int(l);

  printf("Inserting element at position 3\n");
  insert_at(l, 3, alloc_int(44));
  fprint_list_int(l);

  printf("Inserting element at position 6\n");
  insert_at(l, 9, alloc_int(77));
  fprint_list_int(l);

  n = get_size(l);
  printf("size %d\n", n);
  assert(n == 10);

  printf("Deleting element at position 1\n");
  delete_at(l, 1);
  fprint_list_int(l);

  printf("Deleting element at first position\n");
  delete_at(l, 0);
  fprint_list_int(l);

  printf("Deleting element at last position\n");
  delete_at(l, l->size - 1);
  fprint_list_int(l);

  printf("Deleting element at overflow position\n");
  delete_at(l, 1000);
  fprint_list_int(l);

  printf("Deleting element at position 4\n");
  delete_at(l, 4);
  fprint_list_int(l);

  n = get_size(l);
  printf("size %d\n", n);
  assert(n == 6);

  bool b = delete_all(l);
  assert(b == true);
  assert(l->head == NULL);
  assert(l->tail == NULL);
  assert(l->size == 0);
  return 0;
}
