# Travelling-Salesman-Problem

## How do i run it?
First, compile your program using *make*

```bash
make
```

Then, a new executable called **trab1** will be generated at the root directory. 
Now you can go ahead and execute it, passing in a *.tsp* file, as follows: 

```bash
./trab1 <path to .tsp file>
```

--- 

### Conventions
- [x] Code in English.
- [x] Functions must be written in *snake_case*.
- [x] _Structs_ must start with the first letter in uppercase and use _CamelCase_.
- [x] The **.h** files must be at the *include* folder.
- [x] The **.c** files must be at the _src_ folder.

### Steps
- [x] Read **.tsp** file and save it to an array of Cities.
- [x] Create array of **Edge** with the distances between all cities.
- [x] Create *UnionFind* TAD.
- [x] Implement _kruskal_ algorithm to compute *MST*.
- [x] Save mst to a file and see if it works properly.
- [x] Create graph and traverse it using _DFS_ to compute tour.
- [x] Save tour to a file and see if it works properly.
- [x] Check possible memory leaks and solve them.
