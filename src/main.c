#include "../include/city.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  size_t dim = parse_dimension(f);
  printf("dimension: %zu\n", dim);
  City **cities = parse_cities(f);

  for (size_t i = 0; i < dim; i++) {
    printf("id: %zu, x: %.2lf, y: %.2lf\n", city_id(cities[i]),
           city_x(cities[i]), city_y(cities[i]));
  }

  fclose(f);
}
