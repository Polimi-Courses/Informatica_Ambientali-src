#ifndef _GLADIATOR_H
#define _GLADIATOR_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { shield, sword, spear, knife } Weapon;
typedef struct {
  char *name;
  int age;
  Weapon weapons[2];
} Gladiator;

Weapon s2weapon(char *string);
char *weapon2s(Weapon w);
char *gladiator2s(Gladiator *g);
Gladiator *s2gladiator(char *s);
void fprintf_gladiator(FILE *stream, Gladiator *g);
int fscanf_gladiator(FILE *stream, Gladiator *g);
int fscanf_gladiators(FILE *stream, Gladiator **gs, size_t n);
#endif
