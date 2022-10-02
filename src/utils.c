#include "../include/utils.h"
#include "../include/city.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int compare_edges_by_distance(const void *a, const void *b) {
  Edge *e1 = *(Edge **)a;
  Edge *e2 = *(Edge **)b;
  const double d1 = edge_distance(e1);
  const double d2 = edge_distance(e2);
  if (d1 > d2)
    return 1;
  if (d1 == d2)
    return 0;
  return -1;
}

static void skip_lines(FILE *f, size_t n) {
  for (int i = 0; i < n; i++) {
    char buffer[100];
    fgets(buffer, 100, f);
  }
}

City **parse_cities(FILE *f) {
  const size_t dimension = parse_dimension(f);
  const int cities_start_pos = 6;

  // skip the lines until the start of the cities data section
  skip_lines(f, cities_start_pos);

  // allocate dynamic array of cities
  City **cities = malloc(city_size() * dimension);

  size_t id, i = 0;
  double x, y;
  while (fscanf(f, "%zu %lf %lf", &id, &x, &y) == 3) {
    cities[i] = city_new(id, x, y);
    i++;
  }

  return cities;
}

size_t parse_dimension(FILE *f) {
  size_t dimension;
  const int dimension_field_pos = 3;

  // skip the lines until the dimension field
  skip_lines(f, dimension_field_pos);

  fscanf(f, "DIMENSION: %zu\n", &dimension);
  // sets the pointer back to the very top of the file
  fseek(f, 0L, SEEK_SET);
  return dimension;
}

void sort_edges(Edge **edges, size_t qtd_edges) {
  // as the size of pointers in C is always the same, and we're expecting a
  // ponter to edge, its fine to use it like this!
  const size_t pointer_size = sizeof(void *);
  qsort(edges, qtd_edges, pointer_size, compare_edges_by_distance);
}

Edge **compute_edges(City **cities, size_t qtd_cities) {
  assert(cities != NULL && "Cities must not be null");

  // formula for the sum of the first n natural numbers
  // NOTE: the actual number that we wanna compute is the sum of (qtd_cities -
  // 1)
  size_t n = qtd_cities - 1;
  size_t qtd_edges = (n * (n + 1)) / 2;
  size_t k = 0;

  Edge **edges = malloc(edge_size() * qtd_edges);

  for (size_t i = 0; i < qtd_cities; i++) {
    for (size_t j = i + 1; j < qtd_cities; j++) {
      double distance = city_calculate_distance(cities[i], cities[j]);
      edges[k++] = edge_new(cities[i], cities[j], distance);
    }
  }

  return edges;
}

void cities_free(City **cities, size_t qtd_cities) {
  for (size_t i = 0; i < qtd_cities; i++) {
    city_free(cities[i]);
  }
  free(cities);
}

void edges_free(Edge **edges, size_t qtd_edges) {
  for (size_t i = 0; i < qtd_edges; i++) {
    edge_free(edges[i]);
  }
  free(edges);
}
