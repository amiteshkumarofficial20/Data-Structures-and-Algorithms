#include <bits/stdc++.h>
using namespace std;

/*
    Problem: 509. Fibonacci Number (LeetCode - Easy)
    -----------------------------------------------
    The Fibonacci numbers form a sequence:
    F(0) = 0
    F(1) = 1
    F(n) = F(n-1) + F(n-2), for n > 1

    Goal: Given n, return F(n).

    Approaches Implemented:
    1. Recursive (Naive Recursion)
    2. Iterative (Dynamic Programming / Bottom-Up)

    We will also analyze Time Complexity (TC) and Space Complexity (SC).
*/

// ---------------------------------------------------
// 1. Recursive Approach
// ---------------------------------------------------
/*
    Idea:
    - Directly implement the definition:
      F(n) = F(n-1) + F(n-2).
    - Base case: F(0)=0, F(1)=1.

    Example:
    F(4) = F(3) + F(2)
          = (F(2)+F(1)) + (F(1)+F(0))
          = (1+1) + (1+0) = 3

    Time Complexity: O(2^n)
      - Exponential, because it recalculates subproblems many times.
    Space Complexity: O(n)
      - Due to recursion stack depth.
*/
int fibRecursive(int n)
{
    if (n == 0)
        return 0; // Base case
    if (n == 1)
        return 1;                                     // Base case
    return fibRecursive(n - 1) + fibRecursive(n - 2); // Recursive case
}

// ---------------------------------------------------
// 2. Iterative Approach (Bottom-Up DP)
// ---------------------------------------------------
/*
    Idea:
    - Use a loop and store only last two results.
    - F(0)=0, F(1)=1, then iterate up to n.

    Example: n=5
      start: prev2=0, prev1=1
      i=2 → curr=1
      i=3 → curr=2
      i=4 → curr=3
      i=5 → curr=5

    Time Complexity: O(n)
      - Single loop from 2 to n.
    Space Complexity: O(1)
      - Only constant variables used.
*/
int fibIterative(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev2 = 0; // F(0)
    int prev1 = 1; // F(1)
    int curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2; // F(i) = F(i-1) + F(i-2)
        prev2 = prev1;        // shift window
        prev1 = curr;
    }
    return curr;
}

// ---------------------------------------------------
// Main function to test both approaches
// ---------------------------------------------------
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci using Recursion: " << fibRecursive(n) << endl;
    cout << "Fibonacci using Iteration: " << fibIterative(n) << endl;

    return 0;
}
