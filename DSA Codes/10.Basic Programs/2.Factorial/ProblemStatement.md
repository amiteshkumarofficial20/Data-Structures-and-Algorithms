# Factorial of a Number — Problem Statement

> **Difficulty:** Easy  
> **Topic:** Mathematics, Recursion, Iteration, Number Theory  
> **Language:** C++ / DSA  
> **Platforms:** GeeksforGeeks (GFG), Naukri (Code360), HackerEarth, CodeChef

---

## 📌 Problem Statement

Given a **non-negative integer `N`**, find the **factorial of `N`**.

The factorial of a non-negative integer `N`, denoted by:

```text
N!
```

is the product of all positive integers from `1` to `N`.

Mathematically:

```text
N! = N × (N - 1) × (N - 2) × ... × 2 × 1
```

For example:

```text
5! = 5 × 4 × 3 × 2 × 1
   = 120
```

The problem is intended to test your understanding of:

- **Factorial**
- **Multiplication**
- **Loops / Iteration**
- **Recursion**
- **Base cases**
- **Boundary conditions**
- **Integer ranges**
- **Overflow**
- **Time complexity**
- **Space complexity**

> **Important:** This file contains **only the problem statement and requirements**. It intentionally does **not** contain the solution algorithm or solution code.

---

# 🌐 Platforms

This problem is commonly suitable for practice on:

- **GeeksforGeeks (GFG)**
- **Naukri (Code360)**
- **HackerEarth**
- **CodeChef**

> **Platform Note:** The exact input/output format and constraints can vary between platforms. Always follow the constraints and format given by the specific problem version.

---

# 📥 Input

The input contains a single non-negative integer:

```text
N
```

where:

```text
N >= 0
```

`N` represents the number whose factorial must be calculated.

---

## 📋 Input Constraints

For a basic integer-factorial problem, assume:

```text
0 <= N <= 20
```

when the result is expected to fit within a standard **64-bit signed integer (`long long`)**.

The reason for this upper bound is that:

```text
20! = 2432902008176640000
```

which fits within the range of a signed 64-bit integer, while:

```text
21!
```

is larger than the maximum value of a signed 64-bit integer.

### Constraint Table

| Constraint                         |                Value |
| ---------------------------------- | -------------------: |
| Minimum `N`                        |                  `0` |
| Maximum `N` for `long long` result |                 `20` |
| `N` type                           | Non-negative integer |
| Negative `N`                       |          Not allowed |
| Result type for `0 <= N <= 20`     |          `long long` |
| Number of test cases               |                  `1` |

> **Important:** If a platform gives a different range, use the platform's stated constraint. For very large `N`, the factorial may require **arbitrary-precision / big-integer arithmetic**.

---

# 📤 Output

Print the factorial of `N`.

The output should be a single integer:

```text
N!
```

Do not print:

- Intermediate multiplication steps.
- Additional explanations.
- Unnecessary labels.
- The factorial notation itself.

For example, for:

```text
N = 5
```

the required output is:

```text
120
```

not:

```text
5! = 120
```

unless the platform explicitly asks for that format.

---

# 🧪 Examples

## Example 1

**Input:**

```text
5
```

**Output:**

```text
120
```

### Explanation

```text
5! = 5 × 4 × 3 × 2 × 1
   = 120
```

---

## Example 2

**Input:**

```text
0
```

**Output:**

```text
1
```

### Explanation

By definition:

```text
0! = 1
```

This is an important special case.

---

## Example 3

**Input:**

```text
1
```

**Output:**

```text
1
```

---

## Example 4

**Input:**

```text
3
```

**Output:**

```text
6
```

### Explanation

```text
3! = 3 × 2 × 1
   = 6
```

---

## Example 5

**Input:**

```text
10
```

**Output:**

```text
3628800
```

---

## Example 6

**Input:**

```text
20
```

**Output:**

```text
2432902008176640000
```

---

# 📊 Examples Summary

|   # | Input `N` |  Expected Output `N!` |
| --: | --------: | --------------------: |
|   1 |       `0` |                   `1` |
|   2 |       `1` |                   `1` |
|   3 |       `2` |                   `2` |
|   4 |       `3` |                   `6` |
|   5 |       `4` |                  `24` |
|   6 |       `5` |                 `120` |
|   7 |      `10` |             `3628800` |
|   8 |      `15` |       `1307674368000` |
|   9 |      `20` | `2432902008176640000` |

---

# 🔢 Understanding Factorial

The factorial of `N` is defined as:

```text
N! = N × (N - 1) × (N - 2) × ... × 2 × 1
```

For example:

```text
4! = 4 × 3 × 2 × 1
   = 24
```

Similarly:

```text
6! = 6 × 5 × 4 × 3 × 2 × 1
   = 720
```

---

# ⭐ Special Case: `0!`

One of the most important rules in this problem is:

```text
0! = 1
```

This is a mathematical definition and must be handled correctly.

Therefore:

```text
Input:
0

Output:
1
```

> **Important:** Do not assume that the factorial of `0` is `0`. The correct value is **`1`**.

---

# 📋 Important Requirements

Your program should:

1. **Read one non-negative integer `N`.**
2. Calculate the factorial of `N`.
3. Correctly handle:
   ```text
   N = 0
   ```
4. Correctly handle:
   ```text
   N = 1
   ```
5. Produce the exact factorial value.
6. Use a numeric type capable of storing the result for the given constraint.
7. Avoid printing unnecessary text.

---

# ⚠️ Overflow Considerations

Factorial values grow **extremely quickly**.

For example:

```text
10! = 3628800
```

but:

```text
20! = 2432902008176640000
```

and:

```text
21! = 51090942171709440000
```

The value of `21!` does **not** fit inside a signed 64-bit `long long`.

Therefore, always check the platform's constraints before selecting the data type.

### Important

For:

```text
0 <= N <= 20
```

a signed 64-bit integer can store the result.

For larger values of `N`, you may need:

```text
Big Integer
Arbitrary Precision Integer
```

or another representation capable of storing very large numbers.

---

# ⏱️ Expected Complexity

Let:

```text
N = input number
```

The factorial involves multiplication for each integer from `1` through `N`.

Therefore, a straightforward factorial computation performs approximately `N` multiplication operations.

### Expected Time Complexity

```text
O(N)
```

### Expected Auxiliary Space

For an iterative approach:

```text
O(1)
```

For a recursive approach, the recursion depth is proportional to `N`, so the call-stack space would be:

```text
O(N)
```

> **Note:** The complexity of storing the factorial result itself can be larger when `N` is large because the number of digits in `N!` grows rapidly. For the basic `long long` constraint, the result fits in a fixed-size integer.

---

# 📊 Complexity Requirement

Your solution explanation should clearly state:

### Iterative Approach

```text
Time:  O(N)
Space: O(1)
```

### Recursive Approach

```text
Time:  O(N)
Space: O(N)
```

The exact space analysis may differ if a platform uses a big-integer representation for very large factorials.

---

# 🤔 What You Should Think About Before Coding

Before implementing the solution, think about the following questions.

### Question 1

What is the mathematical definition of:

```text
N!
```

?

---

### Question 2

What should the answer be when:

```text
N = 0
```

?

---

### Question 3

What should the initial value of the factorial result be?

Think about why multiplication should start from a particular identity value.

---

### Question 4

How many multiplication operations are required to calculate:

```text
N!
```

?

---

### Question 5

Can the factorial be calculated using:

```text
Iteration
```

?

---

### Question 6

Can the factorial be calculated using:

```text
Recursion
```

?

---

### Question 7

If recursion is used, what should the **base case** be?

---

### Question 8

What happens when `N` becomes large?

Think about:

```text
Integer Overflow
```

---

### Question 9

Which data type is sufficient for the given constraints?

For example:

```text
int
long long
Big Integer
```

---

### Question 10

What is the time complexity of multiplying all numbers from:

```text
1 to N
```

?

---

# 🧩 Edge Cases

Your solution should be tested with the following values.

## 1. Zero

```text
Input:
0

Output:
1
```

---

## 2. One

```text
Input:
1

Output:
1
```

---

## 3. Small Number

```text
Input:
3

Output:
6
```

---

## 4. Number With a Simple Factorial

```text
Input:
5

Output:
120
```

---

## 5. Larger Valid `long long` Input

```text
Input:
20

Output:
2432902008176640000
```

---

## 6. Boundary Beyond `long long`

```text
Input:
21
```

For the stated basic constraint:

```text
0 <= N <= 20
```

this input is outside the allowed range.

If a platform allows `N = 21` or larger, the required numeric representation must be reconsidered because `21!` does not fit in a signed 64-bit integer.

---

# 🚫 Output Format — Important

The problem asks for **only the factorial value**.

For:

```text
Input:
5
```

### Correct

```text
120
```

### Not Required

```text
5! = 120
```

### Also Not Required

```text
Factorial is: 120
```

unless the specific platform explicitly asks for labels.

---

# 🎯 Follow-Up Questions

After solving the basic problem, try these variations.

## 1. Iterative Version

Can you calculate the factorial using a loop?

---

## 2. Recursive Version

Can you calculate the factorial recursively?

---

## 3. Big Factorial

How would you calculate:

```text
100!
```

?

What data type would be required?

---

## 4. Very Large Factorial

How would you calculate:

```text
1000!
```

?

Would `int` or `long long` be sufficient?

---

## 5. Count Digits

Can you determine the **number of digits in `N!`** without explicitly printing the complete factorial?

---

## 6. Trailing Zeroes

Can you determine how many **trailing zeroes** are present in:

```text
N!
```

?

For example:

```text
10! = 3628800
```

contains:

```text
2
```

trailing zeroes.

---

## 7. Factorial Modulo

Can you calculate:

```text
N! % M
```

for very large `N`?

---

## 8. Factorial Using Big Integers

Can you calculate factorial values that are far beyond the range of:

```text
long long
```

?

---

## 9. Multiple Test Cases

Modify the problem so that the input contains multiple values of `N` and calculate the factorial for each one.

---

# 💼 Interview Expectations

If this problem is asked in an interview, be prepared to explain:

1. **What factorial means.**
2. Why:
   ```text
   0! = 1
   ```
3. The difference between **iteration and recursion**.
4. The appropriate **base case** for recursion.
5. The **time complexity**.
6. The **space complexity**.
7. Why factorial values cause **integer overflow**.
8. Which data type is appropriate for the given constraints.
9. How the solution would change for **very large factorials**.
10. How you would handle multiple test cases.

---

# 🧠 Important Mathematical Observation

Factorial can be represented recursively as:

```text
N! = N × (N - 1)!
```

with the mathematical base case:

```text
0! = 1
```

For example:

```text
5!
= 5 × 4!
= 5 × 4 × 3!
= 5 × 4 × 3 × 2!
= 5 × 4 × 3 × 2 × 1!
= 120
```

> **Important:** This section describes the mathematical definition only. It does **not** provide the implementation or solution algorithm.

---

# 📝 Solution Policy for This File

This file intentionally contains **only the problem statement and requirements**.

It does **not** contain:

- The final algorithm.
- Completed C++ solution code.
- Iterative solution code.
- Recursive solution code.
- Big-integer implementation.
- A step-by-step coding solution.

The purpose is to allow you to **solve the problem independently**.

---

# 📌 Problem Summary

| Category                               | Requirement                  |
| -------------------------------------- | ---------------------------- |
| **Problem**                            | Factorial of a Number        |
| **Input**                              | One non-negative integer `N` |
| **Minimum `N`**                        | `0`                          |
| **Maximum `N` for `long long` result** | `20`                         |
| **Special case**                       | `0! = 1`                     |
| **Output**                             | `N!`                         |
| **Negative values**                    | Not allowed                  |
| **Iterative Time**                     | `O(N)`                       |
| **Iterative Auxiliary Space**          | `O(1)`                       |
| **Recursive Time**                     | `O(N)`                       |
| **Recursive Auxiliary Space**          | `O(N)`                       |
| **Large factorials**                   | Require arbitrary precision  |
| **Solution code included?**            | **No**                       |

---

# 🔖 Quick Reference

```text
Problem:
    Factorial of a Number

Input:
    One non-negative integer N

Range:
    0 <= N <= 20
    (for a signed 64-bit result)

Output:
    N!

Special case:
    0! = 1

Example:
    5! = 120

Maximum long long factorial:
    20! = 2432902008176640000

21!:
    Does not fit in signed long long

Expected Iterative Time:
    O(N)

Expected Iterative Space:
    O(1)

Recursive Time:
    O(N)

Recursive Space:
    O(N)

Large N:
    Requires arbitrary-precision arithmetic

Solution code:
    Not included
```

---

# 🏁 One-Line Problem Statement

> **Given a non-negative integer `N`, calculate and print its factorial `N!`, where `N! = N × (N - 1) × ... × 2 × 1`, with the special case `0! = 1`; for the basic 64-bit version, assume `0 <= N <= 20`, with an expected iterative time complexity of `O(N)` and `O(1)` auxiliary space.**

---

# END OF PROBLEM STATEMENT
