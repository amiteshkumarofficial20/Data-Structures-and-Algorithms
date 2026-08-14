#include <iostream>
using namespace std;

int main()
{
    int ascii;

    cout << "Enter ASCII value: ";
    cin >> ascii;

    char ch = (char)ascii;

    if ((ascii >= 65 && ascii <= 90) ||
        (ascii >= 97 && ascii <= 122))
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U')
        {
            cout << "Given Character is a Vowel";
        }
        else
        {
            cout << "Given Character is a Consonant";
        }
    }
    else
    {
        cout << "Given ASCII value is not an Alphabet";
    }

    return 0;
}