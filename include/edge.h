#ifndef EDGE_H
#define EDGE_H

#include "city.h"

typedef struct edge Edge;

Edge *edge_new(size_t origin_id, size_t destination_id, double distance);
size_t edge_origin_id(Edge *e);
size_t edge_destination_id(Edge *e);
Edge **edge_array_new(size_t n);
double edge_distance(Edge *e);
void edge_free(Edge *e);
void edges_free(Edge **edges, size_t qtd_edges);

#endif // !EDGE_H
