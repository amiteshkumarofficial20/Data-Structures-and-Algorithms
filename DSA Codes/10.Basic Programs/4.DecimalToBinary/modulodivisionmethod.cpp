/*
    ================================================================
    DECIMAL TO BINARY — MODULO AND DIVISION METHOD
    ================================================================

    Method Name:
        Modulo-and-Division Method
        Repeated Division by 2 Method
        Repeated Remainder Method

    Core idea:
        remainder = number % 2;
        number    = number / 2;

    The remainder is always 0 or 1, so it gives the next
    binary digit.

    This file contains:
        1. Your exact integer-based approach
        2. Detailed dry-run explanation
        3. String-based version
        4. General base-conversion version
        5. Complexity discussion

    Important:
        The integer-based approach stores binary digits such as
        1101 as the DECIMAL integer 1101. It does not make C++
        treat 1101 as a binary integer.

    Complexity of the basic approach:
        Time  = O(log n)
        Space = O(1) auxiliary

    Limitation:
        The integer answer can overflow for sufficiently large
        binary representations.
*/

// ================================================================
// 1. YOUR EXACT MODULO + DIVISION APPROACH
// ================================================================

#include <iostream>
using namespace std;

int main()
{
    int number, remainder;

    cout << "Enter a Number: ";
    cin >> number;

    // 'ans' stores the binary digits as a decimal-looking integer.
    //
    // Example:
    // Decimal 13 -> binary digits 1101
    //
    // ans will contain the integer value:
    // 1101
    //
    // Important:
    // C++ is NOT treating ans as binary here.
    int ans = 0;

    // 'i' represents the position where the current binary digit
    // will be placed.
    //
    // It changes as:
    //
    // 1
    // 10
    // 100
    // 1000
    // ...
    //
    // This allows us to build:
    //
    // 1101
    //
    // as:
    //
    // 1*1 + 0*10 + 1*100 + 1*1000
    int i = 1;

    while (number > 0)
    {
        // ------------------------------------------------------------
        // STEP 1: Extract the current binary digit
        // ------------------------------------------------------------
        //
        // % is the modulo operator.
        //
        // number % 2 gives the remainder after division by 2.
        //
        // For integer numbers, the remainder is either:
        //
        // 0
        // or
        // 1
        //
        // These are exactly the two digits used by binary.
        remainder = number % 2;

        // ------------------------------------------------------------
        // STEP 2: Move to the next quotient
        // ------------------------------------------------------------
        //
        // This is integer division.
        //
        // Example:
        //
        // 13 / 2 = 6
        //  6 / 2 = 3
        //  3 / 2 = 1
        //  1 / 2 = 0
        //
        // The quotient becomes the number processed
        // in the next iteration.
        number /= 2;

        // ------------------------------------------------------------
        // STEP 3: Put the extracted bit into the answer
        // ------------------------------------------------------------
        //
        // Suppose:
        //
        // remainder = 1
        // i = 100
        //
        // Then:
        //
        // remainder * i
        // = 1 * 100
        // = 100
        //
        // If remainder is 0, nothing is added.
        ans += remainder * i;

        // ------------------------------------------------------------
        // STEP 4: Move to the next position
        // ------------------------------------------------------------
        //
        // i changes:
        //
        // 1 -> 10 -> 100 -> 1000 -> ...
        //
        // This is how the binary digits are assembled
        // into the displayed integer.
        i *= 10;
    }

    cout << "Binary Form: " << ans << endl;

    return 0;
}

/*
    ================================================================
    2. DRY RUN FOR number = 13
    ================================================================

    Initial state:

        number = 13
        ans    = 0
        i      = 1

    ------------------------------------------------
    Iteration 1
    ------------------------------------------------

        remainder = 13 % 2
                  = 1

        number = 13 / 2
               = 6

        ans = 0 + (1 * 1)
            = 1

        i = 1 * 10
          = 10

    State:

        number = 6
        ans    = 1
        i      = 10

    ------------------------------------------------
    Iteration 2
    ------------------------------------------------

        remainder = 6 % 2
                  = 0

        number = 6 / 2
               = 3

        ans = 1 + (0 * 10)
            = 1

        i = 10 * 10
          = 100

    State:

        number = 3
        ans    = 1
        i      = 100

    ------------------------------------------------
    Iteration 3
    ------------------------------------------------

        remainder = 3 % 2
                  = 1

        number = 3 / 2
               = 1

        ans = 1 + (1 * 100)
            = 101

        i = 100 * 10
          = 1000

    State:

        number = 1
        ans    = 101
        i      = 1000

    ------------------------------------------------
    Iteration 4
    ------------------------------------------------

        remainder = 1 % 2
                  = 1

        number = 1 / 2
               = 0

        ans = 101 + (1 * 1000)
            = 1101

        i = 1000 * 10
          = 10000

    number is now 0.

    Loop ends.

    Output:

        Binary Form: 1101

    Therefore:

        13(decimal) = 1101(binary)


    ================================================================
    3. WHY % 2 WORKS
    ================================================================

    Every integer division by 2 follows:

        number = 2 * quotient + remainder

    The remainder can only be:

        0
        1

    Example:

        13 = 2 * 6 + 1

        12 = 2 * 6 + 0

    Therefore:

        number % 2

    extracts one binary digit.

    ================================================================
    4. WHY / 2 WORKS
    ================================================================

    Once the current remainder has been extracted, the quotient
    contains the remaining higher-order binary digits.

        13 / 2 = 6
         6 / 2 = 3
         3 / 2 = 1
         1 / 2 = 0

    So repeated division by 2 eventually extracts every bit.

    The remainders are generated:

        LSB -> next bit -> ... -> MSB

    Normal binary notation is written:

        MSB -> ... -> LSB

    The string approach therefore needs a reverse.

    Your integer approach avoids an explicit reverse by placing
    each remainder directly into its decimal-looking position
    using:

        ans += remainder * i;
        i *= 10;


    ================================================================
    5. IMPORTANT: ans IS NOT A BINARY INTEGER
    ================================================================

    If:

        ans = 1101;

    C++ considers this the decimal integer:

        one thousand one hundred one

    It does NOT mean:

        1101(binary) = 13(decimal)

    For example:

        int ans = 1101;
        cout << ans + 1;

    prints:

        1102

    Therefore this approach constructs the DISPLAYED binary digits
    as an integer. It is excellent for learning the conversion
    process, but it is not the same as storing the actual binary
    value in a machine integer.


    ================================================================
    6. TIME COMPLEXITY
    ================================================================

    Every iteration approximately halves 'number':

        n
        n/2
        n/4
        n/8
        ...
        1
        0

    Therefore the number of iterations is:

        floor(log2(n)) + 1

    for positive n.

    Time Complexity:

        O(log n)


    ================================================================
    7. SPACE COMPLEXITY
    ================================================================

    The program uses only a fixed number of variables:

        number
        remainder
        ans
        i

    No vector, array, stack, recursion, or dynamically growing
    container is required.

    Auxiliary Space:

        O(1)

    Important limitation:

        'ans' is an int, so it has a fixed numeric range.
        For sufficiently large inputs, constructing the binary
        digits inside an int can overflow.


    ================================================================
    8. ZERO CASE
    ================================================================

    If:

        number = 0

    then:

        while (number > 0)

    does not execute.

    Since:

        ans = 0

    the output is correctly:

        Binary Form: 0


    ================================================================
    9. STRING VERSION OF THE SAME MODULO/DIVISION METHOD
    ================================================================

    The arithmetic method is exactly the same:

        remainder = number % 2;
        number /= 2;

    Only the answer storage is different.

    A string is safer for large binary representations because
    it is not restricted by the numeric range of int.

    Example:

        string binary;

        while (number > 0)
        {
            int remainder = number % 2;

            binary.push_back('0' + remainder);

            number /= 2;
        }

        reverse(binary.begin(), binary.end());


    ================================================================
    10. GENERALIZATION TO ANY BASE
    ================================================================

    The same algorithm works for conversion from decimal to
    another base.

    For base 'b':

        remainder = number % b;
        number /= b;

    Repeat until number becomes zero.

    Examples:

        Binary:
            base = 2

        Octal:
            base = 8

        Hexadecimal:
            base = 16

    Binary is simply the special case where:

        base = 2
*/