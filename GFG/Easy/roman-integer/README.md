# Roman Integer

---

## Problem Statement

Given a string s in Roman number format, your task is to convert it to an integer. Various symbols and their values are given below.
Note: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

---

## Examples

### Example 1

```text
Input:
s = "IX"

Output:
9

Explanation:
IX is a Roman symbol which represents 10 – 1 = 9.
```

### Example 2

```text
Input:
s = "XL"

Output:
40

Explanation:
XL is a Roman symbol which represents 50 – 10 = 40.
```

### Example 3

```text
Input:
s = "MCMIV"

Output:
1904

Explanation:
M is 1000, CM is 1000 – 100 = 900, and IV is 4. So we have total as 1000 + 900 + 4 = 1904.
```

---

## Constraints

```text
1 ≤ roman number ≤ 3999
s[i] belongs to [I, V, X, L, C, D, M]
```
