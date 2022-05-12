#include "point.h"
float get_distance_bw_points(const Point2D *p1, const Point2D *p2) {
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

void print_point(FILE *stream, const Point2D *p) {
  fprintf(stream, "X: %.2f, Y: %.2f\n", p->x, p->y);
}
