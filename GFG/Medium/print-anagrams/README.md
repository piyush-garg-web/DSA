# Print Anagrams

Problem Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1

---

## Problem Statement

Given an array arr[] of strings, group together all strings that are anagrams of each other.

Two strings are anagrams if they contain the same characters with the same frequencies, possibly in a different order.

The strings within each group must appear in the same order as they occur in the input array.

Return a 2D array where each inner array represents a group of anagrams.

---

## Examples

### Example 1

```text
Input:
arr[] = ["act", "god", "cat", "dog", "tac"]

Output:
[["act", "cat", "tac"], ["god", "dog"]]

Explanation:
There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
```

### Example 2

```text
Input:
arr[] = ["no", "on", "is"]

Output:
[["is"], ["no", "on"]]

Explanation:
There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
```

### Example 3

```text
Input:
arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]

Output:
[["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]

Explanation:
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
```

---

## Constraints

```text
1 ≤ arr.size() ≤ 104
1 ≤ arr[i].size() ≤ 20
```
