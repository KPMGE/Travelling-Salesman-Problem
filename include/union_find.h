#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "tree.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct uf_node UfNode;

UfNode *uf_set_new(void *value);
UfNode *uf_find(UfNode *uf);
UfNode *uf_union(UfNode *a, UfNode *b);
bool uf_connected(UfNode *a, UfNode *b);

#endif // !UNION_FIND_H
