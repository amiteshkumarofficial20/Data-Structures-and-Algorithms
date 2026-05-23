#include <bits/stdc++.h> // Includes almost all standard C++ libraries
using namespace std;

/*
    ============================================================
                    ARRAYS IN C++ & DSA
    ============================================================

    WHAT IS AN ARRAY?
    ------------------------------------------------------------
    - Array is a collection of elements of SAME data type.
    - Elements are stored in contiguous memory locations.
    - Each element is accessed using an INDEX.

    Example:
        int arr[5] = {10,20,30,40,50};

    Here:
        arr[0] = 10
        arr[1] = 20
        arr[2] = 30
        arr[3] = 40
        arr[4] = 50

    ============================================================

    WHY ARRAYS ARE IMPORTANT IN DSA?
    ------------------------------------------------------------
    Arrays are the foundation of:
        - Searching
        - Sorting
        - Sliding Window
        - Prefix Sum
        - Dynamic Programming
        - Matrix Problems
        - Strings
        - Hashing
        - Graph Representation

    Arrays are one of the MOST IMPORTANT topics in DSA.

    ============================================================

    CHARACTERISTICS OF ARRAY
    ------------------------------------------------------------

    1. Fixed Size
       - Size is defined during declaration.

    2. Same Data Type
       - All elements must be same type.

    3. Indexed Access
       - Access using index number.

    4. Contiguous Memory
       - Memory locations are continuous.

    ============================================================

    ARRAY INDEXING
    ------------------------------------------------------------

    Arrays follow 0-based indexing.

    Example:
        int arr[5] = {1,2,3,4,5};

        Index:
            0 1 2 3 4

    First Element:
        arr[0]

    Last Element:
        arr[n-1]

    ============================================================

    TIME COMPLEXITIES
    ------------------------------------------------------------

    Access Element:
        O(1)

    Traversal:
        O(n)

    Searching:
        O(n)

    ============================================================

    TYPES OF ARRAYS
    ------------------------------------------------------------

    1. One Dimensional Array (1D Array)
    2. Two Dimensional Array (2D Array)

    ============================================================
*/

int main()
{
    /*
        ========================================================
                    1D ARRAY THEORY
        ========================================================

        1D Array means array in single row.

        Syntax:
            data_type array_name[size];

        Example:
            int arr[5];

        Memory Representation:
            arr[0] arr[1] arr[2] arr[3] arr[4]

        ========================================================
    */

    /*
        --------------------------------------------------------
                DECLARATION OF 1D ARRAY
        --------------------------------------------------------
    */

    int arr[5];

    /*
        --------------------------------------------------------
                INSERTING ELEMENTS IN ARRAY
        --------------------------------------------------------

        Elements can be inserted using index.

        Example:
            arr[0] = 10;
    */

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    /*
        --------------------------------------------------------
                PRINTING ARRAY ELEMENTS
        --------------------------------------------------------

        Traversal means visiting every element.

        for loop is mostly used for traversal.

        Time Complexity:
            O(n)
    */

    cout << "1D Array Elements:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    /*
        --------------------------------------------------------
                TAKING INPUT IN ARRAY
        --------------------------------------------------------

        User enters array elements dynamically.
    */

    int n;

    cout << "Enter Size of Array: ";

    cin >> n;

    /*
        Dynamic size array
        (works in many compilers for beginners practice)
    */

    int numbers[n];

    cout << "Enter Array Elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    /*
        Printing entered elements
    */

    cout << "Entered Elements Are:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    /*
        ========================================================
                BASIC OPERATIONS ON 1D ARRAY
        ========================================================
    */

    /*
        --------------------------------------------------------
                FINDING SUM OF ARRAY
        --------------------------------------------------------

        Formula:
            sum = sum + array element

        Important in:
            Prefix Sum
            Sliding Window
            Mathematical Problems
    */

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    cout << "Sum of Array Elements: " << sum << endl;

    /*
        --------------------------------------------------------
                FINDING MAXIMUM ELEMENT
        --------------------------------------------------------

        Logic:
            Compare every element with current maximum.
    */

    int maxi = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > maxi)
        {
            maxi = numbers[i];
        }
    }

    cout << "Maximum Element: " << maxi << endl;

    /*
        --------------------------------------------------------
                FINDING MINIMUM ELEMENT
        --------------------------------------------------------
    */

    int mini = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] < mini)
        {
            mini = numbers[i];
        }
    }

    cout << "Minimum Element: " << mini << endl;

    /*
        --------------------------------------------------------
                LINEAR SEARCH
        --------------------------------------------------------

        Theory:
        - Search element one by one.

        Time Complexity:
            O(n)

        Important Beginner DSA Topic.
    */

    int target;

    cout << "Enter Element to Search: ";

    cin >> target;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == target)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    /*
        ========================================================
                    2D ARRAY THEORY
        ========================================================

        2D Array means rows and columns.

        Also called MATRIX.

        Syntax:
            int arr[row][col];

        Example:
            int matrix[2][3];

        Structure:

            Column →
                0   1   2

        Row 0   1   2   3
        Row 1   4   5   6

        Access:
            matrix[i][j]

        ========================================================
    */

    /*
        --------------------------------------------------------
                DECLARATION OF 2D ARRAY
        --------------------------------------------------------
    */

    int matrix[2][3];

    /*
        --------------------------------------------------------
                INSERTING ELEMENTS
        --------------------------------------------------------
    */

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    /*
        --------------------------------------------------------
                PRINTING 2D ARRAY
        --------------------------------------------------------

        Nested Loop:
        - Outer loop for rows
        - Inner loop for columns
    */

    cout << "2D Array Elements:" << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    /*
        ========================================================
                TAKING INPUT IN 2D ARRAY
        ========================================================
    */

    int row, col;

    cout << "Enter Rows and Columns: ";

    cin >> row >> col;

    int arr2[row][col];

    cout << "Enter Matrix Elements:" << endl;

    /*
        Input using nested loops
    */

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2[i][j];
        }
    }

    /*
        Printing matrix
    */

    cout << "Matrix is:" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr2[i][j] << " ";
        }

        cout << endl;
    }

    /*
        ========================================================
                SUM OF ALL ELEMENTS IN 2D ARRAY
        ========================================================
    */

    int totalsum = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            totalsum += arr2[i][j];
        }
    }

    cout << "Sum of Matrix Elements: " << totalsum << endl;

    /*
        ========================================================
                    IMPORTANT DSA CONCEPTS
        ========================================================

        Arrays are used in:

        1. Pattern Problems
        2. Sorting Algorithms
        3. Binary Search
        4. Prefix Sum
        5. Sliding Window
        6. Matrix Problems
        7. Dynamic Programming
        8. Greedy Algorithms

        ========================================================
                    COMMON ARRAY MISTAKES
        ========================================================

        1. Accessing invalid index
            Example:
                arr[10] when size is 5

        2. Forgetting loop boundaries

        3. Confusing rows and columns in 2D array

        4. Not initializing variables

        ========================================================
    */

    /*
        return 0;
        ----------------
        Indicates successful execution of program.
    */

    return 0;
}