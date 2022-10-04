#include "../include/city.h"
#include <assert.h>
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

void city_free(City *c) {
  assert(c != NULL && "city must not be NULL");
  free(c);
}

double city_calculate_distance(City *c1, City *c2) {
  double dx = c2->x - c1->x;
  double dy = c2->y - c1->y;
  return sqrt(pow(dx, 2) + pow(dy, 2));
}

City **city_array_new(size_t n) { return malloc(n * sizeof(City)); }

void cities_free(City **cities, size_t qtd_cities) {
  assert(cities != NULL && "cities must not be NULL");

  for (size_t i = 0; i < qtd_cities; i++) {
    if (!cities[i])
      continue;
    city_free(cities[i]);
  }
  free(cities);
}
