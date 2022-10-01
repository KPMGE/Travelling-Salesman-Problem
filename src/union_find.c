#include "../include/union_find.h"
#include <stdlib.h>

struct uf_node {
  struct uf_node *parent;
  void *value;
  int depth;
};

UfNode *uf_init(void *value) {
  UfNode *singleton = malloc(sizeof(UfNode));
  singleton->value = value;
  singleton->depth = 1;
  singleton->parent = NULL;
  return singleton;
}

UfNode *uf_find(UfNode *elem) {
  if (!elem)
    return NULL;

  UfNode *original = elem;
  // find the root
  while (elem->parent) {
    elem = elem->parent;
  }

  if (elem != original->parent && elem != original) {
    original->parent = elem; // path compression
  }

  return elem;
}

UfNode *uf_union(UfNode *a, UfNode *b) {
  UfNode *root_a = uf_find(a);
  UfNode *root_b = uf_find(b);
  UfNode *newroot = root_a;
  if (root_a != root_b) {
    if (root_a->depth > root_b->depth) { // merge by rank
      root_b->parent = root_a;
      root_a->depth++;
    } else {
      root_a->parent = root_b;
      root_b->depth++;
      newroot = root_b;
    }
  }
  return newroot;
}

bool uf_connected(UfNode *a, UfNode *b) { return uf_find(a) == uf_find(b); }
