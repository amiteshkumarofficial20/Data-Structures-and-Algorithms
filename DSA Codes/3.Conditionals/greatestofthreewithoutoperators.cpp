#include <iostream>
using namespace std;

int main()
{
    int x, y, z;

    cout << "Enter a Number: ";
    cin >> x;

    cout << "Enter a Number: ";
    cin >> y;

    cout << "Enter a Number: ";
    cin >> z;

    if (x > y)
    {
        if (x > z)
        {
            cout << "x is Greatest";
        }
        else
        {
            cout << "z is Greatest";
        }
    }
    else
    {
        if (y > z)
        {
            cout << "y is Greatest";
        }
        else
        {
            cout << "z is Greatest";
        }
    }

    return 0;
}