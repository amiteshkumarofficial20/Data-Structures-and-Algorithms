#include <iostream>
using namespace std;

int main()
{
    // variables as containers
    int x;
    x = 7;
    cout << x << endl;
    x = 17;
    cout << x << endl;
    x = 27;
    x = 11;
    cout << x << endl;
    x = x + 6;
    cout << x << endl;
    x -= 20;
    cout << x << endl;
    int y = 19;
    cout << y << endl;
    float a = 3.1;
    float b = 8.6;
    cout << a << endl;
    cout << b << endl;
    cout << a / b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    // invalid for float -> cout << a % b << endl;
    cout << 18.9 / 2 << endl;
    return 0; // optional
}