# Travelling-Salesman-Problem

## How do i run it?
First, compile your program using *make*

```bash
make
```

Then, a new executable called **trab1** will be generated at the **/bin** directory. 
Now you can run the program by simply doing: 

```bash
./bin/trab1 <path to .tsp file>
```

--- 

### Conventions
- [x] Code in English
- [x] Functions must be written in *snake-case*
- [x]  Structs must start with the first letter in uppercase and use *camel-case*
- [x] The **.h** files must be at the *include* folder
- [x] The *.c* files must be at the *src* folder

### Steps
- [x] Read **.tsp** file and save it to an array of Cities.
- [x] Create array of **Edge** with the distances between all cities.
- [x] Create **UnionFind** TAD.
- [x] Implement kruskal algorithm to compute *MST*
- [x] Save mst to a file and see if it works properly
