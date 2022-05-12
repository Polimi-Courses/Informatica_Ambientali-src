#ifndef _CITY_H
#define _CITY_H
#include "point.h"
#include <stdlib.h>
#include <string.h>
// Anonymous name, aliased to City
typedef struct {
  char name[100];
  int residents;
  Point2D geolocation;
} City_t;

void city_copy(City_t *dst, const City_t *src);
void city_print(FILE *stream, const City_t *city);

#endif
