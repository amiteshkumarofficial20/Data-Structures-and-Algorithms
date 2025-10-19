// ============================================================================
// 🧩 Problem: Letter Combinations of a Phone Number
// 🔢 LeetCode Problem Number: 17
// 💼 Companies: Amazon, Google, Microsoft, Apple, Facebook, Uber, Adobe
// ============================================================================
// 📝 Description:
// Given a string containing digits from 2–9 inclusive, return all possible
// letter combinations that the number could represent.
// The mapping of digits to letters is the same as on a telephone button pad.
//
// Example:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
// Constraints:
// - 0 <= digits.length <= 4
// - digits[i] is a digit in the range ['2', '9']
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // ------------------------------------------------------------------------
    // 🔹 Recursive helper function
    // This function builds letter combinations by exploring all possible
    // characters for each digit.
    //
    // Parameters:
    // ind     → Current index in the digits string
    // digits  → The input string containing digits (e.g., "23")
    // s       → Current combination being built
    // ans     → Vector storing all possible combinations
    // combos  → Array mapping digits to corresponding letters
    // ------------------------------------------------------------------------
    void func(int ind, string digits, string s, vector<string> &ans, string combos[])
    {

        // 🛑 Base Case:
        // When the index reaches the end of the digits string, we have formed
        // one complete combination, so we push it into the result vector.
        if (ind == digits.size())
        {
            if (!s.empty())
                ans.push_back(s); // Add only if non-empty
            return;
        }

        // Get the digit at the current index and its corresponding characters
        int digit = digits[ind] - '0';
        string letters = combos[digit];

        // 🔁 For each letter mapped to the current digit, add it to the current
        // string and recursively generate combinations for the next digit
        for (int i = 0; i < letters.size(); i++)
        {
            func(ind + 1, digits, s + letters[i], ans, combos);
        }
    }

public:
    // ------------------------------------------------------------------------
    // 🔹 Main function: letterCombinations
    // Returns all possible letter combinations for the given digit string.
    // ------------------------------------------------------------------------
    vector<string> letterCombinations(string digits)
    {

        // Handle empty input case — if digits string is empty, return an empty vector
        if (digits.empty())
            return {};

        // Mapping digits to corresponding characters as on a phone keypad
        string combos[] = {
            "",     // 0 → no letters
            "",     // 1 → no letters
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> ans; // To store all combinations

        // Start recursion from index 0 and empty string
        func(0, digits, "", ans, combos);

        return ans;
    }
};

// ============================================================================
// 🧪 MAIN FUNCTION FOR LOCAL TESTING (not needed on LeetCode)
// ============================================================================
int main()
{
    Solution sol;
    string digits;

    cout << "Enter digits (2–9): ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "\nLetter Combinations are:\n";
    for (auto &s : result)
        cout << s << " ";
    cout << endl;

    return 0;
}
// ============================================================================

// ============================================================================
// 🧠 Explanation of Approach
// ----------------------------------------------------------------------------
// 1️⃣ Use a mapping (array) from digits to letters, similar to a phone keypad.
// 2️⃣ Use recursion (backtracking):
//     - For each digit, iterate over all possible characters.
//     - Append one character and recursively process the next digit.
//     - When you reach the end, store the built string.
// 3️⃣ This explores all possible combinations in a DFS manner.
// ----------------------------------------------------------------------------
//
// Example Trace (digits = "23"):
// combos: 2 → "abc", 3 → "def"
// Path Exploration:
//   "a" + recurse("3") → "ad", "ae", "af"
//   "b" + recurse("3") → "bd", "be", "bf"
//   "c" + recurse("3") → "cd", "ce", "cf"
// ----------------------------------------------------------------------------
//
// ✅ Final Answer: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// ============================================================================

// -----------------------------------------------------------------------------
// ⏱️ Time Complexity Analysis
// -----------------------------------------------------------------------------
// Let N = length of digits string.
//
// For each digit, there can be up to 4 possible letters (at digit 7 or 9).
// Therefore, total combinations = 4^N (in worst case).
// Hence, Time Complexity: O(4^N * N)
// (because we also spend O(N) time to build each combination string).
//
// Example: for digits = "234", combinations ≈ 3 × 3 × 3 = 27 (for 3-letter mapping).
// -----------------------------------------------------------------------------

// 💾 Space Complexity Analysis
// -----------------------------------------------------------------------------
// - Recursion stack depth = O(N)
// - Result vector can hold up to 4^N strings, each of length N.
// Hence, Space Complexity: O(4^N * N)
// -----------------------------------------------------------------------------
