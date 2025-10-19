#include <bits/stdc++.h>
using namespace std;

/* ============================================================
   LeetCode 31. Next Permutation
   ------------------------------------------------------------
   Problem Statement:
   A permutation of an array of integers is an arrangement
   of its members into a sequence or linear order.

   - Given an array of integers 'nums', find the next
     lexicographically greater permutation of numbers.

   - If such an arrangement is not possible, rearrange
     into the lowest possible order (sorted in ascending order).

   - The replacement must be in-place and use only constant extra memory.

   Example:
   Input: nums = [1,2,3]
   Output: [1,3,2]

   Input: nums = [3,2,1]
   Output: [1,2,3]

   ------------------------------------------------------------
   Brute Force Approach:
   ------------------------------------------------------------
   Idea:
   1. Save the original nums.
   2. Generate all permutations in lexicographic order.
   3. Find the position of the original permutation.
   4. Replace nums with the "next" permutation in the list.
      - If it's the last permutation, wrap around to the first.

   ------------------------------------------------------------
   Complexity:
   Let n = size of nums
   - Generating all permutations = O(n! * n)
   - Searching for original = O(n * n!)
   This is extremely inefficient (factorial time),
   but works for learning brute force.
   ============================================================ */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // Step 1: Save original permutation
        vector<int> original = nums;

        // Step 2: Generate all permutations in lexicographic order
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> allPerms;
        allPerms.push_back(sorted);

        // Use STL next_permutation to generate permutations in order
        while (next_permutation(sorted.begin(), sorted.end()))
        {
            allPerms.push_back(sorted);
        }

        // Step 3: Find the index of original in allPerms
        int idx = -1;
        for (int i = 0; i < (int)allPerms.size(); i++)
        {
            if (allPerms[i] == original)
            {
                idx = i;
                break;
            }
        }

        // Safety check (should never happen)
        if (idx == -1)
        {
            nums = allPerms.front();
            return;
        }

        // Step 4: Pick the next permutation (or wrap around)
        if (idx + 1 < (int)allPerms.size())
        {
            nums = allPerms[idx + 1];
        }
        else
        {
            nums = allPerms.front(); // wrap to smallest
        }
    }
};

/* ============================================================
   MAIN FUNCTION (for testing in VS Code)
   ============================================================ */
int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    cout << "Next permutation of [1,2,3]: ";
    for (int x : nums1)
        cout << x << " ";
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    cout << "Next permutation of [3,2,1]: ";
    for (int x : nums2)
        cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    cout << "Next permutation of [1,1,5]: ";
    for (int x : nums3)
        cout << x << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers `nums`, rearrange it into the lexicographically next greater permutation of numbers.
If no such permutation exists, rearrange it to the lowest possible order (sorted ascending).
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        /*
        🔹 Approach (using STL):
        - C++ provides `std::next_permutation()` in <algorithm>.
        - This function rearranges the elements into the next lexicographical permutation (if possible).
        - If the current permutation is the highest (like [3,2,1]), it rearranges to the lowest ([1,2,3]) and returns false.

        ✅ Steps:
        1. Try to generate the next permutation in-place.
        2. If `next_permutation()` returns false → means nums is in descending order.
           → So, we sort(nums.begin(), nums.end()) to reset to the smallest permutation.
        */

        if (!next_permutation(nums.begin(), nums.end()))
        {
            // If nums is the largest permutation → reset to smallest
            sort(nums.begin(), nums.end());
        }
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3}; // Example input

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
Rearrange numbers into the lexicographically next greater permutation.
If no such arrangement is possible, rearrange into the lowest (sorted ascending).
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        // Step 1️⃣: Find the "breakpoint"
        // Breakpoint = first index 'i' from the right where nums[i] < nums[i+1]
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        // Step 2️⃣: If no breakpoint found → nums is in descending order
        // Example: [3,2,1] → reset to [1,2,3]
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3️⃣: Find the element just greater than nums[index] (to the right)
        // Swap it with nums[index]
        for (int j = n - 1; j > index; j--)
        {
            if (nums[j] > nums[index])
            {
                swap(nums[j], nums[index]);
                break;
            }
        }

        // Step 4️⃣: Reverse the suffix starting at index+1
        // Ensures the right half is in increasing order (smallest possible)
        reverse(nums.begin() + index + 1, nums.end());
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3}; // Example input

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
