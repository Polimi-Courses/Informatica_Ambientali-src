#include "linked_list.h"

void fprint_list(FILE *stream, List *list) {
  fprintf(stream, "HEAD -> ");
  for (List *l = list; l != NULL; l = l->next)
    fprintf(stream, "%d -> ", l->value);
  fprintf(stream, "NULL\n");
}
// insert in head
List *push(List *list, int value) {
  List *l = (List *)malloc(sizeof(List));
  l->value = value;
  l->next = list;
  return l;
}

// pop from head
List *pop(List *list, int *value) {
  *value = list->value;
  List *old_head = list;
  list = list->next;
  free(old_head);
  return list;
}

bool get_value_at(List *list, int idx, int *value) {
  for (; idx > 0 && list; idx--, list = list->next)
    ;
  if (list) {
    *value = list->value;
    return true;
  }
  return false;
}

List *insert_element_at(List *list, int idx, int value) {
  if (idx < 0 || !list)
    return list;
  if (idx == 0)
    return push(list, value);
  List *head = list;
  for (; list && idx > 1; list = list->next, --idx)
    ;
  if (list) {
    List *new_val = (List *)malloc(sizeof(List));
    new_val->value = value;
    new_val->next = list->next;
    list->next = new_val;
  }
  return head;
}

List *remove_element_at(List *list, int idx) {
  if (idx < 0 || list == NULL)
    return list;
  // deleting the head
  if (idx == 0)
    return list->next;

  // storing the head, we need to return it later
  List *head = list;

  // go to element at idx - 1
  for (; idx > 1 && list; --idx, list = list->next)
    ;

  // if not null, it means that list contains the list previous to the element
  // to delete
  if (list) {
    List *to_del = list->next;
    // we are trying to remove the (null) element at the tail
    // so we simply return the old list
    if (!to_del)
      return head;
    // removing the pointer to the value to be removed
    list->next = to_del->next;
    free(to_del);
  }
  return head;
}

List *delete_whole_list(List *list) {
  while (list) {
    List *cur = list;
    list = list->next;
    free(list);
  }
}
