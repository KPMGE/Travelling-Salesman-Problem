#ifndef CITY_H
#define CITY_H

#include <stddef.h>
#include <stdio.h>

typedef struct city City;

City *city_new(size_t id, double x, double y);
size_t return_dimension(FILE *f);
size_t city_id(City *c);
double city_x(City *c);
double city_y(City *c);
size_t city_size();
void city_free(City *c);
double city_calculate_distance(City *c1, City *c2);

#endif // !CITY_H
