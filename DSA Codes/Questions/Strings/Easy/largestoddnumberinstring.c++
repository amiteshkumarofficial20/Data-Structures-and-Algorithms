#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 1903 - Largest Odd Number in String
--------------------------------------------------------
You are given a string `num`, representing a large integer.
Return the largest-valued odd number (as a substring of num).
If no odd number exists, return "".

Example 1:
Input:  num = "52"
Output: "5"

Example 2:
Input:  num = "4206"
Output: ""   (no odd digit exists)

Example 3:
Input:  num = "35427"
Output: "35427" (entire string is odd)

--------------------------------------------------------
📝 Brute Force Approach:
--------------------------------------------------------
1. Generate all substrings `num[i..j]` where `0 <= i <= j < n`.
2. Check if the **last digit** of the substring (`num[j]`) is odd.
   - If it's odd, this substring is a valid odd number.
3. Compare with the current best answer:
   - If substring length is larger → update answer.
   - If same length but lexicographically greater → update answer.
4. Return the best substring found.

⚡ Why check last digit only?
   - A number is odd if and only if its last digit is odd.
   - So we don’t need to check the entire substring.

--------------------------------------------------------
⚡ Complexity:
--------------------------------------------------------
- Generating substrings: O(n^2)
- Extracting substring: O(n) (because substr() copies chars)
- Total Time: O(n^3) in worst case
- Space: O(1) extra (ignoring answer string)

This brute force is not practical for large inputs,
but it’s useful for understanding the problem.
*/

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string ans = ""; // to store the best (largest odd substring)
        int n = num.size();

        // Step 1: Iterate over all starting indices
        for (int i = 0; i < n; i++)
        {
            // Step 2: Iterate over all ending indices
            for (int j = i; j < n; j++)
            {

                // Check if last digit is odd
                if ((num[j] - '0') % 2 == 1)
                {

                    // Step 3: Extract substring num[i..j]
                    string sub = num.substr(i, j - i + 1);

                    // Step 4: Update answer if this substring is "larger"
                    if (sub.size() > ans.size() ||
                        (sub.size() == ans.size() && sub > ans))
                    {
                        ans = sub;
                    }
                }
            }
        }

        return ans;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string num = "35427";
    string ans = sol.largestOddNumber(num);

    cout << "Largest Odd Number: " << ans << endl;

    return 0;
}

/*--------------------------------------------------------
📝 Optimal Approach:
--------------------------------------------------------
⚡ Observation:
- A number is odd if its **last digit** is odd.
- So, the largest odd number substring will always be:
  → The prefix of the string from start up to the **rightmost odd digit**.

Steps:
1. Scan from right to left across `num`.
2. The first time we encounter an odd digit:
   - Return the prefix `num[0..i]` (i inclusive).
   - This is the largest odd substring.
3. If no odd digit is found, return "".

--------------------------------------------------------
⚡ Complexity:
--------------------------------------------------------
- Time: O(n)  → one pass from right to left.
- Space: O(1) → no extra space (excluding output).

This is the most efficient solution.
*/

class Solution
{
public:
    string largestOddNumber(string num)
    {
        // Step 1: Scan from rightmost digit
        for (int i = num.size() - 1; i >= 0; --i)
        {
            // Step 2: Check if this digit is odd
            if ((num[i] - '0') % 2 == 1)
            {
                // Step 3: Return prefix (largest odd number)
                return num.substr(0, i + 1);
            }
        }
        // Step 4: If no odd digit found, return empty string
        return "";
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    vector<string> tests = {"52", "4206", "35427", "2468"};
    for (auto &num : tests)
    {
        cout << "Input: " << num
             << " → Largest Odd Number: "
             << sol.largestOddNumber(num) << endl;
    }

    return 0;
}