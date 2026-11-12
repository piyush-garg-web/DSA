# Assembly Line Scheduling

## Problem Statement

A car factory has two assembly lines, each containing n stations.

Every station performs a specific task such as engine fitting, body fitting, painting, etc.

The stations at the same position on both assembly lines perform the same type of task.

A car chassis must pass through all n stations in order, starting from either assembly line, and may switch between lines at any station while incurring the corresponding transfer time.

Determine the minimum total time required to manufacture the car chassis

You are given:

A 2D array a[][] of size 2*n, where a[i][j] represents the time required to process station j on assembly line i.

A 2D array t[][] of size 2*n where t[0][j] represents the time required to switch from assembly line 1 to assembly line 2, and t[1][j] represents the time required to switch from assembly line 2 to assembly line 1, both between stations j-1 and j.

Entry times e[] of size 2, where e[i] is the time required to enter assembly line i.

Exit times x[] of size 2, where x[i] is the time required to exit assembly line i.


## Problem Link
https://www.geeksforgeeks.org/problems/assembly-line-scheduling/1
