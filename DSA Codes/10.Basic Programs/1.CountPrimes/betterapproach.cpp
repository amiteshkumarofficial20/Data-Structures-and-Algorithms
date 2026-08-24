/*
    ============================================================================
        LEETCODE 204 — COUNT PRIMES
        BETTER APPROACH — SQRT(n) PRIME CHECKING
    ============================================================================

    Problem:
        LeetCode 204 — Count Primes

    Approach:
        Better Approach using Square Root

    Language:
        C++17


    ============================================================================
        PROBLEM STATEMENT
    ============================================================================

    Given an integer n, count how many prime numbers are strictly
    less than n.

    In other words, we need to check:

        2, 3, 4, 5, ..., n - 1

    and count how many of these numbers are prime.


    Example:

        n = 10

    Numbers strictly less than 10:

        2 3 4 5 6 7 8 9

    Prime numbers:

        2 3 5 7

    Therefore:

        Answer = 4


    ============================================================================
        PREVIOUS APPROACH — BASIC BRUTE FORCE
    ============================================================================

    In the basic brute-force approach, for every number:

        2
        3
        4
        ...
        n - 1

    we check all possible divisors:

        2
        3
        4
        ...
        num - 1


    The basic isPrime() function was:

        bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }

            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }


    ============================================================================
        WHY IS THE BRUTE-FORCE APPROACH NOT EFFICIENT?
    ============================================================================

    The problem with the brute-force approach is:

        We check divisors from:

            2 to num - 1

    for every number.

    Suppose:

        num = 100

    The brute-force approach can check:

        2, 3, 4, 5, 6, ..., 99

    That means we are doing almost 100 checks just to determine whether
    100 is prime.


    But we do NOT actually need to check all numbers up to num - 1.

    There is an important mathematical observation that allows us to
    stop much earlier.


    ============================================================================
        BETTER APPROACH — MAIN IDEA
    ============================================================================

    Instead of checking divisors from:

        2 to num - 1

    we only check divisors up to:

        sqrt(num)


    In C++, instead of writing:

        i <= sqrt(num)

    we use:

        i * i <= num


    Therefore:

        for (int i = 2; i * i <= num; i++)


    This reduces the work required to check whether ONE number is prime.


    ============================================================================
        WHY CAN WE STOP AT sqrt(num)?
    ============================================================================

    This is the most important concept of this approach.


    Suppose a number is composite.

    A composite number can be represented as:

        num = a * b


    where:

        a > 1
        b > 1


    For example:

        36 = 4 * 9

    or:

        36 = 6 * 6


    Notice the factor pairs of 36:

        1 × 36
        2 × 18
        3 × 12
        4 × 9
        6 × 6
        9 × 4
        12 × 3
        18 × 2
        36 × 1


    Now calculate:

        sqrt(36) = 6


    Notice something important:

        Before or at sqrt(36):

            1
            2
            3
            4
            5
            6


    After sqrt(36):

            9
            12
            18
            36


    The factor pairs after 6 are simply the reverse of the factor pairs
    that appeared before 6.


    Therefore, if 36 has a divisor, at least one divisor must be:

        <= sqrt(36)


    That means:

        We only need to check up to sqrt(num).


    ============================================================================
        THE GENERAL FACTOR-PAIR IDEA
    ============================================================================

    Suppose:

        num = a * b


    If BOTH factors were greater than sqrt(num):

        a > sqrt(num)

    and:

        b > sqrt(num)


    then:

        a * b > sqrt(num) * sqrt(num)


    Therefore:

        a * b > num


    But we already know:

        a * b = num


    This is impossible.


    Therefore:

        If num is composite,
        at least one of its factors must be <= sqrt(num).


    This is the reason we only check divisors up to sqrt(num).


    ============================================================================
        WHY i * i <= num?
    ============================================================================

    We know:

        i <= sqrt(num)


    Instead of calculating sqrt(num), we can square both sides:

        i * i <= num


    Therefore:

        i <= sqrt(num)

    is equivalent to:

        i * i <= num


    In C++ we use:

        i * i <= num


    So our loop becomes:

        for (int i = 2; i * i <= num; i++)


    This is the important improvement over:

        for (int i = 2; i < num; i++)


    ============================================================================
        EXAMPLE — num = 36
    ============================================================================

    We want to check whether:

        36

    is prime.


    sqrt(36):

        sqrt(36) = 6


    Therefore we only need to check:

        2
        3
        4
        5
        6


    We do NOT need to check:

        7
        8
        9
        ...
        35


    Let's see the loop condition.


    ------------------------------------------------------------------------
    i = 2
    ------------------------------------------------------------------------

        i * i <= num

        2 * 2 <= 36

        4 <= 36

        TRUE


    Check:

        36 % 2 == 0


    TRUE.


    Therefore:

        36 is NOT prime.


    We immediately:

        return false;


    We do not need to check:

        3
        4
        5
        6
        ...
        35


    This is another important benefit of:

        return false;


    Once we find a divisor, the answer is already known.


    ============================================================================
        EXAMPLE — num = 29
    ============================================================================

    We want to check:

        29


    sqrt(29) is approximately:

        5.38


    Therefore we only need to check integer divisors:

        2
        3
        4
        5


    ------------------------------------------------------------------------
    i = 2
    ------------------------------------------------------------------------

        2 * 2 <= 29

        4 <= 29

        TRUE


        29 % 2 = 1

        Not divisible.


    ------------------------------------------------------------------------
    i = 3
    ------------------------------------------------------------------------

        3 * 3 <= 29

        9 <= 29

        TRUE


        29 % 3 = 2

        Not divisible.


    ------------------------------------------------------------------------
    i = 4
    ------------------------------------------------------------------------

        4 * 4 <= 29

        16 <= 29

        TRUE


        29 % 4 = 1

        Not divisible.


    ------------------------------------------------------------------------
    i = 5
    ------------------------------------------------------------------------

        5 * 5 <= 29

        25 <= 29

        TRUE


        29 % 5 = 4

        Not divisible.


    ------------------------------------------------------------------------
    i = 6
    ------------------------------------------------------------------------

        6 * 6 <= 29

        36 <= 29

        FALSE


    Loop ends.


    No divisor was found.

    Therefore:

        29 is prime.


    So:

        return true;


    ============================================================================
        IMPORTANT — WHY 3 IS PRIME WITH THIS APPROACH
    ============================================================================

    Consider:

        isPrime(3)


    First:

        3 < 2

    FALSE.


    Now the loop:

        for (int i = 2; i * i <= 3; i++)


    First value:

        i = 2


    Check:

        2 * 2 <= 3

        4 <= 3

        FALSE


    Therefore the loop executes ZERO times.


    Then execution moves to:

        return true;


    Therefore:

        isPrime(3) = true


    This is correct.


    Why is it safe to perform zero divisor checks?

    Because:

        sqrt(3) < 2

    and there is no possible divisor between:

        2 and sqrt(3)


    Therefore 3 must be prime.


    ============================================================================
        IMPORTANT — WHY 4 IS NOT PRIME
    ============================================================================

    Consider:

        isPrime(4)


    First:

        4 < 2

    FALSE.


    Loop:

        i = 2


    Condition:

        2 * 2 <= 4

        4 <= 4

        TRUE


    Check:

        4 % 2 == 0


    TRUE.


    Therefore:

        return false;


    So:

        4 is NOT prime.


    Notice that we found the divisor exactly at:

        sqrt(4) = 2


    This is why the condition is:

        i * i <= num


    and NOT:

        i * i < num


    We MUST include sqrt(num) when it is an integer.


    ============================================================================
        WHY <= AND NOT <
    ============================================================================

    This is extremely important.


    Suppose:

        num = 25


    We know:

        sqrt(25) = 5


    And:

        5 * 5 = 25


    If we write:

        i * i < num


    then:

        5 * 5 < 25

        25 < 25

        FALSE


    So we would NOT check 5.


    But:

        25 % 5 == 0


    and 25 is clearly NOT prime.


    Therefore we must use:

        i * i <= num


    not:

        i * i < num


    ============================================================================
        BETTER isPrime() LOGIC
    ============================================================================

    The improved logic is:

        1. If num < 2:
               return false.

        2. Start divisor from 2.

        3. Continue while:

               i * i <= num

        4. If:

               num % i == 0

           then:

               return false

        5. If the loop finishes:

               return true


    ============================================================================
        COMPLETE BETTER isPrime() FUNCTION
    ============================================================================

    The important change is:

        OLD:

            for (int i = 2; i < num; i++)

        NEW:

            for (int i = 2; i * i <= num; i++)


    ============================================================================
        COMPLETE CODE
    ============================================================================
*/

#include <iostream>

using namespace std;

// ============================================================================
// 1. isPrime()
// ============================================================================
//
// Purpose:
//
//     Check whether a given number is prime.
//
// Better Approach:
//
//     Instead of checking every possible divisor from 2 to num - 1,
//     we only check divisors up to sqrt(num).
//
// Parameter:
//
//     num
//         The number whose primality we want to check.
//
// Return:
//
//     true
//         If num is prime.
//
//     false
//         If num is NOT prime.
//
// ============================================================================

bool isPrime(int num)
{
    // ------------------------------------------------------------------------
    // STEP 1: Check numbers smaller than 2
    // ------------------------------------------------------------------------
    //
    // Prime numbers are greater than 1.
    //
    // Therefore:
    //
    //     0  -> Not Prime
    //     1  -> Not Prime
    //     Negative numbers -> Not Prime
    //
    // ------------------------------------------------------------------------

    if (num < 2)
    {
        return false;
    }

    // ------------------------------------------------------------------------
    // STEP 2: Check possible divisors only up to sqrt(num)
    // ------------------------------------------------------------------------
    //
    // BASIC BRUTE FORCE used:
    //
    //     for (int i = 2; i < num; i++)
    //
    //
    // BETTER APPROACH:
    //
    //     for (int i = 2; i * i <= num; i++)
    //
    //
    // Why?
    //
    // If num is composite, at least one of its factors must be
    // less than or equal to sqrt(num).
    //
    // Therefore checking beyond sqrt(num) is unnecessary.
    //
    // ------------------------------------------------------------------------

    for (int i = 2; i * i <= num; i++)
    {
        // --------------------------------------------------------------------
        // STEP 3: Check whether i divides num
        // --------------------------------------------------------------------
        //
        // If:
        //
        //     num % i == 0
        //
        // then i is a divisor of num.
        //
        // Therefore num is NOT prime.
        //
        // We immediately return false.
        //
        // --------------------------------------------------------------------

        if (num % i == 0)
        {
            return false;
        }
    }

    // ------------------------------------------------------------------------
    // STEP 4: No divisor found
    // ------------------------------------------------------------------------
    //
    // We checked every possible divisor up to sqrt(num).
    //
    // No divisor was found.
    //
    // Therefore num is prime.
    //
    // ------------------------------------------------------------------------

    return true;
}

// ============================================================================
// 2. countPrimes()
// ============================================================================
//
// Purpose:
//
//     Count how many prime numbers are strictly less than n.
//
// Parameter:
//
//     n
//         Upper limit.
//
// Return:
//
//     Total number of prime numbers less than n.
//
// ============================================================================

int countPrimes(int n)
{
    // ------------------------------------------------------------------------
    // STEP 1: Initialize count
    // ------------------------------------------------------------------------
    //
    // Initially we have not found any prime number.
    //
    // Therefore:
    //
    //     count = 0
    //
    // ------------------------------------------------------------------------

    int count = 0;

    // ------------------------------------------------------------------------
    // STEP 2: Check every number from 2 to n - 1
    // ------------------------------------------------------------------------
    //
    // The problem asks for prime numbers STRICTLY LESS THAN n.
    //
    // Therefore:
    //
    //     i < n
    //
    // not:
    //
    //     i <= n
    //
    // ------------------------------------------------------------------------

    for (int i = 2; i < n; i++)
    {
        // --------------------------------------------------------------------
        // STEP 3: Check whether current number is prime
        // --------------------------------------------------------------------
        //
        // isPrime(i) now uses the BETTER sqrt-based approach.
        //
        // It does NOT check divisors all the way up to i - 1.
        //
        // It only checks up to sqrt(i).
        //
        // --------------------------------------------------------------------

        if (isPrime(i))
        {
            // ----------------------------------------------------------------
            // STEP 4: Current number is prime
            // ----------------------------------------------------------------
            //
            // Increase the number of primes found.
            //
            //     count++
            //
            // is equivalent to:
            //
            //     count = count + 1;
            //
            // ----------------------------------------------------------------

            count++;
        }
    }

    // ------------------------------------------------------------------------
    // STEP 5: Return final count
    // ------------------------------------------------------------------------

    return count;
}

// ============================================================================
// 3. main()
// ============================================================================
//
// This main() function is ONLY for local testing.
//
// On LeetCode, you normally submit the Solution class shown later
// in this file instead of main().
//
// ============================================================================

int main()
{
    // ------------------------------------------------------------------------
    // Test Case:
    //
    //     n = 10
    //
    // Prime numbers strictly less than 10:
    //
    //     2 3 5 7
    //
    // Therefore:
    //
    //     Answer = 4
    //
    // ------------------------------------------------------------------------

    int n;
    cout << "Enter a Number Till Which You Have To Count Prime Numbers: ";
    cin >> n;

    cout << "Number of primes less than "
         << n
         << " = "
         << countPrimes(n)
         << endl;

    return 0;
}

/*
    ============================================================================
        DETAILED THEORY
    ============================================================================


    ============================================================================
        4. WHAT WAS WRONG WITH THE PREVIOUS APPROACH?
    ============================================================================

    The previous brute-force approach used:

        for (int i = 2; i < num; i++)


    Suppose:

        num = 100


    It could check:

        2
        3
        4
        5
        ...
        99


    That means almost every number before 100 is being checked.


    But this is unnecessary.


    The factor-pair observation tells us that if 100 is composite,
    we will find a divisor by the time we reach:

        sqrt(100)


    and:

        sqrt(100) = 10


    Therefore we only need to check:

        2
        3
        4
        5
        6
        7
        8
        9
        10


    Instead of:

        2
        3
        ...
        99


    This is a major reduction in work.


    ============================================================================
        5. BRUTE FORCE VS BETTER APPROACH
    ============================================================================

    BRUTE FORCE:

        for (int i = 2; i < num; i++)


    Number of possible checks:

        approximately num


    Time complexity for one isPrime():

        O(num)


    ------------------------------------------------------------


    BETTER APPROACH:

        for (int i = 2; i * i <= num; i++)


    Number of possible checks:

        approximately sqrt(num)


    Time complexity for one isPrime():

        O(sqrt(num))


    Therefore:

        O(num)

    becomes:

        O(sqrt(num))


    ============================================================================
        6. WHY FACTOR PAIRS HELP US
    ============================================================================

    Every composite number can be written as:

        num = a * b


    For example:

        30 = 2 * 15
        30 = 3 * 10
        30 = 5 * 6


    Factor pairs:

        1 × 30
        2 × 15
        3 × 10
        5 × 6
        6 × 5
        10 × 3
        15 × 2
        30 × 1


    sqrt(30) is approximately:

        5.47


    Notice:

        2
        3
        5

    are on the left side of sqrt(30).


    The factors after sqrt(30):

        6
        10
        15
        30

    are simply the corresponding partners of:

        5
        3
        2
        1


    Therefore once we have checked up to sqrt(num), the remaining
    factor pairs do not give us any new information.


    ============================================================================
        7. THE MOST IMPORTANT MATHEMATICAL PROOF
    ============================================================================

    Suppose:

        num = a * b


    Assume both:

        a > sqrt(num)

    and:

        b > sqrt(num)


    Multiplying:

        a * b > sqrt(num) * sqrt(num)


    Therefore:

        a * b > num


    But:

        a * b = num


    Contradiction.


    Therefore BOTH factors cannot be greater than sqrt(num).


    So:

        At least one factor must be <= sqrt(num).


    This is exactly why the loop can stop at sqrt(num).


    ============================================================================
        8. WHY WE USE i * i <= num
    ============================================================================

    Mathematically:

        i <= sqrt(num)


    We could write:

        i <= sqrt(num)


    but this requires the sqrt() function.


    Instead:

        i <= sqrt(num)


    can be represented as:

        i * i <= num


    Therefore:

        for (int i = 2; i * i <= num; i++)


    is the standard implementation.


    ============================================================================
        9. WHY NOT i < sqrt(num)?
    ============================================================================

    Because the square root itself can be a divisor.


    Example:

        num = 49


    sqrt(49) = 7


    And:

        7 * 7 = 49


    Therefore:

        49 % 7 == 0


    So 49 is not prime.


    If we excluded 7, we would miss the divisor.


    Therefore:

        i * i <= num


    is required.


    ============================================================================
        10. WHY <= IS IMPORTANT
    ============================================================================

    Correct:

        i * i <= num


    Incorrect:

        i * i < num


    Example:

        num = 25


    At:

        i = 5


    We get:

        5 * 5 = 25


    Correct condition:

        25 <= 25

        TRUE


    So we check:

        25 % 5 == 0


    and correctly return false.


    With:

        i * i < num


    we would get:

        25 < 25

        FALSE


    and we would skip 5.


    That would be incorrect.


    ============================================================================
        11. DRY RUN — isPrime(2)
    ============================================================================

    num = 2


    Step 1:

        2 < 2

        FALSE


    Loop:

        i = 2


    Condition:

        2 * 2 <= 2

        4 <= 2

        FALSE


    Loop executes zero times.


    Then:

        return true;


    Therefore:

        2 is prime.


    ============================================================================
        12. DRY RUN — isPrime(3)
    ============================================================================

    num = 3


    Step 1:

        3 < 2

        FALSE


    Loop:

        i = 2


    Condition:

        2 * 2 <= 3

        4 <= 3

        FALSE


    Loop executes zero times.


    Then:

        return true;


    Therefore:

        3 is prime.


    ============================================================================
        13. DRY RUN — isPrime(4)
    ============================================================================

    num = 4


    Step 1:

        4 < 2

        FALSE


    Loop:

        i = 2


    Condition:

        2 * 2 <= 4

        4 <= 4

        TRUE


    Check:

        4 % 2 == 0


    TRUE.


    Therefore:

        return false;


    So:

        4 is NOT prime.


    ============================================================================
        14. DRY RUN — isPrime(5)
    ============================================================================

    num = 5


    Loop:

        i = 2


    Condition:

        2 * 2 <= 5

        4 <= 5

        TRUE


    Check:

        5 % 2 = 1


    Not divisible.


    Increment:

        i = 3


    Condition:

        3 * 3 <= 5

        9 <= 5

        FALSE


    Loop ends.


    No divisor was found.


    Therefore:

        return true;


    So:

        5 is prime.


    ============================================================================
        15. DRY RUN — isPrime(9)
    ============================================================================

    num = 9


    Loop:

        i = 2


    Condition:

        2 * 2 <= 9

        4 <= 9

        TRUE


    Check:

        9 % 2 = 1


    Not divisible.


    Increment:

        i = 3


    Condition:

        3 * 3 <= 9

        9 <= 9

        TRUE


    Check:

        9 % 3 == 0


    TRUE.


    Therefore:

        return false;


    So:

        9 is NOT prime.


    Notice that we found the divisor exactly at:

        sqrt(9) = 3


    ============================================================================
        16. DRY RUN — isPrime(25)
    ============================================================================

    num = 25


    i = 2:

        2 * 2 <= 25

        TRUE

        25 % 2 != 0


    i = 3:

        3 * 3 <= 25

        TRUE

        25 % 3 != 0


    i = 4:

        4 * 4 <= 25

        TRUE

        25 % 4 != 0


    i = 5:

        5 * 5 <= 25

        TRUE

        25 % 5 == 0


    Therefore:

        return false;


    So:

        25 is NOT prime.


    ============================================================================
        17. DRY RUN — isPrime(29)
    ============================================================================

    num = 29


    i = 2:

        2 * 2 <= 29
        TRUE

        29 % 2 = 1


    i = 3:

        3 * 3 <= 29
        TRUE

        29 % 3 = 2


    i = 4:

        4 * 4 <= 29
        TRUE

        29 % 4 = 1


    i = 5:

        5 * 5 <= 29
        TRUE

        29 % 5 = 4


    i = 6:

        6 * 6 <= 29
        FALSE


    Loop ends.


    No divisor found.


    Therefore:

        return true;


    So:

        29 is prime.


    ============================================================================
        18. DRY RUN — countPrimes(10)
    ============================================================================

    Input:

        n = 10


    Initialize:

        count = 0


    Outer loop checks:

        2
        3
        4
        5
        6
        7
        8
        9


    ------------------------------------------------------------------------
    i = 2
    ------------------------------------------------------------------------

        isPrime(2)

        returns true

        count = 1


    ------------------------------------------------------------------------
    i = 3
    ------------------------------------------------------------------------

        isPrime(3)

        returns true

        count = 2


    ------------------------------------------------------------------------
    i = 4
    ------------------------------------------------------------------------

        isPrime(4)

        returns false

        count = 2


    ------------------------------------------------------------------------
    i = 5
    ------------------------------------------------------------------------

        isPrime(5)

        returns true

        count = 3


    ------------------------------------------------------------------------
    i = 6
    ------------------------------------------------------------------------

        isPrime(6)

        returns false

        count = 3


    ------------------------------------------------------------------------
    i = 7
    ------------------------------------------------------------------------

        isPrime(7)

        returns true

        count = 4


    ------------------------------------------------------------------------
    i = 8
    ------------------------------------------------------------------------

        isPrime(8)

        returns false

        count = 4


    ------------------------------------------------------------------------
    i = 9
    ------------------------------------------------------------------------

        isPrime(9)

        returns false

        count = 4


    Final:

        count = 4


    Prime numbers:

        2 3 5 7


    ============================================================================
        19. COMPLETE DRY RUN TABLE
    ============================================================================

        Number     sqrt-checking result       Prime?       count

        2          No divisor checked         YES          1
        3          No divisor checked         YES          2
        4          4 % 2 == 0                NO           2
        5          No divisor found           YES          3
        6          6 % 2 == 0                NO           3
        7          No divisor found           YES          4
        8          8 % 2 == 0                NO           4
        9          9 % 3 == 0                NO           4


    Final:

        count = 4


    ============================================================================
        20. VERY IMPORTANT — OUTER LOOP DID NOT CHANGE
    ============================================================================

    Notice something important.


    countPrimes() still uses:

        for (int i = 2; i < n; i++)


    Why?


    Because we still need to consider every number below n.


    The optimization is NOT changing:

        which numbers we consider.


    The optimization changes:

        how we determine whether each number is prime.


    Previously:

        isPrime(i)

    checked:

        2 to i - 1


    Now:

        isPrime(i)

    checks only:

        2 to sqrt(i)


    Therefore the improvement happens inside:

        isPrime()


    ============================================================================
        21. OLD CODE VS NEW CODE
    ============================================================================

    OLD BRUTE FORCE:

        bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }

            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }


    NEW BETTER APPROACH:

        bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }


    THE ONLY IMPORTANT CHANGE:

        i < num

    becomes:

        i * i <= num


    This single change dramatically reduces the work done by isPrime().


    ============================================================================
        22. TIME COMPLEXITY OF isPrime()
    ============================================================================

    OLD:

        for (int i = 2; i < num; i++)


    Maximum iterations:

        approximately num


    Therefore:

        O(num)


    ------------------------------------------------------------


    NEW:

        for (int i = 2; i * i <= num; i++)


    Maximum iterations:

        approximately sqrt(num)


    Therefore:

        O(sqrt(num))


    So:

        OLD:

            O(num)


        NEW:

            O(sqrt(num))


    ============================================================================
        23. TIME COMPLEXITY OF countPrimes()
    ============================================================================

    countPrimes() still checks every number:

        2 to n - 1


    Therefore there are approximately:

        O(n)


    calls to:

        isPrime()


    But each isPrime() now takes approximately:

        O(sqrt(num))


    So this approach is significantly better than the basic brute-force
    implementation.


    A simple upper-bound way to express the overall complexity is:

        O(n * sqrt(n))


    This is not the final optimal approach for LeetCode 204.


    The next major improvement is:

        Sieve of Eratosthenes


    But the current file intentionally focuses on the
    square-root-based improvement.


    ============================================================================
        24. SPACE COMPLEXITY
    ============================================================================

    We are still using only:

        num
        n
        count
        i


    No additional array is required.


    Therefore:

        Auxiliary Space = O(1)


    ============================================================================
        25. BRUTE FORCE VS SQRT APPROACH
    ============================================================================

    ------------------------------------------------------------------------
    BASIC BRUTE FORCE
    ------------------------------------------------------------------------

    For one number:

        Check:

            2 → num - 1


    Time:

        O(num)


    Overall:

        Approximately O(n²)


    Space:

        O(1)


    ------------------------------------------------------------------------
    BETTER SQRT APPROACH
    ------------------------------------------------------------------------

    For one number:

        Check:

            2 → sqrt(num)


    Time:

        O(sqrt(num))


    Overall upper-bound:

        O(n * sqrt(n))


    Space:

        O(1)


    ------------------------------------------------------------------------
    FINAL OPTIMAL APPROACH
    ------------------------------------------------------------------------

    For LeetCode 204, a still better approach exists:

        Sieve of Eratosthenes


    Its typical complexity is approximately:

        Time:
            O(n log log n)

        Space:
            O(n)


    But that is a DIFFERENT approach and is not implemented in this file.


    ============================================================================
        26. WHY THIS IS CALLED A BETTER APPROACH
    ============================================================================

    We are still checking numbers individually.

    However, we have made the prime-checking operation much more efficient.


    Old:

        Check almost all numbers:

            2, 3, 4, ..., num - 1


    New:

        Check only:

            2, 3, 4, ..., sqrt(num)


    Therefore:

        We eliminate unnecessary divisor checks.


    ============================================================================
        27. IMPORTANT DIFFERENCE BETWEEN sqrt(num) AND i * i
    ============================================================================

    Conceptually:

        sqrt(num)


    is the boundary we care about.


    In code:

        i * i <= num


    represents that boundary.


    Example:

        num = 100


    sqrt(100):

        10


    Therefore:

        i <= 10


    Using multiplication:

        i * i <= 100


    gives:

        2 * 2 <= 100
        3 * 3 <= 100
        ...
        10 * 10 <= 100


    At:

        i = 11


    we get:

        11 * 11 = 121


    and:

        121 <= 100

    is false.


    Therefore the loop stops.


    ============================================================================
        28. WHY WE DON'T NEED TO CHECK 11 TO 99 FOR 100
    ============================================================================

    Suppose:

        100 = a * b


    We already know:

        sqrt(100) = 10


    If 100 has a factor greater than 10, its corresponding factor must
    be smaller than 10.


    Examples:

        100 = 4 × 25

        100 = 5 × 20

        100 = 10 × 10


    In every case, we would discover a factor at or before 10.


    Therefore checking:

        11, 12, 13, ..., 99


    cannot provide any new information about whether 100 is composite.


    ============================================================================
        29. IMPORTANT EXAMPLE — 49
    ============================================================================

    This is an excellent example for understanding <=.


    num = 49


    sqrt(49):

        7


    Factor pair:

        7 × 7


    Loop:

        i = 2
        3
        4
        5
        6
        7


    At:

        i = 7


    condition:

        7 * 7 <= 49

        49 <= 49

        TRUE


    Then:

        49 % 7 == 0


    Therefore:

        return false;


    So 49 is correctly identified as non-prime.


    ============================================================================
        30. IMPORTANT EXAMPLE — 47
    ============================================================================

    num = 47


    sqrt(47) is approximately:

        6.85


    Therefore integer values checked are:

        2
        3
        4
        5
        6


    Checks:

        47 % 2 != 0
        47 % 3 != 0
        47 % 4 != 0
        47 % 5 != 0
        47 % 6 != 0


    No divisor found.


    Therefore:

        47 is prime.


    ============================================================================
        31. COMMON MISTAKE — USING i * i < num
    ============================================================================

    Wrong:

        for (int i = 2; i * i < num; i++)


    Example:

        num = 9


    sqrt(9) = 3


    At:

        i = 3


    We need to check:

        9 % 3 == 0


    But with:

        i * i < num


    we get:

        3 * 3 < 9

        9 < 9

        FALSE


    Therefore 3 is not checked.


    That is wrong.


    Correct:

        i * i <= num


    ============================================================================
        32. COMMON MISTAKE — USING sqrt(num) INCORRECTLY
    ============================================================================

    You may see:

        for (int i = 2; i <= sqrt(num); i++)


    This can work for basic code, but:

        i * i <= num


    is a common and clean way to express the same mathematical boundary.


    The important concept is not the syntax itself.


    The important concept is:

        We only need to check possible divisors up to sqrt(num).


    ============================================================================
        33. COMMON MISTAKE — THINKING WE ONLY CHECK sqrt(num)
    ============================================================================

    We do NOT check only:

        sqrt(num)


    We check:

        every integer from 2 through sqrt(num).


    Example:

        num = 36


    sqrt(36) = 6


    We check:

        2
        3
        4
        5
        6


    Not just:

        6


    ============================================================================
        34. COMMON MISTAKE — CONFUSING num AND n
    ============================================================================

    There are two different variables.


    In:

        countPrimes(int n)


    `n` is the upper limit.


    Example:

        n = 10


    We need primes less than 10.


    Then:

        isPrime(i)


    checks one particular number.


    Inside:

        isPrime(int num)


    `num` is the individual number being tested.


    For example:

        isPrime(7)


    Here:

        num = 7


    The sqrt condition is:

        i * i <= 7


    Not:

        i * i <= n


    This distinction is important.


    ============================================================================
        35. OUTER LOOP AND INNER LOOP
    ============================================================================

    There are still two loops.


    OUTER LOOP:

        for (int i = 2; i < n; i++)


    Purpose:

        Visit every candidate number less than n.


    INNER LOOP:

        for (int i = 2; i * i <= num; i++)


    Purpose:

        Check whether ONE candidate number is prime.


    Therefore:

        Outer loop
            ↓
        picks a number

            ↓

        isPrime()
            ↓
        checks divisors only up to sqrt(number)


    ============================================================================
        36. COMPLETE LOGIC FLOW
    ============================================================================


                         n
                         |
                         v
                 count = 0
                         |
                         v
                  i = 2 to n-1
                         |
                         v
                    isPrime(i)
                         |
                         v
               Is i < 2?
                  /     \
                YES      NO
                 |        |
              false       v
                         i = 2
                           |
                           v
                    i * i <= num?
                       /      \
                     NO        YES
                     |          |
                     |          v
                     |      num % i == 0?
                     |        /       \
                     |      YES        NO
                     |       |          |
                     |     false      i++
                     |                  |
                     +--------<---------+
                              |
                              v
                           true
                              |
                              v
                         count++
                              |
                              v
                       next candidate
                              |
                              v
                        return count


    ============================================================================
        37. WHY return false IS STILL IMPORTANT
    ============================================================================

    Even though we are using the sqrt optimization, the early return
    remains extremely important.


    Example:

        num = 100


    At:

        i = 2


    We get:

        100 % 2 == 0


    Immediately:

        return false;


    We do NOT need to check:

        3
        4
        5
        ...
        10


    So there are actually two benefits:


        1. We never go beyond sqrt(num).

        2. We stop immediately when a divisor is found.


    ============================================================================
        38. WHY return true IS AFTER THE LOOP
    ============================================================================

    Consider:

        num = 29


    We check:

        29 % 2
        29 % 3
        29 % 4
        29 % 5


    Every check fails to find a divisor.


    Only AFTER all possible divisors up to sqrt(29) have been checked
    can we safely say:

        29 is prime.


    Therefore:

        return true;


    must be after the loop.


    ============================================================================
        39. PSEUDOCODE
    ============================================================================

    function isPrime(num):

        if num < 2:
            return false

        for i = 2 while i * i <= num:

            if num % i == 0:
                return false

        return true


    function countPrimes(n):

        count = 0

        for i = 2 to n - 1:

            if isPrime(i):
                count++

        return count


    ============================================================================
        40. FINAL LEETCODE VERSION
    ============================================================================

    On LeetCode, you normally submit the Solution class.

    The main() function is not required.


*/

class Solution
{
public:
    // ========================================================================
    // Check whether one number is prime.
    // Better approach:
    // Check divisors only up to sqrt(num).
    // ========================================================================

    bool isPrime(int num)
    {
        // Numbers smaller than 2 are not prime.
        if (num < 2)
        {
            return false;
        }

        // Check only up to sqrt(num).
        //
        // i * i <= num
        //
        // is equivalent to:
        //
        // i <= sqrt(num)
        //
        // We use i * i <= num so that we don't need to call sqrt().
        for (int i = 2; i * i <= num; i++)
        {
            // If num is divisible by i,
            // then num is not prime.
            if (num % i == 0)
            {
                return false;
            }
        }

        // No divisor was found.
        // Therefore num is prime.
        return true;
    }

    // ========================================================================
    // Count all prime numbers strictly less than n.
    // ========================================================================

    int countPrimes(int n)
    {
        int count = 0;

        // The problem asks for numbers STRICTLY LESS THAN n.
        //
        // Therefore:
        //
        //     i < n
        //
        // not:
        //
        //     i <= n
        for (int i = 2; i < n; i++)
        {
            // Check whether the current number is prime.
            //
            // isPrime() now uses the sqrt-based optimization.
            if (isPrime(i))
            {
                count++;
            }
        }

        return count;
    }
};

/*
    ============================================================================
        41. FINAL REVISION
    ============================================================================

    BASIC BRUTE FORCE:

        for (int i = 2; i < num; i++)


    Problem:

        We may check almost every number from 2 to num - 1.


    Better observation:

        If num is composite, at least one factor is <= sqrt(num).


    Therefore:

        We only need to check divisors up to sqrt(num).


    Better loop:

        for (int i = 2; i * i <= num; i++)


    If divisor found:

        return false;


    If no divisor is found:

        return true;


    ============================================================================
        MOST IMPORTANT FORMULA
    ============================================================================

        i * i <= num


    means:

        i <= sqrt(num)


    And this is the key optimization.


    ============================================================================
        COMPLEXITY COMPARISON
    ============================================================================

    BASIC BRUTE FORCE:

        isPrime():

            O(num)


        countPrimes():

            approximately O(n²)


        Space:

            O(1)


    BETTER SQRT APPROACH:

        isPrime():

            O(sqrt(num))


        countPrimes():

            O(n * sqrt(n)) upper bound


        Space:

            O(1)


    NEXT APPROACH:

        Sieve of Eratosthenes

        Time:

            O(n log log n)

        Space:

            O(n)


    ============================================================================
        ONE-LINE MEMORY TRICK
    ============================================================================

        "A composite number must have a factor <= sqrt(num),
         so check divisors only while i * i <= num."


    ============================================================================
        FINAL CODE TO REMEMBER
    ============================================================================

        bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }

            return true;
        }


        int countPrimes(int n)
        {
            int count = 0;

            for (int i = 2; i < n; i++)
            {
                if (isPrime(i))
                {
                    count++;
                }
            }

            return count;
        }


    ============================================================================
        END
        LEETCODE 204 — COUNT PRIMES
        BETTER APPROACH — SQRT(n)
    ============================================================================
*/