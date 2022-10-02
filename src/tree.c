#include <stdio.h>
#include <stdlib.h>

#include "../include/tree.h"
#include "../include/city.h"

struct tree {
  City *origin, *destination;
  double distance;
  struct node **children;
};

TreeNode *treeNode_new(City *origin, City *destination, double distance){
  TreeNode *t = malloc(sizeof(TreeNode));
  t->origin = origin;
  t->destination = destination;
  t->distance = distance;

  return t;
}

int empty_tree(TreeNode *t){
  return t == NULL;
}

void *treeNode_free(TreeNode *t){
  if(!empty_tree(t)){
    free(t->origin);
    free(t->destination);
    //free(t->children);
    free(t);
  }
}

City *return_origin(TreeNode *t){
  return t->origin;
}

City *return_destination(TreeNode *t){
  return t->destination;
}

double return_distance(TreeNode *t){
  return t->distance;
}

// RETURN CHILDREN
