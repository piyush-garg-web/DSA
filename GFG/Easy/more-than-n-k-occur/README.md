# More Than N K Occur

---

## Problem Statement

Given an array arr and an element k. The task is to find the count of elements in the array that appear more than n/k times and n is length of arr.

---

## Examples

### Example 1

```text
Input:
arr = [3, 1, 2, 2, 1, 2, 3, 3], k = 4

Output:
2

Explanation:
In the given array, 3 and 2 are the only elements that appears more than n/k times.
```

### Example 2

```text
Input:
arr = [2, 3, 3, 2], k = 3

Output:
2

Explanation:
In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
```

### Example 3

```text
Input:
arr = [1, 4, 7, 7], k = 2

Output:
0

Explanation:
In the given array, no element appears more than n/k times.
```

---

## Constraints

```text
1 <= arr.size() <= 106
0 <= arr[i] <= 108
1 <= k <= arr.size()
```
