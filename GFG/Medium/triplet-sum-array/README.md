# Triplet Sum Array

Problem Link: https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

---

## Problem Statement

Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

Return true if such a triplet exists, otherwise, return false.

---

## Examples

### Example 1

```text
Input:
arr[] = [1, 4, 45, 6, 10, 8], target = 13

Output:
true

Explanation:
The triplet {1, 4, 8} sums up to 13.
```

### Example 2

```text
Input:
arr[] = [1, 2, 4, 3, 6, 7], target = 10

Output:
true

Explanation:
The triplets {1, 3, 6} and {1, 2, 7} both sum to 10.
```

### Example 3

```text
Input:
arr[] = [40, 20, 10, 3, 6, 7], target = 24

Output:
false

Explanation:
No triplet in the array sums to 24.
```

---

## Constraints

```text
3 ≤ arr.size() ≤ 5*103
0 ≤ arr[i], target ≤ 105
```
