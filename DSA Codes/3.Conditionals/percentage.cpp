#include <iostream>
using namespace std;

int main()
{
    int percentage;

    cout << "Enter Percentage of a Student: ";
    cin >> percentage;

    if (percentage >= 91 && percentage <= 100)
    {
        cout << "Excellent";
    }
    else if (percentage >= 81 && percentage <= 90)
    {
        cout << "Very Good";
    }
    else if (percentage >= 71 && percentage <= 80)
    {
        cout << "Good";
    }
    else if (percentage >= 61 && percentage <= 70)
    {
        cout << "Average";
    }
    else if (percentage >= 41 && percentage <= 60)
    {
        cout << "Pass";
    }
    else if (percentage < 40)
    {
        cout << "Fail";
    }
    else
    {
        cout << "Invalid Percentage";
    }

    return 0;
}