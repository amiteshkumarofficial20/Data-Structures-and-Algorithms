#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 125 - Valid Palindrome
------------------------------------------
Given a string s, return true if it is a palindrome,
or false otherwise.

A palindrome is a string that reads the same
forward and backward, ignoring non-alphanumeric
characters and case differences.

-------------------------------------------------------
📝 Brute Force Approach:
-------------------------------------------------------
1. Create a new string (say `filtered`) that contains
   only lowercase alphanumeric characters from the input.
   - Use `isalnum()` to check if a char is alphanumeric.
   - Use `tolower()` to convert to lowercase.

2. Create another string `reversed = filtered`.
   - Use `reverse()` function to reverse `reversed`.

3. Compare `filtered` with `reversed`.
   - If equal → return true
   - Else → return false

⚡ Time Complexity: O(n)
   - Building filtered string = O(n)
   - Reversing string = O(n)
   - Comparing = O(n)

💾 Space Complexity: O(n)
   - Extra string storage for filtered & reversed.
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered = "";

        // Step 1: Keep only lowercase alphanumeric characters
        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered.push_back(tolower(c));
            }
        }

        // Step 2: Make a reversed copy
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        // Step 3: Compare both
        return filtered == reversed;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s = "A man, a plan, a canal: Panama";
    bool ans = sol.isPalindrome(s);

    cout << "Is Palindrome? " << (ans ? "true" : "false") << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 125 - Valid Palindrome
------------------------------------------
Given a string s, return true if it is a palindrome,
or false otherwise.

-------------------------------------------------------
📝 Optimal Approach (Two Pointer):
-------------------------------------------------------
1. Use two pointers:
   - `left = 0` (start of string)
   - `right = n-1` (end of string)

2. While left < right:
   - Skip characters that are not alphanumeric.
     (use isalnum())
   - Convert valid characters to lowercase (use tolower()).
   - Compare:
       - If mismatch → return false
       - If match → move inward (left++, right--)

3. If loop finishes → string is palindrome → return true

⚡ Time Complexity: O(n)
   - Each character checked at most once.

💾 Space Complexity: O(1)
   - No extra string used.
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            // Step 1: Skip non-alphanumeric characters
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }

            // Step 2: Compare after converting to lowercase
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false; // mismatch
            }

            // Step 3: Move inward
            left++;
            right--;
        }

        return true; // all matched
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s = "A man, a plan, a canal: Panama";
    bool ans = sol.isPalindrome(s);

    cout << "Is Palindrome? " << (ans ? "true" : "false") << endl;

    return 0;
}
