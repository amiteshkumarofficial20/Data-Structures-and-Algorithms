// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//     for (int row = n; row >= 1; row--)
//     {
//         for (int column = 1; column <= row; column++)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int column = 1; column <= n - (row - 1); column++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    return 0;
}