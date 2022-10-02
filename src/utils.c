#include "../include/utils.h"
#include <stdio.h>

static void skip_lines(FILE *f, size_t n) {
  for (int i = 0; i < n; i++) {
    char buffer[100];
    fgets(buffer, 100, f);
  }
}

City **parse_cities(FILE *f) {}

size_t parse_dimension(FILE *f) {
  size_t dimension;
  const int dimension_field_pos = 3;

  // skip the lines until the dimension field
  skip_lines(f, dimension_field_pos);

  fscanf(f, "DIMENSION: %zu\n", &dimension);
  return dimension;
}
