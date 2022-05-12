#include "plane_manager.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  const int n_seats = 12;
  Plane *p = create_plane("Boeing", n_seats);
  printf("%s %d\n", p->name, strlen(p->name));

  printf("Test creating seats\n");
  Seat *ss[n_seats];
  for (int i = 0; i < n_seats; ++i) {
    printf("Creating seat %d\n", i);
    ss[i] = create_seat();
    printf("%p\t\n", ss[i]);
  }

  printf("Test adding seats in bulk\n");
  add_n_seats_to_plane(p, ss, n_seats);

  int n = get_available_seats(p);
  printf("Available seats: %d\n", n);
  assert(n == n_seats);

  printf("Test insert reservation\n");
  for (int i = 0; i < 5; i++) {
    insert_reservation(p, i, "Name", "Surname");
  }
  n = get_available_seats(p);
  printf("Available seats: %d\n", n);
  assert(n == 7);
  // Passenger list
  fprint_passengers_list(stdout, p);
  fprint_seats_list(stdout, p);

  printf("Test delete reservation\n");
  for (int i = 0; i < 2; i++) {
    delete_reservation(p, i);
  }
  n = get_available_seats(p);
  printf("Available seats: %d\n", n);
  assert(n == 9);

  printf("Test print to file\n");
  const char *path = "plane_list.txt";
  FILE *f = fopen(path, "w");
  fprint_passengers_list(f, p);

  for (int i = 0; i < 4; ++i) {
    free((p->seats)[i]);
  }
  free(p->seats);

  return 0;
}
