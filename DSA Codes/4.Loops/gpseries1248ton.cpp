#include <iostream>
using namespace std;

int main()
{
    int n, r;
    int term = 1;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter common ratio: ";
    cin >> r;

    for (int i = 1; i <= n; i++)
    {
        cout << term << endl;
        term = term * r;
    }

    return 0;
}
// Nth Term:
// Tₙ = a × r^(n-1)

// Sum of n Terms:
// Sₙ = a(rⁿ - 1)/(r - 1)

// Next Term:
// Next Term = Current Term × r