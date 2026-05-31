#include <iostream>
using namespace std;

int main()
{
    // input 2 int a and b : a>b
    // find remainder when a / b
    int a;
    int b;
    cout << " Enter a and b : ";
    cin >> a >> b;
    int q = a / b;
    cout << q << endl;
    int r = a - (b * q);
    cout << r << endl;
    // or
    cout << a % b << endl;
    return 0; // optional
}