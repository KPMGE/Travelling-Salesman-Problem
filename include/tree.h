#ifndef TREE_H
#define TREE_H

#include "city.h"

typedef struct tree TreeNode;

TreeNode *treeNode_new(City *origin, City *destination, double distance);

int empty_tree(TreeNode *t);

void *treeNode_free(TreeNode *t);



#endif // !TREE_H
