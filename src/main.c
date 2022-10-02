#include "../include/city.h"
#include "../include/edge.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Edge **kruskal(size_t vertices, Edge **edges, size_t qtd_edges);

void save_mst(FILE *f, Edge **mst, size_t dimension) {
  fprintf(f, "NAME: berlin52\n");
  fprintf(f, "TYPE: MST\n");
  fprintf(f, "DIMENSION: %zu\n", dimension);
  fprintf(f, "MST_SECTION\n");
  for (size_t i = 0; i < dimension; i++) {
    fprintf(f, "%zu %zu\n", city_id(edge_origin(mst[i])),
            city_id(edge_destination(mst[i])));
  }
  fprintf(f, "EOF");
}

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  // dimension of the matrix
  size_t dim = parse_dimension(f);
  printf("dimension: %zu\n", dim);
  // get all cities
  City **cities = parse_cities(f);
  // compute the edges between all cities
  Edge **edges = compute_edges(cities, dim);
  // obtain the actual amount of edges
  size_t dim2 = dim - 1;
  size_t qtd_edges = (dim2 * (dim2 + 1)) / 2;

  sort_edges(edges, qtd_edges);
  Edge **mst = kruskal(dim, edges, qtd_edges);

  FILE *mst_file = fopen("test.mst", "w");
  assert(f != NULL && "Could not create mst file");
  save_mst(mst_file, mst, dim);

  // clean up memorry
  fclose(f);
  fclose(mst_file);
  cities_free(cities, dim);
  edges_free(edges, qtd_edges);
}

Edge **kruskal(size_t vertices, Edge **edges, size_t qtd_edges) {
  Uf *uf_set = uf_init(vertices);
  Edge **mst = malloc(edge_size() * vertices);
  size_t e = 0, i = 0;

  // evaluate until we got a complete tree or there is no elements left
  while (i < qtd_edges) {
    Edge *next_edge = edges[i++];

    // as the ids on the file start with 1, but on Uf we use an array starting
    // with 0, we must adjust the value before using find/union operations
    size_t id1_adjusted = city_id(edge_origin(next_edge)) - 1;
    size_t id2_adjusted = city_id(edge_destination(next_edge)) - 1;
    size_t pos1 = uf_find(uf_set, id1_adjusted);
    size_t pos2 = uf_find(uf_set, id2_adjusted);

    if (!uf_connected(uf_set, pos1, pos2)) {
      mst[e++] = next_edge;
      uf_union(uf_set, pos1, pos2);
    }
  }

  uf_free(uf_set);

  return mst;
}
