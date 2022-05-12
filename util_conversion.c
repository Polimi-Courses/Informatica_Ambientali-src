#include "util_conversion.h"

bool parse_unsigned_long(const char *str, unsigned long *val) {
  errno = 0;
  char *temp;
  *val = strtoul(str, &temp, 10);
  if (temp == str || *temp != '\0' ||
      ((*val == LONG_MIN || *val == LONG_MAX) && errno == ERANGE)) {
    return false;
  }
  return true;
}

bool parse_long(const char *str, long *val) {
  errno = 0;
  char *temp;
  *val = strtol(str, &temp, 10);
  if (temp == str || *temp != '\0' ||
      ((*val == LONG_MIN || *val == LONG_MAX) && errno == ERANGE)) {
    return false;
  }
  return true;
}

bool parse_float(const char *str, float *val) {
  errno = 0;
  char *temp;
  *val = strtof(str, &temp);
  if (temp == str || *temp != '\0' ||
      ((*val == FLT_MAX || *val == FLT_MIN) && errno == ERANGE)) {
    return false;
  }
  return true;
}
