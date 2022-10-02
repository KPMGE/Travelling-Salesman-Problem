#include <stdio.h>
#include <stdlib.h>

#include "../include/city.h"
#include "../include/edge.h"

struct edge {
  City *origin, *destination;
  double distance;
};

Edge *edge_new(City *origin, City *destination, double distance) {
  Edge *e = malloc(sizeof(Edge));
  e->origin = origin;
  e->destination = destination;
  e->distance = distance;
  return e;
}

City *edge_origin(Edge *e) { return e->origin; }

City *edge_destination(Edge *e) { return e->destination; }

double edge_distance(Edge *e) { return e->distance; }

void edge_free(Edge *e) { free(e); }
