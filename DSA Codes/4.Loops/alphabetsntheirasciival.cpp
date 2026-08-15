#include <iostream>
using namespace std;

int main()
{
    // Uppercase: A to Z
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << " = " << i << endl;
    }

    // Lowercase: a to z
    for (int i = 97; i <= 122; i++)
    {
        cout << char(i) << " = " << i << endl;
    }

    return 0;
}