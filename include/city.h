#ifndef CITY_H
#define CITY_H


typedef struct city City;

City *city_new(int id, double x, double y);
int return_dimension(FILE *f);

#endif // !CITY_H
