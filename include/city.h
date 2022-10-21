#ifndef CITY_H
#define CITY_H

#include <stdint.h>
#include <stdio.h>

typedef struct city City;

// allocates a new city 
City *city_new(uint16_t id, float x, float y);
// creates an empty array of cities with n positions
City **city_array_new(uint16_t n);
// returns the id of the given city
uint16_t city_id(City *c);
// returns the x coordinate of the given city
float city_x(City *c);
// returns the y coordinate of the given city
float city_y(City *c);
// calculate distance between two cities
float city_calculate_distance(City *c1, City *c2);
// frees an array of cities
void cities_free(City **cities, uint16_t qtd_cities);
// frees a single city
void city_free(City *c);

#endif // !CITY_H
