# 4 Sum All Quadruples

Problem Link: https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

---

## Problem Statement

Given an array arr[] of integers and another integer target. You have to find all unique quadruples from the given array whose sum is equal to the given target.

Note: All the quadruples should be internally sorted, i.e for any quadruple [q1, q2, q3, q4] it should be : q1 ≤ q2 ≤ q3 ≤ q4.

---

## Examples

### Example 1

```text
Input:
arr[] = [0, 0, 2, 1, 1], target = 3

Output:
[[0, 0, 1, 2]]

Explanation:
Sum of 0, 0, 1, 2 is equal to 3.
```

### Example 2

```text
Input:
arr[] = [10, 2, 3, 4, 5, 7, 8], target = 23

Output:
[[2, 3, 8, 10], [2, 4, 7, 10], [3, 5, 7, 8]]

Explanation:
Sum of [2, 3, 8, 10] is 23, sum of [2, 4, 7, 10] is 23 and sum of [3, 5, 7, 8] is also 23.
```

### Example 3

```text
Input:
arr[] = [0, 0, 2, 1, 1], target = 2

Output:
[[0, 0, 1, 1]]

Explanation:
Sum of [0, 0, 1, 1] is equal to 2.
```

---

## Constraints

```text
1 ≤ arr.size() ≤ 200
-106 ≤ target ≤ 106
-106 ≤ arr[i] ≤ 106
```
