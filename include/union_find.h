#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdbool.h>
#include <stddef.h>

typedef struct uf Uf;

// initializes a new uf unit for sz elements. Where all of them are unconnected at first
Uf *uf_init(size_t sz);
// finds the element given the unit
size_t uf_find(Uf *uf, size_t pos);
// merge two elements together
void uf_union(Uf *uf, size_t pos1, size_t pos2);
// checks if two elements are connected
bool uf_connected(Uf *uf, size_t pos1, size_t pos2);
// frees allocated memory
void uf_free(Uf *uf);

#endif // !UNION_FIND_H
