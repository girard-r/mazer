# README #

### Mazer ###

Mazer is a program that allow you to generate and solve mazes by using different algorithms
The mersene twister algorithm is used for pseudorandom numbers.
Any Maze can be save in a binary file or a svg file.

A diagram (not updated since solve exists) of the classes is available in the data folder.

### How do I get set up? ###

At the root of the project just type make and the program will compile.
The binary mazer will then be compiled and available for launch.
These rules are available in the makefile :

* make
-> Allows you to compile the program
* make re
-> make clean then make
* make clean
-> Erase all .o files that were generated during the compilation.
* make fclean
-> make clean then erase the mazer binary.

To see how to use the program you can run ./mazer without any arguments.

### How to use ? ###

## USAGE ORDER : ##

    ./mazer --g(a|e) [PARAMS] --sb [PARAMS] --sv [PARAMS] --p(m|e|d|b)

## OR : ##

    ./mazer --lb [PARAMS] --sv [PARAMS] --p(m|e|d|b)

* --g(a|e) [seed] [width] [height] <-- Optional parameters, Generate Maze with Aldous-Broder (ga) or Euler(ge)
* --sb [filename.maze] <-- Save maze in binary code into filename.maze
* --sv [filename.svg] <-- Save maze in svg into filename.svg
* --lb [filename.maze] <-- Load Maze from binary file "filename.maze"
* --pm solve the maze using A* with Manhattan Heuristic
* --pe solve the maze using A* with Euclidean Heuristic
* --pd Solve the maze using DepthFirst search
* --pb Solve the maze using BreadthFrist search

### Contribution guidelines ###

author : Aurelien Girardeau
