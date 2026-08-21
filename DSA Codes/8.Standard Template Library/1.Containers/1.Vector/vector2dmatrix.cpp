#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ============================================================
    // 2D VECTOR
    // ============================================================
    //
    // A 2D vector is basically a vector whose elements are
    // themselves vectors.
    //
    // General syntax:
    //
    // vector<vector<int>> arr;
    //
    // Here:
    //
    // vector<int>
    // -> represents one row
    //
    // vector<vector<int>>
    // -> represents multiple rows
    //
    // We can think of it like a matrix:
    //
    //       column
    //       0  1  2  3
    //
    // row 0 0  0  0  0
    // row 1 0  0  0  0
    // row 2 0  0  0  0
    // row 3 0  0  0  0

    // ============================================================
    // CREATING A 4 x 4 2D VECTOR
    // ============================================================

    vector<vector<int>> arr2d(4, vector<int>(4, 0));

    // Let's break this line into small parts:
    //
    // vector<vector<int>>
    // -------------------
    // This means:
    //
    // "arr2d is a vector, and each element of arr2d
    // is itself a vector<int>."
    //
    //
    // First 4:
    //
    // vector<vector<int>> arr2d(4, ...);
    //
    // This creates 4 rows.
    //
    //
    // vector<int>(4, 0)
    // -----------------
    // This creates ONE row containing:
    //
    // [0, 0, 0, 0]
    //
    // because:
    //
    // vector<int>(4, 0)
    //
    // means:
    //
    // "Create a vector of size 4,
    //  and initialize every element with 0."
    //
    //
    // Putting everything together:
    //
    // vector<vector<int>> arr2d(4, vector<int>(4, 0));
    //
    // means:
    //
    // Create 4 rows,
    // and each row contains 4 integers initialized to 0.
    //
    // Final structure:
    //
    // [0, 0, 0, 0]  <- row 0
    // [0, 0, 0, 0]  <- row 1
    // [0, 0, 0, 0]  <- row 2
    // [0, 0, 0, 0]  <- row 3
    //
    //
    // Therefore:
    //
    // total rows    = 4
    // total columns = 4

    // ============================================================
    // FINDING TOTAL NUMBER OF ROWS
    // ============================================================

    int totalrows = arr2d.size();

    // size() tells us how many elements are present
    // in arr2d.
    //
    // But remember:
    //
    // arr2d is a vector of vectors.
    //
    // So each element of arr2d represents one complete row.
    //
    // Therefore:
    //
    // arr2d.size()
    //
    // gives the NUMBER OF ROWS.
    //
    //
    // Our vector:
    //
    // arr2d
    //
    // contains:
    //
    // row 0 -> vector<int>
    // row 1 -> vector<int>
    // row 2 -> vector<int>
    // row 3 -> vector<int>
    //
    // Number of rows = 4
    //
    // Therefore:
    //
    // totalrows = 4

    // ============================================================
    // FINDING TOTAL NUMBER OF COLUMNS
    // ============================================================

    int totalcolumns = arr2d[0].size();

    // This is very important to understand.
    //
    // arr2d[0]
    //
    // means:
    //
    // "Give me the FIRST row."
    //
    // Since our first row is:
    //
    // [0, 0, 0, 0]
    //
    // arr2d[0] is a vector<int>.
    //
    //
    // Now:
    //
    // arr2d[0].size()
    //
    // asks:
    //
    // "How many elements are present inside the first row?"
    //
    // The first row contains:
    //
    // [0, 0, 0, 0]
    //
    // So:
    //
    // arr2d[0].size() = 4
    //
    // Therefore:
    //
    // totalcolumns = 4

    // ============================================================
    // PRINTING ROWS AND COLUMNS
    // ============================================================

    cout << "Total Rows = " << totalrows << endl;
    cout << "Total Columns = " << totalcolumns << endl;

    // ============================================================
    // ACCESSING A PARTICULAR ELEMENT
    // ============================================================

    // In a 2D vector, we use:
    //
    // arr2d[row][column]
    //
    // Example:
    //
    // arr2d[0][0]
    //
    // means:
    //
    // row 0, column 0
    //
    // Current value is 0.

    cout << "arr2d[0][0] = "
         << arr2d[0][0] << endl;

    // ============================================================
    // CHANGING A VALUE
    // ============================================================

    // We can directly change any element using:
    //
    // arr2d[row][column] = value;

    arr2d[1][2] = 50;

    // Now row 1 becomes:
    //
    // [0, 0, 50, 0]
    //
    // So:
    //
    // arr2d[1][2] = 50

    cout << "arr2d[1][2] = "
         << arr2d[1][2] << endl;

    // ============================================================
    // PRINTING THE COMPLETE 2D VECTOR
    // ============================================================

    // Outer loop:
    //
    // Goes through every row.
    //
    // Inner loop:
    //
    // Goes through every column of the current row.

    for (int i = 0; i < totalrows; i++)
    {
        for (int j = 0; j < totalcolumns; j++)
        {
            cout << arr2d[i][j] << " ";
        }

        // After one row is printed,
        // move to the next line.
        cout << endl;
    }

    // ============================================================
    // RANGE-BASED LOOP VERSION
    // ============================================================
    //
    // Since arr2d is a vector of vectors,
    // we can also use range-based loops.
    //
    // First loop:
    //
    // row represents one complete row.
    //
    // Second loop:
    //
    // x represents one element of that row.

    cout << "\nUsing range-based loops:\n";

    for (const auto &row : arr2d)
    {
        for (const auto &x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    // ============================================================
    // IMPORTANT: WHY arr2d[0].size()?
    // ============================================================
    //
    // Suppose:
    //
    // arr2d =
    //
    // [1, 2, 3]
    // [4, 5, 6]
    // [7, 8, 9]
    //
    //
    // arr2d.size()
    //
    // gives:
    //
    // 3
    //
    // because there are 3 rows.
    //
    //
    // arr2d[0].size()
    //
    // gives:
    //
    // 3
    //
    // because row 0 contains 3 elements.
    //
    //
    // So for a regular rectangular 2D vector:
    //
    // rows    = arr2d.size()
    // columns = arr2d[0].size()

    // ============================================================
    // VERY IMPORTANT: EMPTY 2D VECTOR
    // ============================================================
    //
    // Be careful:
    //
    // If arr2d is empty:
    //
    // vector<vector<int>> arr2d;
    //
    // then:
    //
    // arr2d.size() == 0
    //
    // and:
    //
    // arr2d[0]
    //
    // is INVALID because there is no row 0.
    //
    // Therefore, this:
    //
    // arr2d[0].size()
    //
    // should only be used when arr2d is not empty.
    //
    // Safe approach:
    //
    // if (!arr2d.empty())
    // {
    //     int columns = arr2d[0].size();
    // }

    return 0;
}