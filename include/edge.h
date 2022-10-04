#ifndef EDGE_H
#define EDGE_H

#include "city.h"

typedef struct edge Edge;

Edge *edge_new(City *origin, City *destination, double distance);
City *edge_origin(Edge *e);
City *edge_destination(Edge *e);
Edge **edge_array_new(size_t n);
double edge_distance(Edge *e);
void edge_free(Edge *e);
void edges_free(Edge **edges, size_t qtd_edges);

#endif // !EDGE_H
