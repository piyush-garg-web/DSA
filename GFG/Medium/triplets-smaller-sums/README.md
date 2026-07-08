# Triplets Smaller Sums

Problem Link: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

---

## Problem Statement

Given an array arr[] of distinct integers and a value sum, find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

---

## Examples

### Example 1

```text
Input:
sum = 2, arr[] = [-2, 0, 1, 3]

Output:
2

Explanation:
Triplets with sum less than 2 are (-2, 0, 1) and (-2, 0, 3).
```

### Example 2

```text
Input:
sum = 12, arr[] = [5, 1, 3, 4, 7]

Output:
4

Explanation:
Triplets with sum less than 12 are (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).
```

---

## Constraints

```text
1 ≤ sum ≤ 105
3 ≤ arr.size() ≤ 103
-103 ≤ arr[i] ≤ 103
```
