# Pair With Difference

Problem Link: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1?utm_source=chatgpt.com

---

## Problem Statement

Given an array, arr[] and an integer x, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.

---

## Examples

### Example 1

```text
Input:
arr[] = [5, 20, 3, 2, 5, 80], x = 78

Output:
true

Explanation:
Pair (2, 80) have an absolute difference of 78.
```

### Example 2

```text
Input:
arr[] = [90, 70, 20, 80, 50], x = 45

Output:
false

Explanation:
There is no pair with absolute difference of 45.
```

### Example 3

```text
Input:
arr[] = [1], x = 1

Output:
false
```

---

## Constraints

```text
1<= arr.size() <=106
1<= arr[i] <=106
0<= x <=105
```
