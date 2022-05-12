#ifndef _UTIL_CONVERSION_H
#define _UTIL_CONVERSION_H
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

bool parse_unsigned_long(const char *str, unsigned long *val);
bool parse_long(const char *str, long *val);
bool parse_float(const char *str, float *val);
#endif
