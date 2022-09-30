#include <ctype.h>
#include <string.h>

static char *ltrim(char *s) {
  while (isspace(*s))
    s++;
  return s;
}

static char *rtrim(char *s) {
  char *back = s + strlen(s);
  while (isspace(*--back))
    ;
  *(back + 1) = '\0';
  return s;
}

char *trim(char *s) { return rtrim(ltrim(s)); }
