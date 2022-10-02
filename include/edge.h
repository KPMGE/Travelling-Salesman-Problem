#ifndef EDGE_H
#define EDGE_H

#include "city.h"

typedef struct edge Edge;

Edge *edge_new(City *origin, City *destination, double distance);
City *edge_origin(Edge *e);
City *edge_destination(Edge *e);
double edge_distance(Edge *e);
void edge_free(Edge *e);

#endif // !EDGE_H
