// Logical Operators in C++
//
// Logical operators are used to combine two or more conditions.
// The result of a logical operation is either true or false.
//
// Logical Operators:
//
// &&   Logical AND
// ||   Logical OR
// !    Logical NOT

#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    cout << boolalpha;

    // Logical AND (&&)
    // Returns true only when both conditions are true.
    cout << "age >= 18 && age <= 60 : "
         << (age >= 18 && age <= 60) << endl;

    // Logical OR (||)
    // Returns true when at least one condition is true.
    cout << "age < 18 || age > 60 : "
         << (age < 18 || age > 60) << endl;

    // Logical NOT (!)
    // Reverses the result of a condition.
    cout << "!(age >= 18) : "
         << !(age >= 18) << endl;

    return 0;
}