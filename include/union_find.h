#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "tree.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct uf Uf;

Uf *uf_init(size_t sz);
size_t uf_find(Uf *uf, size_t pos);
void uf_union(Uf *uf, size_t pos1, size_t pos2);
bool uf_connected(Uf *uf, size_t pos1, size_t pos2);
void uf_free(Uf *uf);

#endif // !UNION_FIND_H
