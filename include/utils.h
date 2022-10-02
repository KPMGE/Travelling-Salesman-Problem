#ifndef UTILS_H
#define UTILS_H

#include "city.h"

City **parse_cities(FILE *f);
size_t parse_dimension(FILE *f);

#endif // !UTILS_H
