/*
------------------------------------------------------------
💡 Problem Name: Palindrome Partitioning
📘 Problem Number: LeetCode #131

🧩 Problem Statement:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input:  s = "aab"
Output: [["a","a","b"],["aa","b"]]

------------------------------------------------------------
🧠 Intuition:
We need to break the string into all possible substrings such that each substring is a palindrome.
To explore all possibilities, we use recursion (backtracking):
1. Start from index 0.
2. Try every possible substring (s[index...i]).
3. If it's a palindrome, include it and recurse for the remaining part.
4. When we reach the end, we have one valid partition — store it.
5. Backtrack to explore other partitions.

------------------------------------------------------------
⚙️ Algorithm:
1. Start from index 0.
2. For each i from index → end of string:
     - Check if s[index...i] is a palindrome.
     - If yes:
         - Push substring into current path.
         - Recurse for i+1.
         - Pop (backtrack) to explore other options.
3. When index == s.size(), add current path to the result.
4. Return result list after recursion ends.

------------------------------------------------------------
⏱️ Time Complexity:
O(n * 2^n)
- We generate all possible partitions (≈ 2^n).
- For each partition, we check palindromic substrings (O(n) each in worst case).

💾 Space Complexity:
O(n)
- Recursion stack + path vector storage (depth proportional to string length).

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Main function that returns all palindrome partitions of string s
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res; // To store final result (all partitions)
        vector<string> path;        // To store current partition path
        partitionHelper(0, s, path, res);
        return res;
    }

private:
    // Recursive helper function for partitioning
    void partitionHelper(int index, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        // Base case: when index reaches end of string, we found a valid partition
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }

        // Try all possible substrings starting from 'index'
        for (int i = index; i < s.size(); ++i)
        {
            // If substring s[index...i] is a palindrome
            if (isPalindrome(s, index, i))
            {
                // Include this substring in current path
                path.push_back(s.substr(index, i - index + 1));

                // Recurse for remaining substring starting from i+1
                partitionHelper(i + 1, s, path, res);

                // Backtrack: remove last substring to explore next possibility
                path.pop_back();
            }
        }
    }

    // Function to check if substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

// -------------------
// 🧪 Example Usage
// -------------------
int main()
{
    Solution sol;
    string s = "aab";

    vector<vector<string>> ans = sol.partition(s);

    cout << "All possible palindrome partitions:\n";
    for (auto &vec : ans)
    {
        cout << "[ ";
        for (auto &str : vec)
        {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}

/*
------------------------------------------------------------
✅ OUTPUT:
All possible palindrome partitions:
[ "a" "a" "b" ]
[ "aa" "b" ]

------------------------------------------------------------
*/
