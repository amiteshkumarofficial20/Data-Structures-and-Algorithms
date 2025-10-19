#include <iostream>
using namespace std;

/*
    Function: printNumbers
    Purpose: Print numbers from 1 to N using recursion.

    Parameters:
        - current : current number to print
        - N       : maximum number up to which we want to print

    Recursion Idea:
        1. Base Case → stop when current > N.
        2. At each call, print the current number.
        3. Move closer to base case by calling function with current+1.
*/
void printNumbers(int current, int N)
{
    // ✅ Base Case: stop recursion when current > N
    if (current > N)
    {
        return;
    }

    // Step 1: Print the current number
    cout << current << " ";

    // Step 2: Recursive call → move to the next number
    printNumbers(current + 1, N);

    /*
        🔎 Complexity Analysis:
        -----------------------
        ➤ Time Complexity (TC):
            - Each call does O(1) work (just printing).
            - Function is called N times.
            - Total = O(N).

        ➤ Space Complexity (SC):
            - Each call is stored in the recursion call stack.
            - At most N function calls at the same time (before base case).
            - Total = O(N).
    */
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    // Start recursion with current = 1
    cout << "Numbers from 1 to " << N << ": ";
    printNumbers(1, N);

    return 0;
}
