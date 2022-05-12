#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line_n(char *name, int line, char *string) {
  char buffer[255]; // reads up to 255 chars for each line
  FILE *f = fopen(name, "r");
  if (f == NULL) {
    fprintf(stderr, "Unable to open file\n");
    return -1;
  }
  while (line-- >= 0 && (fgets(buffer, 255, f)))
    ;
  printf("%d\n", strlen(buffer));
  strncpy(string, buffer, strlen(buffer));
  fclose(f);
  return 0;
}

int write_to_file(char *name, char *string, int length) {
  FILE *f = fopen(name, "w");
  if (f != NULL) {
    fprintf(f, string);
    fclose(f);
    return 0;
  } else {
    fprintf(stderr, "Unable to open file\n");
    return -1;
  }
}

int write_to_file_newline(char *name, char *string, int length) {
  char *newstring = (char *)malloc(sizeof(char) * length + 2);
  strncpy(newstring, string, length);
  strcat(newstring, "\n");
  return write_to_file(name, newstring, length + 2);
}

int append_to_file(char *name, char *string, int length) {
  FILE *f = fopen(name, "a");
  if (f != NULL) {
    fprintf(f, string);
    fclose(f);
    return 0;
  } else {
    fprintf(stderr, "Unable to open file\n");
    return -1;
  }
}

int append_to_file_newline(char *name, char *string, int length) {
  char *newstring = (char *)malloc(sizeof(char) * length + 2);
  strncpy(newstring, string, length);
  strcat(newstring, "\n");
  return append_to_file(name, newstring, length);
}

int main(int argc, char *argv[]) {
  char *p = "data/es.txt";
  char c;
  char str[10];
  int line;
  do {
    fprintf(stdout, "Insert w to write, a to append, r to read\n");
    scanf(" %c", &c);
  } while (c != 'a' && c != 'w' && c != 'r');
  switch (c) {
  case 'a':
    scanf(" %s", &str);
    append_to_file_newline(p, str, strlen(str));
    break;
  case 'r':
    scanf("%d", &line);
    read_line_n(p, line, str);
    printf("%s", str);
    break;
  case 'w':
    scanf(" %s", &str);
    write_to_file_newline(p, str, strlen(str));
    break;
  default:
    fprintf(stderr, "Wrong choice\n");
    break;
  }
  return 0;
}
