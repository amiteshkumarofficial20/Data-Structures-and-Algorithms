#include <iostream>
using namespace std;

int main()
{

    int number;
    cout << "Enter a Number : ";
    cin >> number;
    if (((number % 5) == 0) || ((number % 3) == 0))
    {
        if ((number % 15) != 0)
        {
            cout << "Number is Divisible By 5 or 3 But Not by 15";
        }
        else
        {
            cout << "Number is Divisible By 5 or 3 and by 15";
        }
    }
    else
    {
        cout << "Number is Either Not Divisible By 5 or Not Divisible By 3";
    }
    return 0;
}