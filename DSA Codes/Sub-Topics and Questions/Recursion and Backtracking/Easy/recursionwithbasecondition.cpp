#include <iostream>
using namespace std;

// Recursive function to print numbers
void num()
{
    int count = 0; // ❌ PROBLEM: "count" is re-initialized to 0 every time num() is called

    // Base case: if count becomes 4, stop recursion
    if (count == 4)
    {
        return;
    }

    cout << count << endl; // Print current value of count

    count++; // Increase count (but this increase is lost after function returns)

    // Recursive call
    num();
}

int main()
{
    num(); // Call the function
    return 0;
}
