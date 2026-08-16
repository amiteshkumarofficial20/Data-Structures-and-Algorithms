#include <iostream>
using namespace std;

// ------------------------------------------------------------
// Function Name : changeValue
// Purpose       : Pass by Reference ko demonstrate karna
//
// Important:
// Pass by Reference mein function ke parameter ke saath '&'
// lagaya jata hai.
//
// Is case mein function ko original variable ka reference milta hai.
// Isliye function ke andar parameter ko change karne par
// original variable bhi change ho jata hai.
// ------------------------------------------------------------

void changeValue(int &x)
{
    // x, original variable ka reference hai.
    //
    // Yahan x ki value change karne ka matlab original variable
    // ki value change karna hai.

    cout << "Function ke andar change se pehle x = "
         << x << endl;

    // x ki value change kar rahe hain.
    //
    // Kyunki x original variable ko refer kar raha hai,
    // original variable ki value bhi 100 ho jayegi.
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
    // changeValue(int& x) mein x, a ka reference ban jayega.
    //
    // Matlab:
    //
    // a = 10
    // x ----> a
    //
    // x aur a same original variable ko refer kar rahe hain.
    //
    changeValue(a);

    // Function ke andar x = 100 kiya gaya tha.
    //
    // Kyunki x, a ka reference tha,
    // original a bhi change ho gaya.
    cout << "Function call ke baad a = "
         << a << endl;

    return 0;
}