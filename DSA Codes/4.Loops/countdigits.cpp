#include <iostream>
using namespace std;

int main()
{
    int num;
    int count = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num > 0)
    {
        count++;

        num = num / 10;
    }

    cout << "Number of digits = " << count;

    return 0;
}