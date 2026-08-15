#include <iostream>
using namespace std;

int main()
{
    int firstterm = 1, n, nextterm, commondiff = 2;

    cout << "Enter n: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        nextterm = firstterm + (i - 1) * commondiff;
        cout << nextterm << endl;
    }

    return 0;
}