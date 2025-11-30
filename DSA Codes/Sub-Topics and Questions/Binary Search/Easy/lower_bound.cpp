// ============================================================================
//   LOWER BOUND IMPLEMENTATION (SUPER DETAILED FILE)
//   Filename : lower_bound_detailed.cpp
// ============================================================================
//
//   FULL DOCUMENTATION (EXTREME INTERVIEW-GRADE EXPLANATION)
//   ---------------------------------------------------------
//
//   ⭐ PROBLEM STATEMENT:
//   ---------------------
//   You are given a SORTED array of N integers and an integer x.
//   You must find the LOWER BOUND of x.
//
//   ❓ What is LOWER BOUND?
//   ------------------------
//   • Lower Bound = the FIRST index 'i' such that:
//          arr[i] >= x
//
//   • If no such index exists → return n (array size).
//
//   Example:
//       Input: arr = [3,5,8,15,19], x = 9
//       Output: 3       (because arr[3] = 15 >= 9)
//
//   ------------------------------------------------------------
//   ⭐ CONSTRAINTS:
//   ------------------------------------------------------------
//   • 1 ≤ N ≤ 10^5
//   • Array is sorted (non-decreasing)
//   • -10^9 ≤ arr[i], x ≤ 10^9
//   • No modification required to the input array
//
// ============================================================================
//   BRUTE FORCE APPROACH
// ============================================================================
//
//   IDEA:
//   -----
//   Scan the array from left to right.
//   At the FIRST index where arr[i] >= x → return i.
//   If no such index exists → return n.
//
//   ------------------------------------------------------------
//   BRUTE FORCE ALGORITHM (Linear Search):
//   ------------------------------------------------------------
//     1. Loop i from 0 to n-1:
//             if arr[i] >= x:
//                 return i
//     2. Return n
//
//   ------------------------------------------------------------
//   BRUTE FORCE PSEUDOCODE:
//   ------------------------------------------------------------
//     function lowerBoundLinear(arr, n, x):
//         for i = 0 to n-1:
//             if arr[i] >= x:
//                 return i
//         return n
//
//   TIME COMPLEXITY  : O(n)
//   SPACE COMPLEXITY : O(1)
//   WHY NOT OPTIMAL? : The array is sorted → we can do better with O(log n).
//
// ============================================================================
//   OPTIMAL APPROACH — BINARY SEARCH (Iterative)
// ============================================================================
//
//   INTUITION:
//   ----------
//   We want the FIRST index i where arr[i] >= x.
//
//   ASCII EXAMPLE:
//
//       arr = [3,5,8,15,19], x = 9
//
//           0  1  2   3   4
//           |  |  |   |   |
//           3, 5, 8, 15, 19
//                  ↑
//                 mid = 2 → arr[2] = 8 < 9 → move RIGHT
//
//                       ↑
//                   mid = 3 → arr[3] = 15 >= 9
//                       store ans = 3
//                       move LEFT to find earlier index
//
//   KEY OBSERVATION:
//   ----------------
//   • If arr[mid] >= x → mid is a *valid* answer → store it and move LEFT
//   • If arr[mid] < x  → mid is too small → move RIGHT
//
//   --------------------------------------------------------------------------
//   ITERATIVE LOWER BOUND ALGORITHM:
//   --------------------------------------------------------------------------
//     low = 0
//     high = n-1
//     ans = n
//
//     while low <= high:
//         mid = (low + high) // 2
//
//         if arr[mid] >= x:
//             ans = mid         -- mid is a POSSIBLE answer
//             high = mid - 1    -- try to find even earlier valid index
//         else:
//             low = mid + 1     -- need bigger values
//
//     return ans
//
//   --------------------------------------------------------------------------
//   ITERATIVE PSEUDOCODE:
//   --------------------------------------------------------------------------
//     function lowerBoundBS(arr, n, x):
//         low = 0
//         high = n - 1
//         ans = n
//
//         while low <= high:
//             mid = (low + high) // 2
//
//             if arr[mid] >= x:
//                 ans = mid
//                 high = mid - 1
//             else:
//                 low = mid + 1
//
//         return ans
//
//   TIME COMPLEXITY  : O(log n)
//   SPACE COMPLEXITY : O(1)
//
// ============================================================================
//   OPTIONAL: RECURSIVE BINARY SEARCH (Lower Bound)
// ============================================================================
//
//   RECURSIVE LOWER BOUND ALGORITHM:
//   ---------------------------------
//     1. Base case: if low > high → return ans (stored globally)
//     2. Compute mid
//     3. If arr[mid] >= x:
//            ans = mid
//            search left half
//        else:
//            search right half
//
//   RECURSIVE PSEUDOCODE:
//   ----------------------
//     function lowerBoundRec(arr, low, high, x, ans):
//         if low > high:
//             return ans
//
//         mid = (low + high) // 2
//
//         if arr[mid] >= x:
//             ans = mid
//             return lowerBoundRec(arr, low, mid - 1, x, ans)
//         else:
//             return lowerBoundRec(arr, mid + 1, high, x, ans)
//
//   TIME COMPLEXITY  : O(log n)
//   SPACE COMPLEXITY : O(log n) (due to recursion stack)
//
// ============================================================================
//   COMPARISON TABLE
// ============================================================================
//
//   Approach        | Time Complexity | Space Complexity | Notes
//   ------------------------------------------------------------------
//   Brute Force     | O(n)            | O(1)             | Simple
//   Binary Search   | O(log n)        | O(1)             | Optimal
//   Recursive BS    | O(log n)        | O(log n)         | Cleaner logic
//
// ============================================================================
//   IMPLEMENTATION BELOW
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

class LowerBoundFinder
{
public:
    // -------------------------------------------------------
    // BRUTE FORCE (Linear Search)
    // -------------------------------------------------------
    int lowerBoundLinear(vector<int> &arr, int n, int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= x)
                return i;
        }
        return n;
    }

    // -------------------------------------------------------
    // OPTIMAL BINARY SEARCH (Iterative version)
    // -------------------------------------------------------
    int lowerBoundBinary(vector<int> &arr, int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n; // default answer

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x)
            {
                ans = mid;      // store possible answer
                high = mid - 1; // go left to check for earlier valid index
            }
            else
            {
                low = mid + 1; // go right
            }
        }
        return ans;
    }

    // -------------------------------------------------------
    // RECURSIVE LOWER BOUND (Optional)
    // -------------------------------------------------------
    int lowerBoundRecursive(vector<int> &arr, int low, int high, int x, int ans)
    {
        if (low > high)
            return ans;

        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;
            return lowerBoundRecursive(arr, low, mid - 1, x, ans);
        }
        return lowerBoundRecursive(arr, mid + 1, high, x, ans);
    }
};

// ============================================================================
//   MAIN FUNCTION — MULTIPLE TESTCASES
// ============================================================================

int main()
{

    LowerBoundFinder finder;

    vector<vector<int>> arrays = {
        {3, 5, 8, 15, 19},
        {1, 2, 4, 6, 10},
        {-5, -2, 0, 3, 7, 9},
        {1, 1, 1, 1, 1},
        {2, 4, 6, 8}};

    vector<int> targets = {9, 5, -3, 1, 10};

    for (int t = 0; t < arrays.size(); t++)
    {

        cout << "\n============================================================\n";
        cout << "Testcase " << (t + 1) << ":\n";

        cout << "Array: ";
        for (int v : arrays[t])
            cout << v << " ";
        cout << "\n";

        cout << "Target x = " << targets[t] << "\n";

        int idxLinear = finder.lowerBoundLinear(arrays[t], arrays[t].size(), targets[t]);
        int idxBinary = finder.lowerBoundBinary(arrays[t], arrays[t].size(), targets[t]);
        int idxRecursive = finder.lowerBoundRecursive(arrays[t], 0, arrays[t].size() - 1, targets[t], arrays[t].size());

        cout << "Brute Force (Linear Search): ";
        (idxLinear == arrays[t].size()) ? cout << "n (not found)\n"
                                        : cout << "Index " << idxLinear << "\n";

        cout << "Binary Search (Iterative):   ";
        (idxBinary == arrays[t].size()) ? cout << "n (not found)\n"
                                        : cout << "Index " << idxBinary << "\n";

        cout << "Binary Search (Recursive):   ";
        (idxRecursive == arrays[t].size()) ? cout << "n (not found)\n"
                                           : cout << "Index " << idxRecursive << "\n";

        cout << "============================================================\n";
    }

    return 0;
}
