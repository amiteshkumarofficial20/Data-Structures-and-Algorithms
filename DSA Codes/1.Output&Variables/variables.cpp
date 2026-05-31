#include <iostream>
using namespace std;

int main()
{
    // variables as containers
    // int / int = int
    // int / float = float
    // float / int = float
    // float / float = float
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
    // true = 1 = on
    // false = 0 = off
    bool e = true;
    cout << e << endl;
    bool f = false;
    cout << f << endl;
    bool flag = 29;
    cout << flag << endl;
    bool efgh = -56;
    cout << efgh << endl;
    bool de = 1;
    cout << de << endl;
    bool deab = 0;
    cout << deab << endl;
    cout << (5 > 3) << endl;
    cout << (5 <= 3) << endl;
    cout << (5 == 3) << endl;
    cout << (5 != 3) << endl;
    cout << (3 == 3) << endl;
    cout << (3 != 3) << endl;
    cout << (2 > 3) << endl;
    cout << (2 <= 3) << endl;
    return 0; // optional
}