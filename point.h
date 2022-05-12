#ifndef _POINT_H
#define _POINT_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D_s {
  float x;
  float y;
} Point2D;

float get_distance_bw_points(const Point2D *p1, const Point2D *p2);
void print_point(FILE *stream, const Point2D *p);
#endif
