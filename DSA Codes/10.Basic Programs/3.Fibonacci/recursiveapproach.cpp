/*
    ============================================================================
        FIBONACCI NUMBER — RECURSIVE APPROACH
    ============================================================================

    Reference style:
        This file follows the detailed, concept-first structure of the
        Fibonacci Iterative Approach reference:
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
        Recursive Fibonacci Method
        Recursion-Based Fibonacci Method
        Top-Down Fibonacci Method

    Platforms:
        LeetCode
        GeeksforGeeks (GFG)

    Core idea:

        The Fibonacci sequence is defined as:

            F(0) = 0
            F(1) = 1

        For N >= 2:

            F(N) = F(N - 1) + F(N - 2)

        The recursive approach directly represents this mathematical
        definition.

        To calculate F(N), we recursively calculate:

            F(N - 1)
            F(N - 2)

        and add their results.

    Example:

        F(5)

        = F(4) + F(3)
        = (F(3) + F(2)) + (F(2) + F(1))
        = 5

    Most important concepts:

        1. Recursive function
        2. Base cases
        3. Recursive cases
        4. Function call stack
        5. Recursion tree
        6. Stack unwinding
        7. Repeated subproblems
        8. Time complexity
        9. Auxiliary space

    Complexity of the basic recursive approach:

        Time  = O(2^N) approximately
        Space = O(N) auxiliary call-stack space

    Important limitation:

        This basic recursive implementation recalculates the same Fibonacci
        values many times.

        For example:

            F(5)

        requires F(3) and F(2) through different branches.

        This repeated work makes the naive recursive approach inefficient
        for large N.

    This file contains:

        1. Complete recursive approach
        2. Detailed explanation of every function
        3. Base cases
        4. Recursive case
        5. Why two base cases are required
        6. Detailed dry runs
        7. Recursion tree
        8. Call-stack explanation
        9. Stack unwinding
       10. Repeated subproblem explanation
       11. Time complexity derivation
       12. Space complexity derivation
       13. Overflow discussion
       14. Data-type discussion
       15. Iterative vs recursive comparison
       16. Memoization comparison
       17. Common mistakes
       18. Edge cases
       19. Platform notes
       20. Interview expectations
       21. Related variations
       22. Quick revision section
*/

#include <iostream>
using namespace std;

// ============================================================================
// 1. RECURSIVE FIBONACCI FUNCTION
// ============================================================================

long long fibonacci(long long number)
{
    // ------------------------------------------------------------------------
    // BASE CASE 1
    // ------------------------------------------------------------------------
    //
    // By definition:
    //
    //      F(0) = 0
    //
    // Therefore when number is 0, the function immediately returns 0.
    //
    // This stops recursion for the first base case.
    if (number == 0)
    {
        return 0;
    }

    // ------------------------------------------------------------------------
    // BASE CASE 2
    // ------------------------------------------------------------------------
    //
    // By definition:
    //
    //      F(1) = 1
    //
    // Therefore when number is 1, the function immediately returns 1.
    //
    // Fibonacci recursion needs TWO base cases because the recursive
    // relationship depends on the previous TWO Fibonacci values.
    if (number == 1)
    {
        return 1;
    }

    // ------------------------------------------------------------------------
    // RECURSIVE CASE
    // ------------------------------------------------------------------------
    //
    // Fibonacci is mathematically defined as:
    //
    //      F(N) = F(N - 1) + F(N - 2)
    //
    // Therefore:
    //
    //      fibonacci(number)
    //
    // becomes:
    //
    //      fibonacci(number - 1) + fibonacci(number - 2)
    //
    // The function recursively calculates both previous Fibonacci values
    // and adds their results.
    return fibonacci(number - 1) + fibonacci(number - 2);
}

// ============================================================================
// 2. MAIN FUNCTION
// ============================================================================

int main()
{
    long long number;

    cout << "Enter a Number: ";
    cin >> number;

    // ------------------------------------------------------------------------
    // INPUT VALIDATION
    // ------------------------------------------------------------------------
    //
    // The standard Fibonacci problem uses a non-negative index:
    //
    //      0, 1, 2, 3, ...
    //
    // Negative indices are not part of this basic implementation.
    if (number < 0)
    {
        cout << "Fibonacci is not defined for negative index in this "
                "basic version."
             << endl;

        return 0;
    }

    // ------------------------------------------------------------------------
    // CALL THE RECURSIVE FUNCTION
    // ------------------------------------------------------------------------
    //
    // Example:
    //
    //      number = 5
    //
    // Then:
    //
    //      fibonacci(5)
    //
    // eventually returns:
    //
    //      5
    cout << "Fibonacci Number: " << fibonacci(number) << endl;

    return 0;
}

/*
    ============================================================================
    3. WHAT IS RECURSION?
    ============================================================================

    Recursion is a programming technique in which a function calls itself.

    In this problem:

        fibonacci()

    calls:

        fibonacci()


    A recursive solution normally contains:

        1. Base Case
        2. Recursive Case


    For Fibonacci:

        Base cases:

            F(0) = 0
            F(1) = 1


        Recursive case:

            F(N) = F(N-1) + F(N-2)


    ============================================================================
    4. WHY FIBONACCI NEEDS TWO BASE CASES
    ============================================================================

    Factorial recursion needs one fundamental base case:

        0! = 1


    Fibonacci is different.

    Its definition begins with TWO known values:

        F(0) = 0
        F(1) = 1


    Then:

        F(2) = F(1) + F(0)


    Therefore the recursive function must know what:

        F(0)

    and:

        F(1)

    are.


    This is why we have:

        if (number == 0)
            return 0;

        if (number == 1)
            return 1;


    ============================================================================
    5. THE RECURSIVE CASE
    ============================================================================

    The core line is:

        return fibonacci(number - 1) + fibonacci(number - 2);


    This directly represents:

        F(N) = F(N-1) + F(N-2)


    Example:

        fibonacci(5)

    becomes:

        fibonacci(4) + fibonacci(3)


    Then:

        fibonacci(4)
        =
        fibonacci(3) + fibonacci(2)


    and:

        fibonacci(3)
        =
        fibonacci(2) + fibonacci(1)


    Recursion continues until the base cases are reached.


    ============================================================================
    6. WHY number - 1 AND number - 2?
    ============================================================================

    Fibonacci is defined using the two previous values.

    For:

        F(N)


    the previous two values are:

        F(N-1)
        F(N-2)


    Therefore the recursive calls are:

        fibonacci(number - 1)

    and:

        fibonacci(number - 2)


    Example:

        F(5)

    depends on:

        F(4)
        F(3)


    ============================================================================
    7. WHY RECURSION TERMINATES
    ============================================================================

    The base cases are:

        0
        1


    Every recursive call decreases the input:

        N
        N-1
        N-2


    Therefore eventually the function reaches either:

        fibonacci(1)

    or:

        fibonacci(0)


    and returns immediately.


    ============================================================================
    8. DETAILED DRY RUN FOR N = 5
    ============================================================================

    Input:

        5


    First call:

        fibonacci(5)


    Since:

        5 != 0
        5 != 1


    recursive case:

        fibonacci(5)
        =
        fibonacci(4) + fibonacci(3)


    Now fibonacci(4):

        fibonacci(4)
        =
        fibonacci(3) + fibonacci(2)


    And fibonacci(3):

        fibonacci(3)
        =
        fibonacci(2) + fibonacci(1)


    Fibonacci(2):

        fibonacci(2)
        =
        fibonacci(1) + fibonacci(0)


    Base cases:

        fibonacci(1) = 1
        fibonacci(0) = 0


    Therefore:

        fibonacci(2)
        = 1 + 0
        = 1


    Then:

        fibonacci(3)
        = fibonacci(2) + fibonacci(1)
        = 1 + 1
        = 2


    Then:

        fibonacci(4)
        = fibonacci(3) + fibonacci(2)
        = 2 + 1
        = 3


    On the other branch:

        fibonacci(3)
        = 2


    Therefore:

        fibonacci(5)
        = fibonacci(4) + fibonacci(3)
        = 3 + 2
        = 5


    Final:

        F(5) = 5


    ============================================================================
    9. RECURSION TREE FOR F(5)
    ============================================================================

                    fibonacci(5)
                    /          \
                   /            \
          fibonacci(4)       fibonacci(3)
           /       \           /       \
          /         \         /         \
     fibonacci(3) fibonacci(2) fibonacci(2) fibonacci(1)
       /    \        /   \       /   \
      /      \      /     \     /     \
    F(2)    F(1)  F(1)   F(0)  F(1)  F(0)


    Notice something important:

        fibonacci(3)

    appears MORE THAN ONCE.

    Also:

        fibonacci(2)

    appears multiple times.

    This is called:

        Repeated Subproblems


    ============================================================================
    10. REPEATED SUBPROBLEMS
    ============================================================================

    Consider:

        fibonacci(5)


    It needs:

        fibonacci(4)
        fibonacci(3)


    But fibonacci(4) itself needs:

        fibonacci(3)
        fibonacci(2)


    Therefore:

        fibonacci(3)

    is calculated more than once.


    Similarly:

        fibonacci(2)

    is calculated multiple times.


    The basic recursive implementation does NOT remember previously
    calculated results.


    This repeated work is the main performance problem with naive recursion.


    ============================================================================
    11. CALL STACK
    ============================================================================

    Every active function call is stored on the call stack.

    For one branch such as:

        fibonacci(5)
        -> fibonacci(4)
        -> fibonacci(3)
        -> fibonacci(2)
        -> fibonacci(1)


    the calls remain active until the deeper call returns.


    At the deepest point, several recursive calls are present on the stack.


    Then the stack unwinds as the functions return their results.


    ============================================================================
    12. STACK UNWINDING
    ============================================================================

    Consider:

        fibonacci(2)


    It becomes:

        fibonacci(1) + fibonacci(0)


    First:

        fibonacci(1) -> 1

    and:

        fibonacci(0) -> 0


    Then:

        fibonacci(2)
        = 1 + 0
        = 1


    That result is returned to its caller.


    The same process happens at every level.


    This return process is called:

        Stack Unwinding


    ============================================================================
    13. RECURSION HAS TWO PHASES
    ============================================================================

    It is useful to visualize recursion as two phases.


    PHASE 1 — CALLING DOWN

        fibonacci(5)
             |
             v
        fibonacci(4)
             |
             v
        fibonacci(3)
             |
             v
        fibonacci(2)
             |
             v
        fibonacci(1)


    PHASE 2 — RETURNING UP

        fibonacci(1) -> 1
        fibonacci(2) -> 1
        fibonacci(3) -> 2
        fibonacci(4) -> 3
        fibonacci(5) -> 5


    Because Fibonacci branches into TWO recursive calls, the complete
    recursion tree contains many calls.


    ============================================================================
    14. DRY RUN TABLE FOR F(5)
    ============================================================================

        Function        Result

        F(0)              0
        F(1)              1
        F(2)              1
        F(1)              1
        F(3)              2
        F(2)              1
        F(4)              3
        F(2)              1
        F(1)              1
        F(3)              2
        F(5)              5


    The exact order in which calls are evaluated follows the recursive
    expression and compiler evaluation rules, but the key concept is that
    the same Fibonacci subproblems are solved repeatedly.


    ============================================================================
    15. DRY RUN FOR N = 0
    ============================================================================

    Input:

        0


    Call:

        fibonacci(0)


    Base case:

        number == 0


    Return:

        0


    Therefore:

        F(0) = 0


    No recursive call is made.


    ============================================================================
    16. DRY RUN FOR N = 1
    ============================================================================

    Input:

        1


    Call:

        fibonacci(1)


    Base case:

        number == 1


    Return:

        1


    Therefore:

        F(1) = 1


    No recursive call is made.


    ============================================================================
    17. DRY RUN FOR N = 2
    ============================================================================

    Input:

        2


    Call:

        fibonacci(2)


    Recursive case:

        fibonacci(2)
        =
        fibonacci(1) + fibonacci(0)


    Base cases:

        fibonacci(1) = 1
        fibonacci(0) = 0


    Therefore:

        fibonacci(2)
        = 1 + 0
        = 1


    Final:

        F(2) = 1


    ============================================================================
    18. DRY RUN FOR N = 3
    ============================================================================

    Input:

        3


    Recursive expansion:

        fibonacci(3)
        =
        fibonacci(2) + fibonacci(1)


    Now:

        fibonacci(2)
        =
        fibonacci(1) + fibonacci(0)


    Therefore:

        fibonacci(1) = 1
        fibonacci(0) = 0


    So:

        fibonacci(2) = 1


    Finally:

        fibonacci(3)
        = 1 + 1
        = 2


    Therefore:

        F(3) = 2


    ============================================================================
    19. TIME COMPLEXITY
    ============================================================================

    This is the most important limitation of naive recursive Fibonacci.


    Each non-base function call creates TWO recursive calls:

        fibonacci(N)
        =
        fibonacci(N-1)
        +
        fibonacci(N-2)


    Therefore the number of calls grows exponentially.


    A commonly used upper-bound description is:

        O(2^N)


    More precisely, the number of calls is related to Fibonacci growth and
    can be described using the golden ratio, but for typical DSA analysis:

        Time Complexity = O(2^N)


    is the standard simplified complexity.


    ============================================================================
    20. WHY TIME IS EXPONENTIAL
    ============================================================================

    Consider:

        F(5)


    It calls approximately:

        F(4)
        F(3)


    F(4) calls:

        F(3)
        F(2)


    F(3) calls:

        F(2)
        F(1)


    The number of calls keeps branching.


    As N increases, the recursion tree becomes much larger.


    Therefore the algorithm performs a large amount of repeated work.


    ============================================================================
    21. SPACE COMPLEXITY
    ============================================================================

    Although the recursion tree contains many total calls, the maximum
    number of calls ACTIVE at one time is only proportional to N.


    For example, one deepest path is approximately:

        F(N)
        F(N-1)
        F(N-2)
        ...
        F(1)


    Therefore maximum recursion depth is:

        O(N)


    Hence:

        Auxiliary Space = O(N)


    Important distinction:

        Time:
            O(2^N)

        Auxiliary call-stack space:
            O(N)


    ============================================================================
    22. TOTAL CALLS VS STACK DEPTH
    ============================================================================

    This distinction is extremely important.


    TOTAL NUMBER OF FUNCTION CALLS:

        Exponential


    MAXIMUM NUMBER OF SIMULTANEOUSLY ACTIVE CALLS:

        Linear


    Therefore:

        Time  = O(2^N)
        Space = O(N)


    Do NOT say:

        Space = O(2^N)

    just because the recursion tree has exponentially many nodes.

    The stack only stores the currently active path.


    ============================================================================
    23. WHY RECURSIVE FIBONACCI IS SLOW
    ============================================================================

    Suppose we calculate:

        fibonacci(6)


    We calculate:

        fibonacci(4)

    through one branch.

    But:

        fibonacci(4)

    itself calculates:

        fibonacci(3)


    and another branch from fibonacci(6) may also calculate:

        fibonacci(3)


    So the same value is calculated repeatedly.


    This is unnecessary work.


    ============================================================================
    24. MEMOIZATION AS AN IMPROVEMENT
    ============================================================================

    A common improvement is:

        Memoization


    The idea is to remember Fibonacci values that have already been
    calculated.


    Then when the same subproblem is requested again, its stored answer
    can be reused instead of recalculated.


    With memoization:

        Time  = O(N)
        Space = O(N)


    The current file intentionally implements the BASIC RECURSIVE approach
    without memoization so that the recursion concept is clear.


    ============================================================================
    25. RECURSIVE VS MEMOIZED RECURSIVE
    ============================================================================

    BASIC RECURSION:

        F(N)
        -> F(N-1)
        -> F(N-2)

        repeated subproblems are recalculated.


        Time:
            O(2^N)

        Space:
            O(N)


    MEMOIZED RECURSION:

        Previously calculated results are stored.


        Time:
            O(N)

        Space:
            O(N)


    The main difference is whether previously calculated subproblems
    are remembered.


    ============================================================================
    26. RECURSIVE VS ITERATIVE
    ============================================================================

    RECURSIVE:

        Mathematical expression:

            F(N) = F(N-1) + F(N-2)

        Time:
            O(2^N)

        Auxiliary space:
            O(N)


    ITERATIVE TWO-VARIABLE:

        Uses only the previous two values.

        Time:
            O(N)

        Auxiliary space:
            O(1)


    Therefore the iterative version is much more efficient for larger N.


    ============================================================================
    27. FULL DP VS RECURSIVE
    ============================================================================

    FULL DP stores all values:

        F(0)
        F(1)
        ...
        F(N)


    Complexity:

        Time:
            O(N)

        Space:
            O(N)


    Basic recursion does not store results:

        Time:
            O(2^N)

        Space:
            O(N) call stack


    ============================================================================
    28. WHY RECURSION IS STILL IMPORTANT
    ============================================================================

    Even though naive recursive Fibonacci is inefficient, it is extremely
    useful for learning:

        - Recursion
        - Base cases
        - Recursive cases
        - Call stack
        - Stack unwinding
        - Recursion trees
        - Repeated subproblems
        - Dynamic programming motivation
        - Memoization


    Fibonacci is one of the classic examples used to understand why
    optimization techniques such as memoization and dynamic programming
    are useful.


    ============================================================================
    29. INTEGER OVERFLOW
    ============================================================================

    Fibonacci values grow quickly.

    Some values:

        F(10) = 55
        F(20) = 6765
        F(30) = 832040
        F(40) = 102334155
        F(50) = 12586269025
        F(60) = 1548008755920


    For signed 64-bit long long:

        F(92) fits


    but:

        F(93) does not fit


    Therefore:

        long long

    is not unlimited precision.


    Always check the platform's input constraints.


    ============================================================================
    30. WHY int MAY NOT BE ENOUGH
    ============================================================================

    A signed 32-bit int has maximum value approximately:

        2,147,483,647


    But:

        F(47) = 2,971,215,073


    which is already greater than the signed 32-bit range.


    Therefore:

        int

    is not sufficient for all Fibonacci values up to 47.


    ============================================================================
    31. NEGATIVE INPUT
    ============================================================================

    The basic Fibonacci problem uses:

        N >= 0


    Therefore the program checks:

        if (number < 0)


    and rejects negative input.


    Negative Fibonacci indices are a separate topic called Negafibonacci.


    ============================================================================
    32. COMMON MISTAKE #1 — MISSING BASE CASES
    ============================================================================

    Wrong:

        long long fibonacci(long long n)
        {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }


    There is no stopping condition.

    The calls will continue indefinitely until stack overflow or invalid
    behavior occurs.


    Correct recursive Fibonacci needs:

        F(0) = 0
        F(1) = 1


    ============================================================================
    33. COMMON MISTAKE #2 — ONLY ONE BASE CASE
    ============================================================================

    Fibonacci needs both:

        n == 0
        n == 1


    If only:

        n == 0

    were handled, then:

        fibonacci(1)

    would attempt:

        fibonacci(0) + fibonacci(-1)


    which is invalid for this basic problem.


    ============================================================================
    34. COMMON MISTAKE #3 — WRONG BASE VALUES
    ============================================================================

    Correct:

        F(0) = 0
        F(1) = 1


    If these values are wrong, every later Fibonacci result will be wrong.


    ============================================================================
    35. COMMON MISTAKE #4 — USING WRONG RECURSIVE FORMULA
    ============================================================================

    Correct:

        fibonacci(n - 1) + fibonacci(n - 2)


    because:

        F(N) = F(N-1) + F(N-2)


    Any different recurrence calculates a different sequence.


    ============================================================================
    36. COMMON MISTAKE #5 — THINKING RECURSION IS ALWAYS FASTER
    ============================================================================

    Recursion can make code mathematically elegant and easy to express.

    But recursive Fibonacci without memoization repeats work.


    Therefore:

        Elegant != automatically efficient


    The naive recursive Fibonacci approach is much slower than the
    two-variable iterative approach for larger N.


    ============================================================================
    37. COMMON MISTAKE #6 — CONFUSING TOTAL CALLS WITH SPACE
    ============================================================================

    The recursion tree may contain exponentially many calls.

    But the call stack only stores one active path at a time.


    Therefore:

        Time:
            O(2^N)

        Space:
            O(N)


    ============================================================================
    38. EDGE CASES
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
        30


    Expected results:

        F(0)  = 0
        F(1)  = 1
        F(2)  = 1
        F(3)  = 2
        F(4)  = 3
        F(5)  = 5
        F(10) = 55
        F(20) = 6765
        F(30) = 832040


    Negative input:

        Not valid for the basic version.


    ============================================================================
    39. PLATFORM NOTES
    ============================================================================

    This Fibonacci problem appears on:

        LeetCode
        GeeksforGeeks (GFG)


    Platform versions may differ in:

        - Function signature
        - Input format
        - Output format
        - Maximum N
        - Number of test cases
        - Modulo requirements
        - Expected complexity


    Always follow the exact problem statement for the platform version
    being solved.


    ============================================================================
    40. LEETCODE NOTE
    ============================================================================

    LeetCode commonly provides a function/class template for Fibonacci.

    The exact submission format can therefore differ from this standalone
    educational program.

    When submitting:

        follow the exact function signature
        provided by the current problem.


    ============================================================================
    41. GEEKSFORGEEKS NOTE
    ============================================================================

    GeeksforGeeks contains multiple Fibonacci-related problems.

    A problem may ask for:

        - N-th Fibonacci number
        - Recursive Fibonacci
        - Iterative Fibonacci
        - DP Fibonacci
        - Fibonacci modulo a value
        - Fibonacci sequence generation


    The exact constraints and required implementation can therefore differ.


    ============================================================================
    42. INTERVIEW EXPECTATIONS
    ============================================================================

    If asked for recursive Fibonacci in an interview, be prepared to explain:

        1. What recursion is.

        2. What the base cases are.

        3. Why there are TWO base cases.

        4. The recurrence:
               F(N) = F(N-1) + F(N-2)

        5. How the recursion tree grows.

        6. What repeated subproblems are.

        7. Why naive recursion is exponential.

        8. Why call-stack space is O(N), not O(2^N).

        9. What stack unwinding means.

       10. How memoization improves the time complexity.

       11. How the iterative two-variable approach improves both
           time and auxiliary space.

       12. Integer overflow considerations.

       13. How the approach changes for very large N.


    ============================================================================
    43. FOLLOW-UP VARIATIONS
    ============================================================================

    After understanding this basic recursive implementation, consider:

        1. Add memoization.

        2. Convert it to bottom-up dynamic programming.

        3. Reduce DP space to O(1).

        4. Calculate F(N) modulo M.

        5. Handle many queries.

        6. Generate the complete Fibonacci sequence.

        7. Find Fibonacci values for very large N.

        8. Explore logarithmic-time Fibonacci methods.

        9. Study negative Fibonacci indices.

       10. Compare recursive, memoized, DP, and iterative implementations.


    ============================================================================
    44. RECURSIVE FIBONACCI IN ONE VIEW
    ============================================================================

        Input:
            N

        Base:
            F(0) = 0
            F(1) = 1

        Recursive case:
            F(N) = F(N-1) + F(N-2)

        Stop when:
            N == 0
            or
            N == 1

        Final:
            return F(N)


    ============================================================================
    45. QUICK CHEAT SHEET
    ============================================================================

    Problem:

        Find the N-th Fibonacci number.


    Base cases:

        F(0) = 0
        F(1) = 1


    Recursive formula:

        F(N) = F(N-1) + F(N-2)


    Recursive calls:

        fibonacci(N-1)
        fibonacci(N-2)


    Basic recursive time:

        O(2^N) approximately


    Auxiliary call-stack space:

        O(N)


    Main problem:

        Repeated subproblems


    Optimization:

        Memoization


    Memoized time:

        O(N)


    Iterative two-variable time:

        O(N)


    Iterative two-variable space:

        O(1)


    Platforms:

        LeetCode
        GeeksforGeeks (GFG)


    Overflow:

        F(92) fits signed 64-bit long long.

        F(93) does not.


    ============================================================================
    46. FINAL CONCEPT
    ============================================================================

    The most important recursive Fibonacci pattern is:

        fibonacci(N)
        =
        fibonacci(N - 1)
        +
        fibonacci(N - 2)


    until one of the base cases:

        fibonacci(0) = 0

        fibonacci(1) = 1


    Think of the execution as:

        CALL DOWN
            |
            v
        Split into two subproblems
            |
            v
        Continue until 0 or 1
            |
            v
        RETURN UP
            |
            v
        Combine results by addition


    The three most important ideas are:

        1. Fibonacci has TWO base cases.

        2. Every non-base call creates TWO recursive subproblems.

        3. Naive recursion has exponential time because of repeated
           subproblems, while the maximum call-stack depth is O(N).


    ============================================================================
    END
    ============================================================================
*/