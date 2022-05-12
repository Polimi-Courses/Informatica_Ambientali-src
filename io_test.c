#include <stdio.h>

/*
 * Reading semicolon-separated list of integers,
 * no problem
 */
void read_n() {
  FILE *f = fopen("data/io_test_n.txt", "r");

  int w, x, y, z;
  int res = fscanf(f, "%d;%d;%d;%d\n", &w, &x, &y, &z);
  printf("res: %d\n", res);
  while (res != EOF && res != 0) {
    printf("w: %d, x: %d, y: %d, z: %d\n", w, x, y, z);
    res = fscanf(f, "%d;%d;%d;%d\n", &w, &x, &y, &z);
    printf("res: %d\n", res);
  }
  fclose(f);
}

/*
 * Reading semicolon-separated list of strings.
 * Problems bcz the semicolon is treated just like a part of string.
 */
void read_s_wrong() {
  FILE *f = fopen("data/io_test_strings.txt", "r");
  char s[20], t[20], u[20];
  int res = fscanf(f, "%s;%s;%s\n", s, t, u);
  printf("s: %s, t: %s, u: %s\n", s, t, u);
  fclose(f);
}

/*
 * Problem avoided using %[^;] instead of s.
 * This pattern simply tells to take all the characters from the line
 * excluding the semicolon.
 */
void read_s() {
  FILE *f = fopen("data/io_test_strings.txt", "r");
  char s[20], t[20], u[20];
  int res = fscanf(f, "%[^;];%[^;];%s\n", s, t, u);
  printf("s: %s, t: %s, u: %s\n", s, t, u);
  fclose(f);
}

/*
 * Reading a mix of integers and numbers from a file.
 */
void read_mixed() {
  FILE *f = fopen("data/io_test_mixed.txt", "r");
  char s[20];
  int w, x, y, z;
  int res = fscanf(f, "%[^;];%d;%d;%d;%d\n", s, &w, &x, &y, &z);
  printf("s: %s, w: %d, x: %d, y: %d, z: %d\n", s, w, x, y, z);
  fclose(f);
}

int main(int argc, char *argv[]) {
  /* read_n(); */
  /* read_s_wrong(); */
  /* read_s(); */
  read_mixed();
  return 0;
}
