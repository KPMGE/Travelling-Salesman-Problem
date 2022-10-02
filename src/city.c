#include "../include/city.h"
#include <math.h>
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

size_t city_size() { return sizeof(City); }

void city_free(City *c) { free(c); }

double city_calculate_distance(City *c1, City *c2) {
  double dx = c2->x - c1->x;
  double dy = c2->y - c1->x;
  return sqrt(pow(dx, 2) + pow(dy, 2));
}
