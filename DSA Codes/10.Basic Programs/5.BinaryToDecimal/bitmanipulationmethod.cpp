/*
    ============================================================================
        BINARY TO DECIMAL — BIT MANIPULATION METHOD
    ============================================================================

    Method Name:
        Bit-Manipulation Method
        Left-Shift and Bitwise-OR Method
        Binary Accumulation Method

    IMPORTANT DIFFERENCE FROM DECIMAL -> BINARY:

        In Decimal -> Binary, we commonly use:

            remainder = number & 1;
            number >>= 1;

        because the input is an actual decimal integer whose machine-level
        bits are being inspected.

        In Binary -> Decimal, the input is normally given as a sequence
        of binary DIGITS such as:

            1101

        If we write:

            int number = 1101;

        C++ treats 1101 as the DECIMAL integer one thousand one hundred one.
        Its machine-level binary representation is NOT the four digits 1101.

        Therefore, for a Binary -> Decimal problem, the safest and most
        meaningful approach is to read the binary representation as a
        STRING and process each binary digit.

    Core bit-manipulation expressions:

        ans = (ans << 1) | bit;

    or equivalently:

        ans = ans * 2 + bit;

    The bit-manipulation version replaces:

        ans = ans * 2 + bit;

    with:

        ans = (ans << 1) | bit;

    Core operations:

        1. Left Shift (<<)
        2. Bitwise OR (|)

    Main idea:

        Read the binary digits from LEFT to RIGHT.

        For every digit:

            1. Shift the current decimal value left by one bit.
            2. Add the current binary digit using bitwise OR.

    Example:

        Binary:

            1101

        Process:

            ans = 0

            read 1:
                ans = (0 << 1) | 1
                    = 1

            read 1:
                ans = (1 << 1) | 1
                    = 3

            read 0:
                ans = (3 << 1) | 0
                    = 6

            read 1:
                ans = (6 << 1) | 1
                    = 13

        Therefore:

            1101(binary) = 13(decimal)

    This file contains:

        1. Complete bit-manipulation approach
        2. Why string input is required
        3. Why << is used
        4. Why | is used
        5. Detailed dry run
        6. Binary place-value explanation
        7. Relationship between << 1 and * 2
        8. Relationship between | bit and + bit
        9. Validation of binary digits
       10. Zero case
       11. Leading zeroes
       12. Overflow considerations
       13. Fixed-width considerations
       14. Complexity
       15. Comparison with modulo/division method
       16. Common mistakes
       17. Additional bit-manipulation examples

    Complexity:

        Time  = O(L)
        Space = O(1) auxiliary

    where:

        L = number of binary digits

    The input string itself requires O(L) storage.
*/

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// 1. BINARY TO DECIMAL — BIT MANIPULATION APPROACH
// ============================================================================

int main()
{
    string binary;

    cout << "Enter a Binary Number: ";
    cin >> binary;

    // 'ans' stores the actual DECIMAL numerical value.
    //
    // Unlike the Decimal -> Binary integer-answer approach, we are NOT
    // constructing something like:
    //
    //      ans = 1101
    //
    // Here:
    //
    //      ans = 13
    //
    // after processing 1101.
    //
    // Therefore this is an actual numerical conversion.
    unsigned int ans = 0;

    // Process the binary digits from:
    //
    //      LEFT -> RIGHT
    //
    // Example:
    //
    //      1101
    //      ^^^^
    //
    // First:
    //
    //      1
    //
    // Then:
    //
    //      1
    //
    // Then:
    //
    //      0
    //
    // Finally:
    //
    //      1
    for (char currentDigit : binary)
    {
        // ====================================================================
        // STEP 1: Validate that the current character is a binary digit
        // ====================================================================
        //
        // A binary number can contain only:
        //
        //      '0'
        //      '1'
        //
        // If any other character is encountered, the input is invalid.
        if (currentDigit != '0' && currentDigit != '1')
        {
            cout << "Invalid Binary Number" << endl;
            return 0;
        }

        // ====================================================================
        // STEP 2: Convert character '0'/'1' into integer 0/1
        // ====================================================================
        //
        // ASCII/character arithmetic:
        //
        //      '0' - '0' = 0
        //
        //      '1' - '0' = 1
        //
        // Therefore:
        //
        //      currentDigit - '0'
        //
        // converts the character into the corresponding integer bit.
        unsigned int bit = currentDigit - '0';

        // ====================================================================
        // STEP 3: LEFT SHIFT the current answer
        // ====================================================================
        //
        // The operation:
        //
        //      ans << 1
        //
        // shifts every bit of ans one position to the LEFT.
        //
        // For non-negative/unsigned integers:
        //
        //      ans << 1
        //
        // corresponds to multiplying by 2, provided the result fits
        // within the available integer width.
        //
        // Example:
        //
        //      ans = 3
        //
        // Binary:
        //
        //      0011
        //
        // After:
        //
        //      3 << 1
        //
        // we get:
        //
        //      0110
        //
        // which is decimal 6.
        //
        // Why do we need this?
        //
        // Because when we append a new binary digit to the right,
        // all previously processed digits move one binary position
        // to the left.
        //
        // Example:
        //
        //      processed = 11
        //
        // append 0:
        //
        //      110
        //
        // Numerically:
        //
        //      3 * 2 + 0 = 6
        //
        // Bitwise:
        //
        //      (3 << 1) | 0 = 6
        ans = ans << 1;

        // ====================================================================
        // STEP 4: Add the new bit using BITWISE OR
        // ====================================================================
        //
        // The operation:
        //
        //      ans | bit
        //
        // places the new binary bit into the least-significant position.
        //
        // Because bit is guaranteed to be either:
        //
        //      0
        //
        // or:
        //
        //      1
        //
        // the OR operation simply makes the last bit equal to that
        // input binary digit.
        //
        // Example:
        //
        //      ans = 6
        //
        // Binary:
        //
        //      0110
        //
        // bit = 1
        //
        // Then:
        //
        //      0110
        //    | 0001
        //    ------
        //      0111
        //
        // which is:
        //
        //      7
        //
        // Therefore:
        //
        //      ans = (ans << 1) | bit;
        //
        // is the complete update.
        ans = ans | bit;
    }

    cout << "Decimal Form: " << ans << endl;

    return 0;
}

/*
    ============================================================================
    2. WHY STRING INPUT IS IMPORTANT
    ============================================================================

    Suppose the binary input is:

        1101

    If you write:

        int number = 1101;

    C++ does NOT understand this as binary.

    It understands:

        1101

    as the decimal integer:

        one thousand one hundred one.

    Its actual machine representation is a completely different sequence
    of bits.

    Therefore this is WRONG for treating the four typed digits as a
    binary representation:

        int number;
        cin >> number;

        // then trying to use:
        number & 1

    Why?

    Because:

        1101 & 1

    operates on the actual binary representation of the decimal integer
    1101, NOT on the characters:

        '1' '1' '0' '1'

    For a Binary -> Decimal conversion problem where the input is written
    as binary digits, use:

        string binary;

        cin >> binary;

    Then process the characters.


    ============================================================================
    3. WHAT DOES BIT MANIPULATION MEAN HERE?
    ============================================================================

    Bit manipulation means using operations that directly operate on
    binary bits.

    The two main operations used in this conversion are:

        <<
        |

    They are:

        <<  = Left Shift
        |   = Bitwise OR


    ============================================================================
    4. LEFT SHIFT OPERATOR <<
    ============================================================================

    Syntax:

        value << k

    means:

        Shift the bits of 'value' left by k positions.

    Example:

        0011

    Left shift by 1:

        0110

    Therefore:

        3 << 1 = 6

    Another example:

        0101

    Left shift by 1:

        1010

    Therefore:

        5 << 1 = 10

    For an unsigned/non-negative value, shifting left by one position
    corresponds to multiplying by 2, as long as the result fits.


    ============================================================================
    5. WHY LEFT SHIFT IS USED IN BINARY -> DECIMAL
    ============================================================================

    Consider:

        11

    Its decimal value is:

        3

    Now append a new binary digit:

        0

    The new number is:

        110

    Mathematically:

        3 * 2 + 0
        = 6

    Bitwise:

        3 << 1
        = 6

        6 | 0
        = 6

    Therefore:

        (3 << 1) | 0
        = 6

    If the new digit is 1:

        3 * 2 + 1
        = 7

    Bitwise:

        (3 << 1) | 1
        = 7

    So every time we read a new binary digit:

        shift previous answer left
        +
        put the new bit at the right


    ============================================================================
    6. BITWISE OR OPERATOR |
    ============================================================================

    OR works bit-by-bit.

    Truth table:

        A   B   A | B

        0   0     0
        0   1     1
        1   0     1
        1   1     1

    OR produces 1 when at least one of the corresponding bits is 1.


    ============================================================================
    7. WHY | bit WORKS AFTER LEFT SHIFT
    ============================================================================

    After:

        ans << 1

    the least-significant bit becomes 0.

    Example:

        ans = 6

        binary:
            0110

    After:

        6 << 1

    we get:

        1100

    The last bit is 0.

    Now suppose the next input bit is:

        1

    We perform:

        1100
      | 0001
      ------
        1101

    Therefore:

        (ans << 1) | 1

    appends binary digit 1.

    If the next input bit is 0:

        1100
      | 0000
      ------
        1100

    Therefore:

        (ans << 1) | 0

    appends binary digit 0.


    ============================================================================
    8. CORE FORMULA
    ============================================================================

    The bit-manipulation conversion uses:

        ans = (ans << 1) | bit;

    The arithmetic equivalent is:

        ans = ans * 2 + bit;

    They express the same binary accumulation idea.

    Bitwise version:

        ans = (ans << 1) | bit;

    Arithmetic version:

        ans = ans * 2 + bit;


    ============================================================================
    9. COMPLETE DRY RUN FOR 1101
    ============================================================================

    Input:

        1101

    Initial:

        ans = 0


    ------------------------------------------------------------------------
    ITERATION 1
    ------------------------------------------------------------------------

    Current digit:

        '1'

    Convert character:

        '1' - '0'
        = 1

    Therefore:

        bit = 1

    Current answer:

        ans = 0

    Shift:

        0 << 1
        = 0

    OR:

        0 | 1
        = 1

    New ans:

        1


    ------------------------------------------------------------------------
    ITERATION 2
    ------------------------------------------------------------------------

    Current digit:

        '1'

    Therefore:

        bit = 1

    Current answer:

        ans = 1

    Shift:

        1 << 1

    Binary:

        0001
          <<
        0010

    Decimal:

        2

    OR:

        0010
      | 0001
      ------
        0011

    Decimal:

        3

    New ans:

        3


    ------------------------------------------------------------------------
    ITERATION 3
    ------------------------------------------------------------------------

    Current digit:

        '0'

    Therefore:

        bit = 0

    Current answer:

        ans = 3

    Shift:

        0011 << 1
        = 0110

    Decimal:

        6

    OR:

        0110
      | 0000
      ------
        0110

    Decimal:

        6

    New ans:

        6


    ------------------------------------------------------------------------
    ITERATION 4
    ------------------------------------------------------------------------

    Current digit:

        '1'

    Therefore:

        bit = 1

    Current answer:

        ans = 6

    Shift:

        0110 << 1
        = 1100

    Decimal:

        12

    OR:

        1100
      | 0001
      ------
        1101

    Decimal:

        13

    New ans:

        13


    FINAL:

        1101(binary) = 13(decimal)


    ============================================================================
    10. STEP-BY-STEP TABLE
    ============================================================================

        Input      bit      ans before      ans << 1      New ans

          1         1            0               0             1
          1         1            1               2             3
          0         0            3               6             6
          1         1            6              12            13

    Final:

        ans = 13


    ============================================================================
    11. POSITIONAL VALUE INTERPRETATION
    ============================================================================

    Binary number:

        1101

    Place values:

        2^3  2^2  2^1  2^0

         8    4    2    1

    Digits:

         1    1    0    1

    Therefore:

        1*8 + 1*4 + 0*2 + 1*1

        = 8 + 4 + 0 + 1

        = 13


    The left-shift accumulation produces exactly the same result.

    Starting from 0:

        0

        0*2 + 1
        = 1

        1*2 + 1
        = 3

        3*2 + 0
        = 6

        6*2 + 1
        = 13


    Bitwise version:

        (0 << 1) | 1 = 1

        (1 << 1) | 1 = 3

        (3 << 1) | 0 = 6

        (6 << 1) | 1 = 13


    ============================================================================
    12. WHY THIS IS BETTER THAN USING % 10 FOR THIS METHOD
    ============================================================================

    A common approach is:

        int digit = number % 10;
        number /= 10;

    That approach treats the typed binary representation as a decimal
    integer containing digits.

    The bit-manipulation approach instead treats the input as a sequence
    of binary digits and constructs the actual numerical value using:

        <<
        |

    Therefore:

        Binary input:
            "1101"

        Actual decimal result:
            13


    This is a genuine bitwise accumulation approach.


    ============================================================================
    13. IMPORTANT: THIS IS DIFFERENT FROM DECIMAL -> BINARY
    ============================================================================

    DECIMAL -> BINARY

        Input:
            decimal integer

        Typical bitwise operations:

            number & 1
            number >>= 1

        These inspect the actual bits of the integer.


    BINARY -> DECIMAL

        Input:
            binary representation such as "1101"

        Bitwise accumulation:

            ans = (ans << 1) | bit;

        Here we read the binary representation and construct the
        decimal numerical value.


    ============================================================================
    14. WHY number & 1 IS NOT THE RIGHT MAIN OPERATION HERE
    ============================================================================

    Suppose the input text is:

        1101

    If we store it as:

        int number = 1101;

    then:

        number & 1

    checks the least-significant bit of the DECIMAL INTEGER 1101.

    It does not mean:

        take the last typed binary digit '1'.

    This distinction is extremely important.

    For Binary -> Decimal, if the input is text:

        "1101"

    the correct bit sequence is obtained from:

        '1'
        '1'
        '0'
        '1'

    and then accumulated using:

        ans = (ans << 1) | bit;


    ============================================================================
    15. ZERO CASE
    ============================================================================

    Input:

        0

    The string is:

        "0"

    Initial:

        ans = 0

    Process digit:

        bit = 0

    Update:

        ans = (0 << 1) | 0
            = 0

    Output:

        Decimal Form: 0


    ============================================================================
    16. LEADING ZEROES
    ============================================================================

    Because the input is a string, leading zeroes can be preserved.

    Example:

        00001101

    Processing:

        0 -> 0
        0 -> 0
        0 -> 0
        0 -> 0
        1 -> 1
        1 -> 3
        0 -> 6
        1 -> 13

    Final:

        13

    Therefore:

        00001101(binary) = 13(decimal)


    ============================================================================
    17. INVALID INPUT
    ============================================================================

    A valid binary number may contain only:

        0
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
        12345

    The program checks every character:

        if (currentDigit != '0' && currentDigit != '1')

    and rejects invalid input.


    ============================================================================
    18. TIME COMPLEXITY
    ============================================================================

    Let:

        L = number of binary digits

    The loop processes exactly one character per iteration.

    Therefore:

        Number of iterations = L

    Time Complexity:

        O(L)


    ============================================================================
    19. SPACE COMPLEXITY
    ============================================================================

    The input string requires:

        O(L)

    storage.

    The conversion itself uses only:

        ans
        bit
        currentDigit

    which is constant extra memory.

    Therefore:

        Auxiliary Space = O(1)

    Total space including the input string:

        O(L)


    ============================================================================
    20. INTEGER OVERFLOW
    ============================================================================

    The result is stored in:

        unsigned int ans;

    Therefore the decimal result must fit inside the selected integer type.

    For a larger binary number, use a wider integer type such as:

        unsigned long long

    when appropriate.

    If the binary representation is too large even for 64 bits, a
    big-integer representation is required.

    The bit-manipulation logic itself remains:

        ans = (ans << 1) | bit;


    ============================================================================
    21. FIXED-WIDTH BINARY INPUT
    ============================================================================

    A binary input may contain exactly a specified number of bits.

    Example:

        00001101

    This is an 8-bit representation.

    Its decimal value is still:

        13

    The string approach preserves the width while processing it.


    ============================================================================
    22. ALTERNATIVE FUNCTION VERSION
    ============================================================================

    The conversion logic can be placed inside a function:

        unsigned int binaryToDecimal(const string& binary)

    Conceptually:

        ans = 0

        for every bit:
            ans = (ans << 1) | bit

        return ans

    This is useful when the conversion is required multiple times.


    ============================================================================
    23. ANOTHER EXAMPLE — 10101
    ============================================================================

    Input:

        10101

    Start:

        ans = 0

    Read 1:

        (0 << 1) | 1
        = 1

    Read 0:

        (1 << 1) | 0
        = 2

    Read 1:

        (2 << 1) | 1
        = 5

    Read 0:

        (5 << 1) | 0
        = 10

    Read 1:

        (10 << 1) | 1
        = 21

    Therefore:

        10101₂ = 21₁₀


    ============================================================================
    24. ANOTHER EXAMPLE — 11111
    ============================================================================

    Input:

        11111

    Processing:

        0

        (0 << 1) | 1 = 1

        (1 << 1) | 1 = 3

        (3 << 1) | 1 = 7

        (7 << 1) | 1 = 15

        (15 << 1) | 1 = 31

    Therefore:

        11111₂ = 31₁₀


    ============================================================================
    25. BITWISE OR TRUTH TABLE
    ============================================================================

        A   B   A | B

        0   0     0
        0   1     1
        1   0     1
        1   1     1

    In our conversion, 'bit' is only 0 or 1.

    After:

        ans << 1

    the least-significant bit is 0.

    Therefore:

        (ans << 1) | 0

    leaves the last bit as 0.

    And:

        (ans << 1) | 1

    sets the last bit to 1.


    ============================================================================
    26. BITWISE LEFT SHIFT VS MULTIPLICATION
    ============================================================================

    Arithmetic:

        ans * 2

    Bitwise:

        ans << 1

    For unsigned values where the result fits:

        ans << 1

    corresponds to:

        ans * 2


    Example:

        5 * 2 = 10

        5 << 1 = 10


    ============================================================================
    27. BITWISE OR VS ADDING THE BIT
    ============================================================================

    Arithmetic update:

        ans = ans * 2 + bit;

    Bitwise update:

        ans = (ans << 1) | bit;

    Why does OR work?

    After shifting:

        ans << 1

    the last bit is 0.

    Since bit is only 0 or 1:

        0 | 0 = 0
        0 | 1 = 1

    Therefore OR inserts the new binary digit.


    ============================================================================
    28. COMMON MISTAKE #1
    ============================================================================

    WRONG conceptual approach:

        int binary = 1101;

        // treating binary as if C++ already stores it as binary

    C++ does not interpret ordinary decimal integer literals this way.

    Correct approach for binary text:

        string binary = "1101";


    ============================================================================
    29. COMMON MISTAKE #2
    ============================================================================

    Do not confuse:

        |

    with:

        ||

    They are different.

        |   = Bitwise OR

        ||  = Logical OR


    ============================================================================
    30. COMMON MISTAKE #3
    ============================================================================

    Do not confuse:

        <<

    with:

        <

    Here:

        <<

    is the bitwise left-shift operator.

    It can also appear in C++ stream output:

        cout << value;

    Context determines its meaning.


    ============================================================================
    31. COMMON MISTAKE #4
    ============================================================================

    Do not use:

        ans = (ans >> 1) | bit;

    for normal left-to-right Binary -> Decimal accumulation.

    We need:

        ans << 1

    because every newly read binary digit extends the number toward
    the RIGHT, which means the existing value must move one binary
    position to the LEFT.


    ============================================================================
    32. COMMON MISTAKE #5
    ============================================================================

    Do not reverse the input unnecessarily.

    For:

        ans = (ans << 1) | bit;

    process:

        LEFT -> RIGHT

    directly.

    Example:

        1101

    must be read:

        1
        1
        0
        1

    in that order.


    ============================================================================
    33. COMPARISON WITH MODULO/DIVISION METHOD
    ============================================================================

    Binary -> Decimal using modulo/division on an integer-looking input:

        digit = number % 10;
        number /= 10;

        ans += digit * power;
        power *= 2;


    Binary -> Decimal using bit manipulation:

        bit = currentDigit - '0';

        ans = (ans << 1) | bit;


    Main difference:

        Modulo/Division:
            Processes digits from RIGHT -> LEFT.

        Bit Manipulation:
            Processes digits from LEFT -> RIGHT.


    Complexity:

        Both can be:

            Time  = O(L)

        The bitwise string method uses:

            Auxiliary Space = O(1)

        plus:

            Input String Space = O(L)


    ============================================================================
    34. COMPARISON WITH DECIMAL -> BINARY BIT MANIPULATION
    ============================================================================

    Decimal -> Binary:

        remainder = number & 1;
        number >>= 1;

    Purpose:

        Extract actual bits from a decimal integer.

    Binary -> Decimal:

        bit = currentDigit - '0';
        ans = (ans << 1) | bit;

    Purpose:

        Read binary digits and construct the actual decimal integer.


    These are reverse conversion directions, so the bit operations
    naturally appear in different forms.


    ============================================================================
    35. QUICK CHEAT SHEET
    ============================================================================

    Read binary input:

        string binary;
        cin >> binary;


    Convert character to bit:

        int bit = currentDigit - '0';


    Shift current answer left:

        ans << 1


    Insert new bit:

        (ans << 1) | bit


    Complete update:

        ans = (ans << 1) | bit;


    Arithmetic equivalent:

        ans = ans * 2 + bit;


    Valid binary characters:

        '0'
        '1'


    Time:

        O(L)


    Auxiliary Space:

        O(1)


    Input String Space:

        O(L)


    Example:

        binary = "1101"

        result = 13


    ============================================================================
    36. FINAL CONCEPT
    ============================================================================

    The most important expression in this entire method is:

        ans = (ans << 1) | bit;

    Think of it as:

        SHIFT
            +
        INSERT BIT

    More explicitly:

        ans << 1
            ↓
        make room for the new binary digit

        | bit
            ↓
        put 0 or 1 into that new position


    Therefore:

        Binary -> Decimal

    using bit manipulation is fundamentally:

        Read each bit from left to right
        ->
        shift the current answer left
        ->
        insert the new bit
        ->
        continue until all bits are processed.


    ============================================================================
    END
    ============================================================================
*/