#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Upper part
    for (int row = n; row >= 1; row--)
    {
        // left stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        // spaces
        for (int space = 1; space <= 2 * (n - row); space++)
        {
            cout << "  ";
        }

        // right stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower part
    for (int row = 1; row <= n; row++)
    {
        // left stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        // spaces
        for (int space = 1; space <= 2 * (n - row); space++)
        {
            cout << "  ";
        }

        // right stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}