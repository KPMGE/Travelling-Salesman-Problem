#ifndef CITY_H
#define CITY_H

#include <stddef.h>
#include <stdio.h>

typedef struct city City;

City *city_new(size_t id, double x, double y);
City **city_array_new(size_t n);
size_t return_dimension(FILE *f);
size_t city_id(City *c);
double city_x(City *c);
double city_y(City *c);
void city_free(City *c);
double city_calculate_distance(City *c1, City *c2);
void cities_free(City **cities, size_t qtd_cities);

#endif // !CITY_H
