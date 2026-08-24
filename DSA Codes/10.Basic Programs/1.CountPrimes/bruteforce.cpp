/*
    ============================================================================
        LEETCODE 204 — COUNT PRIMES
        BASIC BRUTE FORCE APPROACH
    ============================================================================

    Problem:
        LeetCode 204 — Count Primes

    Approach:
        Basic Brute Force

    Language:
        C++17

    Main Idea:

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
        BASIC BRUTE FORCE IDEA
    ============================================================================

    We will divide the problem into two parts:

        1. isPrime()
           Check whether one number is prime.

        2. countPrimes()
           Check every number from 2 to n - 1 and count the prime numbers.


    ============================================================================
        CORE LOGIC
    ============================================================================

    For every number:

        2
        3
        4
        ...
        n - 1

    call:

        isPrime(number)


    If:

        isPrime(number) == true

    then:

        count++


    Finally:

        return count;


    ============================================================================
        PRIME NUMBER DEFINITION
    ============================================================================

    A prime number is a number greater than 1 that has exactly two
    positive divisors:

        1
        itself


    Examples:

        2 → Prime
        3 → Prime
        5 → Prime
        7 → Prime

    Non-prime examples:

        4 → Divisible by 2
        6 → Divisible by 2
        8 → Divisible by 2
        9 → Divisible by 3


    Important:

        0 is NOT prime.

        1 is NOT prime.

        Negative numbers are NOT prime.


    ============================================================================
        IMPORTANT PROBLEM DETAIL
    ============================================================================

    The problem asks for:

        "number of prime numbers LESS THAN n"

    Therefore:

        n itself is NOT included.


    If:

        n = 10

    we check:

        2 through 9


    We DO NOT check:

        10


    Therefore the outer loop is:

        for (int i = 2; i < n; i++)


    NOT:

        for (int i = 2; i <= n; i++)


    ============================================================================
        APPROACH USED IN THIS FILE
    ============================================================================

        BASIC BRUTE FORCE

    For every number from 2 to n - 1:

        Check divisibility by every number from 2 to number - 1.

    If any divisor is found:

        number is NOT prime

    Otherwise:

        number IS prime.


    ============================================================================
        COMPLEXITY OF THIS BASIC VERSION
    ============================================================================

    Outer loop:
        O(N)

    For every number, the isPrime() function can perform:
        O(N)

    Therefore the basic brute-force solution is:

        Time Complexity:
            O(N²)

        Auxiliary Space:
            O(1)


    NOTE:

        A more optimized prime-checking loop can check only up to
        sqrt(number), but that is NOT the approach used in this file.

        This file intentionally demonstrates the BASIC BRUTE FORCE
        approach.


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
    // Prime numbers must be greater than 1.
    //
    // Therefore:
    //
    //     0 → Not Prime
    //     1 → Not Prime
    //     Negative numbers → Not Prime
    //
    // Example:
    //
    //     num = 1
    //
    //     1 < 2
    //
    //     Therefore:
    //
    //     return false;
    //
    // ------------------------------------------------------------------------

    if (num < 2)
    {
        return false;
    }

    // ------------------------------------------------------------------------
    // STEP 2: Try every possible divisor
    // ------------------------------------------------------------------------
    //
    // We start from:
    //
    //     i = 2
    //
    // because every number is divisible by 1, so checking 1 is useless.
    //
    //
    // We continue while:
    //
    //     i < num
    //
    // because we do not need to check the number itself.
    //
    // Every number is divisible by itself.
    //
    // Example:
    //
    //     num = 3
    //
    //     We check:
    //
    //         i = 2
    //
    //     We do NOT check:
    //
    //         i = 3
    //
    // because:
    //
    //     3 % 3 = 0
    //
    // is always true and does not tell us whether 3 is prime.
    //
    // ------------------------------------------------------------------------

    for (int i = 2; i < num; i++)
    {
        // --------------------------------------------------------------------
        // STEP 3: Check divisibility
        // --------------------------------------------------------------------
        //
        // If:
        //
        //     num % i == 0
        //
        // then num is completely divisible by i.
        //
        // Therefore i is a divisor of num.
        //
        // Since i is between 2 and num - 1,
        // we have found a divisor other than:
        //
        //     1
        //
        // and:
        //
        //     num
        //
        // Therefore num is NOT prime.
        //
        // We immediately return false.
        //
        // IMPORTANT:
        //
        // return false immediately terminates the entire isPrime()
        // function.
        //
        // The loop does NOT continue after return false.
        //
        // --------------------------------------------------------------------

        if (num % i == 0)
        {
            return false;
        }
    }

    // ------------------------------------------------------------------------
    // STEP 4: No divisor was found
    // ------------------------------------------------------------------------
    //
    // If the loop finishes without returning false, then no number from:
    //
    //     2 to num - 1
    //
    // divided num completely.
    //
    // Therefore num is prime.
    //
    // So we return true.
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
//     Count the number of prime numbers strictly less than n.
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
    // STEP 1: Create count variable
    // ------------------------------------------------------------------------
    //
    // This variable stores how many prime numbers we have found so far.
    //
    // Initially:
    //
    //     count = 0
    //
    // because we have not checked any number yet.
    //
    // ------------------------------------------------------------------------

    int count = 0;

    // ------------------------------------------------------------------------
    // STEP 2: Check every number from 2 to n - 1
    // ------------------------------------------------------------------------
    //
    // Why start from 2?
    //
    // Because:
    //
    //     0 → Not Prime
    //     1 → Not Prime
    //
    // Therefore the first possible prime number is:
    //
    //     2
    //
    //
    // Why:
    //
    //     i < n
    //
    // instead of:
    //
    //     i <= n
    //
    // Because the problem asks for numbers STRICTLY LESS THAN n.
    //
    // Example:
    //
    //     n = 10
    //
    // We check:
    //
    //     2 3 4 5 6 7 8 9
    //
    // We do NOT check:
    //
    //     10
    //
    // ------------------------------------------------------------------------

    for (int i = 2; i < n; i++)
    {
        // --------------------------------------------------------------------
        // STEP 3: Check whether current number is prime
        // --------------------------------------------------------------------
        //
        // We call:
        //
        //     isPrime(i)
        //
        // If it returns true, the current number is prime.
        //
        // --------------------------------------------------------------------

        if (isPrime(i))
        {
            // ---------------------------------------------------------------
            // STEP 4: Increase count
            // ---------------------------------------------------------------
            //
            // If the current number is prime:
            //
            //     count++
            //
            // is equivalent to:
            //
            //     count = count + 1;
            //
            // ---------------------------------------------------------------

            count++;
        }
    }

    // ------------------------------------------------------------------------
    // STEP 5: Return final count
    // ------------------------------------------------------------------------
    //
    // After checking all numbers from:
    //
    //     2 to n - 1
    //
    // count contains the total number of primes.
    //
    // ------------------------------------------------------------------------

    return count;
}

// ============================================================================
// 3. main()
// ============================================================================
//
// This section is ONLY for testing the solution locally.
//
// On LeetCode, you normally submit the Solution class instead of main().
//
// ============================================================================

int main()
{
    // ------------------------------------------------------------------------
    // Test Case:
    //
    // n = 10
    //
    // Prime numbers less than 10:
    //
    //     2 3 5 7
    //
    // Therefore answer:
    //
    //     4
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
    4. HOW THE SOLUTION WORKS
    ============================================================================

    Suppose:

        n = 10


    countPrimes(10) starts with:

        count = 0


    The outer loop checks:

        i = 2
        i = 3
        i = 4
        i = 5
        i = 6
        i = 7
        i = 8
        i = 9


    For each i:

        isPrime(i)


    is called.


    If:

        isPrime(i) == true

    then:

        count++


    At the end:

        count = 4


    because:

        2
        3
        5
        7

    are prime.


    ============================================================================
        5. DRY RUN FOR n = 10
    ============================================================================


    Initial state:

        n = 10
        count = 0


    ------------------------------------------------------------------------
    OUTER LOOP: i = 2
    ------------------------------------------------------------------------

        Condition:

            i < n

            2 < 10

            TRUE


        Call:

            isPrime(2)


        Inside isPrime():

            num = 2


        Check:

            num < 2

            2 < 2

            FALSE


        Inner loop:

            for (int i = 2; i < num; i++)


        First condition:

            2 < 2

            FALSE


        Therefore the inner loop executes ZERO times.


        Then:

            return true;


        Therefore:

            isPrime(2) = true


        Back in countPrimes():

            count++


        Therefore:

            count = 1


        Current prime numbers:

            2


    ------------------------------------------------------------------------
    OUTER LOOP: i = 3
    ------------------------------------------------------------------------

        Condition:

            3 < 10

            TRUE


        Call:

            isPrime(3)


        Inside:

            num = 3


        Check:

            3 < 2

            FALSE


        Inner loop:

            i = 2


        Condition:

            2 < 3

            TRUE


        Check:

            3 % 2 == 0


        3 % 2 = 1


        Therefore:

            1 == 0

            FALSE


        No return false occurs.


        Now:

            i++


        Therefore:

            i = 3


        Check loop condition again:

            3 < 3

            FALSE


        The inner loop ends.


        Then:

            return true;


        Therefore:

            isPrime(3) = true


        Back to countPrimes():

            count++


        Therefore:

            count = 2


        Current prime numbers:

            2 3


    ------------------------------------------------------------------------
    OUTER LOOP: i = 4
    ------------------------------------------------------------------------

        Condition:

            4 < 10

            TRUE


        Call:

            isPrime(4)


        Inside:

            num = 4


        Check:

            4 < 2

            FALSE


        Inner loop starts:

            i = 2


        Condition:

            2 < 4

            TRUE


        Check:

            4 % 2 == 0


        4 % 2 = 0


        Therefore:

            0 == 0

            TRUE


        So:

            return false;


        IMPORTANT:

            return false

        immediately terminates the isPrime() function.


        Therefore:

            i = 3

        is NEVER checked.


        And:

            4 % 3

        is NEVER calculated.


        Also:

            return true;

        at the bottom of isPrime() is NEVER reached.


        Therefore:

            isPrime(4) = false


        Back to countPrimes():

            if(false)

        Therefore count is NOT increased.


        count remains:

            2


    ------------------------------------------------------------------------
    OUTER LOOP: i = 5
    ------------------------------------------------------------------------

        Call:

            isPrime(5)


        num = 5


        Check:

            5 < 2 → FALSE


        Inner loop:

            i = 2

            2 < 5 → TRUE

            5 % 2 = 1

            1 == 0 → FALSE


        Next:

            i = 3

            3 < 5 → TRUE

            5 % 3 = 2

            2 == 0 → FALSE


        Next:

            i = 4

            4 < 5 → TRUE

            5 % 4 = 1

            1 == 0 → FALSE


        Next:

            i = 5

            5 < 5 → FALSE


        Inner loop ends.


        No divisor was found.


        Therefore:

            return true;


        So:

            isPrime(5) = true


        count becomes:

            3


    ------------------------------------------------------------------------
    OUTER LOOP: i = 6
    ------------------------------------------------------------------------

        Call:

            isPrime(6)


        num = 6


        Inner loop starts:

            i = 2


        Check:

            6 % 2 == 0


        TRUE


        Therefore:

            return false;


        Function ends immediately.


        Therefore:

            isPrime(6) = false


        count remains:

            3


    ------------------------------------------------------------------------
    OUTER LOOP: i = 7
    ------------------------------------------------------------------------

        Call:

            isPrime(7)


        Check divisors:

            7 % 2 = 1
            7 % 3 = 1
            7 % 4 = 3
            7 % 5 = 2
            7 % 6 = 1


        None are zero.


        Therefore:

            return true;


        So:

            isPrime(7) = true


        count becomes:

            4


    ------------------------------------------------------------------------
    OUTER LOOP: i = 8
    ------------------------------------------------------------------------

        Call:

            isPrime(8)


        First divisor:

            i = 2


        Check:

            8 % 2 == 0


        TRUE.


        Therefore:

            return false;


        Function ends immediately.


        count remains:

            4


    ------------------------------------------------------------------------
    OUTER LOOP: i = 9
    ------------------------------------------------------------------------

        Call:

            isPrime(9)


        First:

            i = 2


        Check:

            9 % 2 = 1


        Not divisible.


        Next:

            i = 3


        Check:

            9 % 3 == 0


        TRUE.


        Therefore:

            return false;


        Function ends immediately.


        count remains:

            4


    ------------------------------------------------------------------------
    OUTER LOOP: i = 10
    ------------------------------------------------------------------------

        Now:

            i = 10


        Outer loop condition:

            i < n

            10 < 10

            FALSE


        Therefore the outer loop ends.


        Finally:

            return count;


        count = 4


    ============================================================================
        FINAL ANSWER
    ============================================================================

        n = 10

        Prime numbers less than 10:

            2 3 5 7

        Total:

            4


    ============================================================================
        6. COMPLETE DRY RUN TABLE
    ============================================================================

        i       isPrime(i)       Reason                  count

        2       true             No divisor               1
        3       true             3 % 2 != 0               2
        4       false            4 % 2 == 0               2
        5       true             No divisor               3
        6       false            6 % 2 == 0               3
        7       true             No divisor               4
        8       false            8 % 2 == 0               4
        9       false            9 % 3 == 0               4


    Final:

        count = 4


    ============================================================================
        7. VERY IMPORTANT: WHY 3 IS PRIME
    ============================================================================

    Consider:

        isPrime(3)


    Inner loop:

        for (int i = 2; i < 3; i++)


    First:

        i = 2


    Condition:

        2 < 3

        TRUE


    Check:

        3 % 2 == 0

    Result:

        3 % 2 = 1


    Therefore:

        1 == 0

        FALSE


    So return false is NOT executed.


    Then:

        i++


    i becomes:

        3


    Now loop condition:

        3 < 3

        FALSE


    Therefore the loop ends.


    Then:

        return true;


    So:

        isPrime(3) = true


    IMPORTANT:

        3 % 3 is NEVER checked.

    Why?

        Because the loop condition is:

            i < num

        and not:

            i <= num


    ============================================================================
        8. VERY IMPORTANT: WHY 4 IS NOT PRIME
    ============================================================================

    Consider:

        isPrime(4)


    First inner iteration:

        i = 2


    Check:

        4 % 2 == 0


    This is TRUE.


    Therefore:

        return false;


    Immediately.


    So:

        i = 3

    is never reached.


    Therefore:

        4 % 3

    is never checked.


    This is an important optimization even within the basic brute-force
    logic:

        Once a divisor is found, we already know the answer.

        There is no reason to continue checking.


    ============================================================================
        9. WHY WE DON'T CHECK 1
    ============================================================================

    Suppose:

        num = 7


    We could technically check:

        7 % 1 == 0


    But every integer greater than 1 is divisible by 1.


    Therefore this information is useless for determining whether
    the number is prime.


    So we start at:

        i = 2


    ============================================================================
        10. WHY WE DON'T CHECK num ITSELF
    ============================================================================

    Every number is divisible by itself.

    Example:

        7 % 7 = 0

        11 % 11 = 0

        13 % 13 = 0


    If we checked the number itself, every number greater than 1 would
    appear to have a divisor.


    But prime numbers are allowed to have themselves as a divisor.


    Therefore we only search for an additional divisor:

        2 through num - 1


    ============================================================================
        11. RETURN FALSE VS RETURN TRUE
    ============================================================================

    This is extremely important.


    If we find a divisor:

        num % i == 0


    then:

        return false;


    This means:

        "num is definitely NOT prime."


    The function ends immediately.


    If the loop finishes and no divisor was found:

        return true;


    This means:

        "num has no divisor between 2 and num - 1,
         therefore it is prime."


    Conceptually:


        Start
          |
          v
        Is num < 2?
          |
        YES → false
          |
         NO
          |
          v
        Try divisors
          |
          v
        Is num % i == 0?
          |
        YES → false → END
          |
         NO
          |
          v
        Continue loop
          |
          v
        Loop finished?
          |
         YES
          |
          v
        true


    ============================================================================
        12. WHY return false STOPS THE LOOP
    ============================================================================

    Consider:

        isPrime(4)


    At:

        i = 2


    We get:

        4 % 2 == 0


    So:

        return false;


    `return` does two things:

        1. Produces the return value.
        2. Immediately exits the current function.


    Therefore execution does NOT continue to:

        i = 3

    or:

        i = 4


    and it does NOT reach:

        return true;


    ============================================================================
        13. OUTER LOOP VS INNER LOOP
    ============================================================================

    There are TWO loops in this solution.


    OUTER LOOP:

        for (int i = 2; i < n; i++)


    Purpose:

        Go through every number that might be prime.


    INNER LOOP:

        for (int i = 2; i < num; i++)


    Purpose:

        Check whether ONE particular number is prime.


    Example:

        n = 10


    Outer loop:

        2
        3
        4
        5
        6
        7
        8
        9


    For each outer value, the inner loop checks divisors.


    Conceptually:


        countPrimes(10)
              |
              +--- isPrime(2)
              |
              +--- isPrime(3)
              |
              +--- isPrime(4)
              |
              +--- isPrime(5)
              |
              +--- isPrime(6)
              |
              +--- isPrime(7)
              |
              +--- isPrime(8)
              |
              +--- isPrime(9)


    ============================================================================
        14. DRY RUN FOR n = 3
    ============================================================================

    Input:

        n = 3


    count = 0


    Outer loop:

        i = 2


    Condition:

        2 < 3

        TRUE


    Call:

        isPrime(2)


    Inside:

        num = 2


    Check:

        2 < 2

        FALSE


    Inner loop executes zero times.


    Then:

        return true;


    Therefore:

        isPrime(2) = true


    count becomes:

        1


    Outer loop increments:

        i = 3


    Condition:

        3 < 3

        FALSE


    Outer loop ends.


    Final:

        return 1;


    Therefore:

        countPrimes(3) = 1


    Prime numbers less than 3:

        2


    Answer:

        1


    ============================================================================
        15. DRY RUN FOR n = 2
    ============================================================================

    Input:

        n = 2


    count = 0


    Outer loop:

        i = 2


    Condition:

        2 < 2

        FALSE


    Loop never executes.


    Final:

        count = 0


    Therefore:

        countPrimes(2) = 0


    This is correct because there are no prime numbers less than 2.


    ============================================================================
        16. DRY RUN FOR n = 1
    ============================================================================

    Input:

        n = 1


    count = 0


    Outer loop:

        i = 2


    Condition:

        2 < 1

        FALSE


    Loop never executes.


    Final:

        0


    ============================================================================
        17. DRY RUN FOR n = 0
    ============================================================================

    Input:

        n = 0


    count = 0


    Outer loop:

        2 < 0

        FALSE


    Loop never executes.


    Final:

        0


    ============================================================================
        18. EDGE CASES
    ============================================================================

    Important test cases:


        n = 0
        Answer = 0


        n = 1
        Answer = 0


        n = 2
        Answer = 0


        n = 3
        Answer = 1


        n = 4
        Answer = 2

        Prime numbers:

            2
            3


        n = 5
        Answer = 2

        Prime numbers:

            2
            3


        n = 10
        Answer = 4

        Prime numbers:

            2
            3
            5
            7


    ============================================================================
        19. COMMON MISTAKE #1
    ============================================================================

    Mistake:

        for (int i = 2; i <= n; i++)


    Problem:

        This also checks n itself.


    But the problem asks:

        primes strictly less than n


    Correct:

        for (int i = 2; i < n; i++)


    ============================================================================
        20. COMMON MISTAKE #2
    ============================================================================

    Mistake:

        for (int i = 1; i < num; i++)


    Why is this unnecessary?


    Because:

        num % 1 == 0


    is always true.


    We only care whether num has a divisor between:

        2 and num - 1


    Therefore:

        for (int i = 2; i < num; i++)


    ============================================================================
        21. COMMON MISTAKE #3
    ============================================================================

    Mistake:

        for (int i = 2; i <= num; i++)


    This checks:

        num % num == 0


    for every number.


    That is not useful because every number is divisible by itself.


    Correct:

        i < num


    ============================================================================
        22. COMMON MISTAKE #4
    ============================================================================

    Mistake:

        if (num % i != 0)
        {
            return true;
        }


    This is WRONG.


    Why?


    Consider:

        num = 9


    First:

        i = 2


    9 % 2 != 0


    If we immediately returned true, we would incorrectly say:

        9 is prime.


    But:

        9 % 3 == 0


    Therefore 9 is not prime.


    Correct logic:

        Only return false when a divisor is found.

        Return true AFTER the entire loop finishes.


    ============================================================================
        23. COMMON MISTAKE #5
    ============================================================================

    Wrong:

        bool isPrime(int num)
        {
            for (...)
            {
                if (...)
                    return false;

                return true;
            }
        }


    This is wrong because return true is inside the loop.


    Example:

        num = 9


    i = 2:

        9 % 2 != 0


    If return true is inside the loop:

        9 would incorrectly be considered prime.


    Correct:

        return true;

    must come AFTER the loop.


    ============================================================================
        24. WHY return true IS AFTER THE LOOP
    ============================================================================

    We need to test ALL possible divisors.


    For example:

        num = 15


    Check:

        15 % 2 → not divisible

        15 % 3 → divisible


    If we returned true after checking only 2:

        15 would incorrectly be called prime.


    Therefore:

        return true;

    is executed only when the loop has finished without finding
    any divisor.


    ============================================================================
        25. BASIC BRUTE FORCE ALGORITHM
    ============================================================================

    Step 1:

        Initialize:

            count = 0


    Step 2:

        Loop from:

            2 to n - 1


    Step 3:

        For each number:

            check if it is prime.


    Step 4:

        If prime:

            count++


    Step 5:

        Return count.


    ============================================================================
        26. PSEUDOCODE
    ============================================================================

    function isPrime(num):

        if num < 2:
            return false

        for i = 2 to num - 1:

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
        27. TIME COMPLEXITY — DETAILED
    ============================================================================

    Outer loop can run approximately:

        N times.


    For every number, the inner loop can also run approximately:

        N times.


    Therefore in the basic worst-case analysis:

        O(N × N)


    which becomes:

        O(N²)


    Therefore:

        Time Complexity = O(N²)


    ============================================================================
        28. SPACE COMPLEXITY — DETAILED
    ============================================================================

    We use only a few variables:

        n
        count
        i
        num


    No additional array or container is used.


    Therefore:

        Auxiliary Space = O(1)


    ============================================================================
        29. WHY THIS IS CALLED BRUTE FORCE
    ============================================================================

    Brute force means:

        Try all relevant possibilities directly.


    Here, for every candidate number:

        2
        3
        4
        ...
        n - 1


    we try all possible divisors:

        2
        3
        ...
        num - 1


    We do not use:

        Sieve of Eratosthenes
        precomputation
        prime table
        optimized sqrt bound


    Therefore this is the basic brute-force approach.


    ============================================================================
        30. WHAT THIS APPROACH TEACHES
    ============================================================================

    This simple problem teaches several important DSA concepts:

        1. Functions

        2. Boolean return values

        3. Nested loops

        4. Modulo operator

        5. Early return

        6. Prime number checking

        7. Time complexity

        8. Space complexity

        9. Edge cases

        10. Difference between loop termination and function termination


    ============================================================================
        31. LOOP TERMINATION VS FUNCTION TERMINATION
    ============================================================================

    Very important distinction.


    When the for-loop condition becomes false:

        the LOOP ends.


    Example:

        for (int i = 2; i < 3; i++)


    When:

        i = 3


    condition:

        3 < 3

    becomes false.


    Therefore:

        loop ends


    But the FUNCTION does NOT necessarily end.


    Execution continues to the next statement:

        return true;


    However, if we execute:

        return false;


    inside the loop, then:

        the function ends immediately.


    This distinction is extremely important.


    ============================================================================
        32. EXAMPLE — num = 3
    ============================================================================

        isPrime(3)

        num = 3

        i = 2

        2 < 3 → true

        3 % 2 = 1

        1 == 0 → false

        no return false

        i++

        i = 3

        3 < 3 → false

        loop ends

        return true


    Result:

        true


    ============================================================================
        33. EXAMPLE — num = 4
    ============================================================================

        isPrime(4)

        num = 4

        i = 2

        2 < 4 → true

        4 % 2 = 0

        0 == 0 → true

        return false


    Function immediately ends.


    It does NOT continue to:

        i = 3


    It does NOT check:

        4 % 3


    It does NOT reach:

        return true


    Result:

        false


    ============================================================================
        34. EXAMPLE — num = 5
    ============================================================================

        isPrime(5)

        i = 2:

            5 % 2 = 1


        i = 3:

            5 % 3 = 2


        i = 4:

            5 % 4 = 1


        i = 5:

            5 < 5 → false


        Loop ends.


        No divisor found.


        return true


    Result:

        true


    ============================================================================
        35. COMPLETE LOGIC FLOW
    ============================================================================


                     n
                     |
                     v
             Start count = 0
                     |
                     v
             i = 2 to n-1
                     |
                     v
                isPrime(i)
                     |
              +------+------+
              |             |
            false          true
              |             |
              |          count++
              |             |
              +------+------+
                     |
                     v
              next number
                     |
                     v
             loop finished?
                     |
                    YES
                     |
                     v
               return count


    ============================================================================
        36. LEETCODE VERSION
    ============================================================================

    On LeetCode, you normally submit:

*/

class Solution
{
public:
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
};

/*
    ============================================================================
        37. LEETCODE EXAMPLE
    ============================================================================

    Input:

        n = 10


    Output:

        4


    Explanation:

        There are four prime numbers less than 10:

            2
            3
            5
            7


    ============================================================================
        38. FINAL REVISION
    ============================================================================

    BASIC BRUTE FORCE:

        bool isPrime(int num)
        {
            if (num < 2)
                return false;

            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                    return false;
            }

            return true;
        }


        int countPrimes(int n)
        {
            int count = 0;

            for (int i = 2; i < n; i++)
            {
                if (isPrime(i))
                    count++;
            }

            return count;
        }


    Remember:

        1. Start checking from 2.

        2. Do not check n because the problem asks for numbers
           strictly less than n.

        3. In isPrime(), start divisor checking from 2.

        4. Do not check num itself.

        5. If a divisor is found:
               return false immediately.

        6. If the complete loop finishes:
               return true.

        7. Basic brute-force complexity:
               O(N²)

        8. Auxiliary space:
               O(1)


    ============================================================================
        39. ONE-LINE MEMORY TRICK
    ============================================================================

        "Find one divisor → false immediately.
         Find no divisor → true after the loop."


    ============================================================================
        END OF BASIC BRUTE FORCE APPROACH
        LEETCODE 204 — COUNT PRIMES
    ============================================================================
*/