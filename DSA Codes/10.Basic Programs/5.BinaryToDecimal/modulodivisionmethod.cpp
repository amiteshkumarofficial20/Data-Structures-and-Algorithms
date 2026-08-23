/*
    ========================================================================
        BINARY TO DECIMAL — MODULO AND DIVISION METHOD
    ========================================================================

    Method Name:
        Modulo-and-Division Method
        Positional Value Method
        Repeated Digit Processing Method

    Core idea:

        A binary number is given as digits 0 and 1.

        Each digit has a positional value based on powers of 2.

        For example:

            1101

        means:

            1 * 2^3
          + 1 * 2^2
          + 0 * 2^1
          + 1 * 2^0

        = 8 + 4 + 0 + 1

        = 13

    This file contains:
        1. Detailed Binary -> Decimal approach
        2. Modulo-and-Division based digit extraction
        3. Detailed dry run
        4. Why % 10 works for a binary-digit integer
        5. Why / 10 works
        6. Positional-value approach
        7. Left-to-right approach
        8. String-based version
        9. Validation considerations
        10. Complexity discussion
        11. Important limitations
        12. Comparison of approaches

    IMPORTANT:

        In this particular approach, the binary input is entered as
        an INTEGER such as:

            1101

        C++ treats 1101 as the decimal integer one thousand one
        hundred one.

        We are using its decimal digits:

            1, 1, 0, 1

        as binary digits and converting those digits to their decimal
        numerical value:

            1101(binary) = 13(decimal)

    Complexity of the basic approach:

        Time  = O(log10 B)
        Space = O(1) auxiliary

    Here B means the input integer containing the binary digits.

    IMPORTANT LIMITATION:

        If the binary input has too many digits, storing it inside
        an int can overflow.

        For larger binary strings, a string-based approach is safer.
*/

#include <iostream>
using namespace std;

// ========================================================================
// 1. MODULO + DIVISION APPROACH
// ========================================================================

int main()
{
    int number;

    cout << "Enter a Binary Number: ";
    cin >> number;

    // 'ans' stores the decimal value that we are constructing.
    //
    // Example:
    //
    // Binary input:
    //
    //      1101
    //
    // Decimal answer:
    //
    //      13
    //
    // So ans will finally become:
    //
    //      13
    int ans = 0;

    // 'power' represents the current power of 2.
    //
    // The rightmost binary digit has:
    //
    //      2^0 = 1
    //
    // The next digit has:
    //
    //      2^1 = 2
    //
    // Then:
    //
    //      2^2 = 4
    //
    // Then:
    //
    //      2^3 = 8
    //
    // Therefore we start with:
    //
    //      power = 1
    //
    // which is 2^0.
    int power = 1;

    while (number > 0)
    {
        // ------------------------------------------------------------
        // STEP 1: Extract the last binary digit
        // ------------------------------------------------------------
        //
        // % is the modulo operator.
        //
        // number % 10 gives the LAST DECIMAL DIGIT of number.
        //
        // Since our input is written as a sequence of binary digits,
        // this last decimal digit is also the current binary digit.
        //
        // Example:
        //
        //      number = 1101
        //
        //      1101 % 10 = 1
        //
        // So:
        //
        //      digit = 1
        //
        // The extracted digit will always be 0 or 1 if the input is
        // a valid binary number.
        int digit = number % 10;

        // ------------------------------------------------------------
        // STEP 2: Add the digit's positional contribution
        // ------------------------------------------------------------
        //
        // The current digit represents:
        //
        //      digit * 2^position
        //
        // Instead of calculating pow(2, position), we maintain the
        // current power directly in the variable 'power'.
        //
        // Example for 1101:
        //
        // First digit from right:
        //
        //      1 * 2^0 = 1
        //
        // Second:
        //
        //      0 * 2^1 = 0
        //
        // Third:
        //
        //      1 * 2^2 = 4
        //
        // Fourth:
        //
        //      1 * 2^3 = 8
        //
        // Total:
        //
        //      1 + 0 + 4 + 8 = 13
        ans += digit * power;

        // ------------------------------------------------------------
        // STEP 3: Move to the next binary digit
        // ------------------------------------------------------------
        //
        // / 10 removes the last DECIMAL digit.
        //
        // Example:
        //
        //      1101 / 10 = 110
        //
        //      110 / 10 = 11
        //
        //      11 / 10 = 1
        //
        //      1 / 10 = 0
        //
        // This allows us to process the binary digits from:
        //
        //      RIGHT -> LEFT
        //
        number /= 10;

        // ------------------------------------------------------------
        // STEP 4: Move from 2^k to 2^(k+1)
        // ------------------------------------------------------------
        //
        // Powers of 2:
        //
        //      1
        //      2
        //      4
        //      8
        //      16
        //      ...
        //
        // Multiplying by 2 moves to the next power.
        //
        // Therefore:
        //
        //      power *= 2
        //
        // changes:
        //
        //      2^0 -> 2^1 -> 2^2 -> 2^3 -> ...
        power *= 2;
    }

    cout << "Decimal Form: " << ans << endl;

    return 0;
}

/*
    ========================================================================
    2. DRY RUN FOR number = 1101
    ========================================================================

    Input:

        1101

    Binary interpretation:

        1101₂


    Initial state:

        number = 1101
        ans    = 0
        power  = 1


    ------------------------------------------------------------------------
    ITERATION 1
    ------------------------------------------------------------------------

    Extract last digit:

        digit = 1101 % 10
              = 1

    Current power:

        power = 1
              = 2^0

    Contribution:

        digit * power
        = 1 * 1
        = 1

    Update:

        ans = 0 + 1
            = 1

    Remove last digit:

        number = 1101 / 10
               = 110

    Move to next power:

        power = 1 * 2
              = 2


    Current state:

        number = 110
        ans    = 1
        power  = 2


    ------------------------------------------------------------------------
    ITERATION 2
    ------------------------------------------------------------------------

    Extract last digit:

        digit = 110 % 10
              = 0

    Current power:

        power = 2
              = 2^1

    Contribution:

        digit * power
        = 0 * 2
        = 0

    Update:

        ans = 1 + 0
            = 1

    Remove last digit:

        number = 110 / 10
               = 11

    Move to next power:

        power = 2 * 2
              = 4


    Current state:

        number = 11
        ans    = 1
        power  = 4


    ------------------------------------------------------------------------
    ITERATION 3
    ------------------------------------------------------------------------

    Extract last digit:

        digit = 11 % 10
              = 1

    Current power:

        power = 4
              = 2^2

    Contribution:

        digit * power
        = 1 * 4
        = 4

    Update:

        ans = 1 + 4
            = 5

    Remove last digit:

        number = 11 / 10
               = 1

    Move to next power:

        power = 4 * 2
              = 8


    Current state:

        number = 1
        ans    = 5
        power  = 8


    ------------------------------------------------------------------------
    ITERATION 4
    ------------------------------------------------------------------------

    Extract last digit:

        digit = 1 % 10
              = 1

    Current power:

        power = 8
              = 2^3

    Contribution:

        digit * power
        = 1 * 8
        = 8

    Update:

        ans = 5 + 8
            = 13

    Remove last digit:

        number = 1 / 10
               = 0

    Move to next power:

        power = 8 * 2
              = 16


    number is now 0.

    Loop ends.


    Final answer:

        ans = 13


    Therefore:

        1101(binary) = 13(decimal)


    ========================================================================
    3. WHY % 10 WORKS HERE
    ========================================================================

    IMPORTANT:

        We are NOT using:

            number % 2

        here.

    The input is written as a decimal integer containing binary digits.

    Example:

        number = 1101

    We want to extract its LAST DIGIT:

        1

    For a decimal integer, the last digit is obtained using:

        number % 10

    Therefore:

        1101 % 10 = 1

    This gives the rightmost binary digit.


    Another example:

        number = 1010

        1010 % 10 = 0

    So the rightmost binary digit is:

        0


    ========================================================================
    4. WHY / 10 WORKS HERE
    ========================================================================

    Integer division by 10 removes the last decimal digit.

    Since the input digits are being used as binary digits, this
    effectively removes the already-processed binary digit.

    Example:

        1101 / 10 = 110
         110 / 10 = 11
          11 / 10 = 1
           1 / 10 = 0

    Therefore the digits are processed:

        1 -> 0 -> 1 -> 1

    which is:

        LSB -> MSB


    ========================================================================
    5. WHY POWER OF 2 IS USED
    ========================================================================

    Binary is base 2.

    Therefore each position has a power-of-2 value.

    For:

        1101

    positions from right to left are:

        2^0   2^1   2^2   2^3

    So:

        1    1    0    1
        |    |    |    |
        8    4    2    1

    Therefore:

        1*8 + 1*4 + 0*2 + 1*1

        = 8 + 4 + 0 + 1

        = 13


    ========================================================================
    6. WHY power *= 2 WORKS
    ========================================================================

    We start with:

        power = 1

    which is:

        2^0

    After one iteration:

        power *= 2

        1 * 2 = 2

    which is:

        2^1

    Next:

        2 * 2 = 4

    which is:

        2^2

    Next:

        4 * 2 = 8

    which is:

        2^3

    Therefore:

        1 -> 2 -> 4 -> 8 -> 16 -> ...

    automatically generates:

        2^0 -> 2^1 -> 2^2 -> 2^3 -> ...


    ========================================================================
    7. GENERAL FORMULA
    ========================================================================

    If the binary number is:

        b_k b_(k-1) ... b_2 b_1 b_0

    then its decimal value is:

        b_0 * 2^0
      + b_1 * 2^1
      + b_2 * 2^2
      + ...
      + b_k * 2^k

    Each binary digit is either:

        0
    or:
        1


    ========================================================================
    8. IMPORTANT: INPUT 1101 IS NOT ACTUALLY A BINARY INTEGER IN C++
    ========================================================================

    When we write:

        int number = 1101;

    C++ interprets 1101 as the DECIMAL integer:

        one thousand one hundred one

    It does NOT interpret it as:

        binary 1101 = decimal 13


    We are simply using the decimal digits of that integer as binary
    digits.

    Therefore:

        number % 10

    extracts the rightmost digit.

    And:

        number / 10

    removes the rightmost digit.


    ========================================================================
    9. LEFT-TO-RIGHT ALTERNATIVE
    ========================================================================

    There is another very important way to convert binary to decimal.

    Instead of processing from right to left, process from left to right.

    For each binary digit:

        ans = ans * 2 + digit;

    Example:

        1101

    Start:

        ans = 0

    Read 1:

        ans = 0 * 2 + 1
            = 1

    Read 1:

        ans = 1 * 2 + 1
            = 3

    Read 0:

        ans = 3 * 2 + 0
            = 6

    Read 1:

        ans = 6 * 2 + 1
            = 13

    Final:

        13


    ========================================================================
    10. STRING VERSION
    ========================================================================

    A string is generally safer when the binary input may contain
    many digits.

    Example idea:

        string binary;

        cin >> binary;

    Then each character can be processed as a binary digit.

    For a left-to-right conversion, conceptually:

        digit = binary[i] - '0';

        ans = ans * 2 + digit;

    This avoids treating a long binary number as an int.


    ========================================================================
    11. WHY STRING IS SAFER FOR LARGE INPUTS
    ========================================================================

    Suppose the input contains many binary digits.

    An int has a fixed range.

    Therefore:

        int number;

    cannot safely store arbitrarily long binary input.

    A string can store many characters, subject to available memory.

    Therefore for large binary inputs, prefer:

        string

    over:

        int


    ========================================================================
    12. VALID BINARY DIGITS
    ========================================================================

    Every binary digit must be:

        0
    or:
        1

    Valid:

        0
        1
        101
        1101
        111111

    Invalid:

        102
        1201
        201
        987


    The integer modulo/division approach shown above assumes that
    the input contains only binary digits.

    It does not by itself validate every digit before conversion.


    ========================================================================
    13. ZERO CASE
    ========================================================================

    If:

        number = 0

    then:

        while (number > 0)

    does not execute.

    Since:

        ans = 0

    the output is:

        Decimal Form: 0

    This correctly represents:

        0₂ = 0₁₀


    ========================================================================
    14. LEADING ZEROES
    ========================================================================

    Consider:

        00001101

    Numerically, this represents:

        1101

    which equals:

        13

    However, if the input is stored as an int:

        int number = 00001101;

    C++ does NOT preserve those leading zeroes as decimal input
    digits.

    For a problem where leading zeroes matter, use:

        string

    instead.


    ========================================================================
    15. TIME COMPLEXITY
    ========================================================================

    Suppose the binary input contains L digits.

    The loop processes one digit during each iteration.

    Therefore:

        Number of iterations = L

    Time Complexity:

        O(L)

    If the input is represented by an integer B containing L decimal
    digits, then:

        L = O(log10 B)

    So the integer-based modulo/division loop can also be described as:

        O(log B)


    ========================================================================
    16. SPACE COMPLEXITY
    ========================================================================

    The basic integer approach uses only:

        number
        digit
        ans
        power

    These are a fixed number of variables.

    Therefore:

        Auxiliary Space = O(1)

    No vector, array, stack, recursion, or dynamically growing
    container is required.


    ========================================================================
    17. OVERFLOW CONSIDERATIONS
    ========================================================================

    There are two possible overflow concerns.

    1. INPUT OVERFLOW

       If the binary number has too many digits to fit into int,
       then:

           int number;

       is not appropriate.

       Use a string.

    2. ANSWER OVERFLOW

       Even if the input fits in an integer, the decimal value of
       the binary number must also fit in the selected output type.

       For example, a binary number with 31 bits can represent values
       up to:

           2^31 - 1

       while larger binary strings may require:

           long long

       or arbitrary-precision handling.


    ========================================================================
    18. COMPARISON WITH DECIMAL TO BINARY
    ========================================================================

    DECIMAL -> BINARY:

        remainder = number % 2;
        number /= 2;

    The remainder gives a binary digit.


    BINARY -> DECIMAL:

        digit = number % 10;
        number /= 10;

        ans += digit * power;
        power *= 2;


    Main difference:

        Decimal -> Binary
            repeatedly divides by BASE 2.

        Binary -> Decimal
            extracts binary digits and applies powers of BASE 2.


    ========================================================================
    19. IMPORTANT DIFFERENCE BETWEEN % 2 AND % 10
    ========================================================================

    In Decimal -> Binary:

        number % 2

    is used because division by 2 gives the next binary remainder.


    In this Binary -> Decimal integer-input approach:

        number % 10

    is used because we need the last DIGIT of the input written
    as a decimal integer.

    So:

        % 2
            extracts a remainder from division by 2.

        % 10
            extracts the last decimal digit of the input.


    ========================================================================
    20. IMPORTANT DIFFERENCE BETWEEN / 2 AND / 10
    ========================================================================

    Decimal -> Binary:

        number /= 2;

    This reduces the numerical value by a factor of 2.


    Binary -> Decimal using integer digits:

        number /= 10;

    This removes one digit from the binary representation written
    as a decimal-looking integer.


    ========================================================================
    21. GENERALIZATION TO OTHER BASES
    ========================================================================

    Binary is base 2.

    A positional number system with base B can be converted using
    the same positional-value idea.

    For a digit d at position k:

        contribution = d * B^k


    Examples:

        Binary:
            B = 2

        Octal:
            B = 8

        Decimal:
            B = 10

        Hexadecimal:
            B = 16


    ========================================================================
    22. EXAMPLE: 10101
    ========================================================================

    Binary:

        10101

    Powers:

        2^4  2^3  2^2  2^1  2^0

    Values:

        16    8    4    2    1

    Digits:

        1     0    1    0    1

    Calculation:

        1*16 + 0*8 + 1*4 + 0*2 + 1*1

        = 16 + 0 + 4 + 0 + 1

        = 21

    Therefore:

        10101₂ = 21₁₀


    ========================================================================
    23. QUICK CHEAT SHEET
    ========================================================================

    Binary input as integer:

        int number;

    Extract last binary digit:

        int digit = number % 10;

    Remove last input digit:

        number /= 10;

    Start first power:

        int power = 1;

    Add positional contribution:

        ans += digit * power;

    Move to next power of 2:

        power *= 2;

    Basic complexity:

        Time  = O(L)
        Space = O(1)

    Safer for large input:

        string


    ========================================================================
    END
    ========================================================================
*/