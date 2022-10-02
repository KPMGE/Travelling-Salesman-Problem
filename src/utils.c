#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

static void skip_lines(FILE *f, size_t n) {
  for (int i = 0; i < n; i++) {
    char buffer[100];
    fgets(buffer, 100, f);
  }
}

City **parse_cities(FILE *f) {
  const size_t dimension = parse_dimension(f);
  const int cities_start_pos = 6;

  // skip the lines until the start of the cities data section
  skip_lines(f, cities_start_pos);

  // allocate dynamic array of cities
  City **cities = malloc(city_size() * dimension);

  size_t id, i = 0;
  double x, y;
  while (fscanf(f, "%zu %lf %lf", &id, &x, &y) == 3) {
    cities[i] = city_new(id, x, y);
    i++;
  }

  return cities;
}

size_t parse_dimension(FILE *f) {
  size_t dimension;
  const int dimension_field_pos = 3;

  // skip the lines until the dimension field
  skip_lines(f, dimension_field_pos);

  fscanf(f, "DIMENSION: %zu\n", &dimension);
  // sets the pointer back to the very top of the file
  fseek(f, 0L, SEEK_SET);
  return dimension;
}
