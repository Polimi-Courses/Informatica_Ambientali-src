#include "prova5_ordered_list.h"
int insert_ordered(List_t *l, Node_t *new_node,
                   int (*compare)(Node_t *, Node_t *), bool merge_duplicates,
                   void (*merge)(Node_t *, Node_t *)) {
  if (l == NULL) {
    fprintf(stderr, "List must be initialized first\n");
    return -1;
  }
  if (l->head == NULL || (*compare)(l->head, new_node) > 0) {
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
       tmp != NULL && tmp->next != NULL && (*compare)(tmp->next, new_node) <= 0;
       tmp = tmp->next) {
    i++;
  }
  printf("Inserted at position %d\n", i);
  new_node->next = tmp->next;
  tmp->next = new_node;
  l->len++;
  return 0;
}

int build_and_insert_ordered(List_t *l, void *info,
                             int (*compare)(Node_t *, Node_t *),
                             bool merge_duplicates,
                             void (*merge)(Node_t *, Node_t *)) {
  return insert_ordered(l, build(info), compare, merge_duplicates, merge);
}
Node_t *get_node_at(List_t *l, size_t index) {
  Node_t *tmp = l->head;
  for (size_t i = 0; i < index && tmp != NULL; ++i) {
    tmp = tmp->next;
  }
  return tmp;
}
Node_t *search(List_t *l, void *info, int (*compare)(Node_t *, void *)) {
  if (l == NULL) {
    fprintf(stderr, "List is null\n");
    return NULL;
  }
  for (Node_t *cur = l->head; cur != NULL; cur = cur->next) {
    if (compare(cur, info) == 0)
      return cur;
  }
  fprintf(stdout, "Node not found\n");
  return NULL;
}

Node_t *binary_search(List_t *l, void *info, int (*compare)(Node_t *, void *)) {
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
    // Highly inefficient, but we don't have a tree structure
    /* for (size_t i = 0; i < middle; ++i) { */
    /*   middle_n = middle_n->next; */
    /* } */

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
