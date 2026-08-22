#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
============================================================
1. CUSTOM FUNCTION FOR for_each()
============================================================

for_each() ka kaam:

    Container ke [begin, end) range ke
    har element par given function ko call karna.

Syntax:

    for_each(
        first,
        last,
        function
    );

Yahan:

    first    -> arr.begin()
    last     -> arr.end()
    function -> printdouble

Example:

    arr = {10, 20, 30}

    for_each(arr.begin(), arr.end(), printdouble);

Internally conceptually:

    printdouble(arr[0]);
    printdouble(arr[1]);
    printdouble(arr[2]);

Output:

    20
    40
    60
*/

void printdouble(int a)
{
    // Current element ko 2 se multiply karke print kar rahe hain.
    cout << 2 * a << endl;
}

/*
============================================================
2. CUSTOM PREDICATE FUNCTION
============================================================

Predicate ka matlab:

    Aisi function jo usually bool return karti hai.

Yahan checkeven():

    even number -> true
    odd number  -> false

Examples:

    checkeven(10) -> true
    checkeven(15) -> false

STL ke kaafi algorithms predicates accept karte hain:

    find_if()
    count_if()
    partition()
    remove_if()
    etc.
*/

bool checkeven(int a)
{
    // Agar number 2 se completely divisible hai,
    // to number even hai.
    return a % 2 == 0;
}

int main()
{
    /*
    ========================================================
    VECTOR CREATION
    ========================================================

    Original code mein tha:

        vector<int> arr(5);

    Iska matlab:

        vector mein exactly 5 elements hain.

    Valid indexes:

        0
        1
        2
        3
        4

    Lekin tum original code mein:

        arr[5]
        arr[6]
        arr[7]
        arr[8]

    use kar rahe the.

    Ye OUT OF BOUNDS hai.

    Isliye yahan 9 elements ka vector bana rahe hain.
    */

    vector<int> arr(9);

    /*
    ========================================================
    INITIALIZATION
    ========================================================
    */

    arr[0] = 41;
    arr[1] = 28;
    arr[2] = 63;
    arr[3] = 46;
    arr[4] = 54;
    arr[5] = 54;
    arr[6] = 84;
    arr[7] = 54;
    arr[8] = 54;

    /*
    Current vector:

        Index:   0   1   2   3   4   5   6   7   8
        Value:  41  28  63  46  54  54  84  54  54
    */

    /*
    ========================================================
    for_each()
    ========================================================

    for_each() har element ke liye printdouble() call karega.

    Conceptually:

        printdouble(41);
        printdouble(28);
        printdouble(63);
        ...

    Output:

        82
        56
        126
        92
        108
        108
        168
        108
        108

    Complexity:

        O(n)

    Important:

        for_each() normally container ko modify nahi karta
        unless function/reference ke through modification
        intentionally ki jaaye.
    */

    for_each(
        arr.begin(),
        arr.end(),
        printdouble);

    /*
    ========================================================
    find()
    ========================================================

    find() kisi particular VALUE ko search karta hai.

    Syntax:

        find(
            begin,
            end,
            target
        );

    Agar target mil gaya:

        target ke element par iterator return hota hai.

    Agar nahi mila:

        arr.end()

    return hota hai.

    IMPORTANT:

        find() "0" return nahi karta.

    Tumhare original comment mein tha:

        "not found then 0"

    Ye incorrect hai.

    Correct:

        not found -> arr.end()
    */

    int target = 40;

    vector<int>::iterator it =
        find(
            arr.begin(),
            arr.end(),
            target);

    /*
    IMPORTANT:

    find() ke result ko directly dereference nahi karna chahiye
    jab tak check na kar lo ki iterator == end() nahi hai.

    Wrong:

        cout << *it;

    Agar target nahi mila to:

        it == arr.end()

    aur:

        *it

    invalid/undefined behavior hai.
    */

    if (it != arr.end())
    {
        // Target mil gaya.
        cout << "Target found: "
             << *it
             << endl;
    }
    else
    {
        // Target nahi mila.
        cout << "Target not found"
             << endl;
    }

    /*
    ========================================================
    find_if()
    ========================================================

    find() value search karta hai.

    find_if() CONDITION ke basis par search karta hai.

    Example:

        checkeven()

    Pehla even number return hoga.

    Vector:

        41 28 63 46 54 ...

    Pehla even:

        28

    Isliye iterator 28 ko point karega.
    */

    vector<int>::iterator evenIt =
        find_if(
            arr.begin(),
            arr.end(),
            checkeven);

    if (evenIt != arr.end())
    {
        cout << "First even element: "
             << *evenIt
             << endl;
    }
    else
    {
        cout << "No even element found"
             << endl;
    }

    /*
    ========================================================
    count()
    ========================================================

    count() kisi specific value ki occurrences count karta hai.

    Syntax:

        count(
            begin,
            end,
            value
        );

    Example:

        54 kitni baar hai?

    Vector:

        41 28 63 46 54 54 84 54 54

    54 -> 4 times
    */

    int ourtarget = 54;

    int ans =
        count(
            arr.begin(),
            arr.end(),
            ourtarget);

    cout
        << "Occurrences of Target is: "
        << ans
        << endl;

    /*
    ========================================================
    count() WHEN ELEMENT DOES NOT EXIST
    ========================================================

    Agar target vector mein nahi hai,
    count() simply 0 return karega.

    Isliye:

        504 -> 0 occurrences
    */

    int thetarget = 504;

    int answer =
        count(
            arr.begin(),
            arr.end(),
            thetarget);

    cout
        << "Occurrences of 504 is: "
        << answer
        << endl;

    /*
    ========================================================
    count_if()
    ========================================================

    count():

        VALUE ke basis par count.

    count_if():

        CONDITION ke basis par count.

    Yahan:

        checkeven()

    use ho raha hai.

    Isliye vector mein total even numbers count honge.

    Current vector:

        41 28 63 46 54 54 84 54 54

    Even:

        28
        46
        54
        54
        84
        54
        54

    Total:

        7
    */

    int anss =
        count_if(
            arr.begin(),
            arr.end(),
            checkeven);

    cout
        << "Number of even elements: "
        << anss
        << endl;

    /*
    ========================================================
    sort()
    ========================================================

    sort() range ko ascending order mein sort karta hai.

    Syntax:

        sort(
            begin,
            end
        );

    Example:

        41 28 63 46 54 54 84 54 54

    becomes:

        28 41 46 54 54 54 54 63 84

    Complexity:

        O(n log n)

    Important:

        sort() random-access iterators require karta hai.

    Isliye:

        vector -> yes
        array  -> yes
        deque  -> yes
        list   -> use list.sort()
    */

    sort(
        arr.begin(),
        arr.end());

    /*
    Sorted vector print.
    */

    cout << "After sorting: ";

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    /*
    ========================================================
    DESCENDING SORT
    ========================================================

    Agar descending order chahiye:

        sort(
            arr.begin(),
            arr.end(),
            greater<int>()
        );

    Example:

        1 2 3 4 5

    becomes:

        5 4 3 2 1
    */

    /*
    ========================================================
    reverse()
    ========================================================

    reverse() range ko ulta kar deta hai.

    Example:

        28 41 46 54 54 54 54 63 84

    becomes:

        84 63 54 54 54 54 46 41 28

    Complexity:

        O(n)
    */

    reverse(
        arr.begin(),
        arr.end());

    cout << "After reverse: ";

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    /*
    ========================================================
    rotate()
    ========================================================

    Ye important hai.

    General syntax:

        rotate(
            first,
            middle,
            last
        );

    Iska meaning:

        [first, middle)
        ko end par bhej do

    aur:

        [middle, last)
        ko beginning par le aao.


    Example:

        arr =

        1 2 3 4 5

    Agar:

        rotate(
            arr.begin(),
            arr.begin() + 2,
            arr.end()
        );

    Result:

        3 4 5 1 2


    So:

        rotate(begin, begin + k, end)

    means LEFT ROTATE by k positions.


    ========================================================
    LEFT ROTATE
    ========================================================

        rotate(
            arr.begin(),
            arr.begin() + k,
            arr.end()
        );


    Example:

        1 2 3 4 5

    left rotate by 2:

        3 4 5 1 2


    ========================================================
    RIGHT ROTATE
    ========================================================

    Right rotate by k ke liye:

        rotate(
            arr.begin(),
            arr.end() - k,
            arr.end()
        );

    Example:

        1 2 3 4 5

    right rotate by 2:

        4 5 1 2 3


    IMPORTANT:

        k should normally be normalized:

            k %= arr.size();

    before using it.
    */

    cout << "Before Rotating: ";

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    int k = 2;

    /*
    LEFT ROTATE BY 2
    */

    if (!arr.empty())
    {
        k %= arr.size();

        rotate(
            arr.begin(),
            arr.begin() + k,
            arr.end());
    }

    cout << "After Left Rotating by 2: ";

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    /*
    ========================================================
    RIGHT ROTATE EXAMPLE
    ========================================================

    Agar current vector ko right rotate karna ho:

        rotate(
            arr.begin(),
            arr.end() - k,
            arr.end()
        );

    Example:

        1 2 3 4 5

        right rotate 2

        4 5 1 2 3
    */

    /*
    ========================================================
    IMPORTANT ERROR IN ORIGINAL CODE
    ========================================================

    Tumne likha tha:

        rotate(
            arr.begin(),
            arr.begin() + 2,
            arr.end()
        )
        {
            ...
        }

    Ye invalid C++ syntax hai.

    rotate() ke baad `{}` nahi lagta.

    Correct:

        rotate(
            arr.begin(),
            arr.begin() + 2,
            arr.end()
        );

    Phir separately:

        for (...)
        {
            ...
        }
    */

    /*
    ========================================================
    UNIQUE()
    ========================================================

    unique() ka purpose beginners ke liye confusing hota hai.

    IMPORTANT:

        unique() vector ka size automatically reduce
        nahi karta.

    Ye consecutive duplicate values ko
    range ke front mein compact karta hai.

    Example:

        1 1 1 2 2 3

    unique() ke baad logical range:

        1 2 3

    Lekin vector ka actual size ab bhi 6 ho sakta hai.

    unique() ek iterator return karta hai:

        new logical end

    Correct pattern:

        auto newEnd =
            unique(
                arr.begin(),
                arr.end()
            );

        arr.erase(
            newEnd,
            arr.end()
        );

    Ye actual duplicates ko remove karta hai.

    ========================================================
    VERY IMPORTANT:
    ========================================================

    unique() generally consecutive duplicates remove karta hai.

    Agar:

        1 2 1 2 1

    hai,

    to unique() sab duplicates ko remove nahi karega.

    Agar ALL duplicates remove karne hain:

        sort()
        unique()
        erase()

    Example:

        sort(arr.begin(), arr.end());

        arr.erase(
            unique(arr.begin(), arr.end()),
            arr.end()
        );
    */

    /*
    Hum ek fresh vector bana rahe hain
    unique() ka clearly demonstration karne ke liye.
    */

    vector<int> brr = {
        11,
        11,
        11,
        46,
        54,
        54,
        84,
        124,
        54};

    cout << "Before unique: ";

    for (int x : brr)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    unique() sirf consecutive duplicates
    ko compact karega.

    brr:

        11 11 11 46 54 54 84 124 54

    Logical unique sequence:

        11 46 54 84 124 54

    Last 54 important hai:

        54

    consecutive duplicate nahi hai,
    isliye woh remain karega.
    */

    auto newEnd =
        unique(
            brr.begin(),
            brr.end());

    /*
    newEnd ab logical end ko point karta hai.

    Actual vector memory mein trailing values
    abhi bhi ho sakti hain.

    Isliye erase karna zaroori hai.
    */

    brr.erase(
        newEnd,
        brr.end());

    cout << "After unique + erase: ";

    for (int x : brr)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    ========================================================
    ALL DUPLICATES REMOVE KARNE KA STANDARD PATTERN
    ========================================================

    Agar unordered/random duplicates bhi remove karne hain:

        1. sort
        2. unique
        3. erase

    Example:

        vector<int> x = {
            4,
            1,
            4,
            2,
            1,
            3
        };

        sort(...)

        1 1 2 3 4 4

        unique(...)

        1 2 3 4

        erase(...)

        Final:

        1 2 3 4
    */

    /*
    ========================================================
    PARTITION()
    ========================================================

    partition() elements ko do groups mein divide karta hai:

        condition true
        condition false

    Yahan predicate:

        checkeven()

    hai.

    Therefore:

        EVEN numbers
        ODD numbers

    separate ho jayenge.

    Example:

        41 28 63 46 54 54 84

    After partition, order is NOT guaranteed to be sorted.

    Possible result:

        84 28 54 46 54 | 63 41

        left side  -> even
        right side -> odd


    IMPORTANT:

        partition() stable order guarantee nahi karta.

    Agar relative order preserve karna ho:

        stable_partition()

    use kar sakte ho.
    */

    /*
    Hum brr par partition perform kar rahe hain.
    */

    auto partitionPoint =
        partition(
            brr.begin(),
            brr.end(),
            checkeven);

    /*
    partitionPoint:

        first element of the FALSE group

    Yahan:

        [begin, partitionPoint)

    mein checkeven == true hoga.

    Aur:

        [partitionPoint, end)

    mein checkeven == false hoga.
    */

    cout << "After partition: ";

    for (int x : brr)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    ========================================================
    PRINT ONLY EVEN PART
    ========================================================
    */

    cout << "Even partition: ";

    for (
        auto iter = brr.begin();
        iter != partitionPoint;
        ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    /*
    ========================================================
    PRINT ONLY ODD PART
    ========================================================
    */

    cout << "Odd partition: ";

    for (
        auto iter = partitionPoint;
        iter != brr.end();
        ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    /*
    ========================================================
    partition() vs stable_partition()
    ========================================================

    partition():

        Relative order preserve nahi karta.

    stable_partition():

        Relative order preserve karta hai.

    Example:

        2 4 1 6 3

    Partition:

        Even elements first,
        odd elements later.

    Exact order implementation-dependent ho sakta hai.

    stable_partition():

        2 4 6 1 3

    Even elements ka original order:

        2, 4, 6

    preserve rahega.

    Odd elements ka original order:

        1, 3

    preserve rahega.
    */

    /*
    ========================================================
    FINAL PROGRAM END
    ========================================================
    */

    return 0;
}
