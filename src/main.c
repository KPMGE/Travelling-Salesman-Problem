#include "../include/city.h"
#include "../include/union_find.h"
#include "../include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *file_path = argv[1];
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Could not open file");

  size_t dim = parse_dimension(f);
  printf("dimension: %zu\n", dim);
  City **cities = parse_cities(f);

  for (size_t i = 0; i < dim; i++) {
    printf("id: %zu, x: %.2lf, y: %.2lf\n", city_id(cities[i]),
           city_x(cities[i]), city_y(cities[i]));
  }

  fclose(f);
  cities_free(cities, dim);
}

// typedef struct {
//   City *origin, *destination;
//   double distance;
// } Edge;

// Edge *edge_new(City *origin, City *destination, double distance) {
//   Edge *e = malloc(sizeof(Edge));
//   e->origin = origin;
//   e->destination = destination;
//   e->distance = distance;
//   return e;
// }

// void kruskal(size_t vertices, Edge **edges, size_t qtd_edges) {
//   Uf *uf_set = uf_init(vertices);
//   Edge **mst = malloc(sizeof(Edge) * vertices);
//   size_t e = 0, i = 0;

//   while (e < (vertices - 1) && i < qtd_edges) {
//     Edge *next_edge = edges[i++];

//     size_t pos1 = uf_find(uf_set, city_id(next_edge->origin));
//     size_t pos2 = uf_find(uf_set, city_id(next_edge->destination));

//     if (!uf_connected(uf_set, pos1, pos2)) {
//       mst[e++] = next_edge;
//       uf_union(uf_set, pos1, pos2);
//     }
//   }

//   printf("edges for the mst: \n\n");
//   for (size_t i = 0; i < e; i++) {
//     printf("%zu --> %zu == %.2f\n", city_id(mst[i]->origin),
//            city_id(mst[i]->destination), mst[i]->distance);
//   }

//   uf_free(uf_set);
// }
