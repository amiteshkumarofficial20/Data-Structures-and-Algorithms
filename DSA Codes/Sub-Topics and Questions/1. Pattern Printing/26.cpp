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
        for (int star = 1; star <= row; star++)
            cout << "* ";

        for (int space = 1; space <= 2 * (n - row); space++)
            cout << "  ";

        for (int star = 1; star <= row; star++)
            cout << "* ";

        cout << endl;
    }

    // Lower half
    for (int row = n - 1; row >= 1; row--)
    {
        for (int star = 1; star <= row; star++)
            cout << "* ";

        for (int space = 1; space <= 2 * (n - row); space++)
            cout << "  ";

        for (int star = 1; star <= row; star++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}