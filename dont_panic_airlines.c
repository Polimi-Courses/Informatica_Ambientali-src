#include "plane_manager.h"
#include <stdio.h>
Plane *p;
static int seat_id = 0;
void print_menu() {
  printf("a) Get # of available seats\n");
  printf("b) Assign a seat to a client\n");
  printf("c) Cancel a seat reservation\n");
  printf("q) quit\n");
}

void reserve_seat() {
  char name[20], surname[20];
  printf("Give me the name and surname of the passenger\n");
  scanf("%s %s", name, surname);
  if (add_seat_to_plane(p, create_seat(name, surname, seat_id)))
    seat_id++;
  else
    printf("Unable to add another seat, maybe the plane is full?\n");
  // Clear the last trailing spaces, scanf issues and bla bla bla
}

void exit_function() {

  for (int i = 0; i < p->current_n_seats; ++i) {
    free((p->seats)[i]);
  }
  free(p->seats);
}

void switch_choice(char c) {
  switch (c) {
  case 'a':
    printf("There are currently %d seats available\n", get_available_seats(p));
    break;
  case 'b':
    reserve_seat();
    break;
  case 'c':
    break;
  case 'q':
    exit_function();
    exit(0);
    break;
  default:
    fprintf(stdout, "Wrong choice\n");
  }
}

int main(int argc, char *argv[]) {
  p = create_plane("Boeing", 12);
  while (1) {
    char c;
    print_menu();
    scanf("%c", &c);
    switch_choice(c);
  }
  return 0;
}
