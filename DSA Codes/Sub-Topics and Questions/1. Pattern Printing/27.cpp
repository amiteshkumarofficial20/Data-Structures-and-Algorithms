#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Upper half
    for (int row = 1; row <= n; row++)
    {
        // spaces
        for (int space = 1; space <= n - row; space++)
            cout << " ";

        // stars
        for (int star = 1; star <= row; star++)
            cout << "* ";

        cout << endl;
    }

    // Lower half
    for (int row = n - 1; row >= 1; row--)
    {
        // spaces
        for (int space = 1; space <= n - row; space++)
            cout << " ";

        // stars
        for (int star = 1; star <= row; star++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}