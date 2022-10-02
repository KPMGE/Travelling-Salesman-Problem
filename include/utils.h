#ifndef UTILS_H
#define UTILS_H

#include "city.h"

City **parse_cities(FILE *f);
size_t parse_dimension(FILE *f);
void cities_free(City **cities, size_t qtd_cities);

#endif // !UTILS_H
