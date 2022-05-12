#ifndef PROVA5_SURVEY_H
#define PROVA5_SURVEY_H
#include "prova5_list.h"

typedef struct {
  unsigned day;
  unsigned month;
  unsigned year;
} Date_t;

typedef struct {
  unsigned id;
  char city[20];
  float lat;
  float lon;
  float t;
  float co2;
  float pm10;
  Date_t *date;
} Survey_t;

typedef struct {
  unsigned id;
  Survey_t **surveys;
} SurveyById_t;

Node_t *build_and_insert_ordered(Node_t *ord_head, SurveyId_t *to_insert);
Survey_t *from_line_to_survey(char *line);
Node_t *from_file_to_list(char *filename);
Node_t *from_list_to_ordered_list(Node_t *head);
Survey_t **get_surveys_from_id(int id);
#endif
