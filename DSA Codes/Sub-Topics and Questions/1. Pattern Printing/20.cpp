#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        // print spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // print characters
        for (char character = 'A'; character <= 'A' + (row - 1); character++)
        {
            cout << character;
        }

        cout << endl;
    }
    return 0;
}