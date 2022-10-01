#include "../include/city.h"
#include <stdlib.h>

struct city {
  int id;
  double x, y;
};

City *city_new(int id, double x, double y) {
  City *c = malloc(sizeof(City));
  c->id = id;
  c->x = x;
  c->y = y;
  return c;
}
