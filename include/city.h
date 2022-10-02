#ifndef CITY_H
#define CITY_H

#include <stddef.h>
#include <stdio.h>

typedef struct city City;

City *city_new(size_t id, double x, double y);
size_t return_dimension(FILE *f);

#endif // !CITY_H
