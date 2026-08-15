#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int sumeven = 0;
    int sumodd = 0;

    cout << "Enter n: ";
    cin >> n;

    // Sum of Even Numbers
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sumeven += i;
        }
    }

    cout << "Sum of Even Numbers = " << sumeven << endl;

    // Sum of Odd Numbers
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            sumodd += i;
        }
    }

    cout << "Sum of Odd Numbers = " << sumodd << endl;

    // Sum of Series:
    // 1 - 2 + 3 - 4 + 5 - 6 + 7 - 8 ..... upto n

    sum = sumodd - sumeven;

    cout << "Sum of Series = " << sum;

    return 0;
}
/*
int main()
{
    int n;
    int sum = 0;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum - i;
        }
        else
        {
            sum = sum + i;
        }
    }

    cout << "Sum of Series = " << sum;

    return 0;
}
*/