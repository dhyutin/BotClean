# BotClean
Problem Statement :

https://www.hackerrank.com/challenges/botcleanlarge/problem

MegaMaid is a robot whose function is to move through a matrix and clean all of its dirty cells. It's positioned in some cell of an  matrix of dirty (d) and clean (-) cells. It can perform five types of operations:

- LEFT: Move one cell to the left.

- RIGHT: Move one cell to the right.

- UP: Move one cell up.

- DOWN: Move one cell down.

- CLEAN: Clean the cell.

Given the robot's current location and the configuration of dirty and clean cells in the matrix, print the next operation MegaMaid will perform (e.g., UP, CLEAN, etc.) on a new line.


Solution :
In my code, I first implemented BFS Algorithm to find the dirty cell that is closest to the MegaMaid's location and then moved a step closer to it.
