#include "../include/union_find.h"
#include "../include/utils.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // create some variables, this will be a struct later on ...
  int a = 0, b = 1, c = 3, d = 4;

  // create some sets, noninterconnected to one another
  UfNode *sa = uf_set_new(&a);
  UfNode *sb = uf_set_new(&b);
  UfNode *sc = uf_set_new(&c);
  UfNode *sd = uf_set_new(&d);

  // conects sa and sb
  printf("=== connecting sa and sb === \n");
  uf_union(sa, sb);

  // sa and sb should be connected at this point
  printf("<sa> connected <sb>: %d\n", uf_connected(sa, sb));
  // sa and sc should not be connected at this point
  printf("<sa> connected <sc>: %d\n", uf_connected(sa, sc));
  // sa and sd should not be connected at this point
  printf("<sa> connected <sd>: %d\n", uf_connected(sa, sd));

  printf("\n=== connecting sa and sd === \n");
  // conects sa and sd
  uf_union(sa, sd);
  // sa and sd should be connected at this point
  printf("<sa> connected <sd>: %d\n", uf_connected(sa, sd));
  // sb and sd should be connected at this point
  printf("<sb> connected <sd>: %d\n", uf_connected(sb, sd));
  // sc and sd should be connected at this point
  printf("<sc> connected <sd>: %d\n", uf_connected(sc, sd));
}
