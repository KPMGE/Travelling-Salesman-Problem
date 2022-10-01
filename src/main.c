#include "../include/utils.h"
#include "../include/city.h"
#include <stdio.h> 


int main(int argc, char *argv[])
{
    FILE *f = fopen("a280.tsp", "r");

    int id, dimension;
    float x, y;

    // skip lines and return dimension
    dimension = return_dimension(f);

    City *cities[dimension]; // array of cities

    int i = 0;
    while (fscanf(f, "%d %f %f", &id, &x, &y) == 3)
    {
        cities[i] = city_new(id, x, y);
        i++;
    }
    fclose(f);

    //impriindo as cidades para ver se ta tudo certo
    
    for (int j = 0; j < dimension; j++)
        printf("%d %.2f %.2f\n", cities[j]->id, cities[j]->x, cities[j]->y);

    for (int i = 0; i < dimension; i++)
        free(cities[i]);

    return 0;
}
