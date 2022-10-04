#ifndef UTILS_H
#define UTILS_H

#include "city.h"
#include "edge.h"
#include <stddef.h>

City **parse_cities(FILE *f);
size_t parse_dimension(FILE *f);
Edge **compute_edges(City **cities, size_t qtd_cities);
void sort_edges(Edge **edges, size_t qtd_edges);
Edge **kruskal(size_t vertices, Edge **edges, size_t qtd_edges);
void save_mst(FILE *f, Edge **mst, const char *problem_name, size_t dimension);
char *parse_problem_name(FILE *f);

#endif // !UTILS_H
