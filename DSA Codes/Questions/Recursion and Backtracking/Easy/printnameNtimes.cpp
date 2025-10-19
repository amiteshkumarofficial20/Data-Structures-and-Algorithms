#include <iostream>
using namespace std;

/*
    Function: printMessage
    Purpose: Print "Amitesh" N times using recursion

    Parameters:
        - count : keeps track of how many times we have printed so far
        - N     : total number of times we want to print

    Recursion Idea:
        1. Every recursive function needs a BASE CASE to stop further calls.
        2. At each call, we do one task (print) and then move closer to the base case.
        3. Here, base case is reached when count == N.
*/
void printMessage(int count, int N)
{
    // ✅ BASE CASE: Stop when we have printed N times
    if (count == N)
    {
        return; // recursion ends here
    }

    // Step 1: Do work → Print the message with current count
    cout << "Amitesh (" << count + 1 << ")" << endl;

    // Step 2: Recursive call → Move to the next count
    // Each call reduces the problem size by 1
    printMessage(count + 1, N);

    /*
        🔎 Complexity Analysis:
        -----------------------
        ➤ Time Complexity (TC):
            - Each call prints once (O(1))
            - Function is called N times
            - So total time = O(N)

        ➤ Space Complexity (SC):
            - Each recursive call is stored in the call stack until it returns
            - At max, there are N calls waiting (before reaching base case)
            - So total space = O(N) (stack space)
    */
}

int main()
{
    int N;
    cout << "Enter how many times you want to print Amitesh: ";
    cin >> N;

    // Start recursion with count = 0
    printMessage(0, N);

    return 0;
}
