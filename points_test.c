#include "point.h"

int main(int argc, char *argv[]) {
  Point2D p1, p2;
  printf("The size of the Point2D data structure is %zd bytes\n",
         sizeof(Point2D));
  printf("Give me x y coordinates of first point\n");
  scanf("%f %f", &p1.x, &p1.y);

  printf("Give me x y coordinates of second point\n");
  scanf("%f %f", &p2.x, &p2.y);

  printf("Here are your two points\n");
  print_point(stdout, &p1);
  print_point(stdout, &p2);

  printf("Distance is %.3f\n", get_distance_bw_points(&p1, &p2));

  return 0;
}
