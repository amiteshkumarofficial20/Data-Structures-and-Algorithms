/*
    CHECK WHETHER A CHARACTER IS AN ALPHABET

    There are two common approaches:

    1. Using ASCII conversion
    2. Directly comparing the character with 'A', 'Z', 'a', and 'z'


    APPROACH 1: USING ASCII CONVERSION

    First, the character is converted into an integer:

    int ascii = (int)ch;

    ASCII values of alphabets are:

    A to Z = 65 to 90
    a to z = 97 to 122

    Therefore, we can check:

    ascii >= 65 && ascii <= 90

    OR:

    ascii >= 97 && ascii <= 122


    APPROACH 2: WITHOUT EXPLICIT ASCII CONVERSION

    We can directly compare the character:

    ch >= 'A' && ch <= 'Z'

    OR:

    ch >= 'a' && ch <= 'z'

    C++ internally uses the character's numeric value for
    these comparisons, so explicit (int) conversion is not
    necessary.
*/

#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    // =====================================================
    // APPROACH 1: USING ASCII CONVERSION
    // =====================================================

    int ascii = (int)ch;

    if ((ascii >= 65 && ascii <= 90) ||
        (ascii >= 97 && ascii <= 122))
    {
        cout << "Using ASCII Conversion: ";
        cout << "Given Character is an Alphabet" << endl;
    }
    else
    {
        cout << "Using ASCII Conversion: ";
        cout << "Given Character is not an Alphabet" << endl;
    }

    // =====================================================
    // APPROACH 2: WITHOUT EXPLICIT ASCII CONVERSION
    // =====================================================

    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z'))
    {
        cout << "Without ASCII Conversion: ";
        cout << "Given Character is an Alphabet" << endl;
    }
    else
    {
        cout << "Without ASCII Conversion: ";
        cout << "Given Character is not an Alphabet" << endl;
    }

    return 0;
}