#include "prova5_survey.h"
Node_t *build_survey_by_id_node(Survey_t *survey) {
  SurveyById_t *survey_by_id = (SurveyById_t *)malloc(sizeof(SurveyById_t));
  survey_by_id->id = survey->id;
  Survey_t **surveys = (Survey_t **)malloc(sizeof(Survey_t *));
  *surveys = survey;
  Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
  new_node->info = surveys;
  new_node->next = NULL;
  return new_node;
}

Node_t *build_and_insert_ordered(Node_t *ord_head, Survey_t *to_insert) {
  printf("Inserting ordered %d\n", to_insert->id);

  if (ord_head == NULL) {
    printf("Insert first element\n");
    return build_survey_by_id_node(to_insert);
  }

  Node_t *after;
  SurveyById *cur_surv_id = (SurveyById_t *)ord_head->info;
  if (cur_surv_id->id > to_insert->id) {
    printf("Inserting before head\n");
    after = ord_head;
  }

  Node_t *cur;
  for (cur = ord_head;
       cur->next != NULL && ((SurveyId_t *)cur->next->info)->id < to_insert->id;
       cur = cur->next) {
    printf("next %d, forward\n", ((SurveyId_t *)cur->next->info)->id);
  }
  after = cur->next;
  cur_surv_id = (SurveyById_t *)after->info;
  if (cur_surv_id->id == to_insert->id) {
    // Make space for another pointer
    cur_surv_id->surveys = (Survey_t **)realloc(
        cur_surv_id->surveys, sizeof(cur_surv_id->surveys) + sizeof(Survey_t *))
  }

  new_node->next = cur->next;
  cur->next = new_node;

  return ord_head;
}

Survey_t *from_line_to_survey(char *line) {
  const char *delimiter = ",";
  Survey_t *s = (Survey_t *)malloc(sizeof(Survey_t));
  char *token;

  // First token, id
  token = strtok(line, delimiter);
  s->id = atoi(token);

  // City
  token = strtok(NULL, delimiter);
  strcpy(s->city, token);

  // Lat
  token = strtok(NULL, delimiter);
  s->lat = atof(token);

  // Lon
  token = strtok(NULL, delimiter);
  s->lon = atof(token);

  // T
  token = strtok(NULL, delimiter);
  s->t = atof(token);

  // CO2
  token = strtok(NULL, delimiter);
  s->co2 = atof(token);

  // PM10
  token = strtok(NULL, delimiter);
  s->pm10 = atof(token);

  // Date
  token = strtok(NULL, delimiter);
  Date_t *date = (Date_t *)malloc(sizeof(Date_t));
  delimiter = "/";
  char *token2 = strtok(token, delimiter);
  date->day = atoi(token2);
  token2 = strtok(NULL, delimiter);
  date->month = atoi(token2);
  token2 = strtok(NULL, delimiter);
  date->year = atoi(token2);

  s->date = date;

  return s;
}

Node_t *from_file_to_list(char *filename) {
  FILE *f = fopen(filename, "r");
  const int max_line_length = 128;
  char *line_buffer = (char *)malloc(sizeof(char) * max_line_length);
  char *line = fgets(line_buffer, max_line_length, f);
  Node_t *head = NULL;
  while ((line = fgets(line_buffer, max_line_length, f)) != NULL) {
    Survey_t *s = from_line_to_survey(line);
    head = build_and_push(head, s);
  }
  return head;
}

Node_t *from_list_to_ordered_list(Node_t *head) {
  Node_t *ord_head = NULL;
  // head and cur are node of type survey_t; ord_head of type surveyid_t
  for (Node_t *cur = head; cur != NULL; cur = cur->next) {
    // SurveyId_t *to_insert = from_survey_to_survey_id();
    ord_head = build_and_insert_ordered(ord_head, (Survey_t *)cur->info);
  }
  return ord_head;
}

// TODO
Survey_t **get_surveys_from_id(Node_t *ord_head, int id) { return NULL; }
