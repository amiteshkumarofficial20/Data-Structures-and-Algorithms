/*
    ============================================================================
        LEETCODE 204 — COUNT PRIMES
        OPTIMAL APPROACH — SIEVE OF ERATOSTHENES
    ============================================================================

    Problem:
        LeetCode 204 — Count Primes

    Goal:

        Given an integer n, count the number of prime numbers
        strictly less than n.

    Example:

        n = 10

        Numbers strictly less than 10:

            2 3 4 5 6 7 8 9

        Prime numbers:

            2 3 5 7

        Answer:

            4


    ============================================================================
        WHY BRUTE FORCE IS NOT EFFICIENT
    ============================================================================

    In the basic brute-force approach, we take every number:

        2
        3
        4
        ...
        n - 1

    and individually check whether that number is prime.

    Even if we optimize the individual prime check using:

        i * i <= num

    we are still checking every number separately.

    Therefore, a lot of repeated work is happening.


    Example:

        Suppose:

            n = 30


        We check:

            isPrime(2)
            isPrime(3)
            isPrime(4)
            isPrime(5)
            ...
            isPrime(29)


    Instead of repeatedly asking:

        "Is this number prime?"

    we can PRE-COMPUTE the answer for all numbers together.


    This is exactly what:

        Sieve of Eratosthenes

    does.


    ============================================================================
        SIEVE OF ERATOSTHENES — MAIN IDEA
    ============================================================================

    We create an array:

        prime


    Suppose:

        n = 30


    Since we need to work with numbers from:

        0 to 30

    we create:

        prime[31]


    Why 31?

        Because indexes will be:

            0, 1, 2, 3, ..., 30


    We use:

        1 -> currently considered PRIME
        0 -> NOT PRIME


    Initially, we assume every number is prime.

    Therefore:

        prime[i] = 1


    for all i.


    Conceptually:

        Number:

            0  1  2  3  4  5  6  7  8  9  10 ... 30

        prime:

            1  1  1  1  1  1  1  1  1  1   1 ...  1


    But this is only an INITIAL assumption.


    We already know:

        0 is NOT prime.
        1 is NOT prime.


    Therefore:

        prime[0] = 0
        prime[1] = 0


    ============================================================================
        STEP 1 — START FROM 2
    ============================================================================

    The first possible prime number is:

        2


    2 is definitely prime.


    Therefore:

        prime[2] == 1


    Now observe:

        Every multiple of 2 greater than 2
        can NEVER be prime.


    Multiples of 2:

        4
        6
        8
        10
        12
        14
        16
        ...


    Why are they not prime?


        4  = 2 × 2
        6  = 2 × 3
        8  = 2 × 4
        10 = 2 × 5
        12 = 2 × 6


    Every one of these numbers has a divisor other than:

        1

    and:

        itself


    Therefore they are NOT prime.


    So we mark them:

        prime[4]  = 0
        prime[6]  = 0
        prime[8]  = 0
        prime[10] = 0
        ...


    ============================================================================
        BASIC SIEVE VERSION
    ============================================================================

    The basic Sieve idea can be written as:

        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = 2 * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }


    Let's understand this carefully.


    When:

        i = 2


    Since:

        prime[2] == 1


    2 is prime.


    We mark:

        2 * 2 = 4
        2 * 3 = 6
        2 * 4 = 8
        2 * 5 = 10
        ...


    as:

        0


    --------------------------------------------------------------------------


    When:

        i = 3


    Since:

        prime[3] == 1


    3 is prime.


    We mark multiples of 3:

        6
        9
        12
        15
        18
        21
        ...


    as:

        0


    --------------------------------------------------------------------------


    When:

        i = 4


    We check:

        prime[4]


    But 4 was already marked by 2:

        4 = 2 × 2


    Therefore:

        prime[4] = 0


    So 4 is NOT prime.


    We simply skip it.


    This is important.


    ============================================================================
        WHY DO WE SKIP 4?
    ============================================================================

    Because:

        4 is already known to be non-prime.


    We don't need to process the multiples of 4 again.


    Suppose we did process 4.


    Its multiples would be:

        8
        12
        16
        20
        24
        28
        ...


    But these numbers have already been handled by smaller factors.


    For example:

        8  -> already marked by 2
        12 -> already marked by 2 and 3
        16 -> already marked by 2
        20 -> already marked by 2
        24 -> already marked by 2 and 3
        28 -> already marked by 2


    Therefore processing 4 would only repeat work.


    This is why we use:

        if (prime[i] == 1)


    before marking multiples.


    ============================================================================
        SAME IDEA FOR 6, 8, 9, 10...
    ============================================================================

    Consider:

        i = 6


    6 is already marked by 2 and 3.


    Therefore:

        prime[6] = 0


    So we skip it.


    Similarly:

        8

    was already marked by 2.


    So:

        prime[8] = 0


    Skip it.


    Similarly:

        9

    was already marked by 3:

        9 = 3 × 3


    Therefore:

        prime[9] = 0


    Skip it.


    The important point is:

        We only process i when:

            prime[i] == 1


    because only then do we know that i is prime.


    ============================================================================
        FURTHER OPTIMIZATION
    ============================================================================

    The basic Sieve uses:

        j = 2 * i


    But we can optimize this further.


    Consider:

        i = 5


    Basic approach starts marking from:

        2 * 5 = 10


    So it would process:

        10
        15
        20
        25
        30
        ...


    But let's check what happened before.


    10 was already marked by 2:

        10 = 2 × 5


    15 was already marked by 3:

        15 = 3 × 5


    20 was already marked by 2:

        20 = 2 × 10


    Therefore these numbers don't need to be processed again.


    The FIRST multiple of 5 that we may need to newly mark is:

        5 × 5

        = 25


    Therefore instead of:

        j = 2 * i


    we can start from:

        j = i * i


    So:

        for (int j = i * i; j <= n; j += i)


    ============================================================================
        WHY IS i * i THE FIRST IMPORTANT MULTIPLE?
    ============================================================================

    Suppose:

        i = 5


    Multiples are:

        5
        10
        15
        20
        25
        30
        35
        ...


    We don't mark 5 because:

        5 itself is prime.


    We don't need to newly mark:

        10
        15
        20


    because they have smaller factors:

        10 = 2 × 5
        15 = 3 × 5
        20 = 4 × 5


    Those smaller factors have already been processed.


    Therefore:

        25 = 5 × 5


    is the first multiple that needs to be considered at this stage.


    Hence:

        j = i * i


    ============================================================================
        SECOND OPTIMIZATION — OUTER LOOP
    ============================================================================

    We can optimize the outer loop too.


    Instead of:

        for (int i = 2; i <= n; i++)


    we use:

        for (int i = 2; i * i <= n; i++)


    This means:

        i <= sqrt(n)


    without explicitly calculating sqrt(n).


    ============================================================================
        WHY CAN THE OUTER LOOP STOP AT sqrt(n)?
    ============================================================================

    Suppose a number is composite.


    A composite number can be written as:

        n = a × b


    Suppose BOTH factors were greater than sqrt(n):

        a > sqrt(n)

        b > sqrt(n)


    Then:

        a × b > sqrt(n) × sqrt(n)


    Therefore:

        a × b > n


    But:

        a × b = n


    This is impossible.


    Therefore:

        At least one factor of every composite number
        must be <= sqrt(n).


    So once we process all possible prime factors up to:

        sqrt(n)


    there is no need to continue the outer loop.


    Therefore:

        i * i <= n


    is enough.


    ============================================================================
        WHY i * i <= n AND NOT i * i < n?
    ============================================================================

    The equality is important.


    Consider:

        n = 25


    We know:

        sqrt(25) = 5


    And:

        5 × 5 = 25


    If we use:

        i * i < n


    then:

        5 * 5 < 25

        25 < 25

        FALSE


    So 5 would not be processed.


    But 5 is an important factor of 25.


    We need to mark:

        25


    as non-prime.


    Therefore the correct condition is:

        i * i <= n


    NOT:

        i * i < n


    ============================================================================
        FINAL OPTIMIZED SIEVE
    ============================================================================

    The final optimized logic is:


        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }


    There are TWO major optimizations:


        1. Outer loop:

               i * i <= n

           instead of:

               i <= n


        2. Inner loop starts at:

               i * i

           instead of:

               2 * i


    ============================================================================
        EXAMPLE — n = 30
    ============================================================================

    Initially:

        prime[0] = 0
        prime[1] = 0

        prime[2]  = 1
        prime[3]  = 1
        prime[4]  = 1
        prime[5]  = 1
        ...
        prime[30] = 1


    --------------------------------------------------------------------------
    i = 2
    --------------------------------------------------------------------------

        prime[2] == 1

    Therefore 2 is prime.


    Start marking from:

        i * i

        2 * 2

        = 4


    Mark:

        4
        6
        8
        10
        12
        14
        16
        18
        20
        22
        24
        26
        28
        30


    as:

        0


    --------------------------------------------------------------------------
    i = 3
    --------------------------------------------------------------------------

        prime[3] == 1

    Therefore 3 is prime.


    Start:

        3 * 3

        = 9


    Mark:

        9
        12
        15
        18
        21
        24
        27
        30


    as:

        0


    Notice:

        6

    was NOT processed again.


    Why?

        6 was already marked by 2.


    --------------------------------------------------------------------------
    i = 4
    --------------------------------------------------------------------------

    Check:

        prime[4]


    But:

        prime[4] = 0


    because 4 was already marked by 2.


    Therefore:

        SKIP 4


    --------------------------------------------------------------------------
    i = 5
    --------------------------------------------------------------------------

    Now check the outer-loop condition:

        5 * 5 <= 30

        25 <= 30

        TRUE


    But:

        prime[5] == 1


    So 5 is prime.


    Start:

        5 * 5

        = 25


    Mark:

        25
        30


    as:

        0


    --------------------------------------------------------------------------
    i = 6
    --------------------------------------------------------------------------

    We don't even reach i = 6 because:

        6 * 6 <= 30

        36 <= 30

        FALSE


    Therefore the outer loop stops.


    ============================================================================
        FINAL ARRAY FOR n = 30
    ============================================================================

    After the Sieve:

        index:

             0  1  2  3  4  5  6  7  8  9  10
            11 12 13 14 15 16 17 18 19 20
            21 22 23 24 25 26 27 28 29 30


        prime:

             0  0  1  1  0  1  0  1  0  0  0
             1  0  1  0  0  0  1  0  1  0
             0  0  1  0  0  0  1  0  0  0  0


    Therefore the numbers having:

        prime[i] == 1


    are:

        2
        3
        5
        7
        11
        13
        17
        19
        23
        29


    These are exactly the prime numbers <= 30.


    ============================================================================
        IMPORTANT — LEETCODE 204 SAYS LESS THAN n
    ============================================================================

    The Sieve may create values from:

        0 to n


    But LeetCode asks:

        prime numbers STRICTLY LESS THAN n


    Therefore when counting, we use:

        i < n


    NOT:

        i <= n


    Example:

        n = 10


    We need:

        2
        3
        5
        7


    We do not include:

        10


    ============================================================================
        WHY DO WE CREATE n + 1 ELEMENTS?
    ============================================================================

    Suppose:

        n = 10


    We create:

        vector<int> prime(11, 1);


    Because indexes are:

        0
        1
        2
        3
        4
        5
        6
        7
        8
        9
        10


    So index 10 exists.


    Even though LeetCode asks for numbers strictly less than 10,
    having the index n available makes the sieve implementation simple
    and standard.


    ============================================================================
        COMPLETE RUNNABLE C++ PROGRAM
    ============================================================================

    This version contains main() so that it can be directly compiled
    and run in VS Code.
*/

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// FUNCTION: countPrimes
// ============================================================================
//
// Purpose:
//
//     Count the number of prime numbers strictly less than n.
//
// Approach:
//
//     Sieve of Eratosthenes
//
// Time Complexity:
//
//     O(n log log n)
//
// Space Complexity:
//
//     O(n)
//
// ============================================================================

int countPrimes(int n)
{
    // ------------------------------------------------------------------------
    // STEP 1: Handle very small values
    // ------------------------------------------------------------------------
    //
    // If n <= 2:
    //
    //     There are no prime numbers strictly less than n.
    //
    // Example:
    //
    //     n = 0 -> 0
    //     n = 1 -> 0
    //     n = 2 -> 0
    //
    // The first prime number is 2.
    //
    // ------------------------------------------------------------------------

    if (n <= 2)
    {
        return 0;
    }

    // ------------------------------------------------------------------------
    // STEP 2: Create the prime array
    // ------------------------------------------------------------------------
    //
    // We create n positions + 1:
    //
    //     0 to n
    //
    // Initially:
    //
    //     1 = considered prime
    //
    // Later:
    //
    //     0 = definitely not prime
    //
    // ------------------------------------------------------------------------

    vector<int> prime(n + 1, 1);

    // ------------------------------------------------------------------------
    // STEP 3: 0 and 1 are NOT prime
    // ------------------------------------------------------------------------

    prime[0] = 0;
    prime[1] = 0;

    // ------------------------------------------------------------------------
    // STEP 4: Sieve
    // ------------------------------------------------------------------------
    //
    // We only need to process i while:
    //
    //     i * i <= n
    //
    // This means:
    //
    //     i <= sqrt(n)
    //
    // without explicitly calling sqrt().
    //
    // ------------------------------------------------------------------------

    for (int i = 2; i * i <= n; i++)
    {
        // --------------------------------------------------------------------
        // STEP 5: Process only numbers that are still marked as prime
        // --------------------------------------------------------------------
        //
        // If:
        //
        //     prime[i] == 1
        //
        // then i is prime.
        //
        // Therefore we need to mark all multiples of i as non-prime.
        //
        // If:
        //
        //     prime[i] == 0
        //
        // then i is already known to be composite.
        //
        // Therefore we simply skip it.
        //
        // --------------------------------------------------------------------

        if (prime[i] == 1)
        {
            // ----------------------------------------------------------------
            // STEP 6: Start from i * i
            // ----------------------------------------------------------------
            //
            // Instead of:
            //
            //     j = 2 * i
            //
            // we use:
            //
            //     j = i * i
            //
            //
            // Why?
            //
            // Every multiple of i smaller than i * i has already been
            // marked by some smaller factor.
            //
            // Example:
            //
            //     i = 5
            //
            //     10 = 2 * 5
            //     15 = 3 * 5
            //     20 = 4 * 5
            //
            // These have already been handled.
            //
            // So we begin at:
            //
            //     25 = 5 * 5
            //
            // ----------------------------------------------------------------

            for (int j = i * i; j <= n; j += i)
            {
                // ------------------------------------------------------------
                // STEP 7: Mark the multiple as NOT PRIME
                // ------------------------------------------------------------
                //
                // Example:
                //
                //     i = 2
                //
                //     j = 4
                //
                //     prime[4] = 0
                //
                //
                // Because:
                //
                //     4 = 2 * 2
                //
                // therefore 4 is not prime.
                //
                // ------------------------------------------------------------

                prime[j] = 0;
            }
        }
    }

    // ------------------------------------------------------------------------
    // STEP 8: Count the remaining prime numbers
    // ------------------------------------------------------------------------
    //
    // After the Sieve:
    //
    //     prime[i] == 1
    //
    // means:
    //
    //     i is prime
    //
    // and:
    //
    //     prime[i] == 0
    //
    // means:
    //
    //     i is not prime.
    //
    //
    // IMPORTANT:
    //
    // The problem asks for numbers STRICTLY LESS THAN n.
    //
    // Therefore:
    //
    //     i < n
    //
    // ------------------------------------------------------------------------

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
        {
            count++;
        }
    }

    // ------------------------------------------------------------------------
    // STEP 9: Return the total number of primes
    // ------------------------------------------------------------------------

    return count;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
//
// This main() function is only for running the program locally in VS Code.
//
// On LeetCode:
//     main() is NOT required.
//     You submit the Solution class shown later.
// ============================================================================

int main()
{
    // ------------------------------------------------------------------------
    // Take input
    // ------------------------------------------------------------------------

    int n;
    cout << "Enter a Number Till Which You Have To Count Prime Numbers: ";
    cin >> n;

    // ------------------------------------------------------------------------
    // Calculate and print answer
    // ------------------------------------------------------------------------

    cout << "Number of prime numbers less than "
         << n
         << " = "
         << countPrimes(n)
         << endl;

    return 0;
}

/*
    ============================================================================
        DETAILED DRY RUN — n = 30
    ============================================================================

    We create:

        prime[31]


    Initially:

        prime[0 ... 30] = 1


    Then:

        prime[0] = 0
        prime[1] = 0


    So:

        0 -> NOT PRIME
        1 -> NOT PRIME

        2 -> PRIME (currently)
        3 -> PRIME (currently)
        4 -> PRIME (currently)
        ...
        30 -> PRIME (currently)


    ============================================================================
        i = 2
    ============================================================================

    Check outer condition:

        i * i <= n

        2 * 2 <= 30

        4 <= 30

        TRUE


    Check:

        prime[2] == 1

    TRUE.


    Therefore 2 is prime.


    Start marking:

        j = i * i

        j = 2 * 2

        j = 4


    Mark every multiple of 2:

        j = 4

            prime[4] = 0


        j = 6

            prime[6] = 0


        j = 8

            prime[8] = 0


        j = 10

            prime[10] = 0


        j = 12

            prime[12] = 0


        ...


        j = 30

            prime[30] = 0


    After processing 2:

        All even numbers greater than 2 are marked 0.


    ============================================================================
        i = 3
    ============================================================================

    Check:

        3 * 3 <= 30

        9 <= 30

        TRUE


    Check:

        prime[3] == 1

    TRUE.


    Therefore 3 is prime.


    Start:

        j = 3 * 3

        j = 9


    Mark multiples:

        9
        12
        15
        18
        21
        24
        27
        30


    as:

        0


    Notice:

        6

    was already 0.


    Notice:

        12

    was already 0 because of 2.


    That's completely fine.


    ============================================================================
        i = 4
    ============================================================================

    Check:

        4 * 4 <= 30

        16 <= 30

        TRUE


    Now:

        prime[4] == 0


    Why?


        4 was already marked when i = 2.


    Therefore 4 is not prime.


    So:

        SKIP 4


    We do not mark multiples of 4.


    ============================================================================
        i = 5
    ============================================================================

    Check:

        5 * 5 <= 30

        25 <= 30

        TRUE


    Check:

        prime[5] == 1


    Therefore:

        5 is prime.


    Start:

        j = 5 * 5

        j = 25


    Mark:

        25
        30


    as:

        0


    ============================================================================
        i = 6
    ============================================================================

    We now check the outer-loop condition:

        6 * 6 <= 30

        36 <= 30

        FALSE


    Therefore the outer loop stops.


    We do NOT need:

        i = 6
        i = 7
        i = 8
        ...
        i = 30


    ============================================================================
        FINAL ARRAY
    ============================================================================

    Remaining 1s represent prime numbers.


        0  -> 0
        1  -> 0
        2  -> 1
        3  -> 1
        4  -> 0
        5  -> 1
        6  -> 0
        7  -> 1
        8  -> 0
        9  -> 0
        10 -> 0
        11 -> 1
        12 -> 0
        13 -> 1
        14 -> 0
        15 -> 0
        16 -> 0
        17 -> 1
        18 -> 0
        19 -> 1
        20 -> 0
        21 -> 0
        22 -> 0
        23 -> 1
        24 -> 0
        25 -> 0
        26 -> 0
        27 -> 0
        28 -> 0
        29 -> 1
        30 -> 0


    Therefore:

        prime numbers <= 30 are:

            2
            3
            5
            7
            11
            13
            17
            19
            23
            29


    ============================================================================
        BUT LEETCODE ASKS FOR < n
    ============================================================================

    If:

        n = 30


    We need primes STRICTLY LESS THAN 30.


    Therefore:

        2
        3
        5
        7
        11
        13
        17
        19
        23
        29


    30 is not prime anyway, but the important coding condition remains:

        i < n


    ============================================================================
        WHY DOES THE SIEVE WORK?
    ============================================================================

    The Sieve is based on one simple idea:


        If a number is prime:

            Keep it as 1.


        If a number is a multiple of a prime:

            Mark it as 0.


    Example:

        2 is prime.

        Multiples of 2:

            4, 6, 8, 10, 12, ...


        Therefore:

            4, 6, 8, 10, 12, ...

        cannot be prime.


    Then:

        3 is prime.

        Multiples of 3:

            6, 9, 12, 15, ...


        Therefore:

            6, 9, 12, 15, ...

        cannot be prime.


    Then:

        4 is already 0.

        Therefore:

            Skip 4.


    Then:

        5 is still 1.

        Therefore:

            5 is prime.


    Continue this process.


    ============================================================================
        WHY DOES A FINAL 1 MEAN PRIME?
    ============================================================================

    Initially:

        Every number is assumed to be prime.


    Then we eliminate numbers that are definitely NOT prime.


    A number becomes 0 only when we find:

        some prime factor


    Example:

        15


    15 is marked when we process:

        3


    because:

        15 = 3 × 5


    Therefore:

        prime[15] = 0


    On the other hand:

        17


    is never marked.


    Therefore:

        prime[17] = 1


    So:

        17 is prime.


    ============================================================================
        WHY DON'T WE MARK THE PRIME NUMBER ITSELF?
    ============================================================================

    Suppose:

        i = 5


    We know:

        5 is prime.


    If we started from:

        j = i


    then:

        prime[5] = 0


    That would incorrectly say that 5 is not prime.


    Therefore we never mark:

        i


    itself.


    Starting from:

        i * i


    automatically avoids this.


    ============================================================================
        WHY NOT START FROM 2 * i?
    ============================================================================

    We CAN start from:

        2 * i


    and that is the basic Sieve implementation.


    But:

        i * i


    is more optimized.


    Example:

        i = 5


    Basic:

        2 * 5 = 10


    would process:

        10
        15
        20
        25
        ...


    But:

        10

    was already marked by 2.


        15

    was already marked by 3.


        20

    was already marked by 2.


    So the first useful new multiple is:

        25


    which is:

        5 * 5


    Therefore:

        j = i * i


    ============================================================================
        WHY DO WE SKIP COMPOSITE i?
    ============================================================================

    Suppose:

        i = 9


    9 is not prime.


    Why?


        9 = 3 × 3


    It was already marked when:

        i = 3


    Therefore:

        prime[9] = 0


    If we tried to process 9 again, we would mark:

        81
        90
        99
        ...


    unnecessarily.


    Those numbers already have smaller prime factors.


    Therefore:

        if (prime[i] == 1)


    is important.


    ============================================================================
        TIME COMPLEXITY
    ============================================================================

    The Sieve of Eratosthenes has:

        Time Complexity:

            O(n log log n)


    Why?


    Each prime p marks approximately:

        n / p


    multiples.


    So the total marking work is related to:

        n/2 + n/3 + n/5 + n/7 + ...


    over primes.


    This results in the well-known Sieve complexity:

        O(n log log n)


    There is also:

        O(n)

    work for initializing/counting the array.


    Therefore:

        O(n)
        +
        O(n log log n)
        +
        O(n)


    simplifies to:

        O(n log log n)


    because the dominant term is:

        O(n log log n)


    ============================================================================
        SPACE COMPLEXITY
    ============================================================================

    We create:

        prime[n + 1]


    Therefore the additional memory grows linearly with n.


    Space Complexity:

        O(n)


    ============================================================================
        BRUTE FORCE VS BETTER VS SIEVE
    ============================================================================

    --------------------------------------------------------------------------
    APPROACH 1 — BASIC BRUTE FORCE
    --------------------------------------------------------------------------

    For every number:

        Check divisors:

            2 to num - 1


    isPrime():

        O(num)


    Overall approximately:

        O(n²)


    Space:

        O(1)


    --------------------------------------------------------------------------
    APPROACH 2 — SQRT PRIME CHECKING
    --------------------------------------------------------------------------

    For every number:

        Check divisors only while:

            i * i <= num


    isPrime():

        O(sqrt(num))


    Overall upper-bound:

        O(n * sqrt(n))


    Space:

        O(1)


    --------------------------------------------------------------------------
    APPROACH 3 — SIEVE OF ERATOSTHENES
    --------------------------------------------------------------------------

    Pre-compute prime status for all numbers.


    Time:

        O(n log log n)


    Space:

        O(n)


    This is the optimal approach among these three.


    ============================================================================
        IMPORTANT CONCEPTUAL DIFFERENCE
    ============================================================================

    In the brute-force and sqrt approaches:

        We repeatedly ask:

            "Is this number prime?"


    Example:

        isPrime(2)
        isPrime(3)
        isPrime(4)
        isPrime(5)
        ...


    In the Sieve:

        We calculate the prime/non-prime status of MANY numbers together.


    We don't repeatedly perform independent prime checks.


    Instead:

        Start with all numbers as potential primes.

        Then eliminate composite numbers.


    This is called:

        PRE-COMPUTATION


    ============================================================================
        PRE-COMPUTATION IDEA
    ============================================================================

    Suppose we need to answer many prime-related queries.


    Instead of calculating:

        isPrime(2)
        isPrime(3)
        isPrime(4)
        ...


    every time,


    we can calculate the information once:


        prime[2]
        prime[3]
        prime[4]
        ...
        prime[n]


    Then checking whether x is prime becomes:

        prime[x]


    which is:

        O(1)


    This is a very important DSA pattern:

        PRE-COMPUTE ONCE
            +
        ANSWER QUERIES QUICKLY


    ============================================================================
        LEETCODE VERSION
    ============================================================================

    On LeetCode, we don't need main().

    We submit the Solution class.

    The code is given below.
*/

class Solution
{
public:
    // =========================================================================
    // countPrimes()
    // =========================================================================
    //
    // Count prime numbers strictly less than n.
    //
    // Approach:
    //
    //     Sieve of Eratosthenes
    //
    // Time:
    //
    //     O(n log log n)
    //
    // Space:
    //
    //     O(n)
    //
    // =========================================================================

    int countPrimes(int n)
    {
        // ---------------------------------------------------------------------
        // If n <= 2:
        //
        // The only possible smallest prime is 2.
        //
        // But the problem asks for numbers STRICTLY LESS THAN n.
        //
        // Therefore:
        //
        //     n = 0 -> 0
        //     n = 1 -> 0
        //     n = 2 -> 0
        //
        // ---------------------------------------------------------------------

        if (n <= 2)
        {
            return 0;
        }

        // ---------------------------------------------------------------------
        // Create the prime array.
        //
        // Size:
        //
        //     n + 1
        //
        // so indexes:
        //
        //     0 to n
        //
        // are available.
        //
        //
        // Initially:
        //
        //     prime[i] = 1
        //
        // meaning:
        //
        //     "Assume i is prime for now."
        //
        // ---------------------------------------------------------------------

        vector<int> prime(n + 1, 1);

        // ---------------------------------------------------------------------
        // 0 and 1 are NOT prime.
        // ---------------------------------------------------------------------

        prime[0] = 0;
        prime[1] = 0;

        // ---------------------------------------------------------------------
        // Sieve process.
        //
        // We only need to go until:
        //
        //     i * i <= n
        //
        // because every composite number has at least one factor
        // less than or equal to sqrt(n).
        //
        // ---------------------------------------------------------------------

        for (int i = 2; i * i <= n; i++)
        {
            // -----------------------------------------------------------------
            // If prime[i] is 0:
            //
            // i is already known to be composite.
            //
            // Therefore we don't need to process its multiples.
            //
            // If prime[i] is 1:
            //
            // i is prime.
            //
            // So we mark its multiples as non-prime.
            // -----------------------------------------------------------------

            if (prime[i] == 1)
            {
                // ----------------------------------------------------------------
                // Start from i * i.
                //
                // Why not 2 * i?
                //
                // Because smaller multiples of i have already been handled
                // by smaller factors.
                //
                // Example:
                //
                //     i = 5
                //
                //     10 = 2 * 5  -> already handled by 2
                //     15 = 3 * 5  -> already handled by 3
                //     20 = 4 * 5  -> already handled by 2
                //
                // Therefore first useful multiple:
                //
                //     25 = 5 * 5
                //
                // ----------------------------------------------------------------

                for (int j = i * i; j <= n; j += i)
                {
                    // ------------------------------------------------------------
                    // j is a multiple of i.
                    //
                    // Therefore j has a divisor other than 1 and itself.
                    //
                    // So j cannot be prime.
                    //
                    // Mark:
                    //
                    //     1 -> 0
                    //
                    // ------------------------------------------------------------

                    prime[j] = 0;
                }
            }
        }

        // ---------------------------------------------------------------------
        // Count all numbers strictly less than n that are still marked 1.
        //
        // prime[i] == 1
        //
        // means:
        //
        //     i is prime.
        //
        // ---------------------------------------------------------------------

        int count = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i] == 1)
            {
                count++;
            }
        }

        // ---------------------------------------------------------------------
        // Return total number of primes.
        // ---------------------------------------------------------------------

        return count;
    }
};

/*
    ============================================================================
        FINAL CODE TO REMEMBER
    ============================================================================

    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        vector<int> prime(n + 1, 1);

        prime[0] = 0;
        prime[1] = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i] == 1)
            {
                count++;
            }
        }

        return count;
    }


    ============================================================================
        MOST IMPORTANT THINGS TO REMEMBER
    ============================================================================

    1. Create:

           prime[n + 1]


    2. Initially assume:

           prime[i] = 1


    3. But:

           0 and 1 are NOT prime.


    4. Start from:

           i = 2


    5. Only process i when:

           prime[i] == 1


       because then i is prime.


    6. Mark multiples as non-prime:

           prime[j] = 0


    7. Start marking from:

           j = i * i


       instead of:

           j = 2 * i


    8. Outer loop:

           i * i <= n


       instead of:

           i <= n


    9. Finally count:

           prime[i] == 1


       for:

           i < n


    10. Complexity:

           Time  = O(n log log n)
           Space = O(n)


    ============================================================================
        ONE-LINE MEMORY TRICK
    ============================================================================

        "Assume everyone is prime,
         then remove multiples of every prime."


    And the optimized version:

        "Start multiples from i*i
         and process i only while i*i <= n."


    ============================================================================
        END
        LEETCODE 204 — COUNT PRIMES
        SIEVE OF ERATOSTHENES
    ============================================================================
*/