// Bitwise Operators in C++
//
// Bitwise operators work directly on the individual bits
// of integer values.
//
// Bitwise Operators:
//
// &    Bitwise AND
// |    Bitwise OR
// ^    Bitwise XOR
// ~    Bitwise NOT
// <<   Left Shift
// >>   Right Shift

#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 3;

    // Binary representation:
    //
    // a = 5  -> 0101
    // b = 3  -> 0011

    // Bitwise AND (&)
    // 0101
    // 0011
    // ----
    // 0001 = 1
    cout << "a & b = " << (a & b) << endl;

    // Bitwise OR (|)
    // 0101
    // 0011
    // ----
    // 0111 = 7
    cout << "a | b = " << (a | b) << endl;

    // Bitwise XOR (^)
    // 0101
    // 0011
    // ----
    // 0110 = 6
    cout << "a ^ b = " << (a ^ b) << endl;

    // Bitwise NOT (~)
    // Flips every bit of the value.
    cout << "~a = " << (~a) << endl;

    // Left Shift (<<)
    // Shifts the bits of a to the left by 1 position.
    // For positive integers, this commonly corresponds
    // to multiplying by 2 when no significant bits are lost.
    cout << "a << 1 = " << (a << 1) << endl;

    // Right Shift (>>)
    // Shifts the bits of a to the right by 1 position.
    cout << "a >> 1 = " << (a >> 1) << endl;

    return 0;
}