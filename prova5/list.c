#include "list.h"

int push(List_t *l, Node_t *new_node) {
  if (l == NULL || new_node == NULL) {
    fprintf(stderr, "Can't push, either list or new node is null\n");
    return -1;
  }
  new_node->next = l->head;
  l->head = new_node;
  l->len++;
  return 0;
}

Node_t *build(void *info) {
  Node_t *new = (Node_t *)malloc(sizeof(Node_t));
  new->info = info;
  return new;
}

int build_and_push(List_t *l, void *info) { return push(l, build(info)); }

void print_list(FILE *stream, List_t *l, char *(*to_string)(Node_t *)) {
  if (l == NULL)
    return;
  fprintf(stream, "{");
  for (Node_t *tmp = l->head; tmp != NULL; tmp = tmp->next) {
    fprintf(stream, "[%s] -> ", (*to_string)(tmp));
  }
  fprintf(stream, "NULL}\n");
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
