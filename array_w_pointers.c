/*
Risolvere il seguente esercizio senza mai usare l'operatore
[] per accedere agli elementi degli array.

Scrivere un programma che, inizializzato un array di interi,
chieda all'utente se vuole modificare una cifra dell'array:
se l'utente vuole farlo, chiedergli un indice. Cambiare l'elemento
indicato con un elemento specificato dall'utente.
stampare l'array ogni volta che viene modificato un numero.
Quando l'utente non vuole più modificare un numero, il programma
termina, stampando prima però l'array, ma solo nel caso non sia
stato ancora stampato.

 */
#include <stdio.h>
#define N 10
// This will initialize all the array to 0
int array[N];

/* Note: you can't compute the size of the array within this function.
   When you pass an array into a function in C, the array decays into a pointer
   to its first element. When you use sizeof on the parameter, you are taking
   the size of the pointer, not the array itself.
  */
int print_array2(int *array, size_t size) {
  printf("[ ");
  for (int *ptr = array; ptr < array + size; ++ptr) {
    printf("%d ", *ptr);
  }
  printf("]\n");
}

int print_array(int *array) {
  int *end = array + N;
  printf("address of array start %x\n", (&array));
  printf("address of array end %x\n", &end);
  printf("[ ");
  for (int *ptr = array; ptr != end; ++ptr)
    printf("%d ", *ptr);
  printf("]\n");
}

int modify_element_at(int *array, size_t size, size_t index, int new_value) {
  int *ptr;
  for (ptr = array; ptr < array + index; ++ptr)
    ; // just iterate to the correct index
  *ptr = new_value;
}

int main(int argc, char *argv[]) {

  // Not really necessary (it's N), but useful for teaching purpose
  int size = sizeof(array) / sizeof(*array);

  int choice;

  printf("WARNING: scanf expects well formatted input, be aware to use "
         "integers only!\n");
  do {
    print_array2(array, size);
    printf(
        "Do you want to modify some element inside the pointer? (0 to exit)\n");
    int r = scanf("%d", &choice);
    if (r == EOF || r == 0) {
      fprintf(stderr, "Error parsing");
      return -1;
    }
    if (choice == 0) {
      printf("Good bye!\n");
      continue;
    }

    int idx;
    do {
      printf("Give me an index comprised b/w 0 (included) and %d (excluded)\n",
             size);
      int r = scanf("%d", &idx);
      if (r == EOF || r == 0) {
        fprintf(stderr, "Error parsing");
        return -1;
      }
    } while (idx < 0 || idx >= N);

    int new_elem;
    printf("Give me the value of the new element\n");
    scanf("%d", &new_elem);
    modify_element_at(array, size, idx, new_elem);
  } while (choice != 0);
  return 0;
}
