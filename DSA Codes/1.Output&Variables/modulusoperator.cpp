#include <iostream>
using namespace std;

int main()
{
    // input 2 int a and b : a>b
    // find remainder when a / b
    // a % b if a >= b -- gives a % b
    // a % b if a < b -- gives a
    // a % (-b) == a % b == +ve ans
    // (-a) % b == -(a % b) = -ve ans
    // (-a) % (-b) == (-a) % b = -ve ans
    int a = 19;
    int b = 2;
    cout << a % b << endl;
    cout << 2 % 2 << endl;
    cout << 18 % 2 << endl;
    cout << 1 % 20 << endl;
    return 0; // optional
}