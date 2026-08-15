#include <iostream>
using namespace std;

int main()
{
    int n = 10;

    while (n /= 2) // false at 0
    {
        cout << n << endl;
    }

    return 0;
}