#include "prova5.h"
#include <stdio.h>

void print_surveys(Node_t *head) {
  for (Node_t *cur = head; cur != NULL; cur = cur->next) {
    Survey_t *s = (Survey_t *)cur->info;
    printf("ID: %d; CITY: %s; LAT:%.2f; LON:%.2f; T:%.2f; CO2:%.2f; PM10:%.2f; "
           "DATE:%d-%d-%d\n",
           s->id, s->city, s->lat, s->lon, s->t, s->co2, s->pm10, s->date->day,
           s->date->month, s->date->year);
  }
}

void print_surveys_id(Node_t *ord_head) {
  for (Node_t *cur = ord_head; cur != NULL; cur = cur->next) {
    SurveyId_t *s = (SurveyId_t *)cur->info;
    printf("ID: %d\n", s->id);
  }
}

int main(int argc, char *argv[]) {
  Node_t *head = from_file_to_list("data/prova5.csv");
  print_surveys(head);
  printf("********************\n");
  Node_t *ord_head = from_list_to_ordered_list(head);
  print_surveys_id(ord_head);
  return 0;
}
