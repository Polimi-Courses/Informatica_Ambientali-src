#include "plane_manager.h"
Plane *create_plane(const char *name, int max_n_seats) {
  Plane *s = (Plane *)malloc(sizeof(Plane));
  strncpy(s->name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  s->current_n_seats = 0;
  s->max_n_seats = max_n_seats;
  s->seats = (Seat **)malloc(sizeof(Seat *) * max_n_seats);
  s->status = MAINTENANCE;
  return s;
}

Seat *create_seat() {
  Seat *s = (Seat *)malloc(sizeof(Seat));
  return s;
}

bool add_seat_to_plane(Plane *plane, Seat *seat) {
  if (plane->current_n_seats == plane->max_n_seats)
    return false;
  seat->available = true;
  seat->id = plane->current_n_seats;
  *(plane->seats + plane->current_n_seats++) = seat;
  return true;
}

bool add_n_seats_to_plane(Plane *plane, Seat **seats, size_t n_seats) {
  for (int i = 0; i < n_seats; ++i) {
    add_seat_to_plane(plane, seats[i]);
  }
}

int get_available_seats(const Plane *plane) {
  int counter = 0;
  for (int i = 0; i < plane->current_n_seats; ++i) {
    if (plane->seats[i]->available)
      counter++;
  }
  return counter;
}

void fprint_passengers_list(FILE *stream, const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seats[i];
    if (!s->available)
      fprintf(stream, "Seat %d: %s %s\n", s->id, s->surname, s->name);
  }
}

void fprint_seats_list(FILE *stream, const Plane *plane) {
  for (int i = 0; i < plane->current_n_seats; ++i) {
    Seat *s = plane->seats[i];
    fprintf(stream, "Seat: %d ", s->id);
    if (s->available) {
      fprintf(stream, "; Available\n");
    } else {
      fprintf(stream, "; reserved by %s %s\n", s->surname, s->name);
    }
  }
}
bool insert_reservation(Plane *plane, int id, const char *name,
                        const char *surname) {
  if (id >= plane->max_n_seats)
    return false;
  Seat *seat = plane->seats[id];
  if (!seat->available)
    return false;
  strncpy(seat->surname, surname,
          strlen(surname) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH
                                              : strlen(surname));
  strncpy(seat->name, name,
          strlen(name) > MAX_STRING_LENGTH ? MAX_STRING_LENGTH : strlen(name));
  seat->available = false;
  return true;
}

bool delete_reservation(Plane *plane, int seat_id) {
  if (seat_id >= plane->max_n_seats)
    return false;
  Seat *s = plane->seats[seat_id];
  if (s->available)
    return false;
  s->available = true;
  strncpy(s->name, "", 0);
  strncpy(s->surname, "", 0);
  return false;
}

// typedef enum { MAINTENANCE, DEPOSIT, OK } PlaneStatus;
char *get_plane_status(Plane *plane) {
  switch (plane->status) {
  case MAINTENANCE:
    return "maintenance";
  case DEPOSIT:
    return "deposit";
  case OK:
    return "ok";
  default:
    return "";
  }
}
