// ASCII Conversion in C++
//
// ASCII stands for American Standard Code for Information Interchange.
//
// ASCII assigns a numeric value to characters.
//
// Examples:
//
// 'A' = 65
// 'B' = 66
// 'C' = 67
//
// 'a' = 97
// 'b' = 98
// 'c' = 99
//
// '0' = 48
// '1' = 49
// '2' = 50
//
// In C++, a char can be converted to its ASCII value
// by converting it to an integer type.
//
// Example:
//
// char ch = 'A';
// int ascii = ch;
//
// The value of ascii will be 65.

#include <iostream>
using namespace std;

int main()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    // Character to ASCII conversion
    int asciiValue = ch;

    cout << "Character = " << ch << endl;
    cout << "ASCII Value = " << asciiValue << endl;

    // ASCII value to character conversion
    int number;

    cout << "Enter an ASCII value: ";
    cin >> number;

    char character = number;

    cout << "ASCII Value = " << number << endl;
    cout << "Character = " << character << endl;

    return 0;
}