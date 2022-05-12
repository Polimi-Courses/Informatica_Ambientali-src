#include "journey_manager.h"

Journey *create_journey(Plane *plane, const char *departure_date,
                        const char *departure_hour, const char *arrival_date,
                        const char *arrival_hour) {
  Journey *j = (Journey *)malloc(sizeof(Journey));
  j->plane = plane;
  strncpy(j->departure_date, departure_date, 10);
  strncpy(j->arrival_date, arrival_date, 10);
  strncpy(j->departure_hour, departure_hour, 5);
  strncpy(j->arrival_hour, arrival_hour, 5);
  return j;
}

/*
  CREATED,
  BOARDING,
  DEPARTING,
  FLYING,
  LANDING,
  LANDED
 */
char *get_journey_status(Journey *j) {
  switch (j->status) {
  case CREATED:
    return "just created";
  case BOARDING:
    return "boarding";
  case DEPARTING:
    return "departing";
  case FLYING:
    return "flying";
  case LANDING:
    return "landing";
  case LANDED:
    return "landed";
  default:
    return "";
  }
}

bool ask_to_start(Journey *j) {
  j->plane->status = OK;
  return true;
}

bool board(Journey *j) {
  if (!(j->plane->status == OK))
    return false;
  j->status = BOARDING;
  return true;
}

bool ask_to_leave(Journey *j) {
  if (!(j->status == BOARDING) || !(j->plane->status == OK))
    return false;
  j->status = DEPARTING;
  return true;
}
bool leave(Journey *j) {
  if (!(j->status == DEPARTING || !(j->plane->status == OK)))
    return false;
  j->status = FLYING;
  return true;
}
bool ask_to_land(Journey *j) {
  if (!(j->status == FLYING))
    return false;
  j->status = LANDING;
  return true;
}
bool land(Journey *j) {
  if (!(j->status == LANDING))
    return false;
  j->status = LANDED;
  return true;
}
