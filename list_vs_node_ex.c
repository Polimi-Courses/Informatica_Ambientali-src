#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int value;
    struct Node_s * next;
} Node_t;

typedef struct {
    Node_t *head;
    size_t len;
} List_t;

void inserisci1_wrong(Node_t *head, int value) {
    Node_t *new = (Node_t *)malloc(sizeof(Node_t));
    new->value = value;
    new->next = head;
    head = new;
    printf("inserisci1_wrong: head is %p\n", head);
}

Node_t * inserisci1(Node_t *head, int value) {
    Node_t *new = (Node_t *)malloc(sizeof(Node_t));
    new->value = value;
    new->next = head;
    printf("inserisci1: head is %p\n", head);
    return new;
}

void inserisci2(Node_t **head, int value) {
    Node_t *new = (Node_t *)malloc(sizeof(Node_t));
    new->value = value;
    new->next = *head;
    *head = new;
    printf("inserisci2: head is %p\n", *head);
}

void inserisci3(List_t *l, int value) {
    Node_t *new = (Node_t *)malloc(sizeof(Node_t));
    new->value = value;
    new->next = l->head;
    l->len++;
    l->head = new;
}

void print_list(List_t *l){
    for (Node_t *cur = l->head; cur != NULL; cur = cur->next)
	printf("val: %d -> ", cur->value);
    printf("NULL\n");
}


int main() {
    Node_t *head = NULL;
    head = inserisci1(head, 3);
    printf("Main: head is %p\n", head);
    inserisci2(&head, 5);
    printf("Main: head is %p\n", head);
    List_t *l = (List_t *)malloc(sizeof(List_t));
    l->head = head;
    l->len = 2;
    print_list(l);
    inserisci3(l, 7);
    print_list(l);
}
