#include <iostream>
using namespace std;

int main()
{
    int firstterm = 1, n, nextterms, commondiff = 2;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        nextterms = firstterm + (i - 1) * commondiff;
        cout << nextterms << endl;
    }
    //     for (int i = 1; i <= 2 * n - 1; i += 2)
    // {
    //     cout << i << endl;
    // }

    return 0;
}