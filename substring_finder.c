#include <stdio.h>
#include <string.h>
int find_substring_iterative(char *string, char *substring);
int find_substring_recursive(char *string, char *substring);

int main(int argc, char *argv[]) {
  char string[100];
  char substring[100];

  printf("Give me a string \n");
  scanf("%s", &string);

  printf("Give me a substring \n");
  scanf("%s", &substring);

  int p1 = find_substring_iterative(string, substring);
  int p2 = find_substring_recursive(string, substring);
  printf("substring position %d, %d\n", p1, p2);

  return 0;
}

int find_substring_iterative(char *string, char *substring) {
  int s_len = strlen(string);
  int sub_len = strlen(substring);
  ;

  if ((s_len - sub_len) < 0)
    return -1;

  int i;
  for (i = 0; i < s_len; ++i) {
    int j;
    for (j = 0; j < sub_len; ++j) {
      if (string[i + j] != substring[j])
        break;
    }
    // found
    if (j == sub_len) {
      return i;
    }
  }
  return -1;
}

// basically, checks if string starts with substring
int find_substring_recursive_helper(char *string, char *substring) {
  int s_len = strlen(string);
  int sub_len = strlen(substring);

  if (sub_len == 1)
    return (string[0] == substring[0]);

  return (string[0] == substring[0] &&
          find_substring_recursive_helper(string + 1, substring + 1));
}
int find_substring_recursive(char *string, char *substring) {
  for (int i = 0; i < strlen(string); ++i) {
    if (find_substring_recursive_helper(string + i, substring))
      return i;
  }
  return -1;
}
