#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct List_s {
  int value;
  struct List_s *next;
} List;

void fprint_list(FILE *stream, List *list);
List *push(List *list, int value);
List *pop(List *list, int *value);
bool get_value_at(List *list, int idx, int *value);
List *insert_element_at(List *list, int idx, int value);
List *remove_element_at(List *list, int idx);
List *delete_whole_list(List *list);

#endif
