#include "double_linked_list.h"

List *create_empty_list() {
  List *l = (List *)malloc(sizeof(List));
  l->size = 0;
}

size_t get_size(List *list) { return list->size; }

bool append(List *list, void *value) {
  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->value = value;
  n->prev = list->tail;
  n->next = NULL;
  if (list->tail != NULL)
    list->tail->next = n;

  list->tail = n;
  if (list->head == NULL)
    list->head = n;
  list->size++;
  return true;
}

bool prepend(List *list, void *value) {

  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->value = value;
  if (list->head != NULL)
    list->head->prev = n;
  n->next = list->head;
  n->prev = NULL;
  list->head = n;
  if (list->tail == NULL)
    list->tail = n;
  list->size++;
  return true;
}

bool insert_at(List *list, size_t idx, void *value) {
  if (idx == 0)
    return prepend(list, value);
  if (idx == list->size)
    return append(list, value);
  if (idx > list->size)
    return false;

  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->value = value;
  // Stop at the previous element
  ListNode *tmp;
  for (tmp = list->head; tmp && idx > 1; tmp = tmp->next, --idx)
    ;

  // A <> B <> D
  // Insert C after B: B>C ; C<D; C>D x; B<C
  // B is tmp, C is n, D is tmp->next
  n->next = tmp->next;
  n->prev = tmp;
  tmp->next->prev = n;
  tmp->next = n;
  list->size++;
  return true;
}

bool delete_at(List *list, size_t idx) {
  if (!list || !list->head)
    return false;
  if (idx >= list->size)
    return false;
  ListNode *to_del = list->head;
  if (list->size == 1) {
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    free(to_del);
    return true;
  }

  for (; idx > 0 && to_del; --idx, to_del = to_del->next)
    ;
  if (list->tail == to_del) {
    to_del->prev->next = NULL;
    list->tail = to_del->prev;
  } else if (list->head == to_del) {
    to_del->next->prev = NULL;
    list->head = to_del->next;
  } else {
    to_del->next->prev = to_del->prev;
    to_del->prev->next = to_del->next;
  }
  list->size--;
  free(to_del);
  return true;
}

bool delete_all(List *list) {
  bool ok = true;
  int s = list->size;
  while (s--)
    ok = ok && delete_at(list, 0);
  return ok;
}
