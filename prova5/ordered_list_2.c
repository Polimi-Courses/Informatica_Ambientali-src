#include "ordered_list_2.h"
int insert_ordered(OrderedList_t *l, Node_t *new_node) {
  if (l == NULL) {
    fprintf(stderr, "List must be initialized first\n");
    return -1;
  }
  if (l->head == NULL || l->compare(l->head, new_node) > 0) {
    printf("Insert order: first element or new head\n");
    new_node->next = l->head;
    l->len++;
    l->head = new_node;
    return 0;
  }
  printf("Inserting after head ... ");
  Node_t *tmp;
  unsigned i = 0;
  for (tmp = l->head;
       tmp != NULL && tmp->next != NULL && l->compare(tmp->next, new_node) <= 0;
       tmp = tmp->next) {
    i++;
  }
  printf("Inserted at position %d\n", i);
  new_node->next = tmp->next;
  tmp->next = new_node;
  l->len++;
  return 0;
}

int build_and_insert_ordered(OrderedList_t *l, void *info) {
  return insert_ordered(l, build(info));
}

Node_t *binary_search(OrderedList_t *l, void *info,
                      int (*compare)(Node_t *, void *)) {
  if (l == NULL) {
    fprintf(stderr, "List is null\n");
    return NULL;
  }
  size_t left = 0;
  size_t right = l->len - 1;
  while (left <= right) {
    size_t middle = floor((left + right) / 2);
    printf("left: %d, right: %d, middle: %d\n", left, right, middle);
    Node_t *middle_n = get_node_at(l, middle);
    int comp = compare(middle_n, info);
    printf("compare is: %d\n", comp);
    if (comp > 0)
      left = middle + 1;
    else if (comp < 0)
      right = middle - 1;
    else
      return (middle_n);
  }
  return NULL;
}
