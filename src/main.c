#include "../include/city.h"
#include "../include/edge.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
  char *problem_name = parse_problem_name(f);
  save_mst(mst_file, mst, problem_name, dim);

  // clean up memorry
  fclose(f);
  free(problem_name);
  fclose(mst_file);
  cities_free(cities, dim);
  edges_free(edges, qtd_edges);
}
