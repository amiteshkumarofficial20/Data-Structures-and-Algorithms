#include <iostream>
using namespace std;

int main()
{

    int number;
    cout << "Enter a Number ";
    cin >> number;
    if ((number % 5) == 0)
    {
        cout << "Number is Divisible By 5";
    }
    else
    {
        cout << "Number is Not Divisible By 5";
    }
    return 0;
}