# Search Array Adj Diff At Most K

---

## Problem Statement

Given a step array arr[], its step value k, and a key x, we need to find the index of key x in the array arr[]. If multiple occurrences of key x exist, return the first occurrence of the key. In case of no occurrence of key x exists return -1.

Note: A step array is an array of integers where the difference between adjacent elements is at most k. For example: arr[] = [4, 6, 7, 9] and k = 2 is a step array as the difference between the adjacent elements in the arr[] is at most 2.  

Examples

Input: arr[] = [4, 5, 6, 7, 6] , k = 1 , x = 6
Output: 2
Explanation: In an array arr 6 is present at index 2. So, return 2.
Input: arr[] = [20, 40, 50], k = 20 , x = 70
Output: -1 
Explaination: As there is no occurrence of 70. So, return -1.


Constraints:
1 ≤ arr.size ≤ 105
1 ≤ k ≤ 102
1 ≤ arr[i], x ≤ 105

---

## Complexity Analysis

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## Topics
- Array
