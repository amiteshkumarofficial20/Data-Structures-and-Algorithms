// Character (char) Data Type in C++
//
// The 'char' data type is used to store a single character.
//
// Examples:
// 'A'
// 'B'
// 'a'
// '5'
// '@'
//
// A char normally occupies 1 byte of memory.
//
// Character values are written inside single quotes (' ').
//
// Examples:
//
// char grade = 'A';
// char symbol = '@';
// char digit = '5';

#include <iostream>
using namespace std;

int main()
{
    // Declaring and initializing a char variable
    char grade = 'A';

    cout << "Grade = " << grade << endl;

    // Taking character input from the user
    char character;

    cout << "Enter a character: ";
    cin >> character;

    cout << "You entered: " << character << endl;

    // Another example
    char symbol = '@';

    cout << "Symbol = " << symbol << endl;

    // Null Character (\0) in C++
    //
    // '\0' is called the Null Character or Null Terminator.
    //
    // It represents the character with value 0.
    //
    // The null character is mainly used to mark the END of a
    // C-style string (character array).
    //
    // IMPORTANT:
    //
    // '\0' is NOT the same as '0'.
    //
    // '\0'  -> Null character, value 0
    // '0'   -> Character zero
    // 0     -> Integer zero
    //
    // Example:
    //
    // char a = '\0';
    // char b = '0';
    // int c = 0;

    char ch = '\0';

    cout << "Value of null character: " << (int)ch << endl;

    // '\0' is commonly used at the end of a character array.

    char name[] = {'A', 'm', 'i', 't', 'e', 's', 'h', '\0'};

    cout << "Name: " << name << endl;

    // The '\0' tells C++ where the character string ends.

    return 0;
}