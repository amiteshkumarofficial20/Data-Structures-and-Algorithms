#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    number = abs(number);

    if (number >= 100 && number <= 999)
    {
        cout << "Given Integer is a 3-Digit Number";
    }
    else
    {
        cout << "Given Integer is not a 3-Digit Number";
    }

    return 0;
}
// using loops
//  int count = 0;

// while(number > 0)
// {
//     number = number / 10;
//     count++;
// }