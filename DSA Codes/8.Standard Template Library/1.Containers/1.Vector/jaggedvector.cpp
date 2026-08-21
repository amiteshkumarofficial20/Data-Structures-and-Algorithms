#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // ============================================================
    // JAGGED 2D VECTOR
    // ============================================================
    //
    // A jagged vector is a 2D vector where different rows
    // can have different numbers of columns.
    //
    // Example:
    //
    // Row 0 -> [10, 20, 30]
    // Row 1 -> [40, 50]
    // Row 2 -> [60, 70, 80, 90]
    //
    // Here:
    //
    // Row 0 has 3 elements
    // Row 1 has 2 elements
    // Row 2 has 4 elements
    //
    // This is called a JAGGED VECTOR.

    // ============================================================
    // STEP 1: CREATE OUTER VECTOR
    // ============================================================

    vector<vector<int>> arrjagged(4);

    // Let's understand this carefully.
    //
    // vector<vector<int>>
    //
    // means:
    //
    // "A vector whose elements are themselves vector<int>."
    //
    // In simple words:
    //
    // Outer vector
    //     |
    //     |---- Row 0 -> vector<int>
    //     |---- Row 1 -> vector<int>
    //     |---- Row 2 -> vector<int>
    //     |---- Row 3 -> vector<int>
    //
    //
    // (4)
    //
    // means the OUTER vector has 4 elements.
    //
    // Since each element is a vector<int>,
    // we can think of these 4 elements as 4 rows.
    //
    // IMPORTANT:
    //
    // We have created 4 ROWS,
    // but we have NOT created any columns yet.
    //
    // So initially:
    //
    // arrjagged =
    //
    // Row 0 -> []
    // Row 1 -> []
    // Row 2 -> []
    // Row 3 -> []
    //
    // Every row is currently EMPTY.
    //
    // Therefore:
    //
    // arrjagged.size() = 4
    //
    // But:
    //
    // arrjagged[0].size() = 0
    // arrjagged[1].size() = 0
    // arrjagged[2].size() = 0
    // arrjagged[3].size() = 0

    // ============================================================
    // STEP 2: CREATE ROW 0
    // ============================================================

    arrjagged[0] = vector<int>(4);

    // Let's break this into parts.
    //
    // arrjagged[0]
    //
    // means:
    //
    // "Access row 0 of arrjagged."
    //
    // Initially row 0 was:
    //
    // []
    //
    //
    // Now:
    //
    // vector<int>(4)
    //
    // creates a vector of 4 integers.
    //
    // Since we did not give a specific value,
    // int elements are value-initialized to 0.
    //
    // So:
    //
    // vector<int>(4)
    //
    // becomes:
    //
    // [0, 0, 0, 0]
    //
    //
    // Therefore:
    //
    // arrjagged[0] = [0, 0, 0, 0]
    //
    // Current complete structure:
    //
    // Row 0 -> [0, 0, 0, 0]
    // Row 1 -> []
    // Row 2 -> []
    // Row 3 -> []

    // ============================================================
    // STEP 3: CREATE ROW 1
    // ============================================================

    arrjagged[1] = vector<int>(4);

    // Same concept.
    //
    // arrjagged[1]
    //
    // means second row.
    //
    // vector<int>(4)
    //
    // creates:
    //
    // [0, 0, 0, 0]
    //
    //
    // So now:
    //
    // Row 0 -> [0, 0, 0, 0]
    // Row 1 -> [0, 0, 0, 0]
    // Row 2 -> []
    // Row 3 -> []
    //
    //
    // Notice that Row 0 and Row 1 have 4 columns,
    // but Row 2 and Row 3 are still empty.
    //
    // Therefore this is a JAGGED VECTOR.
    //
    // Different rows can have different sizes.

    // ============================================================
    // CHECK NUMBER OF ROWS
    // ============================================================

    // arrjagged.size() gives the number of elements
    // in the OUTER vector.
    //
    // Since we created:
    //
    // vector<vector<int>> arrjagged(4);
    //
    // there are 4 rows.

    cout << "Total rows = "
         << arrjagged.size() << endl;

    // ============================================================
    // CHECK SIZE OF EACH ROW
    // ============================================================

    // Each row is itself a vector.
    //
    // So:
    //
    // arrjagged[0].size()
    //
    // gives number of elements in Row 0.
    //
    // arrjagged[1].size()
    //
    // gives number of elements in Row 1.
    //
    // arrjagged[2].size()
    //
    // gives number of elements in Row 2.
    //
    // arrjagged[3].size()
    //
    // gives number of elements in Row 3.

    cout << "Row 0 size = "
         << arrjagged[0].size() << endl;

    cout << "Row 1 size = "
         << arrjagged[1].size() << endl;

    cout << "Row 2 size = "
         << arrjagged[2].size() << endl;

    cout << "Row 3 size = "
         << arrjagged[3].size() << endl;

    // ============================================================
    // CURRENT STRUCTURE
    // ============================================================
    //
    // At this point:
    //
    // arrjagged =
    //
    // [0, 0, 0, 0]   <- Row 0
    // [0, 0, 0, 0]   <- Row 1
    // []             <- Row 2
    // []             <- Row 3
    //
    //
    // Row sizes:
    //
    // Row 0 -> 4
    // Row 1 -> 4
    // Row 2 -> 0
    // Row 3 -> 0
    //
    // This is perfectly valid in C++ because each row is
    // an independent vector.

    // ============================================================
    // ADDING DIFFERENT NUMBER OF COLUMNS
    // ============================================================
    //
    // We can now give different sizes to Row 2 and Row 3.
    //
    // This is what makes the structure "jagged."

    // Row 2 gets 2 elements.
    arrjagged[2] = vector<int>(2, 50);

    // Row 2 becomes:
    //
    // [50, 50]

    // Row 3 gets 5 elements.
    arrjagged[3] = vector<int>(5, 100);

    // Row 3 becomes:
    //
    // [100, 100, 100, 100, 100]

    // ============================================================
    // FINAL JAGGED VECTOR
    // ============================================================
    //
    // Now the complete structure is:
    //
    // Row 0 -> [0, 0, 0, 0]
    // Row 1 -> [0, 0, 0, 0]
    // Row 2 -> [50, 50]
    // Row 3 -> [100, 100, 100, 100, 100]
    //
    // Notice:
    //
    // Row 0 -> 4 columns
    // Row 1 -> 4 columns
    // Row 2 -> 2 columns
    // Row 3 -> 5 columns
    //
    // So every row can have a different size.

    // ============================================================
    // MODIFYING AN ELEMENT
    // ============================================================

    // Accessing Row 2, Column 1:
    //
    // arrjagged[2][1]
    //
    // Row 2:
    //
    // [50, 50]
    //       ^
    //       index 1
    //
    // Let's change it to 500.

    arrjagged[2][1] = 500;

    // Now Row 2:
    //
    // [50, 500]

    // ============================================================
    // PRINTING THE JAGGED VECTOR
    // ============================================================

    // We CANNOT assume that every row has the same number
    // of columns.
    //
    // Therefore, this is NOT safe for a jagged vector:
    //
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arrjagged[i][j];
    //     }
    // }
    //
    // Why?
    //
    // Because Row 2 has only 2 elements
    // and Row 3 has 5 elements.
    //
    // So we need to find the size of EACH row separately.

    // ============================================================
    // SAFE WAY TO PRINT JAGGED VECTOR
    // ============================================================

    cout << "\nJagged Vector:\n";

    // Outer loop:
    //
    // i represents the row number.
    for (int i = 0; i < arrjagged.size(); i++)
    {
        // Inner loop:
        //
        // arrjagged[i].size()
        //
        // gives the number of columns in the CURRENT row.
        //
        // This is the important part for jagged vectors.

        for (int j = 0; j < arrjagged[i].size(); j++)
        {
            cout << arrjagged[i][j] << " ";
        }

        // After printing one complete row,
        // go to the next line.
        cout << endl;
    }

    // ============================================================
    // RANGE-BASED LOOP FOR JAGGED VECTOR
    // ============================================================
    //
    // We can also print it more easily using range-based loops.
    //
    // Outer loop:
    //
    // row represents one complete inner vector.
    //
    // Inner loop:
    //
    // x represents one integer from that row.

    cout << "\nUsing range-based loop:\n";

    for (const auto &row : arrjagged)
    {
        for (const auto &x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    // ============================================================
    // IMPORTANT CONCEPT
    // ============================================================
    //
    // vector<vector<int>> does NOT automatically mean
    // a jagged vector.
    //
    // Example 1:
    //
    // vector<vector<int>> arr(3, vector<int>(4, 0));
    //
    // gives:
    //
    // [0 0 0 0]
    // [0 0 0 0]
    // [0 0 0 0]
    //
    // Every row has 4 columns.
    //
    // This is rectangular.
    //
    //
    // Example 2:
    //
    // vector<vector<int>> arr(3);
    //
    // Then:
    //
    // arr[0] = vector<int>(2);
    // arr[1] = vector<int>(5);
    // arr[2] = vector<int>(3);
    //
    // gives:
    //
    // [0 0]
    // [0 0 0 0 0]
    // [0 0 0]
    //
    // This is jagged.

    // ============================================================
    // VERY IMPORTANT DIFFERENCE
    // ============================================================
    //
    // In a normal 2D array:
    //
    // int arr[4][4];
    //
    // the number of columns is fixed.
    //
    //
    // In vector<vector<int>>:
    //
    // Every row is an independent vector.
    //
    // So we can do:
    //
    // arr[0].size() = 4
    // arr[1].size() = 4
    // arr[2].size() = 2
    // arr[3].size() = 5
    //
    // This flexibility is one of the advantages of
    // vector<vector<int>>.

    return 0;
}