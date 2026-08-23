# Decimal to Binary — Problem Statement

> **Difficulty:** Easy  
> **Topic:** Number Systems, Mathematics, Bit Manipulation  
> **Language:** C++ / DSA
> **Platform:** Geeks For Geeks

---

## 📌 Problem Statement

Given a **non-negative decimal integer `N`**, convert it into its **binary representation**.

You are required to determine the binary representation of `N` **without using any built-in decimal-to-binary conversion function**.

This problem is intended to test your understanding of:

- **Number systems**
- **Binary representation**
- **Repeated division by `2`**
- **Remainders**
- **Integer arithmetic**
- **Bit representation**
- **Boundary values**
- **Time complexity**
- **Space complexity**

---

## 📥 Input

The input contains a single integer:

```text
N
```

### Input Range

```text
0 <= N <= 2^31 - 1
```

Which means:

```text
0 <= N <= 2147483647
```

So, the **largest possible input** is:

```text
2147483647
```

---

## 📤 Output

Print the **binary representation** of `N`.

The binary representation must:

- Contain only `0` and `1`.
- **Not contain unnecessary leading zeroes.**
- Represent the same numerical value as `N`.

### Special Case: `N = 0`

For:

```text
N = 0
```

the expected output is:

```text
0
```

---

# 🧪 Examples

## Example 1

**Input:**

```text
13
```

**Output:**

```text
1101
```

### Explanation

```text
13 = 8 + 4 + 1

8  = 2^3
4  = 2^2
1  = 2^0

Therefore:

13 = 1101₂
```

---

## Example 2

**Input:**

```text
10
```

**Output:**

```text
1010
```

---

## Example 3

**Input:**

```text
25
```

**Output:**

```text
11001
```

---

## Example 4 — Zero

**Input:**

```text
0
```

**Output:**

```text
0
```

---

## Example 5 — Smallest Positive Value

**Input:**

```text
1
```

**Output:**

```text
1
```

---

## Example 6 — Power of 2

**Input:**

```text
8
```

**Output:**

```text
1000
```

---

## Example 7 — Maximum Input

**Input:**

```text
2147483647
```

**Output:**

```text
1111111111111111111111111111111
```

---

# 📋 Important Requirements

Your program should:

1. **Read one integer `N`.**
2. Convert `N` from **decimal to binary**.
3. Print the binary representation.
4. Correctly handle the case `N = 0`.
5. Avoid unnecessary leading zeroes.
6. **Do not use a built-in decimal-to-binary conversion function.**

---

# ⚙️ Constraints

| Constraint            |        Value |
| --------------------- | -----------: |
| Minimum `N`           |          `0` |
| Maximum `N`           |   `2^31 - 1` |
| Maximum decimal value | `2147483647` |
| Maximum binary digits |         `31` |
| Number of test cases  |          `1` |

Formally:

```text
0 <= N <= 2^31 - 1
```

---

# ⏱️ Expected Complexity

Your solution should aim for:

### Time Complexity

```text
O(log N)
```

### Auxiliary Space Complexity

```text
O(1)
```

if the binary representation is constructed or printed without storing all digits in an additional container.

> **Note:** If you store the resulting binary representation inside a `string`, `vector`, `stack`, or another container, the storage required for the result can be **O(log N)**.

---

# 📊 Complexity Requirement

In your solution explanation, clearly state the following.

### 1. Time Complexity

Expected:

```text
O(log N)
```

**Reason:** the number is repeatedly reduced by a factor of `2`.

Conceptually:

```text
N
↓
N / 2
↓
N / 4
↓
N / 8
↓
...
↓
1
↓
0
```

---

### 2. Auxiliary Space Complexity

Target:

```text
O(1)
```

for the basic iterative arithmetic approach.

If you store the resulting binary representation, distinguish between:

```text
Auxiliary Space
```

and:

```text
Output / Result Space
```

---

# 🤔 What You Should Think About Before Coding

Before writing the solution, think about these questions.

### Question 1

When an integer is divided by `2`, what possible remainders can occur?

```text
?
```

---

### Question 2

What does the remainder tell us about the binary representation?

```text
?
```

---

### Question 3

After extracting one binary digit, what operation should be performed on the number?

```text
?
```

---

### Question 4

In what order are the binary digits obtained?

```text
?
```

---

### Question 5

If the digits are obtained in reverse order, how can you produce the correct final representation?

```text
?
```

---

### Question 6

How many times can you divide `N` by `2` before it becomes `0`?

```text
?
```

Use this observation to derive the **time complexity**.

---

# 🧩 Edge Cases to Test

Your solution should be tested with at least the following values:

```text
0
1
2
3
4
7
8
15
16
31
32
100
1024
2147483647
```

### Expected Results for Common Cases

| Input | Expected Binary Output |
| ----: | ---------------------: |
|   `0` |                    `0` |
|   `1` |                    `1` |
|   `2` |                   `10` |
|   `3` |                   `11` |
|   `4` |                  `100` |
|   `7` |                  `111` |
|   `8` |                 `1000` |
|  `15` |                 `1111` |
|  `16` |                `10000` |
|  `31` |                `11111` |
|  `32` |               `100000` |

---

# 🚫 Output Format — Important

The problem does **not** ask you to print:

- Intermediate calculations.
- Quotients.
- Remainders.
- The complexity.
- Explanations.
- Any additional labels.

Only the **final binary representation** should be printed.

### Correct

For input:

```text
13
```

output:

```text
1101
```

### Not Required

```text
Binary Form: 1101
```

unless the problem explicitly asks for that format.

---

# 🔍 Important Observation

The first remainder obtained during repeated division by `2` represents the:

**Least Significant Bit (LSB).**

The final remainder represents the:

**Most Significant Bit (MSB).**

Therefore, the digits are naturally obtained in:

```text
LSB → MSB
```

while normal binary notation is written as:

```text
MSB → LSB
```

Think about how this affects your implementation.

---

# 🎯 Follow-Up Questions

After solving the basic problem, try these variations.

## Variation 1 — Modulo and Division

Can you solve it using:

```cpp
%
/
```

That is:

```text
Modulo + Division
```

---

## Variation 2 — Bit Manipulation

Can you solve it using:

```cpp
&
>>
```

That is:

```text
Bitwise AND + Right Shift
```

---

## Variation 3 — Without a String

Can you print the binary representation without storing all digits in a `string`?

---

## Variation 4 — Fixed Width

Can you produce exactly **32 bits**, including leading zeroes?

For example, for:

```text
13
```

the output would be:

```text
00000000000000000000000000001101
```

---

## Variation 5 — Recursion

Can you solve the same problem recursively?

---

## Variation 6 — Other Number Systems

Can you generalize the same idea to:

- **Decimal → Octal**
- **Decimal → Hexadecimal**
- **Decimal → Any Base**

---

# 💼 Interview Expectations

If this problem is asked in an interview, be prepared to explain:

1. **Why division by `2` is used.**
2. **Why the remainder can only be `0` or `1`.**
3. **Why the remainder represents a binary digit.**
4. **Why the digits are obtained in reverse order.**
5. **How you handle `N = 0`.**
6. **Time complexity.**
7. **Space complexity.**
8. **Potential integer overflow issues**, depending on how the result is stored.

---

# 📝 Important Note About the Solution

This file intentionally contains **only the problem statement and requirements**.

It does **not** contain:

- The final algorithm.
- Completed C++ code.
- A step-by-step solution.
- The modulo/division implementation.
- The bit-manipulation implementation.

The purpose is to allow you to **solve the problem independently**.

---

# 📌 Problem Summary

### Input

```text
One non-negative integer N
```

### Input Range

```text
0 <= N <= 2^31 - 1
```

### Output

```text
Binary representation of N
```

### Leading Zeroes

```text
Not allowed
```

except when:

```text
N = 0
```

where the output must be:

```text
0
```

### Target Time Complexity

```text
O(log N)
```

### Target Auxiliary Space

```text
O(1)
```

### Maximum Number of Binary Digits

```text
31
```

for the given input constraint.

---

# 🏁 One-Line Problem Statement

> **Given a non-negative integer `N`, where `0 <= N <= 2^31 - 1`, print its binary representation without unnecessary leading zeroes. The expected time complexity is `O(log N)` with preferably `O(1)` auxiliary space.**

---

## 🔖 Quick Reference

```text
Problem:
    Decimal → Binary

Input:
    One integer N

Range:
    0 <= N <= 2^31 - 1

Maximum N:
    2147483647

Output:
    Binary representation of N

Special case:
    0 → 0

Leading zeroes:
    Not allowed

Expected Time:
    O(log N)

Expected Auxiliary Space:
    O(1)

Maximum output bits:
    31
```

# END OF PROBLEM STATEMENT
