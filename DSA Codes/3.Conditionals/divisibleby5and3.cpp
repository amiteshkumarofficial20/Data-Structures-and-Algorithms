#include <iostream>
using namespace std;

int main()
{

    int number;
    cout << "Enter a Number : ";
    cin >> number;
    if (((number % 5) == 0) && ((number % 3) == 0))
    // number % 15 == 0
    {
        cout << "Number is Divisible By 5 and 3";
    }
    else
    {
        cout << "Number is Either Not Divisible By 5 or Not Divisible By 3";
    }
    return 0;
}