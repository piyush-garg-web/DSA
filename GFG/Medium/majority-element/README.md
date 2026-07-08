# Majority Element

Problem Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

---

## Problem Statement

Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

---

## Examples

### Example 1

```text
Input:
arr[] = [1, 1, 2, 1, 3, 5, 1]

Output:
1

Explanation:
Since, 1 is present more than 7/2 times, so it is the majority element.
```

### Example 2

```text
Input:
arr[] = [7]

Output:
7

Explanation:
Since, 7 is single element and present more than 1/2 times, so it is the majority element.
```

### Example 3

```text
Input:
arr[] = [2, 13]

Output:
-1

Explanation:
Since, no element is present more than 2/2 times, so there is no majority element.
```

---

## Constraints

```text
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
```
