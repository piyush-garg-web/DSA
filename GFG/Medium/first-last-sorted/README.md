# First Last Sorted

Problem Link: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

---

## Problem Statement

Given a sorted array arr[] with possibly some duplicates, find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

---

## Examples

### Example 1

```text
Input:
arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5

Output:
[2, 5]

Explanation:
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5
```

### Example 2

```text
Input:
arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7

Output:
[6, 6]

Explanation:
First and last occurrence of 7 is at index 6
```

### Example 3

```text
Input:
arr[] = [1, 2, 3], x = 4

Output:
[-1, -1]

Explanation:
No occurrence of 4 in the array, so, output is [-1, -1]
```

---

## Constraints

```text
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], x ≤ 109
```
