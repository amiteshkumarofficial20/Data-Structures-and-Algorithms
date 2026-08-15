#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Even Numbers:" << endl;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            continue;
        }

        cout << i << " ";
    }

    cout << endl;

    cout << "Odd Numbers:" << endl;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        cout << i << " ";
    }

    return 0;
}