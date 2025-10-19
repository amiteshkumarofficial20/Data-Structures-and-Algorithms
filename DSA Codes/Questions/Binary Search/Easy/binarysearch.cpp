/***************************************************************
   PROBLEM: 704. Binary Search
   -------------------------------------------------------------
   Given a sorted integer array nums (ascending order),
   and an integer target, return its index if found, else -1.

   Example 1:
   Input:  nums = [-1,0,3,5,9,12], target = 9
   Output: 4   (nums[4] == 9)

   Example 2:
   Input:  nums = [-1,0,3,5,9,12], target = 2
   Output: -1  (2 does not exist in nums)

   Constraints:
   - 1 <= nums.length <= 10^4
   - -10^4 < nums[i], target < 10^4
   - All elements are unique
   - nums is sorted in ascending order

   -------------------------------------------------------------
   Asked In: Google, Amazon, Microsoft, Meta, Apple, Adobe, Uber
   -------------------------------------------------------------
   Goal: Must achieve O(log n) runtime complexity
***************************************************************/

/***************************************************************
   APPROACH 1: ITERATIVE BINARY SEARCH
   -------------------------------------------------------------
   ✅ Algorithm:
   1. Start with low = 0 and high = n-1
   2. While low <= high:
        mid = low + (high - low)/2
        if nums[mid] == target → return mid
        else if nums[mid] > target → move left (high = mid-1)
        else → move right (low = mid+1)
   3. If loop ends → not found → return -1

   ✅ Time Complexity: O(log n)
      - Each iteration halves the array
   ✅ Space Complexity: O(1)
      - Only uses a few variables
***************************************************************/

#include <bits/stdc++.h>
using namespace std;

class SolutionIterative
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // safe mid calc

            if (nums[mid] == target)
            {
                return mid; // ✅ Found
            }
            else if (nums[mid] > target)
            {
                high = mid - 1; // go LEFT
            }
            else
            {
                low = mid + 1; // go RIGHT
            }
        }
        return -1; // ❌ Not found
    }
};

/***************************************************************
   APPROACH 2: RECURSIVE BINARY SEARCH
   -------------------------------------------------------------
   ✅ Algorithm:
   1. Base Case: if low > high → return -1 (target not found)
   2. mid = low + (high - low)/2
   3. If nums[mid] == target → return mid
   4. If nums[mid] > target → recursive call on LEFT half
   5. If nums[mid] < target → recursive call on RIGHT half

   ✅ Time Complexity: O(log n)
      - Each recursive call halves the search space
   ✅ Space Complexity: O(log n)
      - Extra space due to recursion stack
***************************************************************/

class SolutionRecursive
{
public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        // Base case → invalid search space
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid; // ✅ Found
        }
        else if (nums[mid] > target)
        {
            // Explore LEFT half
            return binarySearch(nums, low, mid - 1, target);
        }
        else
        {
            // Explore RIGHT half
            return binarySearch(nums, mid + 1, high, target);
        }
    }
};

/***************************************************************
   🔹 EXAMPLE TRACE (Recursive)
   nums = [-1,0,3,5,9,12], target = 9

   Call stack:
   search(0,5)
     mid=2 → nums[2]=3 < 9 → go RIGHT
       └── search(3,5)
             mid=4 → nums[4]=9 == target → return 4

   Return Flow:
   search(3,5) → 4
   search(0,5) → 4
   Final Answer = 4

   -------------------------------------------------------------
   nums = [-1,0,3,5,9,12], target = 2 (not found)

   Call stack:
   search(0,5)
     mid=2 → nums[2]=3 > 2 → go LEFT
       └── search(0,1)
             mid=0 → nums[0]=-1 < 2 → go RIGHT
               └── search(1,1)
                     mid=1 → nums[1]=0 < 2 → go RIGHT
                       └── search(2,1) → base case → return -1

   Return Flow:
   search(2,1) → -1
   search(1,1) → -1
   search(0,1) → -1
   search(0,5) → -1
   Final Answer = -1
***************************************************************/

/***************************************************************
   🔹 DRIVER CODE (to test both versions)
***************************************************************/
int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};

    int target1 = 9;
    int target2 = 2;

    SolutionIterative it;
    SolutionRecursive rec;

    cout << "Iterative (target=9): " << it.search(nums, target1) << endl;
    cout << "Recursive (target=9): " << rec.search(nums, target1) << endl;

    cout << "Iterative (target=2): " << it.search(nums, target2) << endl;
    cout << "Recursive (target=2): " << rec.search(nums, target2) << endl;

    return 0;
}
