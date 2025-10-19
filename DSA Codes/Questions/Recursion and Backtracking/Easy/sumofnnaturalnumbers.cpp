#include <iostream>
using namespace std;

/*
    Function: sumOfNatural
    Purpose: Calculate sum of first N natural numbers using recursion.

    Formula: 1 + 2 + 3 + ... + N

    Approach:
        - Base Case: if N == 0, return 0 (since sum of 0 numbers is 0).
        - Recursive Case: sum(N) = N + sum(N-1).
*/
int sumOfNatural(int N)
{
    // ✅ Base Case
    if (N == 0)
        return 0;

    // Step 1: Add current number N
    // Step 2: Call function recursively for N-1
    return N + sumOfNatural(N - 1);

    /*
        🔎 Complexity Analysis:
        -----------------------
        ➤ Time Complexity (TC):
            - Each call does O(1) work.
            - Total recursive calls = N.
            - TC = O(N).

        ➤ Space Complexity (SC):
            - Each call is stored on stack until base case is reached.
            - Depth of recursion = N.
            - SC = O(N).
    */
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    // Call recursive function
    int result = sumOfNatural(N);

    cout << "Sum of first " << N << " natural numbers is: " << result << endl;

    return 0;
}
