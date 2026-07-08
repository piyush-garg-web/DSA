# Second Most Repeated String Sequence

---

## Problem Statement

Given a sequence of strings arr[], find and return the second highest frequency (count of occurrences) among all strings in the array.

Note:

If all strings have the same frequency, return -1.
If there is only one unique string in the array, return -1.
If the array is empty, return -1.

Examples:

```
Input: arr[] = ["aaa", "bbb", "ccc", "bbb", "aaa", "aaa"]
Output: 2
Explanation: "bbb" is the second most occurring string with frequency 2. So the answer for this test case is 2.
```

```
Input: arr[] = ["aaa", "aaa", "aaa", "aaa", "aaa", "aaa"]
Output: -1
Explanation: There is only one unique string with frequency 6. So answer for this test case is -1.
```

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i].size() ≤ 10

---

## Complexity Analysis

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

## Topics
- String
- Hash Map
