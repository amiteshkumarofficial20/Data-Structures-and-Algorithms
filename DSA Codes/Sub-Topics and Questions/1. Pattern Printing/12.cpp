#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int column = row; column >= 1; column--)
        {
            cout << column << " ";
        }
        cout << endl;
    }
    return 0;
}