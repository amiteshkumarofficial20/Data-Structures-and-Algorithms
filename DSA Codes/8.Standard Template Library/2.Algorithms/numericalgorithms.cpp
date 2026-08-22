#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

/*
====================================================================
                    NUMERIC STL ALGORITHMS
====================================================================

Ye algorithms <numeric> header mein milte hain.

Important algorithms:

    1. accumulate()
    2. inner_product()
    3. partial_sum()
    4. iota()

Ye algorithms mainly numbers/ranges ke saath calculations
karne ke kaam aate hain.


====================================================================
1. accumulate()
====================================================================

accumulate() ka basic kaam:

    Range ke saare elements ka sum nikalna.

Syntax:

    accumulate(
        first,
        last,
        initial_value
    );


Example:

    vector<int> arr = {
        10,
        20,
        30
    };

    int sum = accumulate(
        arr.begin(),
        arr.end(),
        0
    );


Calculation:

    0 + 10 + 20 + 30

Result:

    60


IMPORTANT:

Third argument initial value hota hai.

    0
        -> integer sum

    100
        -> sum 100 se start hoga


Example:

    vector<int> v = {
        10,
        20,
        30
    };

    accumulate(
        v.begin(),
        v.end(),
        100
    );


Calculation:

    100 + 10 + 20 + 30

Result:

    160


Complexity:

    O(n)
*/

int main()
{
    /*
    =================================================================
                        VECTOR FOR ACCUMULATE
    =================================================================

    Original code mein:

        vector<int> arr(5);

    tha.

    Iska matlab:

        Size = 5

    Valid indexes:

        0
        1
        2
        3
        4

    Lekin original code mein:

        arr[5]
        arr[6]

    bhi use kiya gaya tha.

    Ye OUT OF BOUNDS hai.

    Isliye agar humein 7 elements chahiye:

        vector<int> arr(7);

    karna padega.
    */

    vector<int> arr(7);

    /*
    -----------------------------------------------------------------
    VECTOR VALUES
    -----------------------------------------------------------------
    */

    arr[0] = 11;
    arr[1] = 11;
    arr[2] = 1010;
    arr[3] = 17;
    arr[4] = 18;
    arr[5] = 10;
    arr[6] = 11;

    /*
    Vector:

        11  11  1010  17  18  10  11


    Index:

         0   1    2    3   4   5   6
    */

    /*
    =================================================================
                        ACCUMULATE()
    =================================================================

    Syntax:

        accumulate(
            arr.begin(),
            arr.end(),
            0
        );


    Meaning:

        arr.begin()
            -> first element

        arr.end()
            -> one position after last element

        0
            -> initial sum


    Calculation:

        0
        + 11
        + 11
        + 1010
        + 17
        + 18
        + 10
        + 11


    Result:

        1088
    */

    int totalSum = accumulate(
        arr.begin(),
        arr.end(),
        0);

    cout << "Total Sum: "
         << totalSum
         << endl;

    /*
    =================================================================
                ACCUMULATE WITH DIFFERENT INITIAL VALUE
    =================================================================

    Agar initial value 100 ho:

        100
        + all elements


    Result:

        1188
    */

    int sumWith100 = accumulate(
        arr.begin(),
        arr.end(),
        100);

    cout << "Sum starting from 100: "
         << sumWith100
         << endl;

    /*
    =================================================================
                    SECOND VECTOR
    =================================================================

    Ab hum inner_product() samjhenge.
    */

    vector<int> first;

    first.push_back(1);
    first.push_back(12);
    first.push_back(19);
    first.push_back(80);

    /*
    first:

        1 12 19 80
    */

    vector<int> second;

    second.push_back(16);
    second.push_back(29);
    second.push_back(89);
    second.push_back(50);

    /*
    second:

        16 29 89 50
    */

    /*
    =================================================================
                        INNER_PRODUCT()
    =================================================================

    inner_product() do vectors/ranges ke corresponding
    elements ka product karke unka sum nikal sakta hai.

    Example:

        first:

            1   12   19   80

        second:

            16  29   89   50


    Corresponding multiplication:

        1  * 16 = 16

        12 * 29 = 348

        19 * 89 = 1691

        80 * 50 = 4000


    Then:

        16
        + 348
        + 1691
        + 4000

        = 6055


    Syntax:

        inner_product(
            first_begin,
            first_end,
            second_begin,
            initial_value
        );


    IMPORTANT:

    Tumhare original code mein ye tha:

        inner_product(
            first.begin(),
            first.end(),
            second.begin(),
            second.end(),
            0
        );


    Ye WRONG hai.

    Standard 4-argument version:

        inner_product(
            first.begin(),
            first.end(),
            second.begin(),
            0
        );


    4th argument:

        0

    initial value hai.


    IMPORTANT:

    Dono ranges compatible honi chahiye.

    Agar first mein 4 elements hain,
    to second mein kam se kam 4 elements hone chahiye.
    */

    int innerProduct = inner_product(
        first.begin(),
        first.end(),
        second.begin(),
        0);

    cout << "Inner Product is: "
         << innerProduct
         << endl;

    /*
    =================================================================
                    INNER PRODUCT FORMULA
    =================================================================

    For:

        A = {a1, a2, a3}

        B = {b1, b2, b3}


    inner_product():

        initial
        + a1*b1
        + a2*b2
        + a3*b3


    Example:

        A = {1, 2, 3}
        B = {4, 5, 6}

        initial = 0


    Result:

        0
        + 1*4
        + 2*5
        + 3*6

        = 4 + 10 + 18

        = 32
    */

    vector<int> A = {
        1,
        2,
        3};

    vector<int> B = {
        4,
        5,
        6};

    int product = inner_product(
        A.begin(),
        A.end(),
        B.begin(),
        0);

    cout << "Example Inner Product: "
         << product
         << endl;

    /*
    =================================================================
                        PARTIAL_SUM()
    =================================================================

    partial_sum() prefix sum calculate karta hai.

    Example:

        Input:

            1 2 3 4 5


        Partial Sum:

            1
            1+2
            1+2+3
            1+2+3+4
            1+2+3+4+5


        Output:

            1 3 6 10 15


    Syntax:

        partial_sum(
            first,
            last,
            output_begin
        );


    Usually hum separate output vector use karte hain.


    IMPORTANT:

    partial_sum() <numeric> header mein hota hai.
    */

    vector<int> numbers = {
        1,
        2,
        3,
        4,
        5};

    /*
    Output vector.

    Same size ka vector create kar rahe hain.
    */

    vector<int> prefix(
        numbers.size());

    /*
    partial_sum():

        numbers:

            1 2 3 4 5


        prefix:

            1 3 6 10 15
    */

    partial_sum(
        numbers.begin(),
        numbers.end(),
        prefix.begin());

    cout << "Partial Sum: ";

    for (int x : prefix)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    =================================================================
                    PARTIAL SUM STEP-BY-STEP
    =================================================================

    Input:

        1 2 3 4 5


    Step 1:

        1


    Step 2:

        1 + 2 = 3


    Step 3:

        1 + 2 + 3 = 6


    Step 4:

        1 + 2 + 3 + 4 = 10


    Step 5:

        1 + 2 + 3 + 4 + 5 = 15


    Final:

        1 3 6 10 15


    Complexity:

        O(n)
    */

    /*
    =================================================================
                    iota()
    =================================================================

    iota() range ko consecutive values se fill karta hai.

    IMPORTANT:

    iota() <numeric> header mein hota hai.

    Syntax:

        iota(
            first,
            last,
            starting_value
        );


    Example:

        vector<int> v(5);

        iota(
            v.begin(),
            v.end(),
            1
        );


    Result:

        1 2 3 4 5


    Yahan:

        starting_value = 1

    Phir har next element mein +1 hota hai.
    */

    vector<int> sequence(5);

    iota(
        sequence.begin(),
        sequence.end(),
        1);

    cout << "iota() from 1: ";

    for (int x : sequence)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    =================================================================
                    iota() WITH DIFFERENT START
    =================================================================

    Agar starting value 100 ho:

        100 101 102 103 104
    */

    vector<int> sequence2(5);

    iota(
        sequence2.begin(),
        sequence2.end(),
        100);

    cout << "iota() from 100: ";

    for (int x : sequence2)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    =================================================================
                    iota() WITH NEGATIVE VALUE
    =================================================================

    Starting value -3:

        -3 -2 -1 0 1
    */

    vector<int> sequence3(5);

    iota(
        sequence3.begin(),
        sequence3.end(),
        -3);

    cout << "iota() from -3: ";

    for (int x : sequence3)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    =================================================================
                    ALL FOUR ALGORITHMS SUMMARY
    =================================================================


    1. accumulate()

        Purpose:

            Entire range ka result combine karna.

        Common use:

            Sum

        Example:

            accumulate(
                v.begin(),
                v.end(),
                0
            );


        Input:

            1 2 3 4

        Result:

            10


    -----------------------------------------------------------------

    2. inner_product()

        Purpose:

            Corresponding elements ko multiply
            karke sum/combine karna.

        Example:

            A = 1 2 3

            B = 4 5 6


            1*4 + 2*5 + 3*6

            = 32


    -----------------------------------------------------------------

    3. partial_sum()

        Purpose:

            Prefix sums / running totals.


        Input:

            1 2 3 4 5


        Output:

            1 3 6 10 15


    -----------------------------------------------------------------

    4. iota()

        Purpose:

            Consecutive values se range fill karna.


        Example:

            iota(
                v.begin(),
                v.end(),
                10
            );


        Output:

            10 11 12 13 14


    =================================================================
                        COMPLEXITIES
    =================================================================


    accumulate()

        O(n)


    inner_product()

        O(n)


    partial_sum()

        O(n)


    iota()

        O(n)


    =================================================================
                        IMPORTANT DIFFERENCE
    =================================================================


    accumulate():

        Pura range -> ONE final value


        Example:

            1 2 3 4 5

        Result:

            15


    partial_sum():

        Pura range -> PREFIX VALUES


        Example:

            1 2 3 4 5

        Result:

            1 3 6 10 15


    inner_product():

        TWO ranges -> ONE final value


        Example:

            1 2 3
            4 5 6

        Result:

            32


    iota():

        Range ko values se FILL karta hai


        Example:

            vector<int> v(5);

            iota(
                v.begin(),
                v.end(),
                10
            );


        Result:

            10 11 12 13 14


    =================================================================
                        HEADERS
    =================================================================


    accumulate()
        -> #include <numeric>

    inner_product()
        -> #include <numeric>

    partial_sum()
        -> #include <numeric>

    iota()
        -> #include <numeric>


    So is program mein:

        #include <numeric>

    MOST IMPORTANT header hai.


    =================================================================
                        FINAL PROGRAM END
    =================================================================
    */

    return 0;
}