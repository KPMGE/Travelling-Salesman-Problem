#include "../include/city.h"
#include "../include/edge.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Edge **kruskal(size_t vertices, Edge **edges, size_t qtd_edges);

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  // dimension of the matrix
  size_t dim = parse_dimension(f);
  printf("dimension: %zu\n", dim);
  // get all cities
  City **cities = parse_cities(f);
  // display cities
  // for (int i = 0; i < dim; i++) {
  //   printf("id: %zu, x: %.2lf, y: %.2lf\n", city_id(cities[i]),
  //          city_x(cities[i]), city_y(cities[i]));
  // }

  // compute the edges between all cities
  Edge **edges = compute_edges(cities, dim);
  // obtain the actual amount of edges
  size_t dim2 = dim - 1;
  size_t qtd_edges = (dim2 * (dim2 + 1)) / 2;

  sort_edges(edges, qtd_edges);

  // display edges
  // for (size_t i = 0; i < qtd_edges; i++) {
  //   size_t origin_id = city_id(edge_origin(edges[i]));
  //   size_t destination_id = city_id(edge_destination(edges[i]));
  //   double distance = edge_distance(edges[i]);
  //   printf("origin: %zu, destination: %zu, distance: %.2lf\n", origin_id,
  //          destination_id, distance);
  // }

  Edge **mst = kruskal(dim, edges, dim2);

  printf("MST:\n\n");
  for (size_t i = 0; i < dim; i++) {
    size_t city1_id = city_id(edge_origin(mst[i]));
    size_t city2_id = city_id(edge_destination(mst[i]));
    double distance = edge_distance(mst[i]);
    printf("%zu -> %zu, %.2lf\n", city1_id, city2_id, distance);
  }

  // clean up memorry
  fclose(f);
  cities_free(cities, dim);
  edges_free(edges, qtd_edges);
}

Edge **kruskal(size_t vertices, Edge **edges, size_t qtd_edges) {
  Uf *uf_set = uf_init(vertices);
  Edge **mst = malloc(edge_size() * vertices);
  size_t e = 0, i = 0;

  // evaluate until we got a complete tree or there is no elements left
  while (e < (vertices - 1) && i < qtd_edges) {
    Edge *next_edge = edges[i++];

    size_t pos1 = uf_find(uf_set, city_id(edge_origin(next_edge)));
    size_t pos2 = uf_find(uf_set, city_id(edge_destination(next_edge)));

    if (!uf_connected(uf_set, pos1, pos2)) {
      mst[e++] = next_edge;
      uf_union(uf_set, pos1, pos2);
    }
  }

  uf_free(uf_set);

  return mst;
}
