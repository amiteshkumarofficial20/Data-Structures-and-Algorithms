/*
    DOUBLE STAR BRIDGE / BUTTERFLY PATTERN

    This program prints two groups of stars with spaces
    between them.

    Example for n = 5:

    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * *
    * * * *     * * * *
    * * *         * * *
    * *             * *
    *                 *


    LOGIC:

    The pattern has two parts:

    1. UPPER HALF
    2. LOWER HALF


    UPPER HALF:

    row goes from 1 to n.

    Left stars:
        row

    Middle spaces:
        2 * (n - row)

    Right stars:
        row


    LOWER HALF:

    row goes from n - 1 down to 1.

    The middle row is not repeated because
    the lower loop starts from n - 1.


    MIDDLE SPACE FORMULA:

        2 * (n - row)

    For n = 5:

    row = 1 → 2 * (5 - 1) = 8
    row = 2 → 2 * (5 - 2) = 6
    row = 3 → 2 * (5 - 3) = 4
    row = 4 → 2 * (5 - 4) = 2
    row = 5 → 2 * (5 - 5) = 0

    Therefore, the gap decreases as the number
    of stars increases.

    In the lower half, the opposite happens:
    the gap increases while the number of stars decreases.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the pattern from the user
    cout << "Enter n: ";
    cin >> n;

    // =========================
    // UPPER HALF
    // =========================

    for (int row = 1; row <= n; row++)
    {
        // Print left stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        // Print middle spaces
        for (int space = 1; space <= 2 * (n - row); space++)
        {
            cout << "  ";
        }

        // Print right stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // =========================
    // LOWER HALF
    // =========================

    for (int row = n - 1; row >= 1; row--)
    {
        // Print left stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        // Print middle spaces
        for (int space = 1; space <= 2 * (n - row); space++)
        {
            cout << "  ";
        }

        // Print right stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}