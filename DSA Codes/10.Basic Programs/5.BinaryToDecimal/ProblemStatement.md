# Binary to Decimal — Problem Statement

> **Difficulty:** Easy  
> **Topic:** Number Systems, Mathematics, Binary Representation  
> **Language:** C++ / DSA
> **Platform:** GeeksForGeeks, Naukri(Code360)

---

## 📌 Problem Statement

Given a **binary number** consisting only of `0` and `1`, convert it into its corresponding **decimal integer**.

The problem tests your understanding of:

- **Binary and decimal number systems**
- **Place values**
- **Powers of `2`**
- **Positional number representation**
- **Integer arithmetic**
- **Boundary conditions**
- **Time and space complexity**

> **Important:** This is a **problem-statement-only** file. It contains **no solution algorithm or solution code**.

---

## 📥 Input

The input contains a single binary number:

```text
B
```

`B` consists only of:

```text
0
1
```

The binary number represents a **non-negative integer**.

### Constraints

| Constraint            |        Value |
| --------------------- | -----------: |
| Minimum decimal value |          `0` |
| Maximum decimal value |   `2^31 - 1` |
| Maximum decimal value | `2147483647` |
| Minimum binary length |          `1` |
| Maximum binary length |         `31` |
| Allowed digits        |     `0`, `1` |
| Negative values       |  Not allowed |

Formally:

```text
0 <= DecimalValue(B) <= 2^31 - 1
```

---

## 📤 Output

Print the **decimal value** represented by the input binary number.

The output must:

- Be a single non-negative integer.
- Contain no unnecessary labels.
- Contain no intermediate calculations.
- Represent the same numerical value as the input.

For example:

```text
Input:
1101

Output:
13
```

---

# 🧪 Examples

## Example 1

**Input:**

```text
1101
```

**Output:**

```text
13
```

### Explanation

```text
1101₂

= 1 × 2^3
+ 1 × 2^2
+ 0 × 2^1
+ 1 × 2^0

= 8 + 4 + 0 + 1

= 13
```

---

## Example 2

**Input:**

```text
1010
```

**Output:**

```text
10
```

---

## Example 3

**Input:**

```text
11001
```

**Output:**

```text
25
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

## Example 5 — Single Bit

**Input:**

```text
1
```

**Output:**

```text
1
```

---

## Example 6 — Power of Two

**Input:**

```text
1000
```

**Output:**

```text
8
```

---

## Example 7 — All Ones

**Input:**

```text
11111
```

**Output:**

```text
31
```

---

## Example 8 — Maximum Value

**Input:**

```text
1111111111111111111111111111111
```

**Output:**

```text
2147483647
```

---

## 📊 Examples Summary

|   # |                      Binary Input | Decimal Output |
| --: | --------------------------------: | -------------: |
|   1 |                            `1101` |           `13` |
|   2 |                            `1010` |           `10` |
|   3 |                           `11001` |           `25` |
|   4 |                               `0` |            `0` |
|   5 |                               `1` |            `1` |
|   6 |                            `1000` |            `8` |
|   7 |                           `11111` |           `31` |
|   8 | `1111111111111111111111111111111` |   `2147483647` |

---

# 🔢 Understanding the Representation

Binary uses **base 2**.

Each position represents a power of `2`.

For:

```text
1101
```

the positions are:

```text
Position:     3    2    1    0
Binary:       1    1    0    1
Power:       2^3  2^2  2^1  2^0
```

Therefore:

```text
1101₂ = 1×2^3 + 1×2^2 + 0×2^1 + 1×2^0
      = 13
```

---

# 📋 Important Requirements

Your program should:

1. **Read one binary number.**
2. Treat the input as a **base-2 representation**.
3. Convert it to its corresponding decimal value.
4. Correctly handle `0`.
5. Correctly handle the maximum allowed value.
6. Print only the final decimal result.

---

# 🚫 Input Restrictions

Valid examples:

```text
0
1
101
1101
111111
```

Invalid examples for this problem:

```text
10201
```

because `2` is not a binary digit.

```text
-101
```

because negative values are not allowed.

```text
10.01
```

because this problem deals with integer binary values.

---

# ⏱️ Expected Complexity

Let:

```text
L = number of binary digits
```

Your solution should aim for:

### Time Complexity

```text
O(L)
```

Since the number of binary digits is logarithmic in the represented decimal value `N`, this can also be expressed as:

```text
O(log N)
```

### Auxiliary Space Complexity

Target:

```text
O(1)
```

for the conversion logic itself.

> **Note:** If the input is stored in a `string`, distinguish the memory used to store the **input** from the **auxiliary space** used by the conversion logic.

---

# 📊 Complexity Requirement

Your solution explanation should clearly state:

### Time

```text
O(L)
```

where `L` is the number of binary digits.

Equivalently:

```text
O(log N)
```

with respect to the represented decimal value.

### Auxiliary Space

```text
O(1)
```

for an iterative conversion approach using only constant extra variables.

---

# 🤔 What You Should Think About Before Coding

### Question 1

What are the place values of:

```text
2^0
2^1
2^2
2^3
...
```

?

### Question 2

In:

```text
1101
```

which digit corresponds to `2^0`?

### Question 3

How can you calculate the **decimal contribution** of each binary digit?

### Question 4

Can the binary digits be processed:

```text
left → right
```

?

### Question 5

Can they instead be processed:

```text
right → left
```

?

### Question 6

How can the current decimal value be updated when a new binary digit is encountered?

### Question 7

If the input contains `L` binary digits, how many operations are required?

Use this to derive the **time complexity**.

---

# 🧩 Edge Cases

Test your solution with:

```text
0
1
10
11
100
111
1000
11111
100000
101010
1111111111111111111111111111111
```

### Edge-Case Table

| Case              | Input                             | Expected Output |
| ----------------- | --------------------------------- | --------------: |
| Minimum           | `0`                               |             `0` |
| Smallest positive | `1`                               |             `1` |
| Two-bit value     | `10`                              |             `2` |
| All ones          | `111111`                          |            `63` |
| Power of two      | `100000`                          |            `32` |
| Alternating bits  | `101010`                          |            `42` |
| Maximum allowed   | `1111111111111111111111111111111` |    `2147483647` |

---

# ⚠️ Leading Zeroes

Leading zeroes in the **input** do not change its numerical value.

For example:

```text
00001101
```

represents the same value as:

```text
1101
```

Therefore:

```text
00001101₂ = 13₁₀
```

So the expected output is:

```text
13
```

> **Important:** The output is a decimal integer. Print it normally without unnecessary leading zeroes.

---

# 🚫 Output Format — Important

The problem does **not** ask you to print:

- Conversion steps
- Powers of `2`
- Intermediate values
- The input again
- Complexity
- Explanations
- Additional labels

For input:

```text
1101
```

### Correct

```text
13
```

### Not required

```text
Decimal Form: 13
```

unless explicitly requested.

---

# 🎯 Follow-Up Questions

## 1. Left-to-Right Processing

Can you process the binary digits from **left to right** while continuously constructing the decimal value?

---

## 2. Right-to-Left Processing

Can you process the digits from **right to left** using powers of `2`?

---

## 3. Bit Manipulation

If the input is available as an integer representation, can you use **bitwise operations** to work with individual bits?

---

## 4. Constant Auxiliary Space

Can you solve the conversion using only a constant number of variables apart from the input representation?

---

## 5. Recursive Approach

Can you formulate the conversion recursively?

---

## 6. Other Number Systems

Can you extend the idea to:

- **Binary → Octal**
- **Binary → Hexadecimal**
- **Binary → Any Base**

---

## 7. Reverse Problem

Can you solve:

```text
Decimal → Binary
```

?

---

# 💼 Interview Expectations

Be prepared to explain:

1. What **base-2 representation** means.
2. How **binary place values** are calculated.
3. How each binary digit contributes to the decimal value.
4. Why the conversion takes **`O(L)` time**.
5. Why `L` is related to **`log₂(N)`**.
6. How the input `0` is handled.
7. How leading zeroes affect the input.
8. What **auxiliary space** your approach requires.
9. How you handle the maximum allowed input.

---

# 📝 Solution Policy for This File

This file intentionally contains **only the problem statement and requirements**.

It does **not** contain:

- The final algorithm.
- Completed C++ solution code.
- Step-by-step implementation.
- Modulo/division solution.
- Bit-manipulation solution.

The purpose is to allow you to **solve the problem independently**.

---

# 📌 Problem Summary

| Category                    | Requirement       |
| --------------------------- | ----------------- |
| **Problem**                 | Binary → Decimal  |
| **Input**                   | One binary number |
| **Allowed digits**          | `0`, `1`          |
| **Minimum value**           | `0`               |
| **Maximum value**           | `2^31 - 1`        |
| **Maximum decimal value**   | `2147483647`      |
| **Maximum input length**    | `31` bits         |
| **Negative values**         | Not allowed       |
| **Output**                  | Decimal value     |
| **Target Time**             | `O(L)`            |
| **Equivalent Time**         | `O(log N)`        |
| **Target Auxiliary Space**  | `O(1)`            |
| **Solution code included?** | **No**            |

---

# 🔖 Quick Reference

```text
Problem:
    Binary → Decimal

Input:
    One binary number B

Allowed digits:
    0 and 1

Range:
    0 <= DecimalValue(B) <= 2^31 - 1

Maximum decimal value:
    2147483647

Maximum binary length:
    31 bits

Output:
    Decimal representation of B

Special case:
    0 → 0

Leading zeroes:
    Allowed in input; they do not change the value

Expected Time:
    O(L)

Where:
    L = number of binary digits

Equivalent Time:
    O(log N)

Expected Auxiliary Space:
    O(1)

Solution code:
    Not included
```

---

# 🏁 One-Line Problem Statement

> **Given a binary number `B` consisting only of `0` and `1`, where its represented decimal value satisfies `0 <= DecimalValue(B) <= 2^31 - 1`, print its corresponding decimal value. The expected time complexity is `O(L)` with preferably `O(1)` auxiliary space, where `L` is the number of binary digits.**

---

# END OF PROBLEM STATEMENT
