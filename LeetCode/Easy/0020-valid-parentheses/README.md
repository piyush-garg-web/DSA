# Valid Parentheses

Problem Link: https://leetcode.com/problems/valid-parentheses

---

## Problem Statement

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:


	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Every close bracket has a corresponding open bracket of the same type.

---

## Examples

### Example 1

```text
Input:
s = "()"

Output:
true
```

### Example 2

```text
Input:
s = "()[]{}"

Output:
true
```

### Example 3

```text
Input:
s = "(]"

Output:
false
```

### Example 4

```text
Input:
s = "([])"

Output:
true
```

### Example 5

```text
Input:
s = "([)]"

Output:
false
```

---

## Constraints

```text
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
```
