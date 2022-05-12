#include "city.h"
#define N_CITIES 5

void test0() {
  City_t city_bn = {"Benevento", 60000, {34.5, 45.5}};
  City_t city_mi = {"Milano", 3000000, {25.5, 400.5}};
  city_print(stdout, &city_bn);
  city_print(stdout, &city_mi);

  City_t city_bn_2;
  city_copy(&city_bn_2, &city_bn);
  city_print(stdout, &city_bn_2);
}

// city_1 and city_2 are return values
float min_distance_bw_cities(const City_t *cities, size_t n, int *city_1,
                             int *city_2) {
  float min_dist = INFINITY;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; j++) {
      float dist = get_distance_bw_points(&(cities[i].geolocation),
                                          &(cities[j].geolocation));
      printf("Distance b/w %s and %s is %f\n", cities[i].name, cities[j].name,
             dist);
      if (dist < min_dist) {
        min_dist = dist;
        *city_1 = i;
        *city_2 = j;
      }
    }
  }
  return min_dist;
}

// city_1 and city_2 are return values
float max_distance_bw_cities(const City_t *cities, size_t n, int *city_1,
                             int *city_2) {
  float max_dist = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; j++) {
      float dist = get_distance_bw_points(&(cities[i].geolocation),
                                          &(cities[j].geolocation));
      printf("Distance b/w %s and %s is %f\n", cities[i].name, cities[j].name,
             dist);
      if (dist > max_dist) {
        max_dist = dist;
        *city_1 = i;
        *city_2 = j;
      }
    }
  }
  return max_dist;
}

float tot_distance_of_path(const City_t *cities, size_t n) {
  float tot = 0;
  for (int i = 0; i < n - 1; ++i) {
    tot += get_distance_bw_points(&(cities[i].geolocation),
                                  &(cities[i + 1].geolocation));
  }
}

int main(int argc, char *argv[]) {
  City_t cities[N_CITIES];
  char city_name[100];
  float x, y;
  for (int i = 0; i < N_CITIES; ++i) {
    printf("Give me a city name\n");
    scanf("%s", &city_name);
    printf("Give me the two coordinates as x y\n");
    scanf("%f %f", &x, &y);
    strcpy(cities[i].name, city_name);
    cities[i].geolocation.x = x;
    cities[i].geolocation.y = y;
  }

  int city1;
  int city2;
  float max_dist = max_distance_bw_cities(cities, N_CITIES, &city1, &city2);
  printf("max distance b/w cities is %.2f b/w %s and %s\n", max_dist,
         cities[city1].name, cities[city2].name);
  float min_dist = min_distance_bw_cities(cities, N_CITIES, &city1, &city2);
  printf("min distance b/w cities is %.2f b/w %s and %s\n", min_dist,
         cities[city1].name, cities[city2].name);
  float tot_dist = tot_distance_of_path(cities, N_CITIES);
  printf("Total distance is %f\n", tot_dist);
  return 0;
}
