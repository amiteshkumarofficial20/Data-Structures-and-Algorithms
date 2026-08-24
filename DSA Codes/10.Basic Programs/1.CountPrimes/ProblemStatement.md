# Count Primes — Problem Statement

> **Difficulty:** Medium  
> **Topic:** Mathematics, Number Theory, Prime Numbers, Range Processing  
> **Platforms:** **LeetCode 204, GeeksforGeeks (GFG)**  
> **Language:** C++ / DSA

---

# 1. 📌 Problem Statement

Given a **non-negative integer `n`**, return the **number of prime numbers that are strictly less than `n`**.

A prime number is an integer greater than `1` that has exactly two positive divisors:

```text
1
```

and:

```text
itself
```

For example:

```text
2, 3, 5, 7
```

are prime numbers.

For:

```text
n = 10
```

the prime numbers strictly less than `10` are:

```text
2, 3, 5, 7
```

Therefore:

```text
Output = 4
```

The problem is intended to test your understanding of:

- **Prime Numbers**
- **Factors and Divisibility**
- **Prime Number Checking**
- **Range Processing**
- **Counting**
- **Boundary Conditions**
- **Strictly Less Than**
- **Time Complexity**
- **Space Complexity**
- **Integer Ranges**
- **Integer Overflow**

> **Important:** This file contains **only the problem statement and requirements**. It intentionally contains **no solution code, no algorithm, and no implementation approach**.

---

# 🌐 Platforms

This problem is available in related forms on:

- **LeetCode — 204. Count Primes**
- **GeeksforGeeks (GFG) — Prime Number**

> **Platform Note:** The exact input/output format, function signature, constraints, and expected approach can differ between the LeetCode and GFG versions. Always follow the exact statement provided by the particular platform.

---

# 2. 📥 Input

The input contains a single integer:

```text
n
```

`n` represents the **exclusive upper limit** below which prime numbers must be counted.

The relevant prime numbers satisfy:

```text
2 <= p < n
```

where `p` is a prime number.

---

# 3. 📤 Output

Return or print the **number of prime numbers strictly less than `n`**.

The output should contain a single integer representing the count.

For example:

```text
Input:
10

Output:
4
```

because:

```text
2, 3, 5, 7
```

are the four prime numbers strictly less than `10`.

Do not print:

- The list of prime numbers unless explicitly required.
- Intermediate calculations.
- Additional explanations.
- Unnecessary labels.
- The value `n` itself.

---

# 4. 📋 Constraints

For **LeetCode 204**, the given constraint is:

```text
0 <= n <= 5 * 10^6
```

### Constraint Table

| Constraint | Value |
|---|---:|
| Minimum `n` | `0` |
| Maximum `n` | `5 * 10^6` |
| `n` type | Non-negative integer |
| Negative `n` | Not allowed |
| Prime counting condition | `p < n` |
| Upper boundary | Exclusive |
| Number of input values | `1` |

> **Important:** The exact GFG Prime Number variation may have different constraints. Use the constraints specified by that particular GFG problem.

---

# 5. 🧪 Examples

## Example 1

**Input:**

```text
10
```

**Output:**

```text
4
```

### Explanation

The prime numbers strictly less than `10` are:

```text
2, 3, 5, 7
```

Therefore:

```text
Answer = 4
```

---

## Example 2

**Input:**

```text
0
```

**Output:**

```text
0
```

### Explanation

There are no prime numbers strictly less than `0`.

---

## Example 3

**Input:**

```text
1
```

**Output:**

```text
0
```

### Explanation

There are no prime numbers strictly less than `1`.

---

## Example 4

**Input:**

```text
2
```

**Output:**

```text
0
```

### Explanation

Although `2` is prime, it is not strictly less than `2`.

---

## Example 5

**Input:**

```text
3
```

**Output:**

```text
1
```

### Explanation

The only prime number strictly less than `3` is:

```text
2
```

---

## Example 6

**Input:**

```text
5
```

**Output:**

```text
2
```

### Explanation

The prime numbers strictly less than `5` are:

```text
2, 3
```

The number `5` itself is excluded.

---

## Example 7

**Input:**

```text
10
```

**Output:**

```text
4
```

---

## Example 8

**Input:**

```text
20
```

**Output:**

```text
8
```

### Explanation

The prime numbers strictly less than `20` are:

```text
2, 3, 5, 7, 11, 13, 17, 19
```

---

# 📊 Example Summary Table

| # | Input `n` | Prime Numbers Strictly Less Than `n` | Expected Output |
|---:|---:|---|---:|
| 1 | `0` | None | `0` |
| 2 | `1` | None | `0` |
| 3 | `2` | None | `0` |
| 4 | `3` | `2` | `1` |
| 5 | `4` | `2, 3` | `2` |
| 6 | `5` | `2, 3` | `2` |
| 7 | `10` | `2, 3, 5, 7` | `4` |
| 8 | `20` | `2, 3, 5, 7, 11, 13, 17, 19` | `8` |
| 9 | `30` | `2, 3, 5, 7, 11, 13, 17, 19, 23, 29` | `10` |

---

# 🔢 Prime Number Definition

A **prime number** is an integer greater than `1` that has exactly two positive divisors:

```text
1
```

and:

```text
itself
```

For example:

```text
5
```

has exactly two positive divisors:

```text
1, 5
```

Therefore:

```text
5 → Prime
```

But:

```text
6
```

has:

```text
1, 2, 3, 6
```

Therefore:

```text
6 → Not Prime
```

---

# ⭐ Important Prime Number Rules

## `0` Is Not Prime

```text
0 → Not Prime
```

---

## `1` Is Not Prime

```text
1 → Not Prime
```

`1` has only one positive divisor.

A prime number must have exactly two positive divisors.

---

## `2` Is Prime

```text
2 → Prime
```

Its positive divisors are:

```text
1, 2
```

---

## `2` Is the Only Even Prime

Every even number greater than `2` is not prime.

For example:

```text
4, 6, 8, 10, 12
```

are not prime.

> **Important:** `2` is the only even prime number.

---

# 📌 Understanding "Strictly Less Than `n`"

The problem uses:

```text
p < n
```

not:

```text
p <= n
```

Therefore, `n` itself is **never counted**.

For example:

```text
n = 7
```

The prime numbers counted are:

```text
2, 3, 5
```

Although:

```text
7
```

is prime, it is excluded.

> **Important:** If `n` itself is prime, it must still not be included in the answer.

---

# 🔢 Range and Indexing

The problem can be viewed as working over the half-open range:

```text
[0, n)
```

The right endpoint:

```text
n
```

is excluded.

The prime candidates satisfy:

```text
2 <= p < n
```

> **Important:** This problem is about a numeric range rather than array indexing. The important boundary condition is the **exclusive upper limit**.

---

# ⚠️ Important Notes

> **Note 1:** `0` is not prime.

> **Note 2:** `1` is not prime.

> **Note 3:** `2` is the smallest prime number.

> **Note 4:** `2` is the only even prime number.

> **Note 5:** The problem asks for primes **strictly less than `n`**.

> **Note 6:** If `n` is itself prime, `n` is not counted.

> **Note 7:** The LeetCode constraint is `0 <= n <= 5 * 10^6`.

> **Note 8:** A basic GFG Prime Number problem may ask whether a single number is prime instead of counting primes below a limit.

---

# 🧮 Mathematical Interpretation

The required answer is the number of integers `p` satisfying:

```text
2 <= p < n
```

and:

```text
p is prime
```

This count is associated with the mathematical **prime-counting function**.

The problem requires the count, not the list of primes, unless a particular platform variation explicitly asks for the list.

---

# ⏱️ Expected Complexity

The LeetCode constraint allows:

```text
n <= 5 * 10^6
```

Therefore, the solution must be efficient enough to process a potentially large range of integers.

A method that performs expensive independent prime checking for every candidate can become costly as `n` approaches the upper constraint.

### Complexity Expectations

The problem is expected to be approached with a method suitable for large range processing.

| Approach Category | Time Characteristic | Extra Space | Suitability |
|---|---|---|---|
| Independent trial division for every candidate | Relatively expensive | Low | Potentially costly |
| Individual primality checks up to square root | Better, but repeated | Low | May still be costly |
| Range-based prime processing | Efficient for the given range | Depends on representation | Well suited |
| Advanced prime-counting methods | Depends on method | Depends on method | Useful for much larger ranges |

> **Important:** This section describes the complexity expectations only. It intentionally does **not** reveal the solution algorithm.

---

# 💾 Integer Overflow Considerations

The input constraint:

```text
n <= 5 * 10^6
```

is small enough for common integer types.

However, intermediate arithmetic in number-theory calculations can still require attention.

For example, an expression involving:

```text
x * x
```

can overflow a narrow integer type for sufficiently large `x`.

Therefore:

- Consider the range of input values.
- Consider the range of intermediate calculations.
- Select an appropriate numeric type.
- Do not assume every arithmetic expression is automatically safe.

> **Important:** For the supplied LeetCode constraint, the primary concern is **algorithmic efficiency**, rather than storing `n`.

---

# 🧩 Edge Cases

## 1. Zero

```text
Input:
0

Output:
0
```

---

## 2. One

```text
Input:
1

Output:
0
```

---

## 3. Two

```text
Input:
2

Output:
0
```

Although `2` is prime, it is not strictly less than `2`.

---

## 4. Three

```text
Input:
3

Output:
1
```

The only prime below `3` is:

```text
2
```

---

## 5. Prime Upper Boundary

```text
Input:
7

Output:
3
```

The primes counted are:

```text
2, 3, 5
```

`7` is excluded.

---

## 6. Composite Upper Boundary

```text
Input:
10

Output:
4
```

The primes counted are:

```text
2, 3, 5, 7
```

---

## 7. Maximum LeetCode Constraint

```text
Input:
5 * 10^6
```

This tests whether the chosen solution satisfies the required performance expectations.

---

# 🚫 Output Format — Important

The required output is the **count of primes**, not the primes themselves.

For:

```text
Input:
10
```

### Correct Output

```text
4
```

### Not Required

```text
2 3 5 7
```

unless the specific problem variation explicitly asks for the list.

### Also Not Required

```text
Number of primes = 4
```

unless the platform explicitly requires that format.

---

# 🤔 What You Should Think About Before Coding

## Question 1

What is a prime number?

---

## Question 2

Why is:

```text
0
```

not prime?

---

## Question 3

Why is:

```text
1
```

not prime?

---

## Question 4

Why is:

```text
2
```

prime?

---

## Question 5

Why is `2` the only even prime?

---

## Question 6

What does:

```text
strictly less than n
```

mean?

---

## Question 7

If:

```text
n = 7
```

should `7` be counted?

---

## Question 8

What should the answer be when:

```text
n = 0
```

?

---

## Question 9

What should the answer be when:

```text
n = 1
```

?

---

## Question 10

What should the answer be when:

```text
n = 2
```

?

---

## Question 11

What is the maximum value of `n` in LeetCode 204?

---

## Question 12

Why does:

```text
5 * 10^6
```

make efficiency important?

---

## Question 13

How is checking one number for primality different from counting all primes below `n`?

---

## Question 14

What intermediate calculations could potentially overflow?

---

# 🔁 Follow-Up Questions

## 1. Single Prime Check

Given an integer `x`, determine whether `x` is prime.

How is this different from Count Primes?

---

## 2. Generate All Primes

Given `n`, output all prime numbers strictly less than `n`.

For example:

```text
n = 10

Output:
2 3 5 7
```

---

## 3. Count Primes in a Range

Given:

```text
L
R
```

count all prime numbers in the specified range.

---

## 4. Inclusive Upper Boundary

What changes if the problem asks for:

```text
p <= n
```

instead of:

```text
p < n
```

?

---

## 5. Multiple Queries

Suppose you are given multiple values:

```text
n1
n2
n3
...
nk
```

and must return the number of primes below each value.

How would you avoid repeating unnecessary work?

---

## 6. Very Large `n`

What changes if:

```text
n
```

is much larger than:

```text
5 * 10^6
```

?

---

## 7. Prime Counting Function

What mathematical function represents the number of primes below a given value?

---

## 8. Prime Gaps

Given two consecutive prime numbers, determine the difference between them.

---

## 9. Prime Factorization

Given an integer, determine its prime factors.

---

## 10. Modular Arithmetic

How would the problem change if the answer had to be returned modulo some integer `M`?

---

# 💼 Interview Expectations

If this problem is asked in an interview, be prepared to explain:

1. **What a prime number is.**
2. Why `0` is not prime.
3. Why `1` is not prime.
4. Why `2` is prime.
5. Why `2` is the only even prime.
6. What **strictly less than `n`** means.
7. Whether `n` itself is included.
8. How to check whether one number is prime.
9. Why counting primes is different from checking one number.
10. Why the constraint `n <= 5 * 10^6` matters.
11. The expected time complexity.
12. The expected space complexity.
13. Integer-overflow considerations.
14. How multiple queries change the requirements.
15. How the problem changes for much larger values of `n`.

---

# 📝 Problem Requirements Checklist

Your solution should:

1. **Read one integer `n`.**
2. Treat only numbers:
   ```text
   p < n
   ```
   as candidates.
3. Correctly identify prime numbers.
4. Exclude:
   ```text
   0
   ```
   and:
   ```text
   1
   ```
5. Include:
   ```text
   2
   ```
   when it is within the range.
6. Exclude `n` itself.
7. Return the total number of primes.
8. Respect:
   ```text
   0 <= n <= 5 * 10^6
   ```
   for the LeetCode version.
9. Use a suitable numeric type.
10. Meet the expected performance requirements.

---

# 🌐 Platform-Specific Notes

## LeetCode — 204. Count Primes

**Difficulty:**

```text
Medium
```

**Problem:**

```text
Given an integer n, return the number of prime numbers that are strictly less than n.
```

**Examples:**

```text
n = 10 -> 4
n = 0  -> 0
n = 1  -> 0
```

**Constraint:**

```text
0 <= n <= 5 * 10^6
```

The LeetCode version may provide a class/function template rather than standard console input/output.

---

## GeeksforGeeks — Prime Number

The related GFG version focuses on the basic concept of determining whether a number is prime.

The exact GFG problem may differ in:

- Input format
- Output format
- Constraints
- Function signature
- Whether one number or a range is involved

> **Important:** Follow the exact GFG problem statement when solving that version.

---

# 🧪 Suggested Test Cases

Your solution should be tested with:

### Minimum Values

```text
0
1
2
```

### Small Values

```text
3
4
5
10
```

### Prime Boundaries

```text
7
11
13
17
19
```

### Composite Boundaries

```text
4
6
8
9
10
12
```

### Larger Values

```text
100
1000
10000
```

### Maximum LeetCode Constraint

```text
5 * 10^6
```

---

# 📊 Expected Behavior Table

| Input Condition | Expected Behavior |
|---|---|
| `n = 0` | Return `0` |
| `n = 1` | Return `0` |
| `n = 2` | Return `0` |
| `n = 3` | Return `1` |
| `n` is prime | Do not count `n` |
| `n` is composite | Count primes below `n` |
| `n = 5 * 10^6` | Must satisfy performance expectations |

---

# 💼 Interview-Level Questions

Be able to answer these without writing code:

### Question 1

Why is `1` not a prime number?

### Question 2

Why is `2` prime even though it is even?

### Question 3

What is the difference between:

```text
p < n
```

and:

```text
p <= n
```

?

### Question 4

For:

```text
n = 10
```

why is the answer `4`?

### Question 5

For:

```text
n = 11
```

should `11` be counted?

### Question 6

Why is counting primes different from checking whether a single number is prime?

### Question 7

Why does the constraint:

```text
n <= 5 * 10^6
```

matter?

### Question 8

What changes if the problem asks for many different values of `n`?

### Question 9

What happens when `n` becomes extremely large?

### Question 10

What intermediate arithmetic should be considered for overflow?

---

# 📚 Concept Dependencies

A useful learning order is:

```text
Basic Arithmetic
       ↓
Factors and Multiples
       ↓
Divisibility
       ↓
Prime Numbers
       ↓
Prime Checking
       ↓
Count Primes
       ↓
Range Processing
       ↓
Complexity Analysis
```

The basic GFG Prime Number problem can be used as preparation for understanding LeetCode 204.

---

# 📌 Quick Reference

| Category | Requirement |
|---|---|
| **Problem** | Count Primes |
| **LeetCode** | **204. Count Primes** |
| **GFG** | Basic Prime Number |
| **Difficulty** | Medium on LeetCode |
| **Topic** | Mathematics, Number Theory, Prime Numbers |
| **Input** | Integer `n` |
| **Output** | Number of primes `< n` |
| **Smallest Prime** | `2` |
| **`0`** | Not prime |
| **`1`** | Not prime |
| **`2`** | Prime |
| **Boundary** | Strictly less than `n` |
| **LeetCode Constraint** | `0 <= n <= 5 * 10^6` |
| **Main Challenge** | Efficient range processing |
| **Overflow Concern** | Intermediate arithmetic |
| **Solution Code Included** | **No** |
| **Algorithm Included** | **No** |
| **Implementation Included** | **No** |

---

# 🏁 One-Line Problem Statement

> **Given a non-negative integer `n`, return the number of prime numbers that are strictly less than `n`, where a prime number is an integer greater than `1` with exactly two positive divisors; for LeetCode 204, `0 <= n <= 5 * 10^6`.**

---

# END OF PROBLEM STATEMENT
