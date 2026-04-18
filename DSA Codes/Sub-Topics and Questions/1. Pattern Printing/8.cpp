// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//     char character;
//     cout << "Enter Character: ";
//     cin >> character;
//     for (int row = 1; row <= n; row++)
//     {
//         for (char column = 'a'; column <= character; column++)
//         {
//             cout << column << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, row, column;
    cout << "Enter n: ";
    cin >> n;
    for (row = 1; row <= n; row++)
    {

        for (column = 1; column <= n; column++)
        {
            char ch = 'a' + (column - 1); // ascii value addition
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}