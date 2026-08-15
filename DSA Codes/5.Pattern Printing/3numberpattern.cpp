/*
    NUMBER PATTERN

    This program prints numbers from 1 to n in every row.

    Example:

    If n = 4 and rows = 4:

    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4

    LOGIC:

    The outer loop controls the rows.

    The inner loop prints numbers from 1 to n.

    The inner loop starts again from 1 for every new row.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int column = 1; column <= n; column++)
        {
            cout << column << " ";
        }

        cout << endl;
    }

    return 0;
}