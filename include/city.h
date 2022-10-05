#ifndef CITY_H
#define CITY_H

#include <stdint.h>
#include <stdio.h>

typedef struct city City;

City *city_new(uint16_t id, float x, float y);
City **city_array_new(uint16_t n);
uint16_t return_dimension(FILE *f);
uint16_t city_id(City *c);
float city_x(City *c);
float city_y(City *c);
void city_free(City *c);
float city_calculate_distance(City *c1, City *c2);
void cities_free(City **cities, uint16_t qtd_cities);

#endif // !CITY_H
