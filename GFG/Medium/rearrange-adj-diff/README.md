# Rearrange Adj Diff

Problem Link: https://www.geeksforgeeks.org/problems/rearrange-characters4649/1

---

## Problem Statement

Given a string s consisting of lowercase English letters, check whether it can be rearranged such that no two adjacent characters are the same.

Return true if possible, otherwise, return false.

---

## Examples

### Example 1

```text
Input:
s = "aaabc"

Output:
true

Explanation:
"aaabc" can rearranged to "abaca" or "acaba" as no two adjacent characters are same in the output string.
```

### Example 2

```text
Input:
s = "aaabb"

Output:
true

Explanation:
"aaabb" can rearranged to "ababa" as no two adjacent characters are same in the output string.
```

### Example 3

```text
Input:
s = "aaaabc"

Output:
false

Explanation:
No combinations possible such that two adjacent characters are different.
```

---

## Constraints

```text
1 ≤ |s| ≤ 105
```
