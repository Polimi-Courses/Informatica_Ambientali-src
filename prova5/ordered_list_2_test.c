#include "ordered_list_2.h"
#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned id;
  char name[20];
} City_t;

int compare_int(Node_t *node_a, Node_t *node_b) {
  int *a = (int *)node_a->info;
  int *b = (int *)node_b->info;
  return *a - *b;
}

int compare_city(Node_t *city_a, Node_t *city_b) {
  City_t *a = (City_t *)city_a->info;
  City_t *b = (City_t *)city_b->info;
  return a->id - b->id;
}

int node_city_compare_by_name(Node_t *city_n, void *name) {
  char *n = (char *)name;
  City_t *a = (City_t *)city_n->info;
  return strcmp(a->name, n);
}

int node_city_compare_by_id(Node_t *city_n, void *id) {
  int *i = (int *)id;
  printf("Comparing vs id = %d; ...", *i);
  City_t *a = (City_t *)city_n->info;
  printf("Current city id is = %d\n", a->id);
  return *i - a->id;
}

char *to_string_city(Node_t *node) {
  City_t *city = (City_t *)node->info;
  char *city_string = (char *)malloc(sizeof(char) * 30);
  snprintf(city_string, 30, "id: %d, name: %s", city->id, city->name);
  return city_string;
}

void test_int_node_compare() {
  Node_t *a = (Node_t *)malloc(sizeof(Node_t));
  int *a_i = (int *)malloc(sizeof(int));
  *a_i = 2;
  a->info = a_i;
  Node_t *b = (Node_t *)malloc(sizeof(Node_t));
  int *b_i = (int *)malloc(sizeof(int));
  *b_i = 9;
  b->info = b_i;
  printf("test_int, %d\n", compare_int(a, b));
}

void test_city_node_compare() {
  City_t *c1 = (City_t *)malloc(sizeof(City_t));
  strcpy(c1->name, "Milan");
  c1->id = 1;
  City_t *c2 = (City_t *)malloc(sizeof(City_t));
  strcpy(c2->name, "Benevento");
  c2->id = 2;
  Node_t *a = (Node_t *)malloc(sizeof(Node_t));
  a->info = c1;
  Node_t *b = (Node_t *)malloc(sizeof(Node_t));
  b->info = c2;

  printf("test_city, %d\n", compare_city(a, b));
}

void test_city_node_equals() {
  City_t *c1 = (City_t *)malloc(sizeof(City_t));
  strcpy(c1->name, "Milan");
  c1->id = 1;
  Node_t *a = (Node_t *)malloc(sizeof(Node_t));
  a->info = c1;
  printf("test_city_node_equals: %d; expected %d\n",
         node_city_compare_by_name(a, "Milan"), 1);
  printf("test_city_node_equals: %d; expected %d\n",
         node_city_compare_by_name(a, "Benevento"), 0);
}

void test_city_list_inserts() {
  printf("test_city_list_inserts\n");
  City_t *c1 = (City_t *)malloc(sizeof(City_t));
  strcpy(c1->name, "Milan");
  c1->id = 1;
  Node_t *a = (Node_t *)malloc(sizeof(Node_t));
  a->info = c1;

  City_t *c2 = (City_t *)malloc(sizeof(City_t));
  strcpy(c2->name, "Benevento");
  c2->id = 2;
  Node_t *b = (Node_t *)malloc(sizeof(Node_t));
  b->info = c2;

  City_t *c3 = (City_t *)malloc(sizeof(City_t));
  strcpy(c3->name, "Paris");
  c3->id = 0;
  Node_t *c = (Node_t *)malloc(sizeof(Node_t));
  c->info = c3;

  City_t *c4 = (City_t *)malloc(sizeof(City_t));
  strcpy(c4->name, "Dublin");
  c4->id = 5;
  /* Node_t *d = (Node_t *)malloc(sizeof(Node_t)); */
  /* d->info = c4; */

  City_t *c5 = (City_t *)malloc(sizeof(City_t));
  strcpy(c5->name, "London");
  c5->id = 4;
  /* Node_t *e = (Node_t *)malloc(sizeof(Node_t)); */
  /* e->info = c5; */

  City_t *c6 = (City_t *)malloc(sizeof(City_t));
  strcpy(c6->name, "Paris2");
  c6->id = 0;

  City_t *c7 = (City_t *)malloc(sizeof(City_t));
  strcpy(c7->name, "Benevento2");
  c7->id = 2;

  OrderedList_t *l = (OrderedList_t *)malloc(sizeof(List_t));
  l->compare = compare_city;
  printf("Inserting %s\n", c1->name);
  insert_ordered(l, a);
  printf("Inserted %s\n", c1->name);
  print_list(stdout, (List_t *)l, to_string_city);

  printf("Inserting %s\n", c2->name);
  insert_ordered(l, b);
  print_list(stdout, (List_t *)l, to_string_city);

  printf("Inserting %s\n", c3->name);
  insert_ordered(l, c);
  print_list(stdout, (List_t *)l, to_string_city);

  // Testing also build_and_insert_ordered
  printf("Inserting %s\n", c4->name);
  build_and_insert_ordered(l, c4);
  print_list(stdout, (List_t *)l, to_string_city);

  printf("Inserting %s\n", c5->name);
  build_and_insert_ordered(l, c5);
  print_list(stdout, (List_t *)l, to_string_city);

  printf("Inserting %s\n", c6->name);
  build_and_insert_ordered(l, c6);
  print_list(stdout, (List_t *)l, to_string_city);

  printf("Inserting %s\n", c7->name);
  build_and_insert_ordered(l, c7);
  print_list(stdout, (List_t *)l, to_string_city);
}

void test_city_ordered_list_searchs() {
  printf("test_city_list_searchs\n");
  City_t *c1 = (City_t *)malloc(sizeof(City_t));
  strcpy(c1->name, "Milan");
  c1->id = 1;

  City_t *c6 = (City_t *)malloc(sizeof(City_t));
  strcpy(c6->name, "Paris");
  c6->id = 0;

  City_t *c7 = (City_t *)malloc(sizeof(City_t));
  strcpy(c7->name, "Benevento");
  c7->id = 2;

  OrderedList_t *l = (OrderedList_t *)malloc(sizeof(List_t));
  l->compare = compare_city;
  build_and_insert_ordered(l, c1);
  build_and_insert_ordered(l, c6);
  build_and_insert_ordered(l, c7);

  printf("Searching Milan\n");
  Node_t *n = search(l, "Milan", node_city_compare_by_name);
  City_t *c = (City_t *)n->info;
  printf("Search result is: %s, expected Milan\n", c->name);

  printf("Searching Dublin, not in list\n");
  n = search(l, "Dublin", node_city_compare_by_name);
  printf("Search result is: %p, expected (nil)\n", n);
}

void test_city_ordered_list_binary_searchs() {
  printf("test_city_list_binary_searchs\n");
  City_t *c1 = (City_t *)malloc(sizeof(City_t));
  strcpy(c1->name, "Milan");
  c1->id = 1;
  City_t *c2 = (City_t *)malloc(sizeof(City_t));
  strcpy(c2->name, "Dublin");
  c2->id = 10;
  City_t *c3 = (City_t *)malloc(sizeof(City_t));
  strcpy(c3->name, "Springfield");
  c3->id = 20;
  City_t *c4 = (City_t *)malloc(sizeof(City_t));
  strcpy(c4->name, "Amsterdam");
  c4->id = 30;
  City_t *c5 = (City_t *)malloc(sizeof(City_t));
  strcpy(c5->name, "Vancouver");
  c5->id = 30;
  City_t *c6 = (City_t *)malloc(sizeof(City_t));
  strcpy(c6->name, "Paris");
  c6->id = 4;
  City_t *c7 = (City_t *)malloc(sizeof(City_t));
  strcpy(c7->name, "Benevento");
  c7->id = 2;

  OrderedList_t *l = (OrderedList_t *)malloc(sizeof(List_t));
  l->compare = compare_city;
  build_and_insert_ordered(l, c1);
  build_and_insert_ordered(l, c2);
  build_and_insert_ordered(l, c3);
  build_and_insert_ordered(l, c4);
  build_and_insert_ordered(l, c6);
  build_and_insert_ordered(l, c7);
  print_list(stdout, (List_t *)l, to_string_city);

  int to_search = 2;
  printf("Searching %d\n", to_search);
  Node_t *n = binary_search(l, &to_search, node_city_compare_by_id);
  City_t *c = (City_t *)n->info;
  printf("Search result is: %s, expected Benevento\n", c->name);

  to_search = 22;
  printf("Searching %d, not in list\n", to_search);
  n = binary_search(l, &to_search, node_city_compare_by_id);
  printf("Search result is: %p, expected (nil)\n", n);
}

int main(int argc, char *argv[]) {
  test_int_node_compare();
  printf("*********\n");
  test_city_node_compare();
  printf("*********\n");
  test_city_node_equals();
  printf("*********\n");
  test_city_list_inserts();
  printf("*********\n");
  test_city_ordered_list_searchs();
  printf("*********\n");
  test_city_ordered_list_binary_searchs();
  printf("*********\n");

  return 0;
}
