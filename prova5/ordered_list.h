#ifndef _PROVA5_ORDERED_LIST_H
#define _PROVA5_ORDERED_LIST_H
#include "prova5_list.h"
#include <math.h>
#include <stdbool.h>

// Compare function should return negative number if ord_head < new_head,
// positive if >, 0 if equals
int insert_ordered(List_t *l, Node_t *new_node,
                   int (*compare)(Node_t *, Node_t *), bool merge_duplicates,
                   void (*merge)(Node_t *, Node_t *));
int build_and_insert_ordered(List_t *l, void *info,
                             int (*compare)(Node_t *, Node_t *),
                             bool merge_duplicates,
                             void (*merge)(Node_t *, Node_t *));
Node_t *get_node_at(List_t *l, size_t index);
Node_t *search(List_t *l, void *info, int (*compare)(Node_t *, void *));
Node_t *binary_search(List_t *l, void *info, int (*compare)(Node_t *, void *));

#endif
