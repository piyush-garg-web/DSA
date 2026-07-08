# Zero Sum Subarrays

Problem Link: https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

---

## Problem Statement

You are given an array arr[] of integers. Find the total count of subarrays with their sum equal to 0.

---

## Examples

### Example 1

```text
Input:
arr[] = [0, 0, 5, 5, 0, 0]

Output:
6

Explanation:
The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
```

### Example 2

```text
Input:
arr[] = [6, -1, -3, 4, -2, 2, 4, 6, -12, -7]

Output:
4

Explanation:
The 4 subarrays are [-1, -3, 4], [-2, 2], [2, 4, 6, -12],
and [-1, -3, 4, -2, 2]
```

### Example 3

```text
Input:
arr[] = [0]

Output:
1

Explanation:
The only subarray is [0].
```

---

## Constraints

```text
1 <= n <= 106
-109 <= arr[ i ] <= 109
```
