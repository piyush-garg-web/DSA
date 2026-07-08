# Spiral Matrix

Problem Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

---

## Problem Statement

Given a rectangular matrix mat[][] of size n x m, and return a 1D array containing all its elements in spiral order.

---

## Examples

### Example 1

```text
Input:
mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

Output:
[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
```

### Example 2

```text
Input:
mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]

Output:
[1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]

Explanation:
Applying same technique as shown above.
```

### Example 3

```text
Input:
mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]

Output:
[32, 44, 27, 23, 62, 50, 28, 54]

Explanation:
Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].
```

---

## Constraints

```text
1 ≤ n, m ≤1000
0 ≤ mat[i][j] ≤100
```
