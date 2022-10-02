#include "../include/city.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *f = fopen("../exemplos/in/a280.tsp", "r");

  int id, dimension;
  float x, y;

  // skip lines and return dimension
  dimension = return_dimension(f);

  City *cities[dimension]; // array of cities

  int i = 0;
  while (fscanf(f, "%d %f %f", &id, &x, &y) == 3) {
    cities[i] = city_new(id, x, y);
    i++;
  }
  fclose(f);

  for (int i = 0; i < dimension; i++)
    free(cities[i]);
}
