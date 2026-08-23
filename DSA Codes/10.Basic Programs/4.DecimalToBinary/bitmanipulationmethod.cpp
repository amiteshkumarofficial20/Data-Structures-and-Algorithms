/*
    ========================================================================
        DECIMAL TO BINARY — BIT MANIPULATION METHOD
    ========================================================================

    Method Name:
        Bit-Manipulation Method

    Main operations:
        1. Bitwise AND (&)
        2. Right Shift (>>)

    Core expressions:

        remainder = number & 1;
        number = number >> 1;

    These replace the arithmetic operations:

        remainder = number % 2;
        number = number / 2;

    for non-negative / unsigned integers.

    This file explains:
        - What bit manipulation means
        - Binary representation
        - Bitwise AND
        - Why "number & 1" extracts the last bit
        - Right shift
        - Why "number >> 1" moves to the next bit
        - Your exact ans + i approach
        - Detailed dry runs
        - Fixed-width representation
        - String version
        - bitset version
        - Complexity
        - Common mistakes
        - Important signed/unsigned considerations
        - Comparison with modulo/division method

    IMPORTANT:
        In the integer-answer approach, "ans = 1101" is the decimal
        integer 1101 used to DISPLAY the binary digits of 13.

        It is NOT an integer whose numerical value is binary 1101.

    Complexity:
        Time  = O(log n)
        Space = O(1) auxiliary for the basic integer approach.
*/

#include <iostream>

using namespace std;

// ========================================================================
// 1. YOUR EXACT BIT-MANIPULATION APPROACH
// ========================================================================

int main()
{
    int number;

    cout << "Enter a Number: ";
    cin >> number;

    // 'ans' stores the binary digits as a decimal-looking integer.
    //
    // Example:
    //
    // Decimal:
    //      13
    //
    // Binary:
    //      1101
    //
    // ans will contain:
    //
    //      1101
    //
    // But internally, C++ treats ans as the decimal integer 1101.
    int ans = 0;

    // 'i' controls the displayed position of each binary digit.
    //
    // It becomes:
    //
    //      1
    //      10
    //      100
    //      1000
    //      ...
    //
    // This lets us construct:
    //
    //      1101
    //
    // as:
    //
    //      1 * 1
    //    + 0 * 10
    //    + 1 * 100
    //    + 1 * 1000
    int i = 1;

    while (number > 0)
    {
        // ================================================================
        // STEP 1: Extract the Least Significant Bit
        // ================================================================
        //
        // Instead of:
        //
        //      remainder = number % 2;
        //
        // we use:
        //
        //      remainder = number & 1;
        //
        // The bitwise AND operator compares corresponding bits.
        //
        // The binary representation of 1 is:
        //
        //      0001
        //
        // Therefore:
        //
        //      number & 0001
        //
        // only examines the last (least-significant) bit.
        //
        // If the last bit is 0:
        //
        //      result = 0
        //
        // If the last bit is 1:
        //
        //      result = 1
        //
        // So:
        //
        //      number & 1
        //
        // extracts the least-significant binary bit.
        int remainder = number & 1;

        // ================================================================
        // STEP 2: Move to the Next Binary Bit
        // ================================================================
        //
        // Instead of:
        //
        //      number = number / 2;
        //
        // we use:
        //
        //      number = number >> 1;
        //
        // The >> operator is the RIGHT SHIFT operator.
        //
        // It moves every bit one position to the right.
        //
        // Example:
        //
        //      1101
        //
        // right shift by 1:
        //
        //      0110
        //
        // Decimal:
        //
        //      13 >> 1 = 6
        //
        // For non-negative / unsigned integers, right shifting by
        // one position corresponds to integer division by 2.
        number = number >> 1;

        // ================================================================
        // STEP 3: Put the Extracted Bit into the Answer
        // ================================================================
        //
        // The first extracted bit is the least-significant binary bit.
        //
        // i starts at:
        //
        //      1
        //
        // so the first bit goes into the units position.
        //
        // Then i becomes:
        //
        //      10
        //
        // then:
        //
        //      100
        //
        // then:
        //
        //      1000
        //
        // This allows us to construct the displayed binary digits.
        ans += remainder * i;

        // Move to the next displayed position.
        i *= 10;
    }

    cout << "Binary Form: " << ans << endl;

    return 0;
}

/*
    ========================================================================
    2. WHAT IS BIT MANIPULATION?
    ========================================================================

    Bit manipulation means working directly with the individual bits
    of an integer.

    A bit can have only two values:

        0
        1

    Example:

        Decimal 13

        Binary:

            1101

    Each position is a bit.

    From right to left:

            1 1 0 1
            ^ ^ ^ ^
            | | | |
            | | | +---- bit 0
            | | +------ bit 1
            | +-------- bit 2
            +---------- bit 3


    ========================================================================
    3. THE TWO IMPORTANT OPERATIONS
    ========================================================================

    This method uses:

        &
        >>

    They are different operators.

    '&'
        Bitwise AND

    '>>'
        Right Shift


    ========================================================================
    4. BITWISE AND
    ========================================================================

    The AND operator works bit-by-bit.

    Truth table:

        A   B   A & B

        0   0     0
        0   1     0
        1   0     0
        1   1     1

    So AND produces 1 only when BOTH corresponding bits are 1.


    ========================================================================
    5. WHY "number & 1" EXTRACTS THE LAST BIT
    ========================================================================

    The integer 1 in binary is:

        0001

    Suppose:

        number = 13

    Binary:

        1101

    Perform:

        1101
      & 0001
      ------
        0001

    Result:

        1

    Therefore:

        13 & 1 = 1


    Another example:

        number = 10

    Binary:

        1010

    Perform:

        1010
      & 0001
      ------
        0000

    Result:

        0

    Therefore:

        10 & 1 = 0


    ========================================================================
    6. WHY ONLY THE LAST BIT MATTERS
    ========================================================================

    The mask:

        0001

    has:

        0

    in every position except the last position.

    Therefore:

        number & 1

    clears every other bit and keeps only the least-significant bit.

    This gives:

        0
    or:
        1

    exactly what we need for a binary digit.


    ========================================================================
    7. WHAT IS THE LEAST SIGNIFICANT BIT?
    ========================================================================

    The rightmost bit is called the:

        Least Significant Bit

    or:

        LSB

    Example:

        1101

    The LSB is:

        1

    Example:

        1010

    The LSB is:

        0

    Therefore:

        number & 1

    extracts the LSB.


    ========================================================================
    8. RIGHT SHIFT OPERATOR
    ========================================================================

    The operator:

        >>

    is called the right-shift operator.

    Example:

        1101 >> 1

    gives:

        0110

    So:

        13 >> 1 = 6

    Another example:

        1010 >> 1

        1010
         ↓
        0101

    Therefore:

        10 >> 1 = 5


    ========================================================================
    9. WHY RIGHT SHIFT BY ONE CORRESPONDS TO DIVISION BY 2
    ========================================================================

    Binary place values are:

        2^0 = 1
        2^1 = 2
        2^2 = 4
        2^3 = 8
        2^4 = 16
        ...

    When all bits move one position to the right, every place value
    effectively becomes half as large.

    Example:

        1101

    represents:

        1*8 + 1*4 + 0*2 + 1*1
        = 13

    After right shift:

        0110

    represents:

        0*8 + 1*4 + 1*2 + 0*1
        = 6

    Therefore:

        13 >> 1 = 6

    For non-negative / unsigned integers:

        n >> 1

    corresponds to:

        n / 2

    using integer division.


    ========================================================================
    10. THE TWO CORE EXPRESSIONS
    ========================================================================

    Arithmetic method:

        remainder = number % 2;
        number = number / 2;

    Bit-manipulation method:

        remainder = number & 1;
        number = number >> 1;


    Conceptual relationship for non-negative / unsigned integers:

        number % 2
                ↓
        extracts last bit

        number & 1
                ↓
        extracts last bit


        number / 2
                ↓
        removes one binary position

        number >> 1
                ↓
        removes one binary position


    ========================================================================
    11. COMPLETE DRY RUN FOR 13
    ========================================================================

    Initial:

        number = 13
        ans    = 0
        i      = 1


    ------------------------------------------------
    ITERATION 1
    ------------------------------------------------

    number:

        13 = 1101

    Extract LSB:

        1101
      & 0001
      ------
        0001

    remainder:

        1

    Right shift:

        1101 >> 1
        = 0110

    Therefore:

        number = 6

    Build answer:

        ans = 0 + 1*1
            = 1

    Update:

        i = 10


    ------------------------------------------------
    ITERATION 2
    ------------------------------------------------

    number:

        6 = 0110

    Extract LSB:

        0110
      & 0001
      ------
        0000

    remainder:

        0

    Right shift:

        0110 >> 1
        = 0011

    Therefore:

        number = 3

    Build answer:

        ans = 1 + 0*10
            = 1

    Update:

        i = 100


    ------------------------------------------------
    ITERATION 3
    ------------------------------------------------

    number:

        3 = 0011

    Extract LSB:

        0011
      & 0001
      ------
        0001

    remainder:

        1

    Right shift:

        0011 >> 1
        = 0001

    Therefore:

        number = 1

    Build answer:

        ans = 1 + 1*100
            = 101

    Update:

        i = 1000


    ------------------------------------------------
    ITERATION 4
    ------------------------------------------------

    number:

        1 = 0001

    Extract LSB:

        0001
      & 0001
      ------
        0001

    remainder:

        1

    Right shift:

        0001 >> 1
        = 0000

    Therefore:

        number = 0

    Build answer:

        ans = 101 + 1*1000
            = 1101


    number is now 0.

    Loop ends.

    Output:

        Binary Form: 1101


    ========================================================================
    12. STEP-BY-STEP SUMMARY FOR 13
    ========================================================================

        Decimal      Binary       & 1       >> 1

          13          1101         1          6
           6          0110         0          3
           3          0011         1          1
           1          0001         1          0

    Extracted bits:

        1 0 1 1

    These are generated:

        LSB -> MSB

    Your 'i' technique places them as:

        1
        0
        100
        1000

    giving:

        1101


    ========================================================================
    13. IMPORTANT: ans IS NOT A BINARY INTEGER
    ========================================================================

    Suppose:

        ans = 1101;

    C++ interprets this as:

        decimal 1101

    not:

        binary 1101 = decimal 13

    Example:

        int ans = 1101;

        cout << ans + 1;

    Output:

        1102

    If 1101 were actually being interpreted as binary:

        1101₂ + 1₂ = 1110₂

    which equals:

        14₁₀

    So your approach creates a decimal-looking integer whose digits
    represent the binary answer.

    It is a DISPLAY/CONSTRUCTION technique.


    ========================================================================
    14. FIXED-WIDTH BINARY
    ========================================================================

    Normal binary:

        5 = 101

    8-bit binary:

        00000101

    Bit manipulation makes fixed-width representation easy.

    Example:

        for (int bit = 7; bit >= 0; bit--)
        {
            cout << ((number >> bit) & 1);
        }

    Here:

        number >> bit

    moves the requested bit to the least-significant position.

    Then:

        & 1

    extracts it.


    ========================================================================
    15. FIXED-WIDTH 8-BIT PROGRAM
    ========================================================================
*/

#include <iostream>
using namespace std;

void printBinary8(unsigned int number)
{
    // Start from bit 7 because an 8-bit number contains:
    //
    // bit positions:
    //
    // 7 6 5 4 3 2 1 0
    //
    // We print from most-significant bit to least-significant bit.
    for (int bit = 7; bit >= 0; bit--)
    {
        // Shift the desired bit to position 0.
        //
        // Example:
        //
        // number = 00001101
        //
        // If bit = 3:
        //
        // number >> 3
        //
        // moves that bit to the rightmost position.
        //
        // Then & 1 extracts it.
        int currentBit = (number >> bit) & 1;

        cout << currentBit;
    }
}

/*
    ========================================================================
    16. STRING VERSION USING BIT MANIPULATION
    ========================================================================
*/

#include <string>
#include <algorithm>

string decimalToBinaryBitwise(unsigned int number)
{
    // Special case:
    // 0 has binary representation "0".
    if (number == 0)
        return "0";

    string binary;

    while (number > 0)
    {
        // Extract the least-significant bit.
        int bit = number & 1;

        // Convert integer 0/1 into character '0'/'1'.
        binary.push_back(char('0' + bit));

        // Remove the processed bit.
        number >>= 1;
    }

    // Bits were generated:
    //
    // LSB -> MSB
    //
    // Normal display requires:
    //
    // MSB -> LSB
    reverse(binary.begin(), binary.end());

    return binary;
}

/*
    ========================================================================
    17. BITSET VERSION
    ========================================================================

    C++ also provides:

        std::bitset

    Example:

        bitset<8> binary(number);

    This gives an exactly 8-bit representation.

    Example:

        number = 13

        bitset<8>(13)

        00001101

    This is useful when the required width is known.
*/

#include <bitset>

void printUsingBitset(unsigned int number)
{
    bitset<8> binary(number);

    cout << binary << '\n';
}

/*
    ========================================================================
    18. BITWISE OPERATORS USED HERE
    ========================================================================

    &

        Bitwise AND

    >>

        Right Shift

    These are NOT the same as:

        &&
        >>

    Be careful with operator meanings.

    '&'
        bitwise AND

    '&&'
        logical AND


    ========================================================================
    19. BITWISE AND TRUTH TABLE
    ========================================================================

        A   B   A & B

        0   0     0
        0   1     0
        1   0     0
        1   1     1

    Example:

        1011
      & 0110
      ------
        0010


    ========================================================================
    20. RIGHT SHIFT
    ========================================================================

    Syntax:

        number >> k

    means shift the bits of number right by k positions.

    Example:

        110100

    Right shift by 1:

        011010

    Right shift by 2:

        001101

    So:

        number >> 1

    removes one least-significant position.

    For unsigned/non-negative integer values:

        n >> 1

    corresponds to:

        floor(n / 2)


    ========================================================================
    21. WHY THIS IS USEFUL IN DSA
    ========================================================================

    Bit manipulation appears frequently in:

        - Binary representation
        - Power-of-two checks
        - Setting bits
        - Clearing bits
        - Toggling bits
        - Checking bits
        - Bit masks
        - Subsets using bitmasks
        - Dynamic programming with bitmasks
        - Competitive programming
        - Low-level programming


    ========================================================================
    22. CHECK WHETHER A NUMBER IS EVEN OR ODD
    ========================================================================

    The last binary bit tells whether a number is even or odd.

    Even numbers end in:

        0

    Odd numbers end in:

        1

    Therefore:

        number & 1

    gives:

        0 -> even
        1 -> odd

    Example:

        10 = 1010

        1010 & 0001 = 0000

        even


        13 = 1101

        1101 & 0001 = 0001

        odd

    Code:

        if (number & 1)
            cout << "Odd";
        else
            cout << "Even";


    ========================================================================
    23. CHECKING A SPECIFIC BIT
    ========================================================================

    To check bit position 'k':

        (number >> k) & 1

    Example:

        number = 13

        13 = 1101

    Check bit 2:

        1101 >> 2
        = 0011

        0011 & 0001
        = 1

    So bit 2 is set.


    ========================================================================
    24. SET A BIT
    ========================================================================

    To set bit k to 1:

        number = number | (1 << k)

    Example:

        number = 8

        8 = 1000

    Set bit 1:

        1 << 1
        = 0010

        1000
      | 0010
      ------
        1010

    Result:

        10


    ========================================================================
    25. CLEAR A BIT
    ========================================================================

    To clear bit k:

        number = number & ~(1 << k)

    This is another important bit-manipulation operation.


    ========================================================================
    26. TOGGLE A BIT
    ========================================================================

    To toggle bit k:

        number = number ^ (1 << k)

    XOR is used for toggling.


    ========================================================================
    27. COMPLEXITY
    ========================================================================

    In the decimal-to-binary loop:

        while (number > 0)
        {
            int bit = number & 1;
            number >>= 1;

            ...
        }

    number is approximately halved every iteration.

    Therefore:

        n
        n/2
        n/4
        n/8
        ...
        1
        0

    Number of iterations:

        Θ(log₂ n)

    Therefore:

        Time Complexity = O(log n)


    ========================================================================
    28. SPACE COMPLEXITY
    ========================================================================

    Your integer-answer version uses:

        number
        ans
        i
        remainder

    All are fixed-size variables.

    Therefore:

        Auxiliary Space = O(1)

    If a string is used to store the binary representation:

        Result Space = O(log n)

    The string contains approximately:

        floor(log₂ n) + 1

    binary digits.


    ========================================================================
    29. INTEGER VERSION LIMITATION
    ========================================================================

    This approach:

        ans += remainder * i;
        i *= 10;

    can overflow because ans is an int.

    The binary representation may contain many digits, while int
    has a fixed maximum range.

    For robust large-number output, use:

        string

    instead of:

        int ans


    ========================================================================
    30. SIGNED VS UNSIGNED
    ========================================================================

    For this conversion, it is best to use:

        unsigned int

    when discussing raw bit manipulation.

    Right shifting signed negative integers can have implementation-
    dependent/standard-defined subtleties.

    The simple equivalence:

        n >> 1 == n / 2

    should be understood in the context of non-negative or unsigned
    integer values.

    Negative numbers also require deciding whether we mean:

        - magnitude representation
        - fixed-width two's complement representation


    ========================================================================
    31. BITWISE METHOD VS MODULO/DIVISION METHOD
    ========================================================================

    Arithmetic method:

        int remainder = number % 2;
        number /= 2;

    Bitwise method:

        int remainder = number & 1;
        number >>= 1;

    Both:

        Time  = O(log n)
        Space = O(1)

    Main conceptual difference:

        Arithmetic method
            uses quotient/remainder mathematics.

        Bitwise method
            directly examines and moves individual bits.


    ========================================================================
    32. FINAL BIT-MANIPULATION CHEAT SHEET
    ========================================================================

    Extract last bit:

        number & 1

    Remove last bit / shift right:

        number >> 1

    Check whether odd:

        number & 1

    Check whether even:

        !(number & 1)

    Check bit k:

        (number >> k) & 1

    Set bit k:

        number | (1 << k)

    Clear bit k:

        number & ~(1 << k)

    Toggle bit k:

        number ^ (1 << k)

    Decimal to binary core:

        while (number > 0)
        {
            remainder = number & 1;
            number >>= 1;
            ...
        }

    Complexity:

        Time  = O(log n)
        Space = O(1) auxiliary


    ========================================================================
    END
    ========================================================================
*/