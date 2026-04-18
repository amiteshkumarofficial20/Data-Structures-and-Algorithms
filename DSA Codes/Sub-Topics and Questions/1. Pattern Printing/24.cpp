#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int row = n; row >= 1; row--)
    {
        // print spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }
        // print stars
        for (int star = 1; star <= 2 * row - 1; star++)
        {
            cout << "*";
        }
        // print spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        cout << endl;
    }

    return 0;
}