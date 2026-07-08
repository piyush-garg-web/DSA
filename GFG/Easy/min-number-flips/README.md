# Min Number Flips

---

## Problem Statement

Given a binary string s of length n. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

---

## Examples

### Example 1

```text
Input:
s = "001"

Output:
1

Explanation:
We can flip the 0th bit to 1 to have "101".
```

### Example 2

```text
Input:
s = "0001010111"

Output:
2

Explanation:
We can flip the 1st and 8th bit. After this we have "0101010101"
```

---

## Constraints

```text
1 ≤ |s| ≤ 105
```
