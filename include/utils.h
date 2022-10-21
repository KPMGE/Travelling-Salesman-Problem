#ifndef UTILS_H
#define UTILS_H

#include "city.h"
#include <stdint.h>

#define ORIGIN_ID(arr, pos) arr[2 * pos]
#define DESTINATION_ID(arr, pos) arr[2 * pos + 1]

// returns an array of cities, read from file
City **parse_cities(FILE *f);
// returns the dimension of the tsp file
uint16_t parse_dimension(FILE *f);
// returns array with all the combinations between the cities, sorted by distance
uint16_t *compute_edges(City **cities, uint16_t qtd_cities);
// computes mst
uint16_t *kruskal(uint16_t vertices, uint16_t *edges, size_t qtd_edges);
// save mst into an out file
void save_mst(FILE *f, uint16_t *mst, const char *problem_name,
              uint16_t dimension);
// returns the problem name
char *parse_problem_name(FILE *f);
// save tour to an out file
void save_tour(uint16_t *mst, uint16_t mst_size, const char *problem_name,
               FILE *tour_file);

#endif // !UTILS_H
