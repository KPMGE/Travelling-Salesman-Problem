#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // That's just an example of the trim function
  char *s = strdup("          hello      ");
  printf("%s", trim(s));
  free(s);
}
