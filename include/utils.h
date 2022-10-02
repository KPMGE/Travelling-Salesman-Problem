#ifndef UTILS_H
#define UTILS_H

#include "city.h"
#include "edge.h"
#include <stddef.h>

City **parse_cities(FILE *f);
size_t parse_dimension(FILE *f);
Edge **compute_edges(City **cities, size_t qtd_cities);
void cities_free(City **cities, size_t qtd_cities);
void edges_free(Edge **edges, size_t qtd_edges);

#endif // !UTILS_H
