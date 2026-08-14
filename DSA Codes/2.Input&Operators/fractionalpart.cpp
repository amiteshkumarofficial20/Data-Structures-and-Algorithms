#include <iostream>
using namespace std;

int main()
{
    float number;

    cout << "Enter a float number: ";
    cin >> number;

    int integerPart = (int)number;
    float fractionalPart = number - integerPart;

    cout << "Fractional Part = " << fractionalPart << endl;

    return 0;
}