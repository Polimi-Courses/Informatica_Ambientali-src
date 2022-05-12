#ifndef _JOURNEY_MANAGER_H
#define _JOURNEY_MANAGER_H
#include "plane_manager.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  CREATED,
  BOARDING,
  DEPARTING,
  FLYING,
  LANDING,
  LANDED
} JourneyStatus;

typedef struct {
  Plane *plane;
  JourneyStatus status;
  char departure_date[10];
  char arrival_date[10];
  char departure_hour[5];
  char arrival_hour[5];
} Journey;

Journey *create_journey(Plane *plane, const char *departure_date,
                        const char *departure_hour, const char *arrival_date,
                        const char *arrival_hour);
char *get_journey_status(Journey *j);
// The idea is to create a little finite state automaton
bool ask_to_start(Journey *j);
bool board(Journey *j);
bool ask_to_leave(Journey *j);
bool leave(Journey *j);
bool ask_to_land(Journey *j);
bool land(Journey *j);
#endif
