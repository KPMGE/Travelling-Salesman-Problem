#include "../include/city.h"
#include <stdlib.h>

struct city {
  size_t id;
  double x, y;
};

City *city_new(size_t id, double x, double y) {
  City *c = malloc(sizeof(City));
  c->id = id;
  c->x = x;
  c->y = y;
  return c;
}

size_t return_dimension(FILE *f) {
  int dimension;
  for (int i = 0; i < 6; i++) {
    // go to the line where we have the dimension and get the value
    if (i == 3) {
      fscanf(f, "DIMENSION: %d\n", &dimension);
      continue;
    }
    char buffer[100];
    fgets(buffer, 100, f);
  }

  return dimension;
}
