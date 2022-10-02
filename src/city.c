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

size_t city_id(City *c) { return c->id; }

double city_x(City *c) { return c->x; }

double city_y(City *c) { return c->y; }
