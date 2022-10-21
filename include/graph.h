#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>
#include <stdio.h>

typedef struct graph Graph;
Graph *graph_new(uint16_t vertices);
void graph_edge_new(Graph *graph, uint16_t src, uint16_t dest);
void dfs(Graph *graph, uint16_t vertex, FILE *tour_file);
void graph_free(Graph *graph, uint16_t num_vertices);
#endif // !GRAPH_H
