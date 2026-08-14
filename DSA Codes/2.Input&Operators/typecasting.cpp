// Type Casting in C++
//
// Type casting means converting a value from one data type
// into another data type.
//
// Common data types used in type casting:
//
// int      -> Integer
// char     -> Character
// float    -> Decimal number
// bool     -> true or false
//
// Type casting can be performed using:
//
// (int)value
// (char)value
// (float)value
// (bool)value
//
// This is called C-style type casting.

#include <iostream>
using namespace std;

int main()
{
    // ==========================================
    // 1. INT TO FLOAT
    // ==========================================

    int a = 10;

    float b = (float)a;

    cout << "Integer value = " << a << endl;
    cout << "Float value = " << b << endl;

    // ==========================================
    // 2. FLOAT TO INT
    // ==========================================

    float x = 10.75;

    int y = (int)x;

    cout << "\nFloat value = " << x << endl;
    cout << "Integer value = " << y << endl;

    // Output:
    // 10.75
    // 10
    //
    // The decimal part is removed.
    // It is NOT rounded.

    // ==========================================
    // 3. CHAR TO INT
    // ==========================================

    char ch = 'A';

    int ascii = (int)ch;

    cout << "\nCharacter = " << ch << endl;
    cout << "ASCII value = " << ascii << endl;

    // Output:
    // Character = A
    // ASCII value = 65

    // ==========================================
    // 4. INT TO CHAR
    // ==========================================

    int number = 65;

    char character = (char)number;

    cout << "\nInteger value = " << number << endl;
    cout << "Character = " << character << endl;

    // Output:
    // Integer value = 65
    // Character = A

    // ==========================================
    // 5. CHAR TO FLOAT
    // ==========================================

    char letter = 'B';

    float value = (float)letter;

    cout << "\nCharacter = " << letter << endl;
    cout << "Float value = " << value << endl;

    // 'B' has ASCII value 66.
    // Therefore:
    // float value = 66

    // ==========================================
    // 6. FLOAT TO CHAR
    // ==========================================

    float asciiNumber = 65.0;

    char result = (char)asciiNumber;

    cout << "\nFloat value = " << asciiNumber << endl;
    cout << "Character = " << result << endl;

    // 65 corresponds to 'A'.

    // ==========================================
    // 7. INT TO BOOL
    // ==========================================

    int n1 = 10;
    int n2 = 0;

    bool boolValue1 = (bool)n1;
    bool boolValue2 = (bool)n2;

    cout << "\n10 converted to bool = " << boolValue1 << endl;
    cout << "0 converted to bool = " << boolValue2 << endl;

    // Any non-zero value becomes true.
    // Zero becomes false.

    // ==========================================
    // 8. BOOL TO INT
    // ==========================================

    bool isTrue = true;
    bool isFalse = false;

    int trueValue = (int)isTrue;
    int falseValue = (int)isFalse;

    cout << "\ntrue converted to int = " << trueValue << endl;
    cout << "false converted to int = " << falseValue << endl;

    // true  -> 1
    // false -> 0

    // ==========================================
    // 9. FLOAT TO BOOL
    // ==========================================

    float f1 = 5.5;
    float f2 = 0.0;

    bool result1 = (bool)f1;
    bool result2 = (bool)f2;

    cout << "\n5.5 converted to bool = " << result1 << endl;
    cout << "0.0 converted to bool = " << result2 << endl;

    // Any non-zero floating-point value -> true
    // Zero -> false

    // ==========================================
    // 10. BOOL TO FLOAT
    // ==========================================

    bool valueTrue = true;
    bool valueFalse = false;

    float floatTrue = (float)valueTrue;
    float floatFalse = (float)valueFalse;

    cout << "\ntrue converted to float = " << floatTrue << endl;
    cout << "false converted to float = " << floatFalse << endl;

    // true  -> 1.0
    // false -> 0.0

    // ==========================================
    // 11. CHARACTER, INTEGER, FLOAT AND BOOL
    // ==========================================

    char c = 'A';

    int i = (int)c;
    float fl = (float)i;
    bool bl = (bool)fl;

    cout << "\nOriginal character = " << c << endl;
    cout << "Character to int = " << i << endl;
    cout << "Int to float = " << fl << endl;
    cout << "Float to bool = " << bl << endl;

    return 0;
}