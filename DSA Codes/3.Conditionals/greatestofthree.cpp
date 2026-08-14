#include <iostream>
using namespace std;

int main()
{

    int x;
    cout << "Enter a Number : ";
    cin >> x;
    int y;
    cout << "Enter a Number : ";
    cin >> y;
    int z;
    cout << "Enter a Number : ";
    cin >> z;
    if ((x < y) && (y < z))
    {
        cout << "z is Greatest";
    }
    else if ((y < z) && (z < x))
    {
        cout << "x is Greatest";
    }
    else
    {
        cout << "y is Greatest";
    }
    return 0;
}