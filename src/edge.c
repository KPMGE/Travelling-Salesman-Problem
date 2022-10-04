#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/city.h"
#include "../include/edge.h"

struct edge {
  size_t origin_id, destination_id;
  double distance;
};

Edge *edge_new(size_t origin_id, size_t destination_id, double distance) {
  Edge *e = malloc(sizeof(Edge));
  e->origin_id = origin_id;
  e->destination_id = destination_id;
  e->distance = distance;
  return e;
}

size_t edge_origin_id(Edge *e) { return e->origin_id; }

size_t edge_destination_id(Edge *e) { return e->destination_id; }

double edge_distance(Edge *e) { return e->distance; }

void edge_free(Edge *e) {
  assert(e != NULL && "edge must not be NULL");
  free(e);
}

size_t edge_size() { return sizeof(Edge); }

Edge **edge_array_new(size_t n) { return malloc(n * sizeof(Edge)); }

void edges_free(Edge **edges, size_t qtd_edges) {
  assert(edges != NULL && "edges must not be NULL");

  for (size_t i = 0; i < qtd_edges; i++) {
    edge_free(edges[i]);
  }
  free(edges);
}
