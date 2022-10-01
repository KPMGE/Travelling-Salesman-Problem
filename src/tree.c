#include "../include/tree.h"
#include "../include/city.h"

struct tree {
  City *origin, *destination;
  double distance;
  struct node **children;
};
