#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode_s {
  struct ListNode_s *prev;
  struct ListNode_s *next;
  void *value;
} ListNode;

typedef struct {
  size_t size;
  ListNode *head;
  ListNode *tail;
} List;

List *create_empty_list();
size_t get_size(List *list);
bool append(List *list, void *value);
bool prepend(List *list, void *value);
bool insert_at(List *list, size_t idx, void *value);
// Note: the delete functions delete the node from the list, but
// they don't free the memory allocated for the value they store
bool delete_at(List *list, size_t idx);
bool delete_all(List *list);

#endif
