// ============================================================================
//   LeetCode 704: Binary Search
//   Filename : 704_binary_search.cpp
// ============================================================================
//
//   FULL DOCUMENTATION (EXTREMELY DETAILED, INTERVIEW-GRADE)
//   ---------------------------------------------------------
//
//   PROBLEM STATEMENT:
//   -------------------
//   You are given a sorted array of DISTINCT integers (strictly increasing)
//   and a target value. Your task is to return the index of the target if
//   it exists; otherwise return -1.
//
//   Example:
//       Input : nums = [-1, 0, 3, 5, 9, 12], target = 9
//       Output: 4
//
//   ------------------------------------------------------------
//   CONSTRAINTS:
//   ------------------------------------------------------------
//   • 1 <= nums.size() <= 10^4
//   • -10^4 <= nums[i], target <= 10^4
//   • nums is sorted in strictly increasing order
//   • No duplicate values
//   • Expected time complexity: O(log n)
//
//   ------------------------------------------------------------
//   BRUTE FORCE APPROACH (LINEAR SEARCH)
//   ------------------------------------------------------------
//
//   IDEA:
//      • Traverse array from start to end.
//      • Compare each value with target.
//      • If match occurs → return index.
//      • Otherwise → return -1.
//
//   WHY BRUTE FORCE IS SUBOPTIMAL?
//      • It checks EVERY element.
//      • Runtime O(n), but problem requires O(log n).
//
//   ------------------------------------------------------------
//   ALGORITHM (Brute Force):
//      1. For i = 0 to n-1:
//             If nums[i] == target:
//                 return i
//      2. If not found → return -1
//
//   ------------------------------------------------------------
//   PSEUDOCODE (Brute Force):
//      function linearSearch(nums, target):
//          for i from 0 to length(nums)-1:
//              if nums[i] == target:
//                  return i
//          return -1
//
//   TIME COMPLEXITY  : O(n)
//   SPACE COMPLEXITY : O(1)
//
//   ------------------------------------------------------------
//   OPTIMAL APPROACH — BINARY SEARCH (Iterative)
//   ------------------------------------------------------------
//
//   INTUITION:
//   ----------
//   Since the array is sorted, the middle element tells us which half of the
//   array to discard.
//
//       low                             high
//        |                                |
//        v                                v
//     [ 2, 4, 6, 8, 10, 12, 14 ]
//               ↑
//              mid
//
//   • If target == nums[mid] → FOUND
//   • If target > nums[mid]  → SEARCH RIGHT HALF
//   • If target < nums[mid]  → SEARCH LEFT HALF
//
//   This halves the search space each time → O(log n).
//
//   ------------------------------------------------------------
//   ITERATIVE BINARY SEARCH ALGORITHM:
//      1. low = 0
//      2. high = n - 1
//      3. While low <= high:
//            mid = low + (high - low) / 2
//
//            A. If nums[mid] == target → return mid
//            B. If nums[mid] < target → low = mid + 1
//            C. Else (nums[mid] > target) → high = mid - 1
//
//      4. Return -1
//
//   ------------------------------------------------------------
//   PSEUDOCODE (Iterative BS):
//      function binarySearch(nums, target):
//          low = 0
//          high = length(nums) - 1
//
//          while low <= high:
//              mid = low + (high - low) // 2
//
//              if nums[mid] == target:
//                  return mid
//
//              else if nums[mid] < target:
//                  low = mid + 1
//
//              else:
//                  high = mid - 1
//
//          return -1
//
//   TIME COMPLEXITY  : O(log n)
//   SPACE COMPLEXITY : O(1)
//      → Because it uses only pointers and no extra memory.
//
//   ------------------------------------------------------------
//   RECURSIVE BINARY SEARCH
//   ------------------------------------------------------------
//   Same logic as iterative; recursion replaces the loop.
//
//   ------------------------------------------------------------
//   RECURSIVE BINARY SEARCH ALGORITHM:
//
//      function search(nums, low, high, target):
//          1. If low > high → return -1
//
//          2. mid = low + (high - low) / 2
//
//          3. If nums[mid] == target → return mid
//
//          4. If nums[mid] < target:
//                 return search(nums, mid+1, high, target)
//
//          5. Else:
//                 return search(nums, low, mid-1, target)
//
//   ------------------------------------------------------------
//   RECURSIVE PSEUDOCODE:
//
//      function recursiveBS(nums, low, high, target):
//          if low > high:
//              return -1
//
//          mid = low + (high - low) // 2
//
//          if nums[mid] == target:
//              return mid
//
//          else if nums[mid] < target:
//              return recursiveBS(nums, mid+1, high, target)
//
//          else:
//              return recursiveBS(nums, low, mid-1, target)
//
//   TIME COMPLEXITY  : O(log n)
//   SPACE COMPLEXITY : O(log n)  (recursion stack)
//
//   ------------------------------------------------------------
//   COMPARISON TABLE (Brute vs Binary Search)
//   ------------------------------------------------------------
//
//     Method        | Time Complexity | Space Complexity | When to Use
//   --------------------------------------------------------------------
//     Brute Force   | O(n)            | O(1)             | Unsorted arrays
//     Binary Search | O(log n)        | O(1)             | Sorted arrays
//
//   ------------------------------------------------------------
//   IMPLEMENTATION BELOW
//   ------------------------------------------------------------
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // ------------------------------------------------------------------------
    // BRUTE FORCE SEARCH
    // ------------------------------------------------------------------------
    int linearSearch(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    // ------------------------------------------------------------------------
    // ITERATIVE BINARY SEARCH
    // ------------------------------------------------------------------------
    int searchIterative(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    // ------------------------------------------------------------------------
    // RECURSIVE BINARY SEARCH
    // ------------------------------------------------------------------------
    int searchRecursive(vector<int> &nums, int low, int high, int target)
    {

        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            return searchRecursive(nums, mid + 1, high, target);

        return searchRecursive(nums, low, mid - 1, target);
    }
};

// ============================================================================
//   MAIN FUNCTION (Running multiple testcases)
// ============================================================================

int main()
{

    Solution obj;

    vector<vector<int>> testArrays = {
        {-5, -2, 0, 3, 6, 10, 15},
        {1, 3, 5, 7, 9, 11},
        {2, 4, 6, 8, 10, 12, 14}};

    vector<int> targets = {6, 4, 10};

    for (int t = 0; t < testArrays.size(); t++)
    {

        cout << "\n=============================================\n";
        cout << "Testcase " << (t + 1) << ":\n";

        cout << "Array: ";
        for (int x : testArrays[t])
            cout << x << " ";
        cout << "\n";

        cout << "Target: " << targets[t] << "\n";

        int idxLinear = obj.linearSearch(testArrays[t], targets[t]);
        int idxIter = obj.searchIterative(testArrays[t], targets[t]);
        int idxRecur = obj.searchRecursive(testArrays[t], 0, testArrays[t].size() - 1, targets[t]);

        cout << "Brute Force (Linear Search): ";
        (idxLinear == -1) ? cout << "Not Found\n" : cout << "Index " << idxLinear << "\n";

        cout << "Iterative Binary Search: ";
        (idxIter == -1) ? cout << "Not Found\n" : cout << "Index " << idxIter << "\n";

        cout << "Recursive Binary Search: ";
        (idxRecur == -1) ? cout << "Not Found\n" : cout << "Index " << idxRecur << "\n";

        cout << "=============================================\n";
    }

    return 0;
}
