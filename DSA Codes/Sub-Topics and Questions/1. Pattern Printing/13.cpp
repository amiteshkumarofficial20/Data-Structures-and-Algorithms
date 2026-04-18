#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        char ch = 'a' + (row - 1); // ascii value addition
        for (int column = 1; column <= row; column++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}