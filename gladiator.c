#include "gladiator.h"
Weapon s2weapon(char *string) {
  if (strcmp(string, "shield") == 0)
    return shield;
  else if (strcmp(string, "knife") == 0)
    return knife;
  else if (strcmp(string, "sword") == 0)
    return sword;
  else if (strcmp(string, "spear") == 0)
    return spear;
}
char *weapon2s(Weapon w) {
  switch (w) {
  case knife:
    return "knife";
  case spear:
    return "spear";
  case sword:
    return "sword";
  case shield:
    return "shield";
  default:
    return NULL;
  }
}
char *gladiator2s(Gladiator *g) {
  char *s;
  size_t n = snprintf(NULL, 0, "%s %d %s %s", g->name, g->age,
                      weapon2s(g->weapons[0]), weapon2s(g->weapons[1]));
  s = (char *)malloc(sizeof(char) * n);
  snprintf(s, n + 1, "%s %d %s %s", g->name, g->age, weapon2s(g->weapons[0]),
           weapon2s(g->weapons[1]));
  return s;
}
Gladiator *s2gladiator(char *s) {
  Gladiator *g = (Gladiator *)malloc(sizeof(Gladiator));
  char weapon1[20];
  char weapon2[20];
  g->name = (char *)malloc(sizeof(char) * 20);
  sscanf(s, "%s %d %s %s ", g->name, &(g->age), weapon1, weapon2);
  g->weapons[0] = s2weapon(weapon1);
  g->weapons[1] = s2weapon(weapon2);
  return g;
}
void fprintf_gladiator(FILE *stream, Gladiator *g) {
  fprintf(stream, gladiator2s(g));
}
int fscanf_gladiator(FILE *stream, Gladiator *g) {
  g->name = (char *)malloc(sizeof(Gladiator));
  char weapon1[20];
  char weapon2[20];
  int res =
      fscanf(stream, "%s %d %s %s ", g->name, &(g->age), weapon1, weapon2);
  g->weapons[0] = s2weapon(weapon1);
  g->weapons[1] = s2weapon(weapon2);
  return res;
}
int fscanf_gladiators(FILE *stream, Gladiator **gs, size_t n) {
  int res, i;
  for (i = 0; i < n; ++i) {
    Gladiator *g = (Gladiator *)malloc(sizeof(Gladiator));
    res = fscanf_gladiator(stream, g);
    if (res == EOF)
      return i;
    *(gs + i) = g;
  }
  return i;
}
