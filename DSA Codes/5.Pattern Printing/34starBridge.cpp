/*
    STAR BRIDGE PATTERN

    This program prints a star bridge pattern.

    Example for n = 4:

    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *
    *             *
    * *         * *
    * * *     * * *
    * * * * * * * *


    LOGIC:

    The pattern has two parts:

    1. UPPER PART
    2. LOWER PART


    UPPER PART:

    The number of stars decreases from n to 1.

    Left stars:
        row

    Middle spaces:
        2 * (n - row)

    Right stars:
        row


    LOWER PART:

    The number of stars increases from 1 to n - 1.

    We use n - 1 in the upper part's starting/ending
    relationship so that the middle row is not repeated.

    IMPORTANT:

    Left stars  = row
    Middle spaces = 2 * (n - row)
    Right stars = row
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // =========================
    // UPPER PART
    // =========================

    for (int row = n; row >= 1; row--)
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
    // LOWER PART
    // =========================

    for (int row = 2; row <= n; row++)
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