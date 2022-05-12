#ifndef _ORDERED_LIST_2_PROVA5_H
#define _ORDERED_LIST_2_PROVA5_H
#include "prova5_list.h"
#include <math.h>
#include <stdbool.h>

typedef struct {
  // A way to extend the struct List_t is to create an anonymous struct
  // as first element
  List_t;
  // Compare is the order insert strategy, i.e. how we say that a node
  // is <= to another.
  int (*compare)(Node_t *, Node_t *);
} OrderedList_t;

// Compare function should return negative number if ord_head < new_head,
// positive if >, 0 if equals
int insert_ordered(OrderedList_t *l, Node_t *new_node);
int build_and_insert_ordered(OrderedList_t *l, void *info);
Node_t *binary_search(OrderedList_t *l, void *info,
                      int (*compare)(Node_t *, void *));

#endif
