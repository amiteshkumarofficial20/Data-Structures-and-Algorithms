/*
    ============================================================================
        FACTORIAL OF A NUMBER — ITERATIVE APPROACH
    ============================================================================

    Method Name:
        Iterative Factorial Method
        Loop-Based Factorial Method
        Repeated Multiplication Method

    Platforms:
        GeeksforGeeks (GFG)
        Naukri (Code360)
        HackerEarth
        CodeChef

    Core idea:

        The factorial of a non-negative integer N is:

            N! = N * (N - 1) * (N - 2) * ... * 2 * 1

        Instead of using recursion, the iterative approach uses a loop
        and repeatedly multiplies the current result by the next integer.

    Example:

        5!

        = 5 * 4 * 3 * 2 * 1
        = 120

    Most important special case:

        0! = 1

    Why?

        0! is mathematically defined as 1.

    This file contains:

        1. Complete iterative approach
        2. Detailed explanation of every variable
        3. Detailed explanation of the loop
        4. Why the answer starts from 1
        5. Why the loop starts from 1
        6. Detailed dry runs
        7. Multiplication identity explanation
        8. Zero case
        9. One case
       10. Overflow discussion
       11. Data-type discussion
       12. Time complexity
       13. Space complexity
       14. Iterative vs recursive comparison
       15. Common mistakes
       16. Boundary cases
       17. Big-integer considerations
       18. Mathematical interpretation
       19. Quick revision section

    Complexity of the basic iterative approach:

        Time  = O(n)
        Space = O(1)

    Important limitation:

        Factorial grows extremely quickly.

        For signed 64-bit long long:

            20! fits

        but:

            21! does NOT fit

        Therefore, the allowed input range must match the selected
        data type.
*/

#include <iostream>
using namespace std;

// ============================================================================
// 1. ITERATIVE FACTORIAL APPROACH
// ============================================================================

int main()
{
    int number;

    cout << "Enter a Number: ";
    cin >> number;

    // ------------------------------------------------------------------------
    // STEP 1: Handle the input conceptually
    // ------------------------------------------------------------------------
    //
    // Factorial is normally defined for NON-NEGATIVE integers:
    //
    //      0, 1, 2, 3, 4, ...
    //
    // A negative integer does not have a factorial in the basic definition
    // used in this problem.
    //
    // Therefore we check for a negative input.
    if (number < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    // ------------------------------------------------------------------------
    // STEP 2: Create the variable that stores the answer
    // ------------------------------------------------------------------------
    //
    // 'ans' stores the factorial calculated so far.
    //
    // IMPORTANT:
    //
    // We start with:
    //
    //      ans = 1
    //
    // NOT:
    //
    //      ans = 0
    //
    // Why?
    //
    // Because multiplication has the identity value:
    //
    //      1
    //
    // Any number multiplied by 1 remains unchanged:
    //
    //      5 * 1 = 5
    //      10 * 1 = 10
    //
    // If we started with 0:
    //
    //      0 * anything = 0
    //
    // and the answer would always remain zero.
    //
    // So:
    //
    //      int ans = 1;
    //
    // is the correct starting point.
    long long ans = 1;

    // ------------------------------------------------------------------------
    // STEP 3: Repeat multiplication using a loop
    // ------------------------------------------------------------------------
    //
    // We need:
    //
    //      1 * 2 * 3 * ... * number
    //
    // Therefore we process every integer from:
    //
    //      1 -> number
    //
    // For example, if number = 5:
    //
    //      i = 1
    //      i = 2
    //      i = 3
    //      i = 4
    //      i = 5
    //
    // At every iteration:
    //
    //      ans *= i;
    //
    // updates the factorial calculated so far.
    for (int i = 1; i <= number; i++)
    {
        // --------------------------------------------------------------------
        // STEP 4: Multiply the current answer by i
        // --------------------------------------------------------------------
        //
        // The expression:
        //
        //      ans *= i;
        //
        // is shorthand for:
        //
        //      ans = ans * i;
        //
        // Example:
        //
        //      ans = 6
        //      i   = 4
        //
        // Then:
        //
        //      ans = 6 * 4
        //          = 24
        //
        // This means we have now calculated:
        //
        //      4!
        //
        ans *= i;
    }

    // ------------------------------------------------------------------------
    // STEP 5: Print the final factorial
    // ------------------------------------------------------------------------
    //
    // After the loop finishes:
    //
    //      ans = number!
    //
    // Example:
    //
    //      number = 5
    //
    // Final:
    //
    //      ans = 120
    cout << "Factorial: " << ans << endl;

    return 0;
}

/*
    ============================================================================
    2. WHAT IS FACTORIAL?
    ============================================================================

    The factorial of a non-negative integer N is written as:

        N!

    and is defined as:

        N! = N * (N - 1) * (N - 2) * ... * 3 * 2 * 1


    Examples:

        1! = 1

        2! = 2 * 1
           = 2

        3! = 3 * 2 * 1
           = 6

        4! = 4 * 3 * 2 * 1
           = 24

        5! = 5 * 4 * 3 * 2 * 1
           = 120


    ============================================================================
    3. THE MOST IMPORTANT SPECIAL CASE — 0!
    ============================================================================

    By mathematical definition:

        0! = 1


    This is extremely important.

    Example:

        Input:
            0

        Output:
            1


    In our iterative code:

        ans = 1;

        for (int i = 1; i <= number; i++)

    If:

        number = 0

    then the condition:

        i <= number

    becomes:

        1 <= 0

    which is false.

    Therefore the loop executes ZERO times.

    The initial value:

        ans = 1

    remains unchanged.

    Final:

        ans = 1

    Therefore:

        0! = 1


    ============================================================================
    4. WHY ans STARTS FROM 1
    ============================================================================

    This is one of the most important concepts in the iterative solution.

    We are repeatedly performing MULTIPLICATION.

    The identity element for multiplication is:

        1


    Because:

        x * 1 = x

    for every number x.


    Suppose:

        ans = 1

    and:

        i = 2

    Then:

        ans = 1 * 2
            = 2


    Next:

        ans = 2 * 3
            = 6


    Next:

        ans = 6 * 4
            = 24


    Therefore starting with 1 allows us to build the product correctly.


    ============================================================================
    5. WHY ans = 0 WOULD BE WRONG
    ============================================================================

    Suppose we incorrectly write:

        long long ans = 0;


    Then:

        ans *= 1;

    gives:

        0 * 1 = 0


    Next:

        ans *= 2;

    gives:

        0 * 2 = 0


    Next:

        ans *= 3;

    gives:

        0 * 3 = 0


    The answer will ALWAYS remain:

        0


    Therefore:

        ans = 0

    is incorrect for a multiplication-based factorial loop.


    ============================================================================
    6. WHY THE LOOP STARTS FROM 1
    ============================================================================

    Factorial is:

        N * (N-1) * ... * 2 * 1


    We can multiply the same terms in the opposite order:

        1 * 2 * 3 * ... * N


    Multiplication is commutative, so:

        1 * 2 * 3 * 4 * 5

    gives the same result as:

        5 * 4 * 3 * 2 * 1


    Therefore:

        for (int i = 1; i <= number; i++)

    is a natural iterative representation of factorial.


    ============================================================================
    7. WHY THE LOOP CONDITION IS i <= number
    ============================================================================

    We need to multiply by every number from:

        1

    through:

        number


    Therefore the last multiplication must happen when:

        i == number


    If number = 5:

        i = 1
        i = 2
        i = 3
        i = 4
        i = 5


    Therefore the condition is:

        i <= number


    If we incorrectly use:

        i < number

    then 5 would never be multiplied.

    That would calculate:

        1 * 2 * 3 * 4

    instead of:

        1 * 2 * 3 * 4 * 5


    ============================================================================
    8. DRY RUN FOR number = 5
    ============================================================================

    Input:

        5


    Initial state:

        number = 5
        ans    = 1


    ------------------------------------------------------------------------
    Iteration 1
    ------------------------------------------------------------------------

        i = 1

        ans = 1 * 1
            = 1


    State:

        ans = 1


    ------------------------------------------------------------------------
    Iteration 2
    ------------------------------------------------------------------------

        i = 2

        ans = 1 * 2
            = 2


    State:

        ans = 2


    ------------------------------------------------------------------------
    Iteration 3
    ------------------------------------------------------------------------

        i = 3

        ans = 2 * 3
            = 6


    State:

        ans = 6


    ------------------------------------------------------------------------
    Iteration 4
    ------------------------------------------------------------------------

        i = 4

        ans = 6 * 4
            = 24


    State:

        ans = 24


    ------------------------------------------------------------------------
    Iteration 5
    ------------------------------------------------------------------------

        i = 5

        ans = 24 * 5
            = 120


    Final state:

        ans = 120


    Therefore:

        5! = 120


    ============================================================================
    9. DRY RUN TABLE FOR 5!
    ============================================================================

        i       ans before       Calculation       ans after

        1            1            1 * 1                1
        2            1            1 * 2                2
        3            2            2 * 3                6
        4            6            6 * 4               24
        5           24           24 * 5              120


    Final:

        ans = 120


    ============================================================================
    10. DRY RUN FOR number = 3
    ============================================================================

    Input:

        3


    Initial:

        ans = 1


    i = 1:

        ans = 1 * 1
            = 1


    i = 2:

        ans = 1 * 2
            = 2


    i = 3:

        ans = 2 * 3
            = 6


    Final:

        3! = 6


    ============================================================================
    11. DRY RUN FOR number = 0
    ============================================================================

    Input:

        0


    Initial:

        ans = 1


    Loop:

        for (int i = 1; i <= 0; i++)

    First condition:

        1 <= 0

    This is false.

    Therefore:

        loop iterations = 0


    Final:

        ans = 1


    Therefore:

        0! = 1


    ============================================================================
    12. ITERATIVE APPROACH — CORE FORM
    ============================================================================

    The essential iterative logic is:

        ans = 1;

        for (int i = 1; i <= number; i++)
        {
            ans *= i;
        }


    Think of it as:

        Start with 1
            ↓
        multiply by 1
            ↓
        multiply by 2
            ↓
        multiply by 3
            ↓
        ...
            ↓
        multiply by N


    Final result:

        N!


    ============================================================================
    13. WHAT DOES ans *= i MEAN?
    ============================================================================

    This:

        ans *= i;

    is shorthand for:

        ans = ans * i;


    Example:

        ans = 6;
        i = 4;


    Then:

        ans *= i;


    means:

        ans = 6 * 4;

    resulting in:

        ans = 24;


    ============================================================================
    14. WHY THIS IS CALLED AN ITERATIVE APPROACH
    ============================================================================

    "Iterative" means that we repeatedly execute a block of instructions,
    usually using a loop.

    Here:

        for (...)

    repeatedly performs:

        ans *= i;


    We do not call the function itself.

    Therefore this is:

        Iterative Factorial


    A recursive approach would use a function calling itself.

    That is a different implementation technique.


    ============================================================================
    15. ITERATION VS RECURSION
    ============================================================================

    ITERATIVE APPROACH:

        Uses a loop.

        Concept:

            result = 1

            repeat:
                result *= i


    RECURSIVE APPROACH:

        Uses a function that calls itself.

        Mathematical relationship:

            N! = N * (N-1)!

        with:

            0! = 1


    For the basic factorial problem:

        Iterative Time:
            O(N)

        Iterative Auxiliary Space:
            O(1)


        Recursive Time:
            O(N)

        Recursive Call-Stack Space:
            O(N)


    The iterative version therefore avoids recursion-stack growth.


    ============================================================================
    16. TIME COMPLEXITY
    ============================================================================

    Suppose:

        number = N


    The loop executes for:

        1
        2
        3
        ...
        N


    Therefore the number of iterations is:

        N


    Each iteration performs a constant amount of work:

        multiplication
        assignment


    Therefore:

        Time Complexity = O(N)


    More formally:

        T(N) = c * N + constant

    which simplifies to:

        O(N)


    ============================================================================
    17. SPACE COMPLEXITY
    ============================================================================

    The iterative solution uses a fixed number of variables:

        number
        ans
        i


    No:

        vector
        array
        stack
        recursion
        dynamically growing container

    is required.


    Therefore:

        Auxiliary Space = O(1)


    Important distinction:

        The factorial RESULT can contain many digits for large N.

    If arbitrary-precision arithmetic is used, the storage required
    for the result itself grows with the number of digits.

    But for the basic fixed-width integer implementation:

        Auxiliary Space = O(1)


    ============================================================================
    18. INTEGER OVERFLOW
    ============================================================================

    Factorial grows very quickly.

    Some values:

        5!  = 120

        10! = 3628800

        15! = 1307674368000

        20! = 2432902008176640000

        21! = 51090942171709440000


    A signed 64-bit long long can store values only up to approximately:

        9.22 × 10^18


    Therefore:

        20!

    fits in signed long long.


    But:

        21!

    does NOT fit.


    Therefore if the problem says:

        0 <= N <= 20

    then:

        long long

    is sufficient for the result.


    If N is larger, you need a suitable big-integer/arbitrary-precision
    strategy depending on the problem constraints.


    ============================================================================
    19. WHY int MAY NOT BE ENOUGH
    ============================================================================

    A normal 32-bit signed int can store values only up to approximately:

        2,147,483,647


    But:

        13! = 6227020800


    which is already larger than that limit.


    Therefore this would be unsafe for sufficiently large N:

        int ans;


    Using:

        long long ans;

    extends the range considerably.


    But even long long has a limit, as explained above.


    ============================================================================
    20. DATA TYPE CONSIDERATION
    ============================================================================

    For the common constraint:

        0 <= N <= 20

    use:

        long long


    because:

        20!

    fits inside signed 64-bit integer range.


    For:

        N > 20

    you must check whether the factorial result fits in the selected
    data type.


    For very large N:

        100!
        500!
        1000!
        10000!

    a fixed-width integer is not sufficient.


    ============================================================================
    21. NEGATIVE INPUT
    ============================================================================

    Basic factorial is defined for:

        0, 1, 2, 3, ...


    It is not defined for negative integers in the ordinary factorial
    problem.


    Therefore the program checks:

        if (number < 0)


    and reports that factorial is not defined for negative numbers.


    If the platform guarantees:

        N >= 0

    then this validation may not be required.


    ============================================================================
    22. FACTORIAL AS A PRODUCT
    ============================================================================

    Factorial can be understood as a product:

        N! = 1 * 2 * 3 * ... * N


    This makes it naturally suitable for an iterative loop.


    Compare:

        Sum from 1 to N:

            1 + 2 + 3 + ... + N


    Factorial:

            1 * 2 * 3 * ... * N


    The operator is different, but both can be computed iteratively.


    ============================================================================
    23. MATHEMATICAL IDENTITY
    ============================================================================

    The multiplication identity is:

        1


    because:

        x * 1 = x


    This is why factorial accumulation starts with:

        ans = 1


    Similarly, the addition identity is:

        0


    because:

        x + 0 = x


    This distinction is useful when designing iterative algorithms.


    ============================================================================
    24. ALTERNATIVE LOOP DIRECTION
    ============================================================================

    Factorial can also be accumulated from N downward:

        N
        N-1
        N-2
        ...
        1


    Conceptually:

        ans = 1

        multiply by N
        multiply by N-1
        multiply by N-2
        ...
        multiply by 1


    This produces the same mathematical result because multiplication
    is commutative.

    The current file uses:

        1 -> N


    because it is straightforward and naturally handles:

        0! = 1


    ============================================================================
    25. COMMON MISTAKE #1 — STARTING ans FROM 0
    ============================================================================

    Wrong:

        long long ans = 0;


    Then:

        ans *= i;


    always remains:

        0


    Correct:

        long long ans = 1;


    because 1 is the multiplicative identity.


    ============================================================================
    26. COMMON MISTAKE #2 — USING i < number
    ============================================================================

    Wrong:

        for (int i = 1; i < number; i++)


    For:

        number = 5


    this processes:

        1
        2
        3
        4


    but skips:

        5


    So it calculates:

        4!

    instead of:

        5!


    Correct:

        i <= number


    ============================================================================
    27. COMMON MISTAKE #3 — FORGETTING 0!
    ============================================================================

    Some implementations explicitly handle:

        number == 0


    Others naturally handle it by starting:

        ans = 1

    and using:

        for (i = 1; i <= number; i++)


    For:

        number = 0


    the loop does not execute and the result remains:

        1


    This naturally gives:

        0! = 1


    ============================================================================
    28. COMMON MISTAKE #4 — USING int FOR LARGE FACTORIALS
    ============================================================================

    Example:

        13! = 6227020800


    This is greater than:

        2147483647


    Therefore a 32-bit signed int cannot store it.


    Always compare the problem's constraints with the capacity of
    the selected data type.


    ============================================================================
    29. COMMON MISTAKE #5 — IGNORING OVERFLOW
    ============================================================================

    A program may compile successfully and still produce an incorrect
    factorial because of integer overflow.

    Example:

        long long

    is not infinite precision.

    It has a fixed maximum value.

    Therefore:

        datatype selection

    is part of solving the problem correctly.


    ============================================================================
    30. EDGE CASES
    ============================================================================

    Important test cases:

        0
        1
        2
        3
        4
        5
        10
        20


    Expected results:

        0!  = 1

        1!  = 1

        2!  = 2

        3!  = 6

        4!  = 24

        5!  = 120

        10! = 3628800

        20! = 2432902008176640000


    ============================================================================
    31. INPUT = 1
    ============================================================================

    Input:

        1


    Initial:

        ans = 1


    Loop:

        i = 1


    Calculation:

        ans = 1 * 1
            = 1


    Final:

        1! = 1


    ============================================================================
    32. INPUT = 2
    ============================================================================

    Input:

        2


    Initial:

        ans = 1


    i = 1:

        ans = 1


    i = 2:

        ans = 1 * 2
            = 2


    Final:

        2! = 2


    ============================================================================
    33. INPUT = 10
    ============================================================================

    The iterative accumulation is:

        1
        1 * 2
        1 * 2 * 3
        1 * 2 * 3 * 4
        ...
        1 * 2 * 3 * ... * 10


    Final:

        10! = 3628800


    ============================================================================
    34. FACTORIAL GROWTH
    ============================================================================

    Factorial grows much faster than ordinary polynomial expressions.

    Example:

        1!  = 1

        2!  = 2

        3!  = 6

        4!  = 24

        5!  = 120

        6!  = 720

        7!  = 5040

        8!  = 40320

        9!  = 362880

        10! = 3628800


    Every time N increases by 1:

        (N+1)! = (N+1) * N!


    This is why factorial values become enormous very quickly.


    ============================================================================
    35. IMPORTANT RELATIONSHIP
    ============================================================================

    The factorial recurrence is:

        N! = N * (N-1)!


    Example:

        5! = 5 * 4!

        4! = 4 * 3!

    Therefore:

        5! = 5 * 4 * 3 * 2 * 1


    This mathematical relationship is useful for understanding the
    recursive version.

    The iterative version avoids making recursive function calls and
    instead performs the same multiplication through a loop.


    ============================================================================
    36. ITERATIVE APPROACH IN ONE VIEW
    ============================================================================

        Input:
            N

        Start:
            ans = 1

        Repeat:
            i = 1 to N

        Operation:
            ans = ans * i

        Final:
            ans = N!


    Example:

        N = 5

        ans = 1

        ans = 1 * 1 = 1
        ans = 1 * 2 = 2
        ans = 2 * 3 = 6
        ans = 6 * 4 = 24
        ans = 24 * 5 = 120


    ============================================================================
    37. GENERAL ITERATIVE PRODUCT PATTERN
    ============================================================================

    Factorial is one example of a broader pattern:

        Initialize an accumulator with the multiplicative identity:

            ans = 1

        Iterate through the required values:

            for (...)

        Multiply the accumulator:

            ans *= value;


    This same pattern appears in many product-based problems.


    ============================================================================
    38. WHY NO EXTRA CONTAINER IS NEEDED
    ============================================================================

    We do NOT need:

        vector<int>
        array
        stack
        queue
        string

    to calculate the basic factorial.

    We only need:

        current number
        current loop variable
        current product


    Therefore the iterative approach is memory-efficient.


    ============================================================================
    39. PLATFORM CONSTRAINT NOTE
    ============================================================================

    This educational file assumes the basic version where the factorial
    result fits in long long:

        0 <= N <= 20


    However, platforms may provide different constraints.

    Common practice platforms include:

        GeeksforGeeks (GFG)
        Naukri (Code360)
        HackerEarth
        CodeChef


    Always read the exact problem statement because:

        input range
        output format
        number of test cases
        required data type
        modulo requirement

    can differ between problems.


    ============================================================================
    40. IF THE PLATFORM ASKS FOR FACTORIAL MODULO M
    ============================================================================

    Some advanced problems do NOT ask for the complete factorial.

    They may ask for:

        N! % M


    In such a problem, the requirements and algorithm are different.

    Do not assume that the basic factorial implementation is sufficient
    for extremely large N.


    ============================================================================
    41. BIG-INTEGER FACTORIAL
    ============================================================================

    Consider:

        100!

    Its value contains far more digits than fit in:

        int

    or:

        long long


    For such problems, an arbitrary-precision representation is required.

    The exact implementation depends on the platform and allowed
    libraries.

    The basic iterative idea remains:

        repeatedly multiply by the next integer

    but the representation of 'ans' must support arbitrarily large
    numbers.


    ============================================================================
    42. INTERVIEW EXPECTATIONS
    ============================================================================

    If asked to implement factorial iteratively, be prepared to explain:

        1. What factorial means.

        2. Why:
               0! = 1

        3. Why:
               ans = 1

        4. Why the loop runs:
               1 through N

        5. Why the complexity is:
               O(N)

        6. Why auxiliary space is:
               O(1)

        7. Why factorial can overflow quickly.

        8. Why long long is sufficient only up to:
               20!

           for a signed 64-bit result.

        9. How the solution changes for very large factorials.

       10. Difference between iterative and recursive implementations.


    ============================================================================
    43. QUICK CHEAT SHEET
    ============================================================================

    Problem:

        Factorial of a Number


    Mathematical definition:

        N! = N * (N-1) * ... * 2 * 1


    Special case:

        0! = 1


    Initial answer:

        ans = 1


    Loop:

        for (int i = 1; i <= number; i++)


    Update:

        ans *= i;


    Equivalent:

        ans = ans * i;


    Iterative Time:

        O(N)


    Iterative Auxiliary Space:

        O(1)


    Signed long long:

        20! fits

        21! does not fit


    Negative N:

        Not defined in the basic factorial problem.


    ============================================================================
    44. FINAL CONCEPT
    ============================================================================

    The most important pattern in the iterative factorial approach is:

        ans = 1;

        for (int i = 1; i <= number; i++)
        {
            ans *= i;
        }


    Think of it as:

        START
          |
          v
        ans = 1
          |
          v
        multiply by 1
          |
          v
        multiply by 2
          |
          v
        multiply by 3
          |
          v
        ...
          |
          v
        multiply by N
          |
          v
        FINAL ANSWER = N!


    The three ideas to remember are:

        1. Start the product from 1.
        2. Multiply every integer from 1 to N.
        3. Remember that factorial grows very quickly and can overflow.


    ============================================================================
    END
    ============================================================================
*/