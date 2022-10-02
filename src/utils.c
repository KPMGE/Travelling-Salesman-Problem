#include "../include/utils.h"
#include <stdio.h>

City **parse_cities(FILE *f) {}

size_t parse_dimension(FILE *f) {
  size_t dimension;
  const int dimension_field_pos = 3;

  // skip the lines until the dimension field
  for (int i = 0; i < dimension_field_pos; i++) {
    char buffer[100];
    fgets(buffer, 100, f);
  }

  fscanf(f, "DIMENSION: %zu\n", &dimension);
  return dimension;
}
