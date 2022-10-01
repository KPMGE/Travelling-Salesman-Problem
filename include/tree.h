#ifndef TREE_H
#define TREE_H

#include "city.h"

typedef struct tree TreeNode;

TreeNode *treeNode_new(City *origin, City *destination, double distance);

int empty_tree(TreeNode *t);

void *treeNode_free(TreeNode *t);

City *return_origin(TreeNode *t);

City *return_destination(TreeNode *t);  

double return_distance(TreeNode *t);



#endif // !TREE_H
