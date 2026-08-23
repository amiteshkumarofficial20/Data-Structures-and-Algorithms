/*
    ============================================================================
        FACTORIAL OF A NUMBER — RECURSIVE APPROACH
    ============================================================================
    Method Name:
        Recursive Factorial Method
        Recursion-Based Factorial Method

    Platforms:
        GeeksforGeeks (GFG)
        Naukri (Code360)
        HackerEarth
        CodeChef

    Core idea:

        Factorial has a natural recursive definition:

            N! = N * (N - 1)!

        The recursion continues until the BASE CASE:

            0! = 1

        Therefore:

            factorial(N)
                = N * factorial(N - 1)

        until:

            N == 0

    Example:

        5!

        = 5 * 4!
        = 5 * 4 * 3!
        = 5 * 4 * 3 * 2!
        = 5 * 4 * 3 * 2 * 1!
        = 120

    Most important concepts:

        1. Recursive function
        2. Base case
        3. Recursive case
        4. Function call stack
        5. Returning values
        6. Stack unwinding
        7. O(N) time
        8. O(N) auxiliary space

    This file contains:

        1. Complete recursive approach
        2. Detailed explanation of the recursive function
        3. Base case
        4. Recursive case
        5. Why the base case is necessary
        6. Detailed call sequence
        7. Detailed dry run for 5
        8. Forward recursion expansion
        9. Backward stack unwinding
       10. Call-stack explanation
       11. Zero case
       12. One case
       13. Negative input handling
       14. Integer overflow
       15. Time complexity
       16. Space complexity
       17. Iterative vs recursive comparison
       18. Common mistakes
       19. Interview expectations
       20. Quick revision section

    Complexity:

        Time  = O(N)
        Space = O(N) auxiliary because of the recursion call stack

    Important limitation:

        Recursion does NOT remove the need for a stack.

        Every recursive call remains on the call stack until the deeper
        call returns.

        Therefore the recursive factorial uses O(N) auxiliary stack space.
*/

#include <iostream>
using namespace std;

// ============================================================================
// 1. RECURSIVE FACTORIAL FUNCTION
// ============================================================================

long long factorial(int number)
{
    // ------------------------------------------------------------------------
    // BASE CASE
    // ------------------------------------------------------------------------
    //
    // The recursion must have a condition that stops further recursive calls.
    //
    // For factorial:
    //
    //      0! = 1
    //
    // Therefore:
    //
    //      if (number == 0)
    //
    // we return:
    //
    //      1
    //
    // This is called the BASE CASE.
    //
    // Without a base case, the function would keep calling itself and
    // eventually cause a stack overflow.
    if (number == 0)
    {
        return 1;
    }

    // ------------------------------------------------------------------------
    // RECURSIVE CASE
    // ------------------------------------------------------------------------
    //
    // Mathematical definition:
    //
    //      N! = N * (N - 1)!
    //
    // Therefore:
    //
    //      factorial(number)
    //
    // becomes:
    //
    //      number * factorial(number - 1)
    //
    // Example:
    //
    //      factorial(5)
    //
    // becomes:
    //
    //      5 * factorial(4)
    //
    // Then factorial(4) becomes:
    //
    //      4 * factorial(3)
    //
    // and so on.
    //
    // IMPORTANT:
    //
    // We are NOT immediately getting the final answer.
    //
    // The current function waits for:
    //
    //      factorial(number - 1)
    //
    // to return its value.
    return number * factorial(number - 1);
}

// ============================================================================
// 2. MAIN FUNCTION
// ============================================================================

int main()
{
    int number;

    cout << "Enter a Number: ";
    cin >> number;

    // ------------------------------------------------------------------------
    // NEGATIVE INPUT CHECK
    // ------------------------------------------------------------------------
    //
    // The basic factorial problem is defined for non-negative integers:
    //
    //      0, 1, 2, 3, ...
    //
    // Negative factorial is not part of the basic problem definition.
    if (number < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    // ------------------------------------------------------------------------
    // FUNCTION CALL
    // ------------------------------------------------------------------------
    //
    // We call:
    //
    //      factorial(number)
    //
    // and print the returned result.
    //
    // Example:
    //
    //      number = 5
    //
    //      factorial(5)
    //
    // eventually returns:
    //
    //      120
    cout << "Factorial: " << factorial(number) << endl;

    return 0;
}

/*
    ============================================================================
    3. WHAT IS RECURSION?
    ============================================================================

    Recursion is a technique where a function calls itself.

    A recursive solution normally contains two important parts:

        1. Base Case
        2. Recursive Case


    In factorial:

        Base Case:

            number == 0

        Recursive Case:

            number * factorial(number - 1)


    Conceptually:

        factorial(N)
              |
              v
        Is N == 0?
          /       \
        YES        NO
         |          |
         v          v
        return 1   N * factorial(N-1)


    ============================================================================
    4. WHAT IS THE BASE CASE?
    ============================================================================

    The BASE CASE is the condition that stops recursion.

    Here:

        if (number == 0)
        {
            return 1;
        }


    Why?

    Because:

        0! = 1


    Once we reach:

        factorial(0)

    there is no need to call:

        factorial(-1)


    We simply return:

        1


    ============================================================================
    5. WHY BASE CASE IS NECESSARY
    ============================================================================

    Suppose we wrote:

        return number * factorial(number - 1);

    without any stopping condition.

    Then:

        factorial(5)
        -> factorial(4)
        -> factorial(3)
        -> factorial(2)
        -> factorial(1)
        -> factorial(0)
        -> factorial(-1)
        -> factorial(-2)
        -> ...


    The function would never stop.

    Eventually, the program would run out of call-stack space.

    This is called:

        Stack Overflow


    Therefore every recursive solution must have a correctly designed
    termination condition.


    ============================================================================
    6. WHAT IS THE RECURSIVE CASE?
    ============================================================================

    The recursive case is the part where the function calls itself.

    Here:

        return number * factorial(number - 1);


    The function:

        factorial()

    calls:

        factorial(number - 1)


    Therefore:

        factorial(5)

    calls:

        factorial(4)


    and:

        factorial(4)

    calls:

        factorial(3)


    and so on.


    ============================================================================
    7. MATHEMATICAL DEFINITION OF FACTORIAL
    ============================================================================

    Factorial can be defined recursively as:

        N! = N * (N - 1)!

    with:

        0! = 1


    Therefore:

        5!
        = 5 * 4!
        = 5 * 4 * 3!
        = 5 * 4 * 3 * 2!
        = 5 * 4 * 3 * 2 * 1!
        = 120


    The C++ recursive function directly represents this mathematical
    definition.


    ============================================================================
    8. DETAILED DRY RUN FOR number = 5
    ============================================================================

    Input:

        5


    First call:

        factorial(5)


    The function checks:

        Is 5 == 0?

        NO


    Therefore:

        factorial(5)
        = 5 * factorial(4)


    But factorial(4) has not returned yet.

    So another call is made.


    ------------------------------------------------------------------------
    CALL 1
    ------------------------------------------------------------------------

        factorial(5)

    Waiting for:

        factorial(4)

    Expression waiting:

        5 * factorial(4)


    ------------------------------------------------------------------------
    CALL 2
    ------------------------------------------------------------------------

        factorial(4)

    Checks:

        4 == 0?

        NO


    Calls:

        factorial(3)


    Waiting expression:

        4 * factorial(3)


    ------------------------------------------------------------------------
    CALL 3
    ------------------------------------------------------------------------

        factorial(3)

    Checks:

        3 == 0?

        NO


    Calls:

        factorial(2)


    Waiting expression:

        3 * factorial(2)


    ------------------------------------------------------------------------
    CALL 4
    ------------------------------------------------------------------------

        factorial(2)

    Checks:

        2 == 0?

        NO


    Calls:

        factorial(1)


    Waiting expression:

        2 * factorial(1)


    ------------------------------------------------------------------------
    CALL 5
    ------------------------------------------------------------------------

        factorial(1)

    Checks:

        1 == 0?

        NO


    Calls:

        factorial(0)


    Waiting expression:

        1 * factorial(0)


    ------------------------------------------------------------------------
    CALL 6 — BASE CASE
    ------------------------------------------------------------------------

        factorial(0)

    Checks:

        0 == 0?

        YES


    Returns:

        1


    Now recursion starts returning back.


    ============================================================================
    9. STACK UNWINDING
    ============================================================================

    This is one of the most important concepts in recursion.

    During the downward phase:

        factorial(5)
            |
            v
        factorial(4)
            |
            v
        factorial(3)
            |
            v
        factorial(2)
            |
            v
        factorial(1)
            |
            v
        factorial(0)


    We reach the base case.

    Then the calls return in the REVERSE order.


    factorial(0) returns:

        1


    Then:

        factorial(1)
        = 1 * factorial(0)
        = 1 * 1
        = 1


    Then:

        factorial(2)
        = 2 * factorial(1)
        = 2 * 1
        = 2


    Then:

        factorial(3)
        = 3 * factorial(2)
        = 3 * 2
        = 6


    Then:

        factorial(4)
        = 4 * factorial(3)
        = 4 * 6
        = 24


    Then:

        factorial(5)
        = 5 * factorial(4)
        = 5 * 24
        = 120


    Final:

        120


    ============================================================================
    10. RECURSION TREE / CALL FLOW
    ============================================================================

        factorial(5)
              |
              | 5 *
              v
        factorial(4)
              |
              | 4 *
              v
        factorial(3)
              |
              | 3 *
              v
        factorial(2)
              |
              | 2 *
              v
        factorial(1)
              |
              | 1 *
              v
        factorial(0)
              |
              v
             1


    Then values return upward:

        factorial(0) = 1
        factorial(1) = 1
        factorial(2) = 2
        factorial(3) = 6
        factorial(4) = 24
        factorial(5) = 120


    ============================================================================
    11. CALL STACK
    ============================================================================

    Every time a function is called, information about that function call
    is placed on the CALL STACK.

    For:

        factorial(5)

    the stack grows approximately like:

        factorial(5)
        factorial(4)
        factorial(3)
        factorial(2)
        factorial(1)
        factorial(0)


    At the deepest point, all these calls are active.

    When factorial(0) returns:

        factorial(0)

    is removed from the stack.

    Then factorial(1) completes.

    Then factorial(1) is removed.

    Then factorial(2) completes.

    And so on.


    This process is called:

        Stack Unwinding


    ============================================================================
    12. WHY RECURSIVE SPACE IS O(N)
    ============================================================================

    For:

        factorial(N)

    there can be approximately N + 1 active calls before the base case
    returns.

    Example for N = 5:

        factorial(5)
        factorial(4)
        factorial(3)
        factorial(2)
        factorial(1)
        factorial(0)


    Therefore the maximum recursion depth is proportional to N.

    Hence:

        Auxiliary Space = O(N)


    IMPORTANT:

        The O(N) space is not because we created an array of size N.

        It is because the FUNCTION CALL STACK stores the active recursive
        calls.


    ============================================================================
    13. TIME COMPLEXITY
    ============================================================================

    For:

        factorial(N)


    The function calls:

        factorial(N)
        factorial(N-1)
        factorial(N-2)
        ...
        factorial(1)
        factorial(0)


    Therefore the number of function calls is proportional to N.

    Each call performs constant additional work apart from the recursive
    call and multiplication.

    Therefore:

        Time Complexity = O(N)


    More formally:

        T(N) = T(N-1) + O(1)

    which gives:

        O(N)


    ============================================================================
    14. SPACE COMPLEXITY
    ============================================================================

    Recursive factorial uses:

        O(N)

    auxiliary space.


    Reason:

        Call stack depth is O(N).


    Compare this with the iterative version:

        Iterative:
            O(1) auxiliary space

        Recursive:
            O(N) auxiliary space


    This is one of the most important differences between the two
    implementations.


    ============================================================================
    15. ZERO CASE
    ============================================================================

    Input:

        0


    Call:

        factorial(0)


    Base case:

        number == 0


    Therefore:

        return 1;


    Output:

        Factorial: 1


    This correctly implements:

        0! = 1


    ============================================================================
    16. ONE CASE
    ============================================================================

    Input:

        1


    Call sequence:

        factorial(1)
        -> factorial(0)


    Base case:

        factorial(0) = 1


    Return:

        factorial(1)
        = 1 * 1
        = 1


    Therefore:

        1! = 1


    ============================================================================
    17. TWO CASE
    ============================================================================

    Input:

        2


    Calls:

        factorial(2)
        -> factorial(1)
        -> factorial(0)


    Returns:

        factorial(0) = 1

        factorial(1) = 1 * 1 = 1

        factorial(2) = 2 * 1 = 2


    Therefore:

        2! = 2


    ============================================================================
    18. NEGATIVE INPUT
    ============================================================================

    The basic factorial problem is defined for:

        N >= 0


    The main function therefore checks:

        if (number < 0)


    and stops before calling the recursive factorial function.


    This is important because the recursive function is intentionally
    designed around the base case:

        number == 0


    If negative input were passed into it without validation, the recursive
    calls would continue:

        factorial(-1)
        factorial(-2)
        factorial(-3)
        ...


    which would never reach:

        number == 0


    Therefore input validation prevents invalid recursion.


    ============================================================================
    19. WHY factorial(number - 1) MOVES TOWARD THE BASE CASE
    ============================================================================

    A recursive function must make progress toward its stopping condition.

    Here the base case is:

        number == 0


    The recursive call uses:

        number - 1


    Therefore:

        5 -> 4 -> 3 -> 2 -> 1 -> 0


    Every call gets closer to zero.

    This guarantees termination for valid non-negative input.


    ============================================================================
    20. WHAT WOULD HAPPEN IF WE USED factorial(number + 1)?
    ============================================================================

    Suppose the recursive case were conceptually:

        factorial(number + 1)


    Starting from:

        5


    would produce:

        5 -> 6 -> 7 -> 8 -> ...


    This moves AWAY from the base case:

        0


    Therefore recursion would not terminate.


    The recursive call must move toward the base case.


    ============================================================================
    21. RETURN IS VERY IMPORTANT
    ============================================================================

    Consider:

        return number * factorial(number - 1);


    The keyword:

        return

    is essential.

    It means:

        calculate the recursive result
        and send it back to the previous call.


    Example:

        factorial(3)


    becomes:

        3 * factorial(2)


    Once factorial(2) returns:

        2


    the expression becomes:

        3 * 2


    and returns:

        6


    Without correctly returning the recursive result, the computed values
    would not propagate back through the call stack.


    ============================================================================
    22. RECURSION HAS TWO PHASES
    ============================================================================

    It is useful to think of this factorial recursion as having two phases.


    PHASE 1 — CALLING DOWN

        factorial(5)
        factorial(4)
        factorial(3)
        factorial(2)
        factorial(1)
        factorial(0)


    PHASE 2 — RETURNING UP

        factorial(0) -> 1
        factorial(1) -> 1
        factorial(2) -> 2
        factorial(3) -> 6
        factorial(4) -> 24
        factorial(5) -> 120


    This downward and upward behavior is fundamental to recursion.


    ============================================================================
    23. ITERATIVE VS RECURSIVE FACTORIAL
    ============================================================================

    ITERATIVE:

        Uses a loop.

        Concept:

            ans = 1

            for i = 1 to N:
                ans *= i


    RECURSIVE:

        Uses a function calling itself.

        Concept:

            factorial(N)
                = N * factorial(N-1)

            base:
                factorial(0) = 1


    Complexity:

        Iterative:
            Time  = O(N)
            Space = O(1) auxiliary


        Recursive:
            Time  = O(N)
            Space = O(N) auxiliary


    Both have the same asymptotic time complexity for this basic problem,
    but recursion uses additional call-stack space.


    ============================================================================
    24. WHICH ONE IS MORE SPACE-EFFICIENT?
    ============================================================================

    For the basic factorial problem:

        Iterative:
            O(1) auxiliary space

        Recursive:
            O(N) auxiliary space


    Therefore the iterative version is more space-efficient.


    The recursive version is valuable because it directly represents the
    mathematical recurrence and teaches recursion and call-stack behavior.


    ============================================================================
    25. INTEGER OVERFLOW
    ============================================================================

    Factorial values grow extremely quickly.

        5!  = 120

        10! = 3628800

        15! = 1307674368000

        20! = 2432902008176640000

        21! = 51090942171709440000


    For signed 64-bit long long:

        20! fits

    but:

        21! does not fit


    Therefore the recursive algorithm itself is not the only concern.

    The DATA TYPE used to store the result must also be capable of holding
    the result.


    ============================================================================
    26. WHY long long IS USED
    ============================================================================

    The program uses:

        long long


    rather than:

        int


    because factorial values become large quickly.

    A 32-bit signed int cannot store:

        13!


    because:

        13! = 6227020800


    which is greater than:

        2147483647


    A signed 64-bit long long can store factorial values through:

        20!


    but not:

        21!


    for the standard signed 64-bit range.


    ============================================================================
    27. BIG INTEGER CONSIDERATION
    ============================================================================

    If the problem asks for:

        100!
        500!
        1000!
        10000!

    then:

        int

    and:

        long long

    are not enough to store the complete result.


    A big-integer / arbitrary-precision representation would be needed.

    The recursive mathematical relationship remains:

        N! = N * (N-1)!

    but the data representation must support very large numbers.


    ============================================================================
    28. COMMON MISTAKE #1 — NO BASE CASE
    ============================================================================

    Wrong recursive design:

        factorial(N)
        {
            return N * factorial(N - 1);
        }


    There is no stopping condition.

    This causes:

        infinite recursion

    until:

        stack overflow


    Correct design requires:

        if (N == 0)
            return 1;


    ============================================================================
    29. COMMON MISTAKE #2 — WRONG BASE CASE VALUE
    ============================================================================

    Wrong:

        if (N == 0)
            return 0;


    Why wrong?

        0! = 1


    If factorial(0) returned 0, then:

        factorial(1)
        = 1 * factorial(0)
        = 1 * 0
        = 0


    and every larger factorial would also become zero.


    Correct:

        if (N == 0)
            return 1;


    ============================================================================
    30. COMMON MISTAKE #3 — MOVING AWAY FROM THE BASE CASE
    ============================================================================

    Wrong direction:

        factorial(N + 1)


    Correct direction:

        factorial(N - 1)


    because:

        N -> N-1 -> N-2 -> ... -> 0


    moves toward the base case.


    ============================================================================
    31. COMMON MISTAKE #4 — FORGETTING return
    ============================================================================

    The recursive result must be returned:

        return number * factorial(number - 1);


    The recursive call produces a value that the current call needs
    to multiply by number.


    ============================================================================
    32. COMMON MISTAKE #5 — USING int FOR LARGE RESULTS
    ============================================================================

    Even though recursion is correct mathematically, the result can
    overflow the selected data type.

    Always check the input constraint and expected output range.


    ============================================================================
    33. COMMON MISTAKE #6 — NEGATIVE INPUT WITHOUT VALIDATION
    ============================================================================

    If:

        number = -1


    and the recursive function only stops at:

        number == 0


    then:

        -1 -> -2 -> -3 -> ...


    Therefore invalid negative input should be rejected when the problem
    does not define factorial for negative numbers.


    ============================================================================
    34. DETAILED CALL-STACK VIEW FOR 4!
    ============================================================================

    Input:

        4


    Stack growth:


        | factorial(0) |
        | factorial(1) |
        | factorial(2) |
        | factorial(3) |
        | factorial(4) |
        +--------------+


    At this point factorial(0) executes the base case and returns 1.


    Then stack unwinds:


        factorial(0) returns 1
        factorial(1) returns 1
        factorial(2) returns 2
        factorial(3) returns 6
        factorial(4) returns 24


    Final:

        4! = 24


    ============================================================================
    35. RECURSION FORMULA
    ============================================================================

    The recursive factorial function follows:

        F(N) = N * F(N-1)


    Base:

        F(0) = 1


    Therefore:

        F(1) = 1 * F(0)
             = 1


        F(2) = 2 * F(1)
             = 2


        F(3) = 3 * F(2)
             = 6


        F(4) = 4 * F(3)
             = 24


        F(5) = 5 * F(4)
             = 120


    ============================================================================
    36. TIME COMPLEXITY DERIVATION
    ============================================================================

    Each recursive call reduces N by 1.

    Therefore:

        T(N) = T(N-1) + O(1)


    Expanding:

        T(N)
        = T(N-1) + 1
        = T(N-2) + 2
        = ...
        = T(0) + N


    Therefore:

        T(N) = O(N)


    ============================================================================
    37. SPACE COMPLEXITY DERIVATION
    ============================================================================

    Maximum active calls:

        factorial(N)
        factorial(N-1)
        factorial(N-2)
        ...
        factorial(0)


    Number of active calls is proportional to N.

    Therefore:

        Space = O(N)


    This is call-stack space, not a user-created container.


    ============================================================================
    38. EDGE CASES
    ============================================================================

    Test:

        N = 0
        N = 1
        N = 2
        N = 3
        N = 5
        N = 10
        N = 20


    Important results:

        0!  = 1

        1!  = 1

        2!  = 2

        3!  = 6

        5!  = 120

        10! = 3628800

        20! = 2432902008176640000


    Negative values:

        Not part of the basic factorial definition.


    ============================================================================
    39. PLATFORM NOTE
    ============================================================================

    This approach is suitable for the standard factorial problem commonly
    encountered on:

        GeeksforGeeks (GFG)
        Naukri (Code360)
        HackerEarth
        CodeChef


    However, exact constraints can differ.

    Always check:

        - Input range
        - Number of test cases
        - Required output format
        - Whether modulo is required
        - Whether arbitrary precision is required


    ============================================================================
    40. INTERVIEW EXPECTATIONS
    ============================================================================

    If asked to implement factorial recursively, be ready to explain:

        1. What recursion is.

        2. What the base case is.

        3. Why:
               0! = 1

        4. What the recursive case is.

        5. Why:
               number - 1

           moves toward the base case.

        6. How the call stack behaves.

        7. What stack unwinding means.

        8. Time complexity:
               O(N)

        9. Auxiliary space:
               O(N)

       10. Why iterative factorial uses:
               O(1)

           auxiliary space.

       11. Why factorial causes integer overflow.

       12. How you would handle very large factorials.


    ============================================================================
    41. QUICK CHEAT SHEET
    ============================================================================

    Problem:

        Factorial of a Number


    Mathematical definition:

        N! = N * (N-1)!


    Base case:

        0! = 1


    Recursive case:

        N! = N * (N-1)!


    Recursive function idea:

        return N * factorial(N - 1);


    Stop condition:

        N == 0


    Time:

        O(N)


    Recursive Auxiliary Space:

        O(N)


    Iterative Auxiliary Space:

        O(1)


    Signed long long:

        20! fits

        21! does not fit


    Valid basic input:

        N >= 0


    Platforms:

        GeeksforGeeks (GFG)
        Naukri (Code360)
        HackerEarth
        CodeChef


    ============================================================================
    42. FINAL CONCEPT
    ============================================================================

    The most important recursive pattern is:

        factorial(N)
        =
        N * factorial(N - 1)


    until:

        factorial(0)
        =
        1


    Think of recursion as two phases:

        CALL DOWN:

            5
            4
            3
            2
            1
            0


        RETURN UP:

            1
            1
            2
            6
            24
            120


    The three most important things to remember are:

        1. Every recursion needs a BASE CASE.

        2. Every recursive call must move toward the BASE CASE.

        3. Recursive factorial takes O(N) call-stack space.


    ============================================================================
    END
    ============================================================================
*/