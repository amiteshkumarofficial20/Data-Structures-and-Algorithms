#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   LeetCode 18: 4Sum
   Problem:
   Given an array nums[] of n integers and an integer target,
   return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
   such that:
       - 0 <= a, b, c, d < n
       - a, b, c, d are distinct
       - nums[a] + nums[b] + nums[c] + nums[d] == target

   You may return the answer in any order.
==================================================== */

/* ====================================================
   1. BRUTE FORCE APPROACH
   ----------------------------------------------------
   Idea:
   - Use 4 nested loops to try every possible quadruplet.
   - Check if their sum == target.
   - Sort each quadruplet before inserting into a set (to avoid duplicates).
   - Convert set to vector for output.

   Time Complexity:  O(n^4 * log m)
                     → n^4 for 4 loops, log m for set insertion.
   Space Complexity: O(m)
                     → set to store unique quadruplets.
==================================================== */
vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st; // store unique quadruplets

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end()); // sort before inserting
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

/* ====================================================
   2. BETTER APPROACH (Hashing)
   ----------------------------------------------------
   Idea:
   - Fix 2 numbers (i, j).
   - Use a hashset to check if the 4th number exists.
   - Store unique quadruplets in a set.

   Time Complexity:  O(n^3 * log m)
                     → O(n^3) for loops, log m for set insert.
   Space Complexity: O(n + m)
                     → hashset + result set.
==================================================== */
vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset; // to store seen numbers
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j] + nums[k];
                long long fourth = target - sum;

                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end()); // keep sorted
                    st.insert(temp);
                }
                hashset.insert(nums[k]); // mark current number as seen
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

/* ====================================================
   3. OPTIMAL APPROACH (Sorting + Two Pointers)
   ----------------------------------------------------
   Idea:
   - Sort the array.
   - Fix the first 2 numbers (i, j).
   - Use 2 pointers (k, l) for the remaining 2 numbers.
   - Adjust pointers based on sum comparison.
   - Skip duplicates for i, j, k, l.

   Time Complexity:  O(n^3)
                     → two nested loops + two pointers.
   Space Complexity: O(1) (ignoring output).
==================================================== */
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end()); // sort for two-pointer

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // skip duplicate i

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue; // skip duplicate j

            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++, l--;

                    // skip duplicates
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}

/* ====================================================
   MAIN FUNCTION → Run all 3 approaches
==================================================== */
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;

    cout << "=== Brute Force Solution ===\n";
    auto ans1 = fourSumBrute(nums, target);
    for (auto &quad : ans1)
    {
        cout << "[ ";
        for (int val : quad)
            cout << val << " ";
        cout << "] ";
    }
    cout << "\n\n";

    cout << "=== Better (Hashing) Solution ===\n";
    auto ans2 = fourSumBetter(nums, target);
    for (auto &quad : ans2)
    {
        cout << "[ ";
        for (int val : quad)
            cout << val << " ";
        cout << "] ";
    }
    cout << "\n\n";

    cout << "=== Optimal (Sorting + Two Pointers) Solution ===\n";
    auto ans3 = fourSumOptimal(nums, target);
    for (auto &quad : ans3)
    {
        cout << "[ ";
        for (int val : quad)
            cout << val << " ";
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
