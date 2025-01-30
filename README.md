# Maze-Solver
To start learning C I decided to make a Maze Solver using the A* algorithm.

## How it works
The program loads a map.txt file path that is specified in the main.c.

The program will then load the map and read the meta-data and start the algorithm.

It will print out somethings to the console to show what is happening at that point.

### Map format
*   The first line of the map.txt file should be reserved for the dimensions of the map. The first dimension is the height (top to bottom) and the second number is the width (left to right)
*   After the first line you can start making the map.
*   To specify the start and goal of the maze is noted as 's' and 'g'.
*   To specify a cell that is part of the path that can be traversed is a space.
*   To specify the walls or part of the map that is not on the path is noted as '#'.
*   **make sure that the dimension match**
*   The last thing to note is the '$' at the end of the file that tells the program that the end of the map has been reached.
~~~
20 40
########################################
#                                      #
### ################################## #
### ################################## #
# # ################################## #
# # ################################## #
# # ################################## #
# # ################################## #
# # ################################## #
# # ################################## #
#   ################################## #
# #################################### #
# #################################### #
# #################################### #
# #################################### #
# #################################### #
# #################################### #
# #################################### #
#                                      #
#s####################################g#
$
~~~

When the algorithm is done a function will be called to backtrack and find the optimized path from the A* algorithm.

After this the map will be printed out with the final path shown with '.'.

Example of output
~~~
Loading map
Reading map meta-data
Map Row : 20
Map Column : 20
Allocating memory space for mapData
Reading map data
Loaded map data
Done loading map
Start Node: 0 1
End Node: 19 1

1 . 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 . . . . . . . . . . . . . . . . . . 1
1 1 1   1 1 1 1 1 1 1 1 1   1 1 1 1 . 1
1   1   1 1                 1 1 1 1 . 1
1   1   1 1   1 1 1 1 1 1   1 1 1 1 . 1
1   1   1 1   1 1 1 1 1 1   1 1 1 1 . 1
1       1 1   1 1 1 1 . . . . . . . . 1
1 1 1         1 1 1 1 . 1 1 1 1 1 1 1 1
1   1 1 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 1
1                   1 . 1 1 1 1 1 1 1 1
1 1 1   1 1 1 1 1   1 . 1 1 1 1 1 1 1 1
1 1 1   1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 1
1 . . . . . . . . . . . 1 1 1 1 1 1 1 1
1 . 1 1 1 1 1 1 1 1 1   1 1 1 1 1 1 1 1
1 . 1               1   1 1 1 1 1 1 1 1
1 . 1   1 1 1 1 1   1   1 1 1 1 1 1 1 1
1 . 1 1 1 1 1 1 1   1   1 1 1 1 1 1 1 1
1 . . . . . . . . . . . 1 1 1 1 1 1 1 1
1 . . . . . . . . . . . 1 1 1 1 1 1 1 1
1 . 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
~~~

**There is a little issue with the algorithm doing more work than is needed, example above**

I think for a first time C program, it is decent. It was definetily a learning curve having to manage the memory myself and not by a garbage collector.
