#include "../include/graph.h"
#include <stdlib.h>

typedef struct node {
  uint16_t vertex;
  struct node *next;
} Node;

Node *node_new(int v) {
  Node *new_node = malloc(sizeof(Node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

struct graph {
  uint16_t num_vertices;
  uint16_t *visited;
  Node **adj_lists;
};

void dfs(Graph *graph, uint16_t vertex, FILE *tour_file) {
  Node *adjList = graph->adj_lists[vertex];
  Node *temp = adjList;

  graph->visited[vertex] = 1;
  fprintf(tour_file, "%d\n", vertex + 1);

  while (temp != NULL) {
    uint16_t connected_vertex = temp->vertex;

    if (graph->visited[connected_vertex] == 0) {
      dfs(graph, connected_vertex, tour_file);
    }
    temp = temp->next;
  }
}

Graph *graph_new(uint16_t vertices) {
  Graph *graph = malloc(sizeof(Graph));

  graph->num_vertices = vertices;
  graph->adj_lists = malloc(vertices * sizeof(Node *));
  graph->visited = malloc(vertices * sizeof(uint16_t));

  for (uint16_t i = 0; i < vertices; i++) {
    graph->adj_lists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void graph_edge_new(Graph *graph, uint16_t src, uint16_t dest) {
  // Add edge from src to dest
  Node *new_node = node_new(dest);
  new_node->next = graph->adj_lists[src];
  graph->adj_lists[src] = new_node;

  // Add edge from dest to src
  new_node = node_new(src);
  new_node->next = graph->adj_lists[dest];
  graph->adj_lists[dest] = new_node;
}

void graph_free(Graph *graph, uint16_t num_vertices) {
  Node *aux = NULL;
  for (uint16_t i = 0; i < num_vertices; i++) {
    aux = graph->adj_lists[i]->next;
    free(graph->adj_lists[i]);
    while (aux) {
      Node *aux2 = aux->next;
      free(aux);
      aux = aux2;
    }
  }
  free(graph->adj_lists);
  free(graph->visited);
  free(graph);
}
