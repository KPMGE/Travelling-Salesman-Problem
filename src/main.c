#include "../include/city.h"
#include "../include/edge.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void compute_tour(Edge **mst, int mst_size) {
int idx = 0;
Edge *elem = mst[0];
int *arr = malloc(sizeof(int) * (mst_size * 2));

while (idx < (2 * mst_size)) {
  int origin_id = edge_origin_id(elem);
  int destination_id = edge_destination_id(elem);
  arr[idx++] = origin_id; 
  arr[idx++] = destination_id;

  printf("elem: (%d %d)\n", origin_id, destination_id);

  // find the mst that has th destination_id
  for (int i = 0; i < mst_size; i++) {
    if (!mst[i]) continue;
    if (edge_origin_id(elem) == edge_origin_id(mst[i]) && edge_destination_id(elem) == edge_destination_id(mst[i])) {
      continue;
    } 
    if (edge_origin_id(elem) == edge_origin_id(mst[i])) {
      elem = mst[i];
      mst[i] = NULL;
      break;
    }
    if (edge_destination_id(elem) == edge_destination_id(mst[i])) {
      elem = mst[i];
      mst[i] = NULL;
      break;
    }
    if (edge_destination_id(elem) == edge_origin_id(mst[i])) {
      elem = mst[i];
      mst[i] = NULL;
      break;
    }
  }
}

printf("cities: ");
  for (int i = 0; i < (2 * mst_size); i++) {
    printf("%d\n", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  // dimension of the matrix
  uint16_t dim = parse_dimension(f);
  printf("dimension: %hu\n", dim);
  // get all cities
  City **cities = parse_cities(f);
  // compute the edges between all cities

  Edge **edges = compute_edges(cities, dim);
  // obtain the actual amount of edges
  uint16_t dim2 = dim - 1;
  size_t qtd_edges = (dim2 * (dim2 + 1)) / 2;

  sort_edges(edges, qtd_edges);
  Edge **mst = kruskal(dim, edges, qtd_edges);
  
  edges_free(edges, qtd_edges);

  FILE *mst_file = fopen("test.mst", "w");
  assert(f != NULL && "Could not create mst file");
  char *problem_name = parse_problem_name(f);
  save_mst(mst_file, mst, problem_name, dim);

  // clean up memorry
  free(mst);
  fclose(f);
  free(problem_name);
  fclose(mst_file);
}
