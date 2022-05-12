#include "city.h"

void city_copy(City_t *dst, const City_t *src) {
  dst->residents = src->residents;
  // this can be copied w/out any special care (I think) bcz the
  // Point2D struct just contains float
  dst->geolocation = src->geolocation;
  strcpy(dst->name, src->name);
}

void city_print(FILE *stream, const City_t *city) {
  fprintf(stream, "%s:\n\tResidents: %d\n\tPosition: (%.2f, %.2f)\n",
          city->name, city->residents, (city->geolocation).x,
          (city->geolocation).y);
}
