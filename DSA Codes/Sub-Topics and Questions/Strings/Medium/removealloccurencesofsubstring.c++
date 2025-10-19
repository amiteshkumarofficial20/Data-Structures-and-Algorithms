#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 1910 - Remove All Occurrences of a Substring
-----------------------------------------------------------------
You are given two strings s and part. Remove all occurrences of
substring part from s until s no longer contains part.
Return the final string.

Example:
---------
Input:  s = "daabcbaabcbc", part = "abc"
Output: "dab"

-------------------------------------------------------
📝 Brute Force Approach:
-------------------------------------------------------
1. While string s contains substring "part":
   - Find its starting index using s.find(part).
   - Remove that substring using s.erase(index, part.length()).

2. Repeat until no more occurrences exist.

⚡ Time Complexity:
   - Each `find()` takes O(n) in worst case.
   - Each `erase()` can also take O(n).
   - If substring occurs k times → O(k * n).
   - Worst case → O(n^2).

💾 Space Complexity:
   - O(1), since operations are done in-place.
*/

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int m = part.size();

        // Keep removing until no occurrence left
        while (s.find(part) != string::npos)
        {
            int pos = s.find(part); // find starting index
            s.erase(pos, m);        // erase substring
        }

        return s;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s = "daabcbaabcbc";
    string part = "abc";

    string ans = sol.removeOccurrences(s, part);
    cout << "Final string after removal: " << ans << endl;

    return 0;
}
