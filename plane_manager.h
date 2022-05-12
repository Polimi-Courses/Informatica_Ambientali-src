#ifndef _PLANE_MANAGER_H
#define _PLANE_MANAGER_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20

typedef enum { MAINTENANCE, DEPOSIT, OK } PlaneStatus;

typedef struct {
  int id;
  char surname[20];
  char name[20];
  bool available;
} Seat;

typedef struct {
  char name[20];
  int current_n_seats;
  int max_n_seats;
  Seat **seats;
  PlaneStatus status;
} Plane;

Plane *create_plane(const char *name, int max_n_seats);
Seat *create_seat();
bool add_seat_to_plane(Plane *plane, Seat *seat);
bool add_n_seats_to_plane(Plane *plane, Seat **seats, size_t n_seats);
bool insert_reservation(Plane *plane, int id, const char *name,
                        const char *surname);
bool delete_reservation(Plane *plane, int seat_id);
int get_available_seats(const Plane *plane);
void fprint_passengers_list(FILE *stream, const Plane *plane);
void fprint_seats_list(FILE *stream, const Plane *plane);
char *get_plane_status(Plane *plane);

#endif
