#include <iostream>
using namespace std;

int main()
{
    int n, r;
    int firstterm = 1;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter common ratio: ";
    cin >> r;

    // Find the nth term
    int term = firstterm;

    for (int i = 1; i <= n - 1; i++)
    {
        // cout << term << endl;
        term = term * r;
    }

    // Print GP in reverse
    for (int i = n; i >= 1; i--)
    {
        cout << term << endl;
        term = term / r;
    }

    return 0;
}