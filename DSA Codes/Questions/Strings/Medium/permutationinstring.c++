#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 567 - Permutation in String
------------------------------------------------
Given two strings s1 and s2, return true if s2 contains
a permutation of s1, otherwise return false.

In other words, return true if one of s1's permutations
is a substring of s2.

Example:
---------
Input:  s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains "ba" which is a permutation of "ab".

-------------------------------------------------------
📝 Brute Force Approach:
-------------------------------------------------------
1. Generate ALL possible permutations of string s1.
   - Sort s1 first → to start from lexicographically
     smallest permutation.
   - Use STL `next_permutation` to generate all permutations.

2. For each permutation:
   - Check if it exists in s2 using s2.find(perm).
   - If found → return true.

3. If no permutation found → return false.

-------------------------------------------------------
⚡ Time Complexity:
-------------------------------------------------------
- Number of permutations of s1 = O(n!) where n = s1.length().
- Checking each permutation in s2 → O(m * n),
  where m = s2.length().
- Total = O(n! * m * n) → extremely large for n > 9.

💾 Space Complexity:
- O(1), only using variables for permutations.
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // Step 1: sort s1 to start with smallest permutation
        sort(s1.begin(), s1.end());

        // Step 2: generate all permutations
        do
        {
            // Step 3: check if current permutation exists in s2
            if (s2.find(s1) != string::npos)
            {
                return true; // found a valid permutation
            }
        } while (next_permutation(s1.begin(), s1.end()));

        // Step 4: no permutation found
        return false;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool ans = sol.checkInclusion(s1, s2);

    cout << "Does s2 contain a permutation of s1? "
         << (ans ? "true" : "false") << endl;

    return 0;
}

// -------------------------------------------------------
// 📝 Better Approach (Sorting Substrings):
// -------------------------------------------------------
// 1. Sort s1 once and store it in sortedS1.
//    (This gives us a "signature" for comparison.)

// 2. Iterate over s2 and check every substring of length n = s1.size().
//    - Extract substring of length n → O(n).
//    - Sort substring → O(n log n).
//    - Compare with sortedS1.

// 3. If any substring matches → return true.
// 4. If no match after full scan → return false.

// -------------------------------------------------------
// ⚡ Time Complexity:
// -------------------------------------------------------
// - Extracting substring: O(n)
// - Sorting substring: O(n log n)
// - Checking m-n+1 substrings
// Total = O((m-n+1) * n log n) ≈ O(m * n log n)

// 💾 Space Complexity:
// - O(n) for substring storage
// - O(1) extra beyond input strings

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        if (n > m)
            return false; // impossible case

        // Step 1: Sort s1 once
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());

        // Step 2: Check all substrings of length n in s2
        for (int i = 0; i + n <= m; i++)
        {
            string sub = s2.substr(i, n); // O(n)
            sort(sub.begin(), sub.end()); // O(n log n)

            if (sub == sortedS1)
            {
                return true; // found a permutation
            }
        }

        // Step 3: No substring matched
        return false;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool ans = sol.checkInclusion(s1, s2);

    cout << "Does s2 contain a permutation of s1? "
         << (ans ? "true" : "false") << endl;

    return 0;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// 📝 Optimal Approach(Sliding Window + Frequency Count) : -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -1. Count frequency of each character in s1 → need[26].

//                                                          2. Use a sliding window of size m = s1.length() over s2.- Maintain frequency of current window → have[26].- For each window,
//                                                                                          compare have[] with need[].- If they match → found a permutation → return true.

//                                                                                                                       3. Slide the window : -Remove the leftmost char -
//                                                                                              Add the next char on the right
//                                                                                              - Update have[] in O(1)

//                                                                                                    4. If no window matched → return false.

//                                                                                                -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
// ⚡ Time Complexity : -Building need[] → O(m) - Checking first window → O(m + 26) - Each slide update → O(1) -
//                                                                                              Total = O(m + n)  ✅ (linear)

// 💾 Space Complexity : -O(26) = O(1) constant space
//                                 - Just frequency arrays
//                                       * /

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false; // impossible case

        // Step 1: Frequency of s1
        int need[26] = {0};
        for (char c : s1)
            need[c - 'a']++;

        // Step 2: Frequency of first window in s2
        int have[26] = {0};
        for (int i = 0; i < m; i++)
        {
            have[s2[i] - 'a']++;
        }

        // Step 3: Compare initial window
        if (equal(begin(need), end(need), begin(have)))
            return true;

        // Step 4: Slide window across s2
        for (int i = m; i < n; i++)
        {
            // Add new char (right side)
            have[s2[i] - 'a']++;

            // Remove old char (left side)
            have[s2[i - m] - 'a']--;

            // Compare updated window
            if (equal(begin(need), end(need), begin(have)))
            {
                return true;
            }
        }

        return false;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool ans = sol.checkInclusion(s1, s2);

    cout << "Does s2 contain a permutation of s1? "
         << (ans ? "true" : "false") << endl;

    return 0;
}