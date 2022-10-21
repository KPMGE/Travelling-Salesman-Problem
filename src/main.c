#include "../include/city.h"
#include "../include/edge.h"
#include "../include/graph.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  // dimension of the matrix
  uint16_t dimension_from_file = parse_dimension(f);

  // get all cities
  City **cities = parse_cities(f);

  // compute the edges between all cities
  uint16_t *edges = compute_edges(cities, dimension_from_file);

  // as the dimension from the file starts at 1, but on our program we 
  // wish to use it starting from 0, we must adjust it subtracting 1.
  uint16_t dimension_for_program = dimension_from_file - 1;

  // calculate amount of edges
  size_t qtd_edges = (dimension_for_program * (dimension_for_program + 1)) / 2;

  // compute mst
  uint16_t *mst = kruskal(dimension_from_file, edges, qtd_edges);

  // save tour
  FILE *tour_file = fopen("test.tour", "w");
  assert(f != NULL && "Could not create mst file");
  char *problem_name = parse_problem_name(f);
  save_tour(mst, dimension_from_file, problem_name, tour_file);

  // save mst
  FILE *mst_file = fopen("test.mst", "w");
  assert(f != NULL && "Could not create mst file");
  save_mst(mst_file, mst, problem_name, dimension_from_file);

  // clean up memorry
  free(edges);
  free(mst);
  fclose(f);
  free(problem_name);
  fclose(mst_file);
  fclose(tour_file);
}
