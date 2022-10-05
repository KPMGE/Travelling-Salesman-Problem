#ifndef EDGE_H
#define EDGE_H

#include "city.h"
#include <stdint.h>

typedef struct edge Edge;

Edge *edge_new(uint16_t origin_id, uint16_t destination_id, float distance);
uint16_t edge_origin_id(Edge *e);
uint16_t edge_destination_id(Edge *e);
Edge **edge_array_new(size_t n);
float edge_distance(Edge *e);
void edge_free(Edge *e);
void edges_free(Edge **edges, size_t qtd_edges);

#endif // !EDGE_H
