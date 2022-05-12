#ifndef _PROVA5_LIST_H
#define _PROVA5_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_s {
  void *info;
  struct Node_s *next;
} Node_t;

typedef struct {
  Node_t *head;
  size_t len;
} List_t;

// Node_t *push(Node_t *head, Node_t *new_node);
int push(List_t *l, Node_t *new_node);
// Node_t *build_and_push(Node_t *head, void *info);
int build_and_push(List_t *l, void *info);
Node_t *build(void *info);
// Node_t *pop(Node_t *head);
Node_t *get_node_at(List_t *l, size_t index);
// Compare is the search criteria
Node_t *search(List_t *l, void *info, int (*compare)(Node_t *, void *));
int pop(List_t *l);
// void print_list(FILE *stream, Node_t *head, char *(*to_string)(Node_t *));
void print_list(FILE *stream, List_t *l, char *(*to_string)(Node_t *));
#endif
