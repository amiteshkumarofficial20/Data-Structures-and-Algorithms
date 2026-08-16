#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Function Name : changeValue
// Purpose       : Pass by Value ko demonstrate karna
//
// Important:
// Jab hum variable ko normal parameter ke through function
// mein pass karte hain, to uski ek COPY function ko milti hai.
//
// Isliye function ke andar parameter ko change karne se
// original variable ki value change nahi hoti.
// ------------------------------------------------------------

void changeValue(int x)
{
    // Yahan x original variable nahi hai.
    // x, original variable ki ek copy hai.

    cout << "Function ke andar change se pehle x = "
         << x << endl;

    // x ki value change kar rahe hain.
    // Sirf local copy change hogi.
    x = 100;

    cout << "Function ke andar change ke baad x = "
         << x << endl;
}

// ------------------------------------------------------------
// main() function
// Program execution yahin se start hota hai.
// ------------------------------------------------------------

int main()
{
    // Original variable create kiya.
    int a = 10;

    cout << "Function call se pehle a = "
         << a << endl;

    // a ko function mein pass kar rahe hain.
    //
    // Yahan a ki VALUE ki copy function ke parameter x mein
    // chali jayegi.
    //
    // Isliye:
    //
    // a = 10
    // x = 10   <-- x, a ki copy hai
    //
    changeValue(a);

    // Function ke andar x ko 100 kiya gaya tha,
    // lekin original a change nahi hua.
    //
    // Isliye yahan a ki value ab bhi 10 hai.
    cout << "Function call ke baad a = "
         << a << endl;

    return 0;
}