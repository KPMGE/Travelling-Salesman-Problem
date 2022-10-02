#include "../include/union_find.h"
#include <stdlib.h>

struct uf {
  size_t *ids;
  size_t *sizes;
};

Uf *uf_init(size_t sz) {
  Uf *uf = malloc(sizeof(Uf));

  uf->sizes = calloc(sz, sizeof(size_t));
  uf->ids = malloc(sizeof(size_t) * sz);

  for (size_t i = 0; i < sz; i++) {
    uf->ids[i] = i;
  }

  return uf;
}

size_t uf_find(Uf *uf, size_t pos) {
  size_t *ids = uf->ids;
  while (pos != ids[pos]) {
    ids[pos] = ids[ids[pos]];
    pos = ids[pos];
  }
  return pos;
}

void uf_union(Uf *uf, size_t pos1, size_t pos2) {
  size_t idx1 = uf_find(uf, pos1);
  size_t idx2 = uf_find(uf, pos2);

  size_t *sizes = uf->sizes;
  size_t *ids = uf->ids;

  if (idx1 == idx2)
    return;
  if (sizes[idx1] < sizes[idx2]) {
    ids[idx1] = idx2;
    sizes[idx2] += sizes[idx1];
  } else {
    ids[idx2] = idx1;
    sizes[idx1] += sizes[idx2];
  }
}

bool uf_connected(Uf *uf, size_t pos1, size_t pos2) {
  return uf_find(uf, pos1) == uf_find(uf, pos2);
}
