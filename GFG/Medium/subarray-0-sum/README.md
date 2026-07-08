# Subarray 0 Sum

---

## Problem Statement

Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not.

---

## Examples

### Example 1

```text
Input:
arr[] = [4, 2, -3, 1, 6]

Output:
true

Explanation:
2, -3, 1 is the subarray with a sum of 0.
```

### Example 2

```text
Input:
arr = [4, 2, 0, 1, 6]

Output:
true

Explanation:
0 is one of the element in the array so there exist a subarray with sum 0.
```

### Example 3

```text
Input:
arr = [1, 2, -1]

Output:
false
```

---

## Constraints

```text
1 <= arr.size <= 105
-105 <= arr[i] <= 105
```
