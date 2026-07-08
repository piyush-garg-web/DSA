# Median Row Wise Sorted Matrix

---

## Problem Statement

Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

---

## Examples

### Example 1

```text
Input:
mat[][] = [[1, 3, 5],

Output:
5

Explanation:
Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
```

### Example 2

```text
Input:
mat[][] = [[2, 4, 9],

Output:
6

Explanation:
Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
```

### Example 3

```text
Input:
mat = [[3], [4], [8]]

Output:
4

Explanation:
Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
```

---

## Constraints

```text
1 ≤ n, m ≤ 400
1 ≤ mat[i][j] ≤ 2000
```
