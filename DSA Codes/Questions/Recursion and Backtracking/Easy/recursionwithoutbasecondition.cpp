#include <iostream>
using namespace std;

// A simple recursive function
void greet()
{
    cout << "Hey" << endl; // Step 1: Print "Hey"

    greet(); // Step 2: Call greet() again (recursive call)
    // ⚠️ There is NO base case here -> recursion never stops!
}

int main()
{
    greet(); // Start the recursion
}
