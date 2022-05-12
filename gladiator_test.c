#include "gladiator.h"
#include <stdio.h>

void check_conversions() {
  printf("***** Function check conversions\n");
  Gladiator g1 = {"Simone", 29, {sword, shield}};
  char *s1 = gladiator2s(&g1);
  printf("%s\n", s1);

  Gladiator *g2 = s2gladiator(s1);
  char *s2 = gladiator2s(g2);
  printf("%s\n", s2);
  assert(strcmp(s1, s2) == 0);
}

void check_file_txt() {
  const char *path = "data/gladiators.txt";
  printf("***** Function check file\n");
  Gladiator *gs[20];
  FILE *f = fopen(path, "r");
  int n = fscanf_gladiators(f, gs, 20);
  printf("%d\n", n);

  for (int i = 0; i < n; ++i) {
    printf("%s\n", gladiator2s(gs[i]));
  }
  fclose(f);

  f = fopen(path, "a");
  Gladiator g1 = {"Simone", 29, {sword, shield}};
  fprintf(f, "%s\n", gladiator2s(&g1));
}

void check_file_raw() {
  const char *path = "data/gladiators.raw";
  Gladiator g1 = {"Simone", 29, {sword, shield}};
  Gladiator g2 = {"Virginia", 31, {knife, knife}};
  FILE *f = fopen(path, "w");
  size_t n = fwrite(&g1, sizeof(Gladiator), 1, f);
  n += fwrite(&g2, sizeof(Gladiator), 1, f);
  printf("%u structs written\n", n);
  assert(n == 2);
  fclose(f);
  // Read same structures back
  f = fopen(path, "r");
  Gladiator g3, g4;
  n = fread(&g3, sizeof(Gladiator), 1, f);
  n += fread(&g4, sizeof(Gladiator), 1, f);
  printf("%u structs read\n", n);
  assert(n == 2);
  fprintf_gladiator(stdout, &g3);
  fprintf(stdout, "\n");
  fprintf_gladiator(stdout, &g4);
  fprintf(stdout, "\n");
  fclose(f);
  // check with array of structs
  f = fopen(path, "w");
  Gladiator gs[4] = {g1, g2, g3, g4};
  n = fwrite(gs, sizeof(Gladiator), 4, f);
  printf("%u structs read\n", n);
  assert(n == 4);
}

int main(int argc, char *argv[]) {
  check_conversions();
  check_file_txt();
  check_file_raw();
  return 0;
}
