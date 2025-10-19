#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode 796. Rotate String
    ---------------------------
    Problem:
        Given two strings s and goal, return true if and only if s can
        become goal after some number of rotations.

        A "rotation" means moving the leftmost character of s
        to the rightmost position.

        Example:
            s = "abcde" → "bcdea" → "cdeab"

    ----------------------------------------------------------------

    ✅ Brute Force Approach:
    ------------------------
    - Start with the original string `s`.
    - Rotate the string left by 1 position, up to `n` times (where n = length of s).
    - After each rotation, check if the new string equals `goal`.
    - If we find a match, return true.
    - If after all rotations no match is found, return false.

    ----------------------------------------------------------------
    Implementation Notes:
    ---------------------
    - We use the STL function `rotate()` from `<algorithm>`:
        rotate(begin, begin+1, end) → rotates left by 1.

    ----------------------------------------------------------------
    Time Complexity:
    ----------------
    - Each rotation takes O(n) (since `rotate` shifts elements).
    - We perform at most n rotations.
    - Each comparison `temp == goal` takes O(n).
    - Total: O(n^2) time.

    Space Complexity:
    -----------------
    - O(n) extra space for storing the rotated string (`temp`).
    - Otherwise O(1) extra space beyond input/output.

    ----------------------------------------------------------------
    This is a brute-force solution. More optimal solutions exist
    (e.g., checking if goal is a substring of s+s → O(n)).
*/

// =========================
// Brute Force Implementation
// =========================
class BruteForceSolution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false; // lengths must match

        string temp = s; // make a copy
        for (int i = 0; i < s.size(); i++)
        {
            // Rotate left by 1
            rotate(temp.begin(), temp.begin() + 1, temp.end());

            // Check after rotation
            if (temp == goal)
                return true;
        }
        return false;
    }
};

/*
 ----------------------------------------------------------------
    ✅ Better Approach (String Concatenation + Substring Search):
    --------------------------------------------------------------
    - Key Observation:
        If `goal` is a rotation of `s`, then it must appear as a substring in `s+s`.

        Example:
            s = "abcde", goal = "cdeab"
            s+s = "abcdeabcde"
            "cdeab" is a substring of "abcdeabcde".

    - Steps:
        1. If `s` and `goal` are of different lengths → return false.
        2. Concatenate string with itself: `s+s`.
        3. Check if `goal` exists inside this concatenated string using `find()`.
        4. If yes → return true, else false.

    ----------------------------------------------------------------
    Time Complexity:
    ----------------
    - Concatenating `s+s` takes O(n).
    - Finding substring (`find`) is O(n) in average case (using efficient algorithms).
    - Total: O(n).

    Space Complexity:
    -----------------
    - O(n) extra space for the concatenated string (`s+s`).
    - No extra data structures used beyond this.

    ----------------------------------------------------------------
    This is much faster than the brute-force O(n^2) approach because
    we avoid repeated rotations and string comparisons.
*/

// =========================
// Better Implementation
// =========================
class BetterSolution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};

// ----------------------
// Driver Code for VS Code
// ----------------------
int main()
{
    string s, goal;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string goal: ";
    cin >> goal;

    BruteForceSolution brute;
    BetterSolution better;

    cout << "\n--- Testing Brute Force Approach ---\n";
    if (brute.rotateString(s, goal))
    {
        cout << "Yes, \"" << s << "\" can be rotated to become \"" << goal << "\" (Brute Force)\n";
    }
    else
    {
        cout << "No, \"" << s << "\" cannot be rotated to become \"" << goal << "\" (Brute Force)\n";
    }

    cout << "\n--- Testing Better Approach ---\n";
    if (better.rotateString(s, goal))
    {
        cout << "✅ Yes, \"" << s << "\" can be rotated to become \"" << goal << "\" (Better)\n";
    }
    else
    {
        cout << "❌ No, \"" << s << "\" cannot be rotated to become \"" << goal << "\" (Better)\n";
    }

    return 0;
}
