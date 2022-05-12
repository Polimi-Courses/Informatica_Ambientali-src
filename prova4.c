#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int giorno;
  int mese;
  int anno;
} Data_t;

typedef struct {
  int mm;
  char regione[20];
  Data_t *data;
} Precipitazione_t;
// 40

int conta_righe(char *nome_file) {
  printf("conta_righe: inizio\n");
  FILE *f = fopen(nome_file, "r");
  char c;
  int contatore = 0;
  while ((c = fgetc(f)) != EOF) {
    if (c == '\n') {
      contatore++;
    }
  }
  return contatore - 1;
}

// n numero di righe
Precipitazione_t **da_file_ad_array(char *nome_file, int n) {
  printf("da_file_ad_array: inizio\n");
  FILE *f = fopen(nome_file, "r");
  Precipitazione_t **precipitazioni =
      (Precipitazione_t **)malloc(n * sizeof(Precipitazione_t *));
  printf("da_file_ad_array: precipitazioni = %p\n", precipitazioni);

  for (int i = 0; i < n; ++i) {
    Precipitazione_t *precipitazione =
        (Precipitazione_t *)malloc(sizeof(Precipitazione_t));
    Data_t *data = (Data_t *)malloc(sizeof(Data_t));
    precipitazione->data = data;

    printf("da_file_ad_array: precipitazione %d all'indirizzo %p\n", i,
           precipitazione);
    // check malloc
    char s[20];
    int w, x, y, z;
    int res = fscanf(f, "%[^;];%d;%d;%d;%d\n", s, &w, &x, &y, &z);
    printf("s: %s, w: %d, x: %d, y: %d, z: %d\n", s, w, x, y, z);
    strcpy(precipitazione->regione, s);
    precipitazione->data->giorno = w;
    precipitazione->data->mese = x;
    precipitazione->data->anno = y;
    precipitazione->mm = z;

    printf("da_file_ad_array: precipitazione %s, %d, %d, %d, %d\n",
           precipitazione->regione, precipitazione->data->giorno,
           precipitazione->data->mese, precipitazione->data->anno,
           precipitazione->mm);

    printf("da_file_ad_array: precipitazioni+i = %p -> %p precipitazione\n",
           precipitazioni + i, precipitazione);
    precipitazioni[i] = precipitazione;
  }
  return precipitazioni;
}

void stampa_qualcosa(Precipitazione_t **precipitazioni, int n, char *regione,
                     int anno) {
  int totale = 0;
  for (int i = 0; i < n; ++i) {
    printf("precipitazione %d: regione: %s, anno: %d\n", i,
           precipitazioni[i]->regione, precipitazioni[i]->data->anno);
    if (precipitazioni[i]->data->anno == anno &&
        strcmp(precipitazioni[i]->regione, regione) == 0) {
      printf("EUREKA\n");
      totale += precipitazioni[i]->mm;
    }
  }
  printf(
      "Il totale delle precipitazioni per la regione %s nell'anno %d e' %d\n",
      regione, anno, totale);
}

int main(int argc, char *argv[]) {
  char *filename = "data/prova4.txt";
  int righe = conta_righe(filename);
  printf("main: righe = %d\n", righe);
  printf("main: size of struct is %d bytes\n", sizeof(Precipitazione_t));
  printf("main: size of a pointer is %d bytes\n", sizeof(void *));
  Precipitazione_t **precipitazioni = da_file_ad_array(filename, righe);

  char regione[10];
  int anno;

  printf("Dammi un nome di regione: ");
  scanf("%s", regione);
  printf("Dammi un anno: ");
  scanf("%d", &anno);
  stampa_qualcosa(precipitazioni, righe, regione, anno);
}
