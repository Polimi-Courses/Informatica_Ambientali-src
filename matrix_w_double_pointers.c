/*
  Risolvere il seguente esercizio senza mai usare l'operatore
  [] per accedere agli elementi degli array.

  Scrivere un programma che, inizializzato una matrice di caratteri,
  chieda all'utente se vuole modificare una cella:
  Se l'utente vuole farlo, chiedergli riga e colonna. Cambiare l'elemento
  indicato  con un elemento specificato dall'utente.
  stampare la matrice ogni volta che viene modificato un carattere.
  Quando l'utente non vuole più modificare un carattere, il programma
  termina, stampando prima però la matrice, ma solo nel caso non sia
  stata ancora stampata.
 */

#include <stdio.h>
#include <stdlib.h>
#define R 4
#define C 5
int print_matrix(char **matrix, size_t rows, size_t columns);
int change_matrix_element(char **matrix, size_t row, size_t column,
                          char new_value);

int main(int argc, char *argv[]) {
  /* size_t m_s = sizeof(m); */
  /* size_t c_s = sizeof(*m); */
  /* size_t r_s = m_s / c_s; */
  /* fprintf(stdout, "m_s %d\n", m_s); */
  /* fprintf(stdout, "c_s %d\n", c_s); */
  /* fprintf(stdout, "r_s %d\n", r_s); */

  char **matrix;
  printf("How many rows? ");
  int rows;
  scanf("%d", &rows);
  printf("How many columns? ");
  int columns;
  scanf("%d", &columns);

  printf("Allocating matrix\n");
  matrix = (char **)malloc(sizeof(char *) * rows);
  for (int i = 0; i < rows; ++i) {
    *(matrix + i) = (char *)malloc(sizeof(char) * columns);
  }

  printf("Initializing matrix\n");
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < columns; ++j) {
      *(*(matrix + i) + j) = 'a';
    }

  int choice = 1;
  do {
    print_matrix(matrix, rows, columns);
    printf("Do you want to change a matrix element? (0 to exit)\n");
    scanf("%d", &choice);
    if (!choice)
      continue;
    int row, column;
    char val;
    printf("Give me row, column and new value (space separated)\n");
    scanf("%d %d %c", &row, &column, &val);
    *(*(matrix + row) + column) = val;

  } while (choice != 0);

  printf("Deallocating matrix\n");
  for (int i = 0; i < rows; ++i) {
    free(*(matrix + i));
  }
  free(matrix);

  printf("See you soon...\n");
  return 0;
}

int print_matrix(char **matrix, size_t rows, size_t columns) {
  printf("Printing matrix\n");
  for (int i = 0; i < rows; ++i) {
    printf("\n");
    for (int j = 0; j < columns; ++j) {
      printf("%c ", *(*(matrix + i) + j));
    }
  }
}

int change_matrix_element(char **matrix, size_t row, size_t column,
                          char new_value) {}
