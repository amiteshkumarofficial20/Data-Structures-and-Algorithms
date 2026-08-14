#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three sides of triangle: ";
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && c + a > b)
    {
        cout << "Valid Triangle";
    }
    else
    {
        cout << "Invalid Triangle";
    }

    return 0;
}