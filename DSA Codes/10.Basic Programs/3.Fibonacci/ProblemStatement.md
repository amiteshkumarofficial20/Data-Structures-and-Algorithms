# Fibonacci Number — Problem Statement

> **Difficulty:** Easy  
> **Topic:** Mathematics, Recursion, Dynamic Programming, Iteration, Sequence  
> **Platforms:** **LeetCode, GeeksforGeeks (GFG)**  
> **Language:** C++ / DSA

---

# 1. 📌 Problem Statement

Given a non-negative integer `N`, find the **N-th Fibonacci number**.

The Fibonacci sequence is a sequence in which each number is obtained by adding the previous two numbers.

The sequence is defined as:

```text
F(0) = 0
F(1) = 1
```

For every integer:

```text
N >= 2
```

the Fibonacci number is defined as:

```text
F(N) = F(N - 1) + F(N - 2)
```

The beginning of the Fibonacci sequence is:

```text
Index:      0  1  2  3  4  5  6  7  8  9  10
            ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓
Value:      0  1  1  2  3  5  8 13 21 34  55
```

For example:

```text
F(5) = 5
```

because:

```text
F(5)
= F(4) + F(3)
= 3 + 2
= 5
```

> **Important:** This file contains **only the problem statement and requirements**. It intentionally contains **no solution code, no algorithm, and no implementation approach**.

---

# 🌐 Platforms

This problem is available in different forms on:

- **LeetCode**
- **GeeksforGeeks (GFG)**

> **Platform Note:** The exact function signature, input format, constraints, and expected output format can differ between platform versions. Always follow the exact constraints provided by the particular problem.

---

# 2. 📥 Input

The input contains a single **non-negative integer**:

```text
N
```

`N` represents the **zero-based position** of the Fibonacci sequence whose value must be found.

For example:

```text
N = 0
```

refers to:

```text
F(0) = 0
```

and:

```text
N = 1
```

refers to:

```text
F(1) = 1
```

---

# 3. 📤 Output

Print or return the **N-th Fibonacci number**.

The output should contain the Fibonacci value corresponding to the given index `N`.

For example:

```text
Input:
5

Output:
5
```

Do not print additional explanatory text unless the specific platform requires it.

---

# 4. 📋 Constraints

For the basic version of the problem, assume:

```text
0 <= N <= 30
```

unless the particular platform specifies a different range.

### Constraint Table

| Constraint | Requirement |
|---|---|
| `N` | Non-negative integer |
| Minimum `N` | `0` |
| Basic maximum `N` | `30` |
| Negative `N` | Not allowed |
| Fibonacci indexing | Zero-based |
| `F(0)` | `0` |
| `F(1)` | `1` |
| Recurrence for `N >= 2` | `F(N) = F(N-1) + F(N-2)` |

> **Important:** Fibonacci numbers grow rapidly. If a platform allows a much larger `N`, the required numeric data type and complexity expectations may be different.

---

# 5. 🧪 Examples

## Example 1

**Input:**

```text
0
```

**Output:**

```text
0
```

### Explanation

The first Fibonacci number using zero-based indexing is:

```text
F(0) = 0
```

---

## Example 2

**Input:**

```text
1
```

**Output:**

```text
1
```

### Explanation

By definition:

```text
F(1) = 1
```

---

## Example 3

**Input:**

```text
5
```

**Output:**

```text
5
```

### Explanation

The sequence begins:

```text
0, 1, 1, 2, 3, 5
```

Therefore:

```text
F(5) = 5
```

---

## Example 4

**Input:**

```text
7
```

**Output:**

```text
13
```

### Explanation

```text
F(7) = 13
```

because the sequence is:

```text
0, 1, 1, 2, 3, 5, 8, 13
```

---

## Example 5

**Input:**

```text
10
```

**Output:**

```text
55
```

---

## Example 6

**Input:**

```text
20
```

**Output:**

```text
6765
```

---

# 📊 Example Summary Table

| # | Input `N` | Expected Output `F(N)` |
|---:|---:|---:|
| 1 | `0` | `0` |
| 2 | `1` | `1` |
| 3 | `2` | `1` |
| 4 | `3` | `2` |
| 5 | `4` | `3` |
| 6 | `5` | `5` |
| 7 | `6` | `8` |
| 8 | `7` | `13` |
| 9 | `8` | `21` |
| 10 | `10` | `55` |
| 11 | `20` | `6765` |

---

# 🔢 Fibonacci Sequence

The first several Fibonacci numbers are:

```text
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
```

Their indices are:

```text
Index:  0  1  2  3  4  5  6   7   8   9   10  11   12   13   14
Value:  0  1  1  2  3  5  8  13  21  34   55  89  144  233  377
```

---

# 🧠 Fibonacci Definition

The Fibonacci sequence is mathematically defined by:

```text
F(0) = 0
F(1) = 1
```

and:

```text
F(N) = F(N - 1) + F(N - 2)
```

for:

```text
N >= 2
```

Therefore:

```text
F(2) = F(1) + F(0)
     = 1 + 0
     = 1
```

Then:

```text
F(3) = F(2) + F(1)
     = 1 + 1
     = 2
```

Then:

```text
F(4) = F(3) + F(2)
     = 2 + 1
     = 3
```

Then:

```text
F(5) = F(4) + F(3)
     = 3 + 2
     = 5
```

---

# ⭐ Important Base Values

There are two fundamental starting values:

```text
F(0) = 0
F(1) = 1
```

These values are important because every later Fibonacci number depends on earlier values.

> **Important:** Do not confuse the Fibonacci sequence with a one-based sequence. In this problem statement, the indexing is **zero-based**.

---

# ⚠️ Zero-Based Indexing

The Fibonacci sequence starts at index `0`:

```text
F(0) = 0
F(1) = 1
F(2) = 1
F(3) = 2
F(4) = 3
F(5) = 5
```

Therefore:

```text
N = 0
```

means the answer is:

```text
0
```

and:

```text
N = 1
```

means the answer is:

```text
1
```

> **Important:** A common mistake is to treat the first Fibonacci number as `F(1)`. This problem uses **zero-based indexing**, where `F(0) = 0`.

---

# ⏱️ Complexity Expectations

The expected complexity depends on the solution approach allowed by the specific problem.

For a basic iterative / dynamic-programming style solution, the commonly expected complexity is:

```text
Time:  O(N)
Space: O(1)
```

if only the previous two Fibonacci values are retained.

A recursive implementation without memoization has significantly worse time complexity because the same subproblems can be calculated repeatedly.

> **Important:** This section describes expected complexity characteristics only. It does **not** provide the algorithm or solution implementation.

---

# 📊 Complexity Comparison

| Approach Category | Expected Time | Expected Auxiliary Space |
|---|---:|---:|
| Simple recursion without memoization | Exponential | `O(N)` call stack |
| Iterative / constant-space approach | `O(N)` | `O(1)` |
| Memoized recursion | `O(N)` | `O(N)` |
| Full DP storage | `O(N)` | `O(N)` |
| Advanced logarithmic-time methods | Depends on method | Depends on implementation |

> **Note:** The exact expected approach depends on the constraints and the specific platform problem.

---

# 💾 Integer Overflow Considerations

Fibonacci numbers grow quickly.

Some values are:

```text
F(10) = 55

F(20) = 6765

F(30) = 832040

F(40) = 102334155

F(50) = 12586269025

F(60) = 1548008755920
```

Therefore, the allowed range of `N` must be considered together with the data type used to store the result.

For example, a standard 32-bit signed integer cannot store:

```text
F(47)
```

because the value exceeds the maximum signed 32-bit integer range.

A 64-bit integer can store Fibonacci values only up to a certain index as well.

For very large `N`, arbitrary-precision arithmetic may be required.

---

# 🧩 Edge Cases

Your solution should be tested against the following cases.

## 1. Minimum Input

```text
Input:
0

Output:
0
```

---

## 2. Second Base Value

```text
Input:
1

Output:
1
```

---

## 3. First Repeated Fibonacci Value

```text
Input:
2

Output:
1
```

Notice that:

```text
F(1) = 1
F(2) = 1
```

Both values are equal.

---

## 4. Small Input

```text
Input:
5

Output:
5
```

---

## 5. Moderate Input

```text
Input:
10

Output:
55
```

---

## 6. Larger Valid Input

```text
Input:
20

Output:
6765
```

---

## 7. Boundary Input

For a constraint such as:

```text
0 <= N <= 30
```

test:

```text
Input:
30

Output:
832040
```

---

## 8. Negative Input

If:

```text
N < 0
```

the input violates the stated constraints.

A standard Fibonacci problem does not require handling negative indices unless the problem explicitly defines them.

---

# 🚫 Input / Output Formatting

The exact formatting depends on the platform.

For a standard standalone-input problem:

### Input

```text
N
```

### Output

```text
F(N)
```

For example:

```text
Input:
8

Output:
21
```

Do not add:

```text
Fibonacci Number:
```

or:

```text
Answer:
```

unless explicitly required by the platform.

---

# 📌 Important Notes

> **Note 1:** Fibonacci indexing in this problem is **zero-based**.

> **Note 2:** The two base values are **`F(0) = 0`** and **`F(1) = 1`**.

> **Note 3:** For `N >= 2`, each Fibonacci number depends on the previous two numbers.

> **Note 4:** Fibonacci values grow rapidly, so **integer overflow** must be considered.

> **Note 5:** The exact constraints may differ between **LeetCode** and **GeeksforGeeks** versions of the problem.

> **Note 6:** This document intentionally contains **no solution code and no algorithm**.

---

# 🤔 Questions to Think About Before Coding

1. What are the two base values of the Fibonacci sequence?

2. Why is the indexing zero-based?

3. What is the relationship between `F(N)`, `F(N-1)`, and `F(N-2)`?

4. What should the answer be when `N = 0`?

5. What should the answer be when `N = 1`?

6. Why does a simple recursive implementation repeat work?

7. What is the time complexity of the naive recursive approach?

8. How can repeated Fibonacci subproblems affect performance?

9. What happens to Fibonacci values as `N` increases?

10. When does integer overflow become a concern?

11. What data type is appropriate for the given constraints?

12. How would the complexity change if all previously calculated Fibonacci values were stored?

---

# 🔁 Follow-Up Questions

After solving the basic problem, consider these variations.

## 1. Recursive Fibonacci

Can you solve the problem using recursion?

What would be the:

```text
Time Complexity?
Space Complexity?
```

?

---

## 2. Memoization

Can you avoid calculating the same Fibonacci value repeatedly?

How does memoization affect:

```text
Time Complexity?
Space Complexity?
```

?

---

## 3. Dynamic Programming

Can you calculate the sequence while storing previously computed values?

What is the resulting:

```text
Time Complexity?
Space Complexity?
```

?

---

## 4. Constant-Space Optimization

Can you calculate `F(N)` while keeping only the information required for the next Fibonacci value?

---

## 5. Very Large `N`

How would you calculate Fibonacci numbers when:

```text
N
```

is extremely large?

Would an `O(N)` approach still be practical?

---

## 6. Fibonacci Modulo

How would the problem change if the question asked for:

```text
F(N) % M
```

instead of the complete Fibonacci number?

---

## 7. Multiple Test Cases

Suppose the input contains multiple values of `N`.

How would you handle all queries efficiently?

---

## 8. Fibonacci Sequence

Instead of finding only `F(N)`, how would you generate the first `N` Fibonacci numbers?

---

## 9. Negative Fibonacci Numbers

What would change if the problem allowed negative indices?

This is sometimes discussed using the concept of **Negafibonacci numbers**.

---

# 💼 Interview Expectations

If this problem is asked in an interview, be prepared to explain:

1. **What the Fibonacci sequence is.**
2. The meaning of:
   ```text
   F(0)
   ```
3. The meaning of:
   ```text
   F(1)
   ```
4. The recurrence:
   ```text
   F(N) = F(N-1) + F(N-2)
   ```
5. Why the first two values are special.
6. Why a naive recursive solution can be inefficient.
7. How repeated subproblems arise.
8. The difference between:
   - Recursion
   - Memoization
   - Dynamic Programming
   - Iteration
9. Time complexity of different approaches.
10. Space complexity of different approaches.
11. Integer overflow considerations.
12. How the solution should change for very large `N`.

---

# 🧠 Important Mathematical Observation

The Fibonacci sequence follows:

```text
F(N) = F(N - 1) + F(N - 2)
```

This means every term after the first two is determined entirely by the previous two terms.

For example:

```text
F(2) = F(1) + F(0)
     = 1 + 0
     = 1

F(3) = F(2) + F(1)
     = 1 + 1
     = 2

F(4) = F(3) + F(2)
     = 2 + 1
     = 3

F(5) = F(4) + F(3)
     = 3 + 2
     = 5
```

> **Important:** This section describes the mathematical definition only. It does **not** provide an implementation algorithm.

---

# 📝 Problem Requirements Checklist

Before considering your solution complete, verify that it:

- [ ] Accepts a non-negative integer `N`.
- [ ] Uses zero-based Fibonacci indexing.
- [ ] Correctly handles `N = 0`.
- [ ] Correctly handles `N = 1`.
- [ ] Produces the correct `F(N)`.
- [ ] Respects the specified constraints.
- [ ] Uses a suitable numeric data type.
- [ ] Does not overflow for the allowed input range.
- [ ] Matches the platform's required input format.
- [ ] Matches the platform's required output format.
- [ ] Meets the expected complexity requirements.

---

# 🌐 Platform Reference

## LeetCode

The problem is available on **LeetCode** as a Fibonacci-number problem.

The platform may provide a function-based interface rather than requiring complete input/output handling.

> Always follow the exact function signature and constraints shown in the current platform version.

---

## GeeksforGeeks (GFG)

The Fibonacci problem is also available in multiple forms on **GeeksforGeeks**.

Different versions may ask for:

- The N-th Fibonacci number.
- Fibonacci sequence generation.
- Recursive Fibonacci.
- Iterative Fibonacci.
- Fibonacci using dynamic programming.
- Fibonacci under modulo constraints.

> Always follow the exact problem statement and constraints of the particular GFG version.

---

# 📋 Quick Reference

| Category | Requirement |
|---|---|
| **Problem** | N-th Fibonacci Number |
| **Platforms** | LeetCode, GeeksforGeeks (GFG) |
| **Input** | Non-negative integer `N` |
| **Indexing** | Zero-based |
| **Base Value 1** | `F(0) = 0` |
| **Base Value 2** | `F(1) = 1` |
| **Recurrence** | `F(N) = F(N-1) + F(N-2)` |
| **Basic Example** | `F(5) = 5` |
| **Basic Constraint** | `0 <= N <= 30` |
| **Iterative Expected Time** | `O(N)` |
| **Iterative Expected Space** | `O(1)` |
| **Naive Recursive Time** | Exponential |
| **Memoized Time** | `O(N)` |
| **Full DP Space** | `O(N)` |
| **Large N** | May require advanced methods / big integers |
| **Solution Code Included** | **No** |
| **Algorithm Included** | **No** |

---

# 🏁 One-Line Problem Statement

> **Given a non-negative integer `N`, find the N-th Fibonacci number using zero-based indexing, where `F(0) = 0`, `F(1) = 1`, and `F(N) = F(N-1) + F(N-2)` for `N >= 2`.**

---

# 📌 Final Problem Statement Summary

The task is to determine the Fibonacci number at position `N`.

The sequence begins with:

```text
0, 1
```

and every subsequent value is the sum of the previous two values:

```text
0, 1, 1, 2, 3, 5, 8, 13, ...
```

For a given:

```text
N
```

return:

```text
F(N)
```

while respecting the specified input constraints, output requirements, numeric limits, and expected complexity.

> **Final Reminder:** This document is intentionally a **problem-statement-only file**. It contains **no solution code, no algorithm, and no implementation steps**.

---

# END OF PROBLEM STATEMENT
