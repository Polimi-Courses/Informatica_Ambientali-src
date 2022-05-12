#include "journey_manager.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  const int n_seats = 12;
  Plane *p = create_plane("Boeing", n_seats);
  for (int i = 0; i < n_seats; ++i) {
    add_seat_to_plane(p, create_seat());
  }
  for (int i = 0; i < 5; i++) {
    insert_reservation(p, i, "Name", "Surname");
  }
  Journey *j = create_journey(p, "28/12/2018", "08:00", "29/12/2018", "08:00");
  printf("Checking FSA\n");
  printf("Journey status: %s\n", get_journey_status(j));
  printf("Plane status: %s\n", get_plane_status(j->plane));

  bool b = board(j);
  // Can't board now, plane still in maintenance
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == false);

  b = ask_to_start(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  // Now we can board
  b = board(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  // we can't land
  b = land(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == false);

  // we can't fly also
  b = leave(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == false);

  // but we can ask
  b = ask_to_leave(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  // continuing journey
  b = leave(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  b = ask_to_land(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  b = land(j);
  printf("Boolean is %d and now plane is %s and journey is %s\n", b,
         get_plane_status(j->plane), get_journey_status(j));
  assert(b == true);

  getchar();
  return 0;
}
