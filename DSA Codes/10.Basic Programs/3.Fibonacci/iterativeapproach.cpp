/*
    ============================================================================
        FIBONACCI NUMBER — ITERATIVE APPROACH
    ============================================================================

    Reference style:
        This file follows the detailed, concept-first structure of the
        provided reference file:
            - Method name
            - Core idea
            - Complete C++ code
            - Detailed comments
            - Step-by-step explanation
            - Dry runs
            - Important concepts
            - Complexity
            - Edge cases
            - Limitations
            - Related variations
            - Interview expectations
            - Quick revision section

    Method Name:
        Iterative Fibonacci Method
        Loop-Based Fibonacci Method
        Bottom-Up Fibonacci Method
        Constant-Space Fibonacci Method

    Platforms:
        LeetCode
        GeeksforGeeks (GFG)

    Core idea:

        The Fibonacci sequence is defined as:

            F(0) = 0
            F(1) = 1

        For N >= 2:

            F(N) = F(N - 1) + F(N - 2)

        The iterative approach calculates Fibonacci numbers from left to
        right using a loop.

        We only need the PREVIOUS TWO Fibonacci values to calculate the
        NEXT value.

    Example:

        Fibonacci sequence:

            Index:  0  1  2  3  4  5  6  7  8
            Value:  0  1  1  2  3  5  8 13 21

        Therefore:

            F(5) = 5

    Important special cases:

        F(0) = 0
        F(1) = 1

    Complexity:

        Time  = O(N)
        Space = O(1)

    Important limitation:

        Fibonacci numbers grow very quickly.

        The data type must be large enough for the required result.

        For signed 64-bit long long:

            F(92) fits

        but:

            F(93) does NOT fit

        Therefore, the allowed input range must be considered together
        with the selected data type.

    This file contains:

        1. Complete iterative approach
        2. Detailed explanation of every variable
        3. Why first = 0
        4. Why second = 1
        5. Why the loop starts from 2
        6. Why the loop uses i <= number
        7. Why we need only two previous values
        8. Detailed dry runs
        9. Dry-run tables
       10. Special cases N = 0 and N = 1
       11. Meaning of next
       12. Variable update order
       13. Time complexity
       14. Space complexity
       15. Overflow discussion
       16. Data-type discussion
       17. Iterative vs recursive comparison
       18. Common mistakes
       19. Edge cases
       20. Interview expectations
       21. Platform notes
       22. Related variations
       23. Quick revision section
*/

#include <iostream>
using namespace std;

// ============================================================================
// 1. ITERATIVE FIBONACCI APPROACH
// ============================================================================

int main()
{
    long long number;

    cout << "Enter a Number: ";
    cin >> number;

    // ------------------------------------------------------------------------
    // STEP 1: Validate the input
    // ------------------------------------------------------------------------
    //
    // The standard Fibonacci problem uses a NON-NEGATIVE index:
    //
    //      0, 1, 2, 3, 4, ...
    //
    // Therefore a negative index is not accepted in this basic version.
    if (number < 0)
    {
        cout << "Fibonacci is not defined for negative index in this "
                "basic version."
             << endl;

        return 0;
    }

    // ------------------------------------------------------------------------
    // STEP 2: Handle the first base case
    // ------------------------------------------------------------------------
    //
    // By definition:
    //
    //      F(0) = 0
    //
    // Therefore if the user asks for Fibonacci number at index 0,
    // the answer is immediately 0.
    if (number == 0)
    {
        cout << "Fibonacci Number: 0" << endl;
        return 0;
    }

    // ------------------------------------------------------------------------
    // STEP 3: Handle the second base case
    // ------------------------------------------------------------------------
    //
    // By definition:
    //
    //      F(1) = 1
    //
    // Therefore if number is 1, the answer is immediately 1.
    if (number == 1)
    {
        cout << "Fibonacci Number: 1" << endl;
        return 0;
    }

    // ------------------------------------------------------------------------
    // STEP 4: Store the previous two Fibonacci values
    // ------------------------------------------------------------------------
    //
    // The Fibonacci sequence begins:
    //
    //      F(0) = 0
    //      F(1) = 1
    //
    // Therefore:
    //
    //      first  = F(0) = 0
    //      second = F(1) = 1
    //
    // We do NOT need an entire array/vector because the next Fibonacci
    // number depends only on the previous two values.
    long long first = 0;
    long long second = 1;

    // ------------------------------------------------------------------------
    // STEP 5: Generate Fibonacci numbers from index 2 to number
    // ------------------------------------------------------------------------
    //
    // We already know:
    //
    //      F(0)
    //      F(1)
    //
    // So the first value that needs to be calculated is:
    //
    //      F(2)
    //
    // Therefore the loop starts from:
    //
    //      i = 2
    //
    // and continues until:
    //
    //      i <= number
    for (long long i = 2; i <= number; i++)
    {
        // --------------------------------------------------------------------
        // STEP 6: Calculate the next Fibonacci number
        // --------------------------------------------------------------------
        //
        // Fibonacci definition:
        //
        //      F(i) = F(i - 1) + F(i - 2)
        //
        // In our variables:
        //
        //      first  = older Fibonacci value
        //      second = immediately previous Fibonacci value
        //
        // Therefore:
        //
        //      next = first + second
        //
        // Example:
        //
        //      first  = 1
        //      second = 2
        //
        // Then:
        //
        //      next = 1 + 2
        //           = 3
        long long next = first + second;

        // --------------------------------------------------------------------
        // STEP 7: Move the two variables forward
        // --------------------------------------------------------------------
        //
        // After calculating:
        //
        //      next
        //
        // we need to move the Fibonacci window forward.
        //
        // Old state:
        //
        //      first  = F(i - 2)
        //      second = F(i - 1)
        //
        // New state should be:
        //
        //      first  = F(i - 1)
        //      second = F(i)
        //
        // Therefore:
        //
        //      first = second;
        //      second = next;
        //
        // The ORDER matters.
        first = second;
        second = next;
    }

    // ------------------------------------------------------------------------
    // STEP 8: Print the answer
    // ------------------------------------------------------------------------
    //
    // After the loop finishes:
    //
    //      second = F(number)
    //
    // Therefore second contains the required Fibonacci number.
    cout << "Fibonacci Number: " << second << endl;

    return 0;
}

/*
    ============================================================================
    2. WHAT IS THE FIBONACCI SEQUENCE?
    ============================================================================

    Fibonacci is a sequence in which every number after the first two
    numbers is the sum of the previous two numbers.

    The standard zero-based definition is:

        F(0) = 0
        F(1) = 1


    For every N >= 2:

        F(N) = F(N - 1) + F(N - 2)


    The sequence is:

        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...


    With indices:

        Index:  0  1  2  3  4  5  6   7   8   9   10
        Value:  0  1  1  2  3  5  8  13  21  34   55


    Therefore:

        F(0) = 0
        F(1) = 1
        F(2) = 1
        F(3) = 2
        F(4) = 3
        F(5) = 5


    ============================================================================
    3. WHAT DOES THE PROBLEM ASK?
    ============================================================================

    Given:

        N


    we need to find:

        F(N)


    Example:

        N = 5


    Then:

        F(5) = 5


    because:

        0, 1, 1, 2, 3, 5


    ============================================================================
    4. WHY THIS IS CALLED AN ITERATIVE APPROACH
    ============================================================================

    "Iterative" means that we repeatedly execute a set of instructions,
    usually using a loop.

    In this approach we use:

        for (...)


    instead of:

        a recursive function calling itself.


    We calculate the sequence from smaller indices toward the requested
    index.

    Therefore this is:

        Iterative Fibonacci
        Loop-Based Fibonacci


    ============================================================================
    5. THE TWO BASE VALUES
    ============================================================================

    Fibonacci starts with two known values:

        F(0) = 0
        F(1) = 1


    These are the starting values from which all later values are generated.


    Example:

        F(2)
        = F(1) + F(0)
        = 1 + 0
        = 1


        F(3)
        = F(2) + F(1)
        = 1 + 1
        = 2


        F(4)
        = F(3) + F(2)
        = 2 + 1
        = 3


    ============================================================================
    6. WHY first = 0?
    ============================================================================

    We declare:

        long long first = 0;


    because:

        first = F(0)


    The first variable represents the OLDER of the two Fibonacci values
    currently being used.


    Initially:

        first = F(0) = 0


    ============================================================================
    7. WHY second = 1?
    ============================================================================

    We declare:

        long long second = 1;


    because:

        second = F(1)


    Therefore initially:

        first  = F(0) = 0
        second = F(1) = 1


    These are exactly the two values required to calculate F(2).


    ============================================================================
    8. WHY DO WE START THE LOOP FROM 2?
    ============================================================================

    We already know:

        F(0) = 0
        F(1) = 1


    So there is no need to calculate them again.

    The first unknown Fibonacci value is:

        F(2)


    Therefore:

        for (long long i = 2; ...)


    is the natural starting point.


    ============================================================================
    9. WHY IS THE LOOP CONDITION i <= number?
    ============================================================================

    We need to calculate Fibonacci values up to:

        F(number)


    If:

        number = 5


    then we need:

        F(2)
        F(3)
        F(4)
        F(5)


    Therefore the final iteration must occur when:

        i == number


    Hence:

        i <= number


    If we used:

        i < number


    then F(number) would not be calculated.


    ============================================================================
    10. WHAT DOES next REPRESENT?
    ============================================================================

    We calculate:

        long long next = first + second;


    The variable:

        next


    represents the next Fibonacci number.

    If:

        first  = F(i - 2)
        second = F(i - 1)


    then:

        next = F(i)


    because:

        F(i) = F(i - 1) + F(i - 2)


    ============================================================================
    11. THE MOST IMPORTANT UPDATE
    ============================================================================

    After calculating:

        next = first + second;


    we execute:

        first = second;
        second = next;


    Before the update:

        first  = older value
        second = newer value


    After the update:

        first  = old second
        second = new next


    This moves our two-value window one position forward.


    ============================================================================
    12. WHY UPDATE ORDER MATTERS
    ============================================================================

    Correct:

        first = second;
        second = next;


    We already saved the new value inside:

        next


    Therefore the old second value can safely move into first.


    The temporary variable:

        next


    is important because it stores the newly calculated Fibonacci number
    before the old variables are updated.


    ============================================================================
    13. WHAT IF WE DID NOT USE next?
    ============================================================================

    Consider:

        first = second;
        second = first + second;


    This particular ordering can still be made to work because second is
    calculated using the newly assigned first, but it changes the meaning
    of the expressions and is easy to misunderstand.

    The explicit:

        next

    variable is clearer for learning because it directly represents:

        F(i)


    and makes the state transition easy to follow.


    ============================================================================
    14. DETAILED DRY RUN FOR N = 5
    ============================================================================

    Input:

        5


    Initial state:

        first  = 0
        second = 1


    These represent:

        first  = F(0)
        second = F(1)


    ------------------------------------------------------------------------
    ITERATION 1
    ------------------------------------------------------------------------

        i = 2


    Calculate:

        next = first + second
             = 0 + 1
             = 1


    Update:

        first = second
              = 1

        second = next
               = 1


    State now:

        first  = 1
        second = 1


    Meaning:

        first  = F(1)
        second = F(2)


    ------------------------------------------------------------------------
    ITERATION 2
    ------------------------------------------------------------------------

        i = 3


    Calculate:

        next = 1 + 1
             = 2


    Update:

        first = 1
        second = 2


    Meaning:

        first  = F(2)
        second = F(3)


    ------------------------------------------------------------------------
    ITERATION 3
    ------------------------------------------------------------------------

        i = 4


    Calculate:

        next = 1 + 2
             = 3


    Update:

        first = 2
        second = 3


    Meaning:

        first  = F(3)
        second = F(4)


    ------------------------------------------------------------------------
    ITERATION 4
    ------------------------------------------------------------------------

        i = 5


    Calculate:

        next = 2 + 3
             = 5


    Update:

        first = 3
        second = 5


    Meaning:

        first  = F(4)
        second = F(5)


    Loop ends because:

        i <= number

    is now false after i becomes 6.


    Final:

        second = 5


    Therefore:

        F(5) = 5


    ============================================================================
    15. DRY RUN TABLE FOR N = 5
    ============================================================================

        i    first    second    next = first + second    new first    new second

        2      0         1              1                    1            1
        3      1         1              2                    1            2
        4      1         2              3                    2            3
        5      2         3              5                    3            5


    Final:

        second = 5


    Therefore:

        F(5) = 5


    ============================================================================
    16. DRY RUN FOR N = 6
    ============================================================================

    Initial:

        first  = 0
        second = 1


    i = 2:

        next = 0 + 1 = 1

        first  = 1
        second = 1


    i = 3:

        next = 1 + 1 = 2

        first  = 1
        second = 2


    i = 4:

        next = 1 + 2 = 3

        first  = 2
        second = 3


    i = 5:

        next = 2 + 3 = 5

        first  = 3
        second = 5


    i = 6:

        next = 3 + 5 = 8

        first  = 5
        second = 8


    Final:

        F(6) = 8


    ============================================================================
    17. DRY RUN FOR N = 0
    ============================================================================

    Input:

        0


    The program checks:

        number == 0


    This is true.

    By definition:

        F(0) = 0


    Therefore output:

        0


    The loop is never required.


    ============================================================================
    18. DRY RUN FOR N = 1
    ============================================================================

    Input:

        1


    The program checks:

        number == 1


    This is true.

    By definition:

        F(1) = 1


    Therefore output:

        1


    Again, the loop is not required.


    ============================================================================
    19. WHY WE HANDLE 0 AND 1 SEPARATELY
    ============================================================================

    The iterative generation starts at:

        i = 2


    because:

        F(0)
        F(1)

    are already known.


    If N is 0 or 1, there is no calculation required.

    Therefore explicit handling makes the program's logic clear:

        N = 0 -> return 0
        N = 1 -> return 1
        N >= 2 -> generate using the loop


    ============================================================================
    20. WHY WE DO NOT NEED AN ARRAY
    ============================================================================

    A straightforward Fibonacci implementation might store:

        F(0)
        F(1)
        F(2)
        F(3)
        ...
        F(N)


    in an array or vector.


    But to calculate the next Fibonacci number, we only need:

        previous two values


    For example:

        F(5) = F(4) + F(3)


    Once F(5) has been calculated, we only need:

        F(4)
        F(5)

    to calculate:

        F(6)


    Therefore older values can be discarded.


    This allows constant auxiliary space:

        O(1)


    ============================================================================
    21. SLIDING TWO-VALUE WINDOW
    ============================================================================

    Think of:

        first
        second


    as a window containing only the two values currently needed.


    Example:

        Initially:

            [F(0), F(1)]

        Then:

            [F(1), F(2)]

        Then:

            [F(2), F(3)]

        Then:

            [F(3), F(4)]

        Then:

            [F(4), F(5)]


    The window keeps moving forward.


    This is why we do not need to store the complete sequence.


    ============================================================================
    22. ITERATIVE APPROACH IN ONE VIEW
    ============================================================================

        Input:
            N

        Known:
            F(0) = 0
            F(1) = 1

        Store:
            first  = 0
            second = 1

        Repeat:
            next = first + second
            first = second
            second = next

        Until:
            i == N

        Final:
            second = F(N)


    ============================================================================
    23. TIME COMPLEXITY
    ============================================================================

    Suppose:

        number = N


    The loop runs from:

        2

    through:

        N


    Therefore the number of iterations is proportional to N.


    Each iteration performs a constant number of operations:

        addition
        assignment
        assignment
        assignment


    Therefore:

        Time Complexity = O(N)


    More formally:

        T(N) = T(N - 1) + O(1)


    which gives:

        O(N)


    ============================================================================
    24. SPACE COMPLEXITY
    ============================================================================

    The iterative approach uses only a fixed number of variables:

        number
        first
        second
        next
        i


    The number of variables does NOT grow with N.


    No:

        vector
        array
        recursion stack
        dynamically growing container

    is required.


    Therefore:

        Auxiliary Space = O(1)


    This is one of the biggest advantages of the two-variable iterative
    Fibonacci approach.


    ============================================================================
    25. INTEGER OVERFLOW
    ============================================================================

    Fibonacci numbers grow rapidly.

    Some values:

        F(0)  = 0
        F(1)  = 1
        F(2)  = 1
        F(5)  = 5
        F(10) = 55
        F(20) = 6765
        F(30) = 832040
        F(40) = 102334155
        F(50) = 12586269025
        F(60) = 1548008755920


    For signed 64-bit long long:

        F(92) fits


    but:

        F(93) does NOT fit


    Therefore:

        long long

    is not arbitrary precision.


    Always check the input constraints before choosing the data type.


    ============================================================================
    26. WHY int MAY NOT BE ENOUGH
    ============================================================================

    A signed 32-bit int has a maximum value of approximately:

        2,147,483,647


    But:

        F(47) = 2971215073


    which is larger than the signed 32-bit integer limit.


    Therefore:

        int

    cannot safely store all Fibonacci values up to 47.


    For larger values, a wider integer type or arbitrary-precision approach
    may be required.


    ============================================================================
    27. DATA TYPE CONSIDERATION
    ============================================================================

    The current educational implementation uses:

        long long


    for:

        number
        first
        second
        next


    This is useful for learning and for ranges where the Fibonacci result
    fits inside signed 64-bit range.


    However, the correct data type depends on the problem's constraints.


    If the problem allows very large N, a fixed-width integer may not be
    sufficient.


    ============================================================================
    28. NEGATIVE INPUT
    ============================================================================

    The standard Fibonacci problem uses:

        N >= 0


    Therefore the code checks:

        if (number < 0)


    and rejects the input.


    Negative-index Fibonacci numbers are a separate mathematical topic
    sometimes called Negafibonacci.

    They are NOT part of this basic implementation.


    ============================================================================
    29. COMMON MISTAKE #1 — WRONG INITIAL VALUES
    ============================================================================

    Correct:

        first  = 0
        second = 1


    because:

        F(0) = 0
        F(1) = 1


    If these are initialized incorrectly, every later Fibonacci number
    will also be incorrect.


    ============================================================================
    30. COMMON MISTAKE #2 — STARTING FROM THE WRONG INDEX
    ============================================================================

    We already know:

        F(0)
        F(1)


    Therefore the first generated value is:

        F(2)


    Correct:

        for (long long i = 2; i <= number; i++)


    ============================================================================
    31. COMMON MISTAKE #3 — USING i < number
    ============================================================================

    Wrong:

        for (long long i = 2; i < number; i++)


    If:

        number = 5


    then the loop stops at:

        i = 4


    and never generates:

        F(5)


    Correct:

        i <= number


    ============================================================================
    32. COMMON MISTAKE #4 — WRONG VARIABLE UPDATE
    ============================================================================

    The intended state transition is:

        old first
        old second

            ↓

        new first  = old second
        new second = old next


    Therefore:

        first = second;
        second = next;


    is the clear update.


    ============================================================================
    33. COMMON MISTAKE #5 — OVERWRITING A VALUE TOO EARLY
    ============================================================================

    The Fibonacci calculation needs BOTH previous values:

        first
        second


    before either one is changed.

    Therefore we first calculate:

        next = first + second;


    and only then update:

        first
        second


    This preserves the old values long enough to calculate the new value.


    ============================================================================
    34. COMMON MISTAKE #6 — IGNORING OVERFLOW
    ============================================================================

    A program can compile successfully but still produce an incorrect
    Fibonacci value if the result exceeds the selected integer type.


    For example:

        long long

    has a finite maximum.


    Therefore:

        datatype selection

    is part of solving the problem correctly.


    ============================================================================
    35. ITERATIVE VS RECURSIVE FIBONACCI
    ============================================================================

    ITERATIVE:

        Uses a loop.

        For the two-variable approach:

            Time  = O(N)
            Space = O(1)


    NAIVE RECURSIVE:

        Uses recursive calls:

            F(N) = F(N-1) + F(N-2)


        Without memoization, the same values are recalculated many times.

        Time is exponential.

        Auxiliary call-stack space is O(N).


    MEMOIZED RECURSIVE:

        Stores already calculated results.

        Time:
            O(N)

        Space:
            O(N)


    Therefore the simple two-variable iterative approach is especially
    memory-efficient.


    ============================================================================
    36. FULL DP VS TWO-VARIABLE ITERATION
    ============================================================================

    FULL DP:

        Store:

            F(0)
            F(1)
            F(2)
            ...
            F(N)


        Time:
            O(N)

        Space:
            O(N)


    TWO-VARIABLE ITERATION:

        Store only:

            previous two values


        Time:
            O(N)

        Space:
            O(1)


    The final result is the same when the problem asks only for F(N).


    ============================================================================
    37. WHY OLDER VALUES CAN BE DISCARDED
    ============================================================================

    Suppose we are calculating:

        F(6)


    To calculate:

        F(6)


    we need:

        F(5)
        F(4)


    We do NOT need:

        F(0)
        F(1)
        F(2)
        F(3)


    after the necessary values have already been used.


    Therefore older values can be discarded.


    ============================================================================
    38. FIBONACCI AS A STATE TRANSITION
    ============================================================================

    Current state:

        first  = F(i - 2)
        second = F(i - 1)


    Calculate:

        next = first + second


    New state:

        first  = F(i - 1)
        second = F(i)


    This is the core state transition of the iterative approach.


    ============================================================================
    39. DRY RUN TABLE FOR N = 10
    ============================================================================

        i    first    second    next

        2      0         1        1
        3      1         1        2
        4      1         2        3
        5      2         3        5
        6      3         5        8
        7      5         8       13
        8      8        13       21
        9     13        21       34
       10     21        34       55


    Final:

        second = 55


    Therefore:

        F(10) = 55


    ============================================================================
    40. SPECIAL CASE N = 0
    ============================================================================

    Input:

        0


    Output:

        0


    Reason:

        F(0) = 0


    The program returns immediately.


    ============================================================================
    41. SPECIAL CASE N = 1
    ============================================================================

    Input:

        1


    Output:

        1


    Reason:

        F(1) = 1


    The program returns immediately.


    ============================================================================
    42. SPECIAL CASE N = 2
    ============================================================================

    Input:

        2


    Initial:

        first  = 0
        second = 1


    Loop:

        i = 2


    Calculate:

        next = 0 + 1
             = 1


    Update:

        first  = 1
        second = 1


    Final:

        F(2) = 1


    ============================================================================
    43. SPECIAL CASE N = 3
    ============================================================================

    Input:

        3


    i = 2:

        next = 0 + 1 = 1

        first  = 1
        second = 1


    i = 3:

        next = 1 + 1 = 2

        first  = 1
        second = 2


    Final:

        F(3) = 2


    ============================================================================
    44. PLATFORM NOTES
    ============================================================================

    This problem appears on major DSA practice platforms including:

        LeetCode
        GeeksforGeeks (GFG)


    Platform versions can differ in:

        - Function signature
        - Input format
        - Output format
        - Maximum N
        - Number of test cases
        - Required data type
        - Whether modulo is required


    Always read the exact problem statement provided by the platform.


    ============================================================================
    45. LEETCODE NOTE
    ============================================================================

    LeetCode's Fibonacci problem is commonly presented as:

        Given an integer n, calculate F(n).


    The platform may provide a class/function template and expect only
    the required function implementation.

    Therefore, when submitting to LeetCode, follow the exact signature
    shown by the current problem.


    ============================================================================
    46. GEEKSFORGEEKS NOTE
    ============================================================================

    GeeksforGeeks contains Fibonacci problems in multiple forms.

    Depending on the specific problem, it may ask for:

        - N-th Fibonacci number
        - Fibonacci sequence
        - Recursive Fibonacci
        - Iterative Fibonacci
        - Dynamic programming
        - Fibonacci modulo a number


    Therefore, always follow the exact constraints and expected function
    signature of the particular GFG problem.


    ============================================================================
    47. INTERVIEW EXPECTATIONS
    ============================================================================

    If asked to implement Fibonacci iteratively, be prepared to explain:

        1. What the Fibonacci sequence is.

        2. Why:
               F(0) = 0

        3. Why:
               F(1) = 1

        4. The recurrence:
               F(N) = F(N-1) + F(N-2)

        5. Why the loop starts from 2.

        6. Why only two previous values are required.

        7. What first represents.

        8. What second represents.

        9. What next represents.

       10. Why the update order matters.

       11. Time complexity:
               O(N)

       12. Auxiliary space:
               O(1)

       13. Difference between full DP and constant-space iteration.

       14. Difference between iterative and naive recursive Fibonacci.

       15. Integer overflow.

       16. How the approach changes for very large N.


    ============================================================================
    48. FOLLOW-UP VARIATIONS
    ============================================================================

    After understanding the basic iterative approach, consider:

        1. Implement Fibonacci recursively.

        2. Implement Fibonacci using memoization.

        3. Implement Fibonacci using a DP array.

        4. Reduce DP space from O(N) to O(1).

        5. Calculate Fibonacci modulo M.

        6. Handle many Fibonacci queries efficiently.

        7. Generate the first N Fibonacci numbers.

        8. Find the first Fibonacci number greater than a given value.

        9. Work with very large N.

       10. Explore logarithmic-time Fibonacci techniques.


    ============================================================================
    49. INPUT / OUTPUT EXAMPLES
    ============================================================================

    Example 1:

        Input:
            0

        Output:
            Fibonacci Number: 0


    Example 2:

        Input:
            1

        Output:
            Fibonacci Number: 1


    Example 3:

        Input:
            5

        Output:
            Fibonacci Number: 5


    Example 4:

        Input:
            10

        Output:
            Fibonacci Number: 55


    Example 5:

        Input:
            20

        Output:
            Fibonacci Number: 6765


    NOTE:

        The explanatory output text above matches this educational
        standalone program.

        On an online judge, use the exact output format expected by
        that platform.


    ============================================================================
    50. QUICK CHEAT SHEET
    ============================================================================

    Problem:

        Find the N-th Fibonacci number.


    Definition:

        F(0) = 0
        F(1) = 1


    Recurrence:

        F(N) = F(N-1) + F(N-2)


    Initial variables:

        first  = 0
        second = 1


    Loop starts:

        i = 2


    Next value:

        next = first + second


    Update:

        first = second
        second = next


    Final answer:

        second


    Time:

        O(N)


    Auxiliary Space:

        O(1)


    Important overflow fact:

        F(92) fits in signed 64-bit long long.

        F(93) does not.


    Platforms:

        LeetCode
        GeeksforGeeks (GFG)


    ============================================================================
    51. FINAL CONCEPT
    ============================================================================

    The entire iterative Fibonacci idea can be remembered as:

        START
          |
          v
        first = 0
        second = 1
          |
          v
        Need F(N)?
          |
          v
        Generate from i = 2 to N
          |
          v
        next = first + second
          |
          v
        first = second
          |
          v
        second = next
          |
          v
        Repeat
          |
          v
        second = F(N)


    The three most important ideas are:

        1. Fibonacci starts with:
               0, 1

        2. Every next value is:
               previous + current

        3. Only two previous values are required, giving:
               O(N) time
               O(1) auxiliary space


    ============================================================================
    END
    ============================================================================
*/