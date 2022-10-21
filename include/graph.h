#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>
#include <stdio.h>

typedef struct graph Graph;

// returns a new, allocated graph.
Graph *graph_new(uint16_t vertices);
// adds a new edge to the graph.
void graph_edge_new(Graph *graph, uint16_t src, uint16_t dest);
// makes a dfs throught the graph, saving it to the file
void dfs(Graph *graph, uint16_t vertex, FILE *tour_file);
// free allocated graph and its nodes.
void graph_free(Graph *graph, uint16_t num_vertices);
#endif // !GRAPH_H
