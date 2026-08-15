#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num > 0)
    {
        sum = sum + (num % 10);

        num = num / 10;
    }

    cout << "Sum of digits = " << sum;

    return 0;
}