#include "../include/utils.h"
#include "../include/city.h"
#include "../include/graph.h"
#include "../include/union_find.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(type, a, b)                                                       \
  {                                                                            \
    type temp = a;                                                             \
    a = b;                                                                     \
    b = temp;                                                                  \
  }

void quick_sort(float *arr, uint16_t first, uint16_t last, uint16_t *id_pairs) {
  uint16_t i, j, pivot;

  if (first < last) {
    pivot = first;
    i = first;
    j = last;
    while (i < j) {
      while (arr[i] <= arr[pivot] && i < last)
        i++;
      while (arr[j] > arr[pivot])
        j--;
      if (i < j) {
        SWAP(float, arr[i], arr[j]);
        SWAP(float, ORIGIN_ID(id_pairs, i), ORIGIN_ID(id_pairs, j));
        SWAP(float, DESTINATION_ID(id_pairs, i), DESTINATION_ID(id_pairs, j));
      }
    }

    SWAP(float, arr[pivot], arr[j]);
    SWAP(int, ORIGIN_ID(id_pairs, pivot), ORIGIN_ID(id_pairs, j));
    SWAP(int, DESTINATION_ID(id_pairs, pivot), DESTINATION_ID(id_pairs, j));

    quick_sort(arr, first, j - 1, id_pairs);
    quick_sort(arr, j + 1, last, id_pairs);
  }
}

static void skip_lines(FILE *f, size_t n) {
  for (int i = 0; i < n; i++) {
    char buffer[100];
    fgets(buffer, 100, f);
  }
}

char *parse_problem_name(FILE *f) {
  char name[256];
  fscanf(f, "NAME: %s", name);
  // sets the pointer back to the very top of the file
  fseek(f, 0L, SEEK_SET);
  return strdup(name);
}

City **parse_cities(FILE *f) {
  const uint16_t dimension = parse_dimension(f);
  const uint16_t cities_start_pos = 6;

  // skip the lines until the start of the cities data section
  skip_lines(f, cities_start_pos);

  // allocate dynamic array of cities
  City **cities = city_array_new(dimension);

  uint16_t id, i = 0;
  float x, y;
  while (fscanf(f, "%hu %f %f", &id, &x, &y) == 3) {
    cities[i] = city_new(id, x, y);
    i++;
  }

  // sets the pointer back to the very top of the file
  fseek(f, 0L, SEEK_SET);
  return cities;
}

uint16_t parse_dimension(FILE *f) {
  uint16_t dimension;
  const uint16_t dimension_field_pos = 3;

  // skip the lines until the dimension field
  skip_lines(f, dimension_field_pos);

  fscanf(f, "DIMENSION: %hu\n", &dimension);
  // sets the pointer back to the very top of the file
  fseek(f, 0L, SEEK_SET);
  return dimension;
}

uint16_t *compute_edges(City **cities, uint16_t qtd_cities) {
  assert(cities != NULL && "Cities must not be null");
  // formula for the sum of the first n natural numbers
  // NOTE: the actual number that we wanna compute is the sum of (qtd_cities -
  // 1)
  uint16_t n = qtd_cities - 1;
  size_t qtd_edges = (n * (n + 1)) / 2;
  size_t k = 0, z = 0;

  // array to hold pairs of city ids
  uint16_t *id_pairs = malloc(sizeof(uint16_t) * 2 * qtd_edges);
  // array of city distances
  float *distances = malloc(sizeof(float) * qtd_edges);

  // calculate all the combinations between the cities
  for (uint16_t i = 0; i < qtd_cities; i++) {
    for (uint16_t j = i + 1; j < qtd_cities; j++) {
      // saves distance in the kth position
      distances[k++] = city_calculate_distance(cities[i], cities[j]);
      // saves origin and destination ids
      id_pairs[z++] = city_id(cities[i]);
      id_pairs[z++] = city_id(cities[j]);
    }
    city_free(cities[i]);
  }

  // sort edges
  quick_sort(distances, 0, qtd_edges - 1, id_pairs);

  free(cities);
  free(distances);

  return id_pairs;
}

Edge **kruskal(uint16_t vertices, Edge **edges, size_t qtd_edges) {
  Uf *uf_set = uf_init(vertices);
  Edge **mst = edge_array_new(vertices);
  size_t i = 0;
  uint16_t e = 0;

  // evaluate until we got a complete tree or there is no elements left
  while ((e < (vertices - 1)) && i < qtd_edges) {
    Edge *next_edge = edges[i++];

    // as the ids on the file start with 1, but on Uf we use an array starting
    // with 0, we must adjust the value before using find/union operations
    size_t id1_adjusted = edge_origin_id(next_edge) - 1;
    size_t id2_adjusted = edge_destination_id(next_edge) - 1;
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

void save_mst(FILE *f, Edge **mst, const char *problem_name,
              uint16_t dimension) {
  fprintf(f, "NAME: %s\n", problem_name);
  fprintf(f, "TYPE: MST\n");
  fprintf(f, "DIMENSION: %hu\n", dimension);
  fprintf(f, "MST_SECTION\n");
  for (size_t i = 0; i < dimension - 1; i++) {
    fprintf(f, "%hu %hu\n", edge_origin_id(mst[i]),
            edge_destination_id(mst[i]));
  }
  fprintf(f, "EOF");
}

void save_tour(Edge **mst, uint16_t mst_size, const char *problem_name,
               FILE *tour_file) {
  const uint16_t start_city_id = 1;
  Graph *g = graph_new(mst_size);
  for (int i = 0; i < mst_size - 1; i++) {
    graph_edge_new(g, (edge_origin_id(mst[i]) - 1),
                   (edge_destination_id(mst[i]) - 1));
  }

  fprintf(tour_file, "NAME: %s\n", problem_name);
  fprintf(tour_file, "TYPE: TOUR\n");
  fprintf(tour_file, "DIMENSION: %hu\n", mst_size);
  fprintf(tour_file, "TOUR_SECTION\n");
  dfs(g, start_city_id, tour_file);
  fprintf(tour_file, "EOF");
  graph_free(g, mst_size);
}
