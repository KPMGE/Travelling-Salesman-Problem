#include "../include/city.h"
#include <stdlib.h>
#include <stdio.h>

#include "city.h"

struct city
{
  int id;
  float x, y;
};

City *city_new(int id, double x, double y)
{
  City *c = malloc(sizeof(City));
  c->id = id;
  c->x = x;
  c->y = y;
  return c;
}

int return_dimension(FILE *f)
{
  int dimension;
  for (int i = 0; i < 6; i++)
  {
    // go to the line where we have the dimension and get the value
    if (i == 3)
    {
      fscanf(f, "DIMENSION: %d\n", &dimension);
      continue;
    }
    char buffer[100];
    fgets(buffer, 100, f);
  }

  return dimension;
}
