#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode 242. Valid Anagram
    ----------------------------
    Problem:
        Given two strings s and t, return true if t is an anagram of s,
        and false otherwise.

        An anagram is a word or phrase formed by rearranging the
        letters of a different word/phrase, using all the original
        letters exactly once.

    Example 1:
        Input: s = "anagram", t = "nagaram"
        Output: true

    Example 2:
        Input: s = "rat", t = "car"
        Output: false

    Constraints:
        - 1 <= s.length, t.length <= 5 * 10^4
        - Strings contain only lowercase English letters.

    ---------------------------------------------------------
    ✅ Brute Force Approach (Sorting Both Strings)
    ---------------------------------------------------------
    Idea:
        - If two strings are anagrams, then after sorting
          their characters, both strings should be identical.
        - Steps:
            1. If lengths differ → immediately return false.
            2. Sort both strings.
            3. Compare them directly.
            4. If equal → return true, else false.

    ---------------------------------------------------------
    Time Complexity:
        - Sorting takes O(n log n) for each string (n = length).
        - Total: O(n log n).

    Space Complexity:
        - O(1) extra space (in-place sort).
        - Only minor variables used.

    ---------------------------------------------------------
    Note:
        This is a brute force approach.
        A better O(n) solution exists using frequency counts (hashmap/array),
        but sorting is the simplest brute solution.
*/

// -------------------------
// 1. Brute Force Approach
// -------------------------
class SolutionBrute
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Compare sorted versions
        return s == t;
    }
};

/*
 ---------------------------------------------------------
    ✅ Better Approach (Hash Map / Frequency Count)
    ---------------------------------------------------------
    Idea:
        - Instead of sorting (O(n log n)), we can count frequencies of characters.
        - If two strings are anagrams, they must have the exact same frequency
          of each character.

        Steps:
            1. If lengths differ → immediately return false.
            2. Count character frequencies for both strings.
            3. Compare the two frequency maps.
            4. If equal → return true, else false.

    ---------------------------------------------------------
    Time Complexity:
        - Counting characters in s → O(n).
        - Counting characters in t → O(n).
        - Comparing hash maps → O(n) in worst case.
        - Total: O(n).

    Space Complexity:
        - O(1) if input limited to lowercase English (26 letters).
        - O(k) if generalized for all characters, where k = charset size.
        - In this implementation → unordered_map<char,int> used,
          so space depends on number of distinct characters.

    ---------------------------------------------------------
    This is better than the brute-force (sorting) approach
    since it avoids O(n log n) sorting and achieves O(n).
*/
// -------------------------
// 2. Better Approach (HashMap)
// -------------------------
class SolutionBetter
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> freqS, freqT;

        // Count characters in both strings
        for (char c : s)
            freqS[c]++;
        for (char c : t)
            freqT[c]++;

        // Compare both maps
        return freqS == freqT;
    }
};

/*
---------------------------------------------------------
    ✅ Optimal Approach (Fixed-size Frequency Array)
    ---------------------------------------------------------
    Idea:
        - Since input only contains lowercase English letters (26 total),
          we don’t need an unordered_map.
        - Instead, we can use a fixed-size integer array of size 26
          to store character counts.
        - Increment count for each character in `s` and decrement
          for each character in `t`.
        - Finally, check if all counts are zero.

        If yes → strings are anagrams.
        If no → not anagrams.

    ---------------------------------------------------------
    Why Optimal?
        - Avoids sorting (O(n log n)).
        - Avoids hash map overhead.
        - Constant space since only 26 letters.

    ---------------------------------------------------------
    Time Complexity:
        - O(n) to scan through both strings.
        - O(26) to check counts → O(1).
        - Total: O(n).

    Space Complexity:
        - O(1) → fixed-size array of 26 integers.

    ---------------------------------------------------------
    This is the most efficient solution for this problem.
*/
// -------------------------
// 3. Optimal Approach (Fixed-size Array)
// -------------------------
class SolutionOptimal
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int count[26] = {0};

        // Increment for s, decrement for t
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // Check if all counts are zero
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};

// -------------------------
// Driver Code for VS Code
// -------------------------
int main()
{
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    // Brute Force
    SolutionBrute bruteSol;
    cout << "\n[Brute Force: Sorting]\n";
    if (bruteSol.isAnagram(s, t))
        cout << "✅ Yes, \"" << t << "\" is an anagram of \"" << s << "\"\n";
    else
        cout << "❌ No, \"" << t << "\" is NOT an anagram of \"" << s << "\"\n";

    // Better
    SolutionBetter betterSol;
    cout << "\n[Better: HashMap]\n";
    if (betterSol.isAnagram(s, t))
        cout << "✅ Yes, \"" << t << "\" is an anagram of \"" << s << "\"\n";
    else
        cout << "❌ No, \"" << t << "\" is NOT an anagram of \"" << s << "\"\n";

    // Optimal
    SolutionOptimal optimalSol;
    cout << "\n[Optimal: Fixed Array]\n";
    if (optimalSol.isAnagram(s, t))
        cout << "✅ Yes, \"" << t << "\" is an anagram of \"" << s << "\"\n";
    else
        cout << "❌ No, \"" << t << "\" is NOT an anagram of \"" << s << "\"\n";

    return 0;
}
