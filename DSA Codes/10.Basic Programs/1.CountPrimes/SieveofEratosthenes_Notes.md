# Sieve of Eratosthenes --- Complete Detailed Notes

> **Topic:** Sieve of Eratosthenes\
> **Purpose:** Find all prime numbers up to a given limit\
> **Language:** C++17\
> **Time Complexity:** O(N log log N)\
> **Space Complexity:** O(N)

------------------------------------------------------------------------

# 1. Introduction

The **Sieve of Eratosthenes** is a classic algorithm for finding all
prime numbers up to a given limit `N`.

It is useful when we need:

-   All prime numbers up to `N`
-   All prime numbers less than `N`
-   Number of primes in a range
-   Prime/non-prime status of many numbers
-   Answers to multiple prime-related queries

The main idea is **precomputation**:

> Initially assume numbers are prime, then mark numbers that are
> definitely composite.

At the end:

``` text
1 → Prime
0 → Not Prime / Composite
```

------------------------------------------------------------------------

# 2. What Is a Prime Number?

A prime number is an integer greater than `1` having exactly two
positive divisors:

``` text
1
itself
```

Examples:

``` text
2 3 5 7 11 13 17 19 23 29
```

For example:

``` text
5 → divisors are 1 and 5 → Prime

6 → divisors are 1, 2, 3, 6 → Not Prime
```

Important:

``` text
0 → Not Prime
1 → Not Prime
```

The first prime number is `2`.

------------------------------------------------------------------------

# 3. What Is the Sieve of Eratosthenes?

The Sieve finds primes by repeatedly marking multiples of known prime
numbers as composite.

Suppose:

``` text
N = 30
```

Start by assuming every number is prime.

Then start from `2`.

Since `2` is prime, its multiples greater than itself are composite:

``` text
4 6 8 10 12 14 16 18 20 22 24 26 28 30
```

Then process `3`:

``` text
9 12 15 18 21 24 27 30
```

Numbers such as `4` are skipped because `4` was already marked composite
by `2`.

At the end, the numbers still marked prime are:

``` text
2 3 5 7 11 13 17 19 23 29
```

------------------------------------------------------------------------

# 4. Why Do We Need Sieve?

Suppose:

``` text
N = 1,000,000
```

With brute force, we can check every number independently.

That causes repeated work.

For example, once we know `2` is prime, we already know:

``` text
4, 6, 8, 10, 12, ...
```

are composite.

Once we know `3` is prime, we know:

``` text
6, 9, 12, 15, ...
```

are composite.

The Sieve uses this information directly instead of checking every
number independently.

This makes it much faster for finding primes across a range.

------------------------------------------------------------------------

# 5. Basic Idea

Suppose:

``` text
N = 30
```

Create:

``` cpp
vector<int> prime(n + 1, 1);
```

The index represents the number:

``` text
prime[0]
prime[1]
prime[2]
...
prime[30]
```

Initially every value is `1`.

This means:

``` text
"Assume every number is prime."
```

Then correct the known exceptions:

``` cpp
prime[0] = 0;
prime[1] = 0;
```

Now start eliminating composite numbers.

------------------------------------------------------------------------

# 6. Prime Array

We use:

``` text
prime[i] = 1
```

to represent:

``` text
i is prime
```

and:

``` text
prime[i] = 0
```

to represent:

``` text
i is not prime
```

Example:

``` text
prime[2] = 1
prime[3] = 1
prime[4] = 0
prime[5] = 1
prime[6] = 0
```

Therefore:

``` text
2 → Prime
3 → Prime
4 → Not Prime
5 → Prime
6 → Not Prime
```

------------------------------------------------------------------------

# 7. Initialisation

``` cpp
vector<int> prime(n + 1, 1);
```

Why `n + 1`?

Because we want indexes:

``` text
0 through n
```

For:

``` text
n = 10
```

we need:

``` text
0 1 2 3 4 5 6 7 8 9 10
```

which requires 11 positions.

------------------------------------------------------------------------

# 8. Why 0 and 1 Are Not Prime

Prime numbers must be greater than `1`.

Therefore:

``` cpp
prime[0] = 0;
prime[1] = 0;
```

The first possible prime is:

``` text
2
```

------------------------------------------------------------------------

# 9. Starting From 2

We start with:

``` text
i = 2
```

because `2` is the smallest prime.

If:

``` cpp
prime[2] == 1
```

then we know `2` is prime.

Now mark its multiples.

------------------------------------------------------------------------

# 10. Marking Multiples of 2

Multiples of 2 are:

``` text
2
4
6
8
10
12
14
...
```

We do not mark `2` because it is prime.

We mark:

``` text
4
6
8
10
12
...
```

as composite.

The basic marking loop is:

``` cpp
for (int j = 2 * i; j <= n; j += i)
{
    prime[j] = 0;
}
```

For:

``` text
i = 2
```

we get:

``` text
j = 4
j = 6
j = 8
j = 10
...
```

------------------------------------------------------------------------

# 11. Marking Multiples of 3

Next:

``` text
i = 3
```

Since:

``` text
prime[3] = 1
```

3 is prime.

Its multiples are:

``` text
6
9
12
15
18
21
24
27
30
```

They are composite.

Some were already marked by 2. That is okay.

------------------------------------------------------------------------

# 12. Why Composite Numbers Are Skipped

Consider:

``` text
i = 4
```

4 is composite:

``` text
4 = 2 × 2
```

When we processed `2`, we already marked:

``` text
prime[4] = 0
```

Therefore:

``` cpp
if (prime[i] == 1)
```

is false.

So we skip 4.

This is important:

> We only process values that are still marked as prime.

Composite numbers have already been handled by smaller factors.

------------------------------------------------------------------------

# 13. Basic Sieve: Start From 2\*i

A straightforward version is:

``` cpp
for (int i = 2; i <= n; i++)
{
    if (prime[i] == 1)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
}
```

This works, but performs repeated marking.

We can optimize it.

------------------------------------------------------------------------

# 14. Optimization: Start From i\*i

Instead of:

``` cpp
j = 2 * i;
```

we use:

``` cpp
j = i * i;
```

So:

``` cpp
for (int j = i * i; j <= n; j += i)
{
    prime[j] = 0;
}
```

This avoids marking numbers that were already handled by smaller
factors.

------------------------------------------------------------------------

# 15. Why Is i\*i the Starting Point?

Suppose:

``` text
i = 5
```

Multiples of 5 are:

``` text
5
10
15
20
25
30
35
...
```

We do not mark 5 because 5 itself is prime.

Now:

``` text
10 = 2 × 5
```

10 was already handled when processing 2.

``` text
15 = 3 × 5
```

15 was already handled when processing 3.

``` text
20 = 4 × 5
```

20 was already handled by smaller factors.

The first multiple that has not already been handled by a smaller factor
is:

``` text
25 = 5 × 5
```

Therefore we start from:

``` text
5 × 5
```

In general:

``` text
i × i
```

------------------------------------------------------------------------

# 16. Why Does the Outer Loop Stop at sqrt(N)?

We use:

``` cpp
for (int i = 2; i * i <= n; i++)
```

which is equivalent to:

``` text
i <= sqrt(n)
```

Why is this enough?

Suppose a composite number is:

``` text
N = a × b
```

At least one of `a` and `b` must be less than or equal to:

``` text
sqrt(N)
```

Otherwise, if both were greater than `sqrt(N)`:

``` text
a > sqrt(N)
b > sqrt(N)
```

then:

``` text
a × b > sqrt(N) × sqrt(N)
```

so:

``` text
a × b > N
```

which contradicts:

``` text
a × b = N
```

Therefore every composite number has a factor `<= sqrt(N)`.

That is why we do not need to process larger factors.

------------------------------------------------------------------------

# 17. Why Is the Condition i\*i \<= N?

The correct inclusive condition is:

``` cpp
i * i <= n
```

not:

``` cpp
i * i < n
```

Example:

``` text
n = 25
```

Then:

``` text
sqrt(25) = 5
```

and:

``` text
5 * 5 = 25
```

We must still process `5`, because it marks:

``` text
25 = 5 × 5
```

If we used:

``` cpp
i * i < n
```

then:

``` text
25 < 25
```

would be false.

So 5 would be skipped.

For an inclusive sieve `[0, n]`:

``` cpp
i * i <= n
```

is correct.

------------------------------------------------------------------------

# 18. Complete Example: N = 30

We want all primes up to:

``` text
30
```

Create:

``` cpp
vector<int> prime(31, 1);
```

Then:

``` cpp
prime[0] = 0;
prime[1] = 0;
```

Now process the array.

------------------------------------------------------------------------

## Step 1 --- i = 2

Check:

``` text
2 * 2 <= 30
4 <= 30
true
```

2 is prime.

Start from:

``` text
j = 2 * 2 = 4
```

Mark:

``` text
4
6
8
10
12
14
16
18
20
22
24
26
28
30
```

as 0.

------------------------------------------------------------------------

## Step 2 --- i = 3

Check:

``` text
3 * 3 <= 30
9 <= 30
true
```

3 is prime.

Start from:

``` text
j = 9
```

Mark:

``` text
9
12
15
18
21
24
27
30
```

as 0.

------------------------------------------------------------------------

## Step 3 --- i = 4

We already have:

``` text
prime[4] = 0
```

So:

``` text
4 is composite
```

and we skip it.

------------------------------------------------------------------------

## Step 4 --- i = 5

Check:

``` text
5 * 5 <= 30
25 <= 30
true
```

5 is prime.

Start from:

``` text
j = 25
```

Mark:

``` text
25
30
```

as 0.

------------------------------------------------------------------------

## Step 5 --- i = 6

Check:

``` text
6 * 6 <= 30
36 <= 30
false
```

The loop stops.

We do not need to process larger factors.

------------------------------------------------------------------------

# 19. Step-by-Step Dry Run

For:

``` text
n = 30
```

the important operations are:

``` text
i = 2
    j = 4
    mark multiples of 2

i = 3
    j = 9
    mark multiples of 3

i = 4
    prime[4] = 0
    skip

i = 5
    j = 25
    mark multiples of 5

i = 6
    36 > 30
    stop
```

Remaining primes:

``` text
2 3 5 7 11 13 17 19 23 29
```

------------------------------------------------------------------------

# 20. Final Prime Array

For `N = 30`:

``` text
Number    prime[number]

0         0
1         0
2         1
3         1
4         0
5         1
6         0
7         1
8         0
9         0
10        0
11        1
12        0
13        1
14        0
15        0
16        0
17        1
18        0
19        1
20        0
21        0
22        0
23        1
24        0
25        0
26        0
27        0
28        0
29        1
30        0
```

Therefore:

``` text
2 3 5 7 11 13 17 19 23 29
```

are prime.

------------------------------------------------------------------------

# 21. Algorithm

1.  Create `prime[0...N]`.
2.  Initialise all values to `1`.
3.  Set `prime[0] = 0`.
4.  Set `prime[1] = 0`.
5.  Loop:

``` cpp
for (int i = 2; i * i <= N; i++)
```

6.  If `prime[i] == 1`, then `i` is prime.
7.  Mark its multiples from `i*i`:

``` cpp
for (int j = i * i; j <= N; j += i)
{
    prime[j] = 0;
}
```

8.  At the end, every index whose value is `1` is prime.

------------------------------------------------------------------------

# 22. Pseudocode

``` text
SIEVE(N):

    create prime[0...N]

    set every value to 1

    prime[0] = 0
    prime[1] = 0

    for i = 2 while i*i <= N:

        if prime[i] == 1:

            for j = i*i while j <= N:

                prime[j] = 0

    return prime
```

------------------------------------------------------------------------

# 23. Complete C++ Program

``` cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n)
{
    // ============================================================
    // STEP 1:
    // Create an array from 0 to n.
    //
    // Initially assume every number is prime.
    //
    // prime[i] = 1
    // means:
    //
    //     "i is currently considered prime."
    // ============================================================

    vector<int> prime(n + 1, 1);

    // ============================================================
    // STEP 2:
    // 0 and 1 are not prime.
    // ============================================================

    if (n >= 0)
    {
        prime[0] = 0;
    }

    if (n >= 1)
    {
        prime[1] = 0;
    }

    // ============================================================
    // STEP 3:
    // Sieve of Eratosthenes
    //
    // We only need to process i while:
    //
    //     i * i <= n
    //
    // This means:
    //
    //     i <= sqrt(n)
    //
    // ============================================================

    for (int i = 2; i * i <= n; i++)
    {
        // ========================================================
        // If prime[i] is still 1,
        // then i is prime.
        // ========================================================

        if (prime[i] == 1)
        {
            // ====================================================
            // STEP 4:
            // Mark multiples of i.
            //
            // Start from i*i.
            //
            // Smaller multiples have already been marked by
            // smaller factors.
            // ====================================================

            for (int j = i * i; j <= n; j += i)
            {
                // =================================================
                // j is divisible by i.
                //
                // Therefore j has a divisor other than 1
                // and itself.
                //
                // So j is NOT prime.
                // =================================================

                prime[j] = 0;
            }
        }
    }

    return prime;
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> prime = sieve(n);

    cout << "Prime numbers up to " << n << " are:
";

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
```

------------------------------------------------------------------------

# 24. Detailed Code Explanation

## `vector<int> prime(n + 1, 1)`

This creates the prime-status array.

The index itself is the number.

For:

``` text
n = 10
```

we have:

``` text
prime[0] ... prime[10]
```

------------------------------------------------------------------------

## `prime[0] = 0` and `prime[1] = 0`

Because:

``` text
0 is not prime
1 is not prime
```

------------------------------------------------------------------------

## Outer Loop

``` cpp
for (int i = 2; i * i <= n; i++)
```

Only factors up to `sqrt(n)` are required.

------------------------------------------------------------------------

## `if (prime[i] == 1)`

If `i` has not already been marked composite, then `i` is prime.

Only prime values should be used to eliminate multiples.

------------------------------------------------------------------------

## Inner Loop

``` cpp
for (int j = i * i; j <= n; j += i)
```

This generates:

``` text
i*i
i*i+i
i*i+2*i
i*i+3*i
...
```

which are the multiples of `i`.

------------------------------------------------------------------------

## `prime[j] = 0`

Every multiple of a prime greater than the prime itself is composite.

Therefore:

``` cpp
prime[j] = 0;
```

------------------------------------------------------------------------

# 25. Time Complexity

The optimized Sieve has:

``` text
O(N log log N)
```

time complexity.

The marking work for each prime `p` is approximately:

``` text
N / p
```

so the total work behaves like:

``` text
N/2 + N/3 + N/5 + N/7 + ...
```

over prime values.

The resulting complexity is:

``` text
O(N log log N)
```

------------------------------------------------------------------------

# 26. Space Complexity

The array:

``` cpp
vector<int> prime(n + 1);
```

contains approximately `N` elements.

Therefore:

``` text
Space Complexity = O(N)
```

The main extra memory is the prime-status array.

------------------------------------------------------------------------

# 27. Sieve vs Brute Force

## Basic Brute Force

For every number, check divisors individually.

Approximate complexity:

``` text
O(N²)
```

------------------------------------------------------------------------

## Square-Root Prime Check

For every number, check divisors only up to:

``` text
sqrt(number)
```

For counting all primes this way, the total work is roughly:

``` text
O(N sqrt(N))
```

------------------------------------------------------------------------

## Sieve

Precompute prime status for the whole range:

``` text
O(N log log N)
```

Comparison:

``` text
Brute Force
    ↓
O(N²)

Square Root Checking
    ↓
O(N√N)

Sieve
    ↓
O(N log log N)
```

------------------------------------------------------------------------

# 28. Sieve vs Square-Root Approach

A useful rule:

``` text
One number → Square-root prime check

Many numbers in a range → Sieve
```

If the question is:

``` text
Is 97 prime?
```

a square-root check is simple.

If the question is:

``` text
Find all primes from 2 to 1,000,000.
```

Sieve is much more suitable.

------------------------------------------------------------------------

# 29. Precomputation

The Sieve is an example of precomputation.

We calculate prime status once:

``` cpp
vector<int> prime = sieve(1000000);
```

After that:

``` cpp
prime[x]
```

can tell us whether `x` is prime in:

``` text
O(1)
```

time.

This is especially useful when there are many queries.

------------------------------------------------------------------------

# 30. Multiple Queries

Suppose we need:

``` text
Is 17 prime?
Is 29 prime?
Is 100 prime?
Is 997 prime?
Is 10000 prime?
```

We can sieve once up to the maximum value:

``` cpp
vector<int> prime = sieve(10000);
```

Then each query is:

``` cpp
if (prime[x] == 1)
{
    // Prime
}
else
{
    // Not prime
}
```

Each lookup is O(1) after preprocessing.

------------------------------------------------------------------------

# 31. Counting Primes --- LeetCode 204

LeetCode 204 asks:

> Count the number of prime numbers strictly less than `n`.

For:

``` text
n = 10
```

the primes are:

``` text
2 3 5 7
```

Answer:

``` text
4
```

Notice that `10` itself is not included.

A LeetCode-style Sieve solution is:

``` cpp
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        // prime[x] tells whether x is prime.
        // The array represents numbers 0 through n-1.
        vector<bool> prime(n, true);

        // 0 and 1 are not prime.
        prime[0] = false;
        prime[1] = false;

        // Because the range is [0, n),
        // use i*i < n.
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i])
            {
                // Start from i*i because smaller multiples
                // have already been handled.
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        // Strictly less than n.
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
            }
        }

        return count;
    }
};
```

Important distinction:

### Inclusive range `[0, n]`

Use:

``` cpp
i * i <= n
```

and:

``` cpp
j <= n
```

### Exclusive range `[0, n)`

Use:

``` cpp
i * i < n
```

and:

``` cpp
j < n
```

The boundary depends on what your array represents.

------------------------------------------------------------------------

# 32. Important Edge Cases

``` text
n = 0 → no primes
n = 1 → no primes
n = 2 → 2 is prime if the range is <= n
n = 3 → 2 and 3 are prime if the range is <= n
n = 10 → 2,3,5,7 are prime
```

Always check whether the problem asks for:

``` text
<= n
```

or:

``` text
< n
```

------------------------------------------------------------------------

# 33. Common Mistakes

## Mistake 1 --- Forgetting 0 and 1

Correct:

``` cpp
prime[0] = 0;
prime[1] = 0;
```

------------------------------------------------------------------------

## Mistake 2 --- Starting from `j = i`

Wrong:

``` cpp
for (int j = i; j <= n; j += i)
```

This would mark the prime `i` itself as composite.

------------------------------------------------------------------------

## Mistake 3 --- Using `2*i` in the optimized version

`2*i` can work, but it repeats work.

Optimized:

``` cpp
j = i * i;
```

------------------------------------------------------------------------

## Mistake 4 --- Using the wrong boundary

Inclusive `[0,n]`:

``` cpp
i * i <= n
```

Exclusive `[0,n)`:

``` cpp
i * i < n
```

------------------------------------------------------------------------

## Mistake 5 --- Processing composite `i`

Use:

``` cpp
if (prime[i])
```

before marking multiples.

------------------------------------------------------------------------

## Mistake 6 --- Confusing `< n` and `<= n`

For LeetCode 204:

``` text
strictly less than n
```

so use `< n`.

------------------------------------------------------------------------

# 34. Interview Questions

### Q1. What is Sieve of Eratosthenes?

An algorithm that finds all primes up to a limit by marking multiples of
prime numbers as composite.

### Q2. Why start from `i*i`?

Because smaller multiples have already been marked by smaller factors.

### Q3. Why stop at sqrt(N)?

Every composite number has at least one factor `<= sqrt(N)`.

### Q4. Complexity?

``` text
Time: O(N log log N)
Space: O(N)
```

### Q5. Why is it better than brute force?

It eliminates many composite numbers together instead of testing every
number independently.

### Q6. When should you use it?

When you need prime information for many numbers in a range.

------------------------------------------------------------------------

# 35. Quick Revision

The core optimized Sieve is:

``` cpp
vector<int> prime(n + 1, 1);

prime[0] = 0;
prime[1] = 0;

for (int i = 2; i * i <= n; i++)
{
    if (prime[i] == 1)
    {
        for (int j = i * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
}
```

Then:

``` cpp
for (int i = 2; i <= n; i++)
{
    if (prime[i] == 1)
    {
        cout << i << " ";
    }
}
```

Remember:

``` text
1. Start from 2.
2. 0 and 1 are not prime.
3. Only process i if prime[i] is still 1.
4. Start marking from i*i.
5. Move by i.
6. Stop when i*i > n.
7. Remaining 1s are prime.
```

------------------------------------------------------------------------

# 36. Final Code Template

``` cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // ============================================================
    // STEP 1:
    // Assume every number is prime initially.
    // ============================================================

    vector<int> prime(n + 1, 1);

    // ============================================================
    // STEP 2:
    // 0 and 1 are not prime.
    // ============================================================

    prime[0] = 0;

    if (n >= 1)
    {
        prime[1] = 0;
    }

    // ============================================================
    // STEP 3:
    // Process possible prime factors up to sqrt(n).
    // ============================================================

    for (int i = 2; i * i <= n; i++)
    {
        // If i is still marked as prime,
        // use it to eliminate its multiples.
        if (prime[i] == 1)
        {
            // Start from i*i.
            //
            // Smaller multiples were already handled
            // by smaller prime factors.

            for (int j = i * i; j <= n; j += i)
            {
                // j is divisible by i,
                // so j is composite.
                prime[j] = 0;
            }
        }
    }

    // ============================================================
    // STEP 4:
    // Print remaining prime numbers.
    // ============================================================

    cout << "Prime numbers up to " << n << ":
";

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
```

------------------------------------------------------------------------

# Final Mental Model

``` text
                 SIEVE OF ERATOSTHENES
                          |
                          v
              Assume every number is prime
                          |
                          v
                   0 and 1 → false
                          |
                          v
                      Start at 2
                          |
                          v
                 Is i still prime?
                    /                            NO            YES
                  |              |
                Skip       Mark multiples
                                 |
                                 v
                         Start from i*i
                                 |
                                 v
                      i*i, i*i+i, i*i+2i...
                                 |
                                 v
                         Mark them false
                                 |
                                 v
                    Continue until sqrt(N)
                                 |
                                 v
                       Remaining true values
                                 |
                                 v
                         PRIME NUMBERS
```

## The 4 Most Important Points

``` text
1. prime[i] = 1
   → i is currently considered prime.

2. prime[j] = 0
   → j is composite / not prime.

3. Start marking from i*i
   → avoids repeated work.

4. Stop at i*i <= N
   → only factors up to sqrt(N) are needed
     for an inclusive [0, N] sieve.
```

## Complexity

``` text
Time Complexity:
    O(N log log N)

Space Complexity:
    O(N)
```

## One-Line Memory Trick

``` text
"Assume all numbers are prime,
then remove the multiples of every prime."
```

# END --- SIEVE OF ERATOSTHENES
