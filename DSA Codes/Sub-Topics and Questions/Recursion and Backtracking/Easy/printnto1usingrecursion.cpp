#include <iostream>
using namespace std;

/*
    Function: printNumbersReverse
    Purpose: Print numbers from N down to 1 using recursion.

    Parameters:
        - current : current number to print
        - N       : maximum number (starting point)

    Recursion Idea:
        1. Base Case → stop when current == 0.
        2. At each call, print the current number.
        3. Move closer to base case by calling function with current-1.
*/
void printNumbersReverse(int current)
{
    // ✅ Base Case: stop when current becomes 0
    if (current == 0)
    {
        return;
    }

    // Step 1: Print current number
    cout << current << " ";

    // Step 2: Recursive call → move to next smaller number
    printNumbersReverse(current - 1);

    /*
        🔎 Complexity Analysis:
        -----------------------
        ➤ Time Complexity (TC):
            - Each call prints once (O(1)).
            - Total calls = N.
            - Total = O(N).

        ➤ Space Complexity (SC):
            - Each call waits on the stack until it finishes.
            - At most N calls deep.
            - Total = O(N).
    */
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Numbers from " << N << " down to 1: ";
    printNumbersReverse(N);

    return 0;
}
