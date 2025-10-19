#include <bits/stdc++.h>
using namespace std;

/*
🔹 Problem: LeetCode 151 - Reverse Words in a String
----------------------------------------------------
Given an input string s, reverse the order of the words.

Rules:
- A word is defined as a sequence of non-space characters.
- Multiple spaces may exist between words.
- Return the string with words in reverse order, separated by a single space.

Example:
--------
Input:  s = "  the   sky is   blue "
Output: "blue is sky the"

----------------------------------------------------
📝 Approach (Using stringstream + vector + reverse):
----------------------------------------------------
1. Use stringstream to split the input string into words.
   - stringstream automatically skips multiple spaces.
   - Each word is pushed into a vector<string>.

2. Reverse the vector of words.

3. Concatenate the reversed words into a new string,
   separated by a single space.

----------------------------------------------------
⚡ Complexity:
- Splitting words → O(n)
- Reversing vector → O(k) where k = number of words
- Building result → O(n)
Total Time = O(n)
Space = O(n) (for storing words in vector)
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s); // Create stringstream from input string
        string word;
        vector<string> words;

        // Extract words from the stringstream (ignores multiple spaces)
        while (ss >> word)
        {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join words into final result string
        string result;
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i < words.size() - 1)
                result += " "; // add space between words
        }

        return result;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s = "  the   sky is   blue ";
    string ans = sol.reverseWords(s);

    cout << "Reversed Words: \"" << ans << "\"" << endl;

    return 0;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// 📝 Optimal In - Place Approach(O(n) time, O(1) space) : -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --We avoid extra data structures(like vector<string>) by working directly on the string.

//                                                          Steps : 1. Reverse the entire string.-
//     Example : "the sky" → "yks eht"

//               2. Reverse each word individually to restore proper word order.-
//     After step 1 : "yks eht" - After step 2 : "sky the"

//                                               3. Remove extra spaces(in - place) : -Trim leading / trailing spaces.-
//                    Reduce multiple spaces to a single space.

//                    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// ⚡ Complexity : -Reversing full string : O(n) -
//                    Reversing each word : O(n) - Cleaning spaces : O(n) Total Time = O(3n) ≈ O(n)
//     Space = O(1)(in - place) * /

class Solution
{
public:
    string reverseWords(string s)
    {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0, right = 0;

        // Step 2: Reverse each word back to correct orientation
        while (left < n)
        {
            // Skip spaces to find the start of a word
            while (left < n && s[left] == ' ')
                left++;

            right = left;
            // Move until we reach a space or end of string
            while (right < n && s[right] != ' ')
                right++;

            // Reverse this word (from left to right-1)
            reverse(s.begin() + left, s.begin() + right);

            // Move left to the end of this word
            left = right;
        }

        // Step 3: Clean spaces (remove leading, trailing, multiple spaces)
        int i = 0, j = 0;
        while (i < n)
        {
            // Skip extra spaces
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n)
                break;

            // Insert one space between words (not before the first word)
            if (j > 0)
                s[j++] = ' ';

            // Copy the current word
            while (i < n && s[i] != ' ')
            {
                s[j++] = s[i++];
            }
        }

        // Resize string to remove trailing characters
        s.resize(j);

        return s;
    }
};

// ---------------- For VS Code Testing ----------------
int main()
{
    Solution sol;

    string s = "  the   sky is   blue ";
    string ans = sol.reverseWords(s);

    cout << "Reversed Words: \"" << ans << "\"" << endl;

    return 0;
}