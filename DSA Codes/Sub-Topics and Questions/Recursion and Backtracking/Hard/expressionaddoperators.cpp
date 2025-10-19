// ============================================================================
// 🧩 Problem: Expression Add Operators
// 🔢 LeetCode Problem Number: 282
// 💼 Companies: Google, Amazon, Microsoft, Apple, Facebook, Uber, Adobe
// ============================================================================
//
// 📝 Description:
// Given a string num that contains only digits and an integer target,
// return all possible expressions by inserting '+', '-', and '*'
// between the digits of num such that the resulting expression evaluates to target.
//
// Note:
// - No reordering of digits is allowed.
// - No leading zeros are allowed except for the number 0 itself.
//
// Example:
// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"]
//
// Constraints:
// 1 <= num.length <= 10
// num consists of digits only.
// -2^31 <= target <= 2^31 - 1
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// 🔹 CLASS DEFINITION
// ============================================================================
class Solution
{
private:
    // ------------------------------------------------------------------------
    // 🧠 Recursive DFS Helper Function
    // ------------------------------------------------------------------------
    // Parameters:
    // - num            → Input numeric string (e.g., "123")
    // - target         → Target integer value to achieve
    // - start          → Current index in the string num
    // - current_value  → Current evaluated value of the expression so far
    // - last_operand   → The last operand used (for handling multiplication)
    // - expression     → The current expression being built
    // - result         → Vector storing all valid expressions
    //
    // This function explores all possible placements of '+', '-', and '*'
    // between digits and backtracks when necessary.
    // ------------------------------------------------------------------------
    void dfs(string &num, int target, int start,
             long long current_value, long long last_operand,
             string expression, vector<string> &result)
    {

        // 🛑 Base Case:
        // If we have reached the end of the string,
        // check if the expression evaluates to target.
        if (start == num.size())
        {
            if (current_value == target)
                result.push_back(expression);
            return;
        }

        // 🔁 Try all possible splits of the remaining string
        for (int i = start; i < num.size(); i++)
        {
            // Skip numbers with leading zeros (e.g., "05")
            if (i > start && num[start] == '0')
                return;

            // Extract the current number substring
            string current_num = num.substr(start, i - start + 1);
            long long current_num_val = stoll(current_num);

            // 🧮 CASE 1: First number — start new expression
            if (start == 0)
            {
                dfs(num, target, i + 1, current_num_val, current_num_val, current_num, result);
            }
            else
            {
                // ➕ CASE 2: Add '+'
                dfs(num, target, i + 1,
                    current_value + current_num_val,
                    current_num_val,
                    expression + "+" + current_num,
                    result);

                // ➖ CASE 3: Add '-'
                dfs(num, target, i + 1,
                    current_value - current_num_val,
                    -current_num_val,
                    expression + "-" + current_num,
                    result);

                // ✖️ CASE 4: Add '*'
                // Undo last addition/subtraction and apply multiplication
                dfs(num, target, i + 1,
                    current_value - last_operand + last_operand * current_num_val,
                    last_operand * current_num_val,
                    expression + "*" + current_num,
                    result);
            }
        }
    }

public:
    // ------------------------------------------------------------------------
    // 🔹 Main Function: addOperators
    // ------------------------------------------------------------------------
    // Returns all valid expressions that evaluate to the target.
    // ------------------------------------------------------------------------
    vector<string> addOperators(string num, int target)
    {
        vector<string> result;
        if (num.empty())
            return result;

        dfs(num, target, 0, 0, 0, "", result);
        return result;
    }
};

// ============================================================================
// 🧠 Explanation of Approach
// ----------------------------------------------------------------------------
// This problem is solved using **Backtracking / DFS**.
//
// 1️⃣ We explore all possible positions to place '+', '-', or '*'.
// 2️⃣ Each recursive call adds an operator and a number to the current expression.
// 3️⃣ For '*', we handle precedence by adjusting the last operand correctly.
// 4️⃣ Once we reach the end of the string, we check if the total equals target.
// ----------------------------------------------------------------------------
//
// Example Trace: num = "123", target = 6
// Step-by-step paths explored:
//   "1+2+3" → 6 ✅
//   "1*2*3" → 6 ✅
//   "12-3"  → 9 ❌
// ----------------------------------------------------------------------------
//
// ✅ Final Answer: ["1+2+3", "1*2*3"]
// ============================================================================

// -----------------------------------------------------------------------------
// ⏱️ Time Complexity Analysis
// -----------------------------------------------------------------------------
// Let N = num.size()
// - At each position, we can choose '+', '-', or '*' → 3 choices
// - We also try different substring lengths
// Therefore, approximate upper bound: O(4^N)
// (since substring creation adds another factor).
//
// ⏱️ Time Complexity: O(4^N)
// 💾 Space Complexity: O(N) for recursion stack
// (excluding the space required for storing results).
// -----------------------------------------------------------------------------

// ============================================================================
// 🧪 Main Function (for Local Testing)
// ============================================================================
int main()
{
    Solution solution;

    string num = "123";
    int target = 6;

    vector<string> result = solution.addOperators(num, target);

    cout << "🔢 Possible expressions for num = \"" << num
         << "\" and target = " << target << ":\n";

    for (string &expr : result)
    {
        cout << "➡️ " << expr << endl;
    }

    return 0;
}

// ============================================================================
// ✅ End of File
// ============================================================================
