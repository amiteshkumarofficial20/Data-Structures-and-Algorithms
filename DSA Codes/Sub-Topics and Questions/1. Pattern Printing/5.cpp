// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int count = 1;
//     for (int i = 1; i <= 5; i++)
//     {
//         for (int j = 1; j <= 5; j++)
//         {
//             cout << count << " ";
//             count++;
//         }
//         cout << endl;
//     }
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
        for (int column = 1; column <= n; column++)
        {
            cout << (row - 1) * 5 + column << " ";
        }
        cout << endl;
    }
}