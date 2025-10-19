#include <bits/stdc++.h>
using namespace std;

/*
    Problem: 205. Isomorphic Strings (LeetCode - Easy)
    -------------------------------------------------
    Two strings s and t are isomorphic if:
      - The characters in s can be replaced to get t.
      - Each character must map to another character consistently.
      - No two characters may map to the same character,
        but a character may map to itself.

    Example 1:
    Input: s = "egg", t = "add"
    Output: true
    Explanation: 'e' -> 'a', 'g' -> 'd'

    Example 2:
    Input: s = "foo", t = "bar"
    Output: false

    Example 3:
    Input: s = "paper", t = "title"
    Output: true
*/

/*
    Approach: Brute Force Check (Nested Loops)
    -----------------------------------------
    - Compare every pair of characters (s[i], s[j]) and (t[i], t[j]).
    - If two characters in s are same, then t[i] and t[j] must also be same.
    - If two characters in s are different, then t[i] and t[j] must also be different.
    - If either condition fails, return false.
    - If no conflicts are found after checking all pairs, return true.

    Example Walkthrough:
    s = "egg", t = "add"
    i=0,j=1 → s[0]='e',s[1]='g' → diff, t[0]='a',t[1]='d' → diff ✔
    i=1,j=2 → s[1]='g',s[2]='g' → same, t[1]='d',t[2]='d' → same ✔
    → return true.

    Time Complexity:
    - O(n^2): double loop comparing all pairs.
    Space Complexity:
    - O(1): no extra data structures used.
*/

class BruteForce
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        if (n != t.size())
            return false;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // If two characters in s are same, then corresponding t must also match
                if (s[i] == s[j] && t[i] != t[j])
                    return false;

                // If two characters in s are different, then corresponding t must also be different
                if (s[i] != s[j] && t[i] == t[j])
                    return false;
            }
        }
        return true;
    }
};

/*
    ✅ Approach: Hash Maps for Both Directions
    ------------------------------------------
    - If we only map s → t, it may fail when multiple chars map to the same target.
      Example: s="ab", t="cc". If we only check s→t, it looks okay, but it's WRONG.
    - Therefore, we need **two mappings**:
        1. s_to_t: maps char in s → char in t
        2. t_to_s: maps char in t → char in s
    - While iterating:
        - If s[i] already mapped to some char but it's different from t[i], return false.
        - If t[i] already mapped to some char but it's different from s[i], return false.
        - Otherwise, establish the mapping both ways.
    - If we complete the loop, strings are isomorphic.

    ✅ Example Walkthrough:
    s = "egg", t = "add"
    i=0: 'e' → 'a', store mappings.
    i=1: 'g' → 'd', store mappings.
    i=2: 'g' → 'd' already consistent ✔
    → return true.

    ✅ Time Complexity:
    - O(n), where n = length of strings.
      Each lookup/insert in unordered_map is O(1) average.
    ✅ Space Complexity:
    - O(1), since there can be at most 26 mappings (for lowercase letters),
      or O(charset) in general (usually 256 for ASCII).
*/

class HashMapApproach
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i], b = t[i];

            // Check mapping from s -> t
            if (s_to_t.find(a) != s_to_t.end() && s_to_t[a] != b)
                return false;

            // Check mapping from t -> s
            if (t_to_s.find(b) != t_to_s.end() && t_to_s[b] != a)
                return false;

            s_to_t[a] = b;
            t_to_s[b] = a;
        }
        return true;
    }
};

/*
 ✅ Approach: Using Fixed-size Arrays (Better than Hash Maps)
    ------------------------------------------------------------
    - Instead of using unordered_map (which has hashing overhead),
      we can directly use two arrays of size 256 (for ASCII).
    - s_map[a] stores the character in t that 'a' in s should map to.
    - t_map[b] stores the character in s that 'b' in t should map to.
    - If a mapping does not exist yet, initialize it.
    - If a mapping exists, it must be consistent; otherwise return false.

    ✅ Why 256?
    - To cover all possible ASCII characters (not just lowercase).
    - Works for general cases, not limited to 'a'-'z'.

    ✅ Example:
    s = "egg", t = "add"
    i=0: s_map['e'] = 'a', t_map['a'] = 'e'
    i=1: s_map['g'] = 'd', t_map['d'] = 'g'
    i=2: 'g' → 'd' already consistent ✔
    → return true.

    ✅ Time Complexity: O(n)
    - Just one scan through the strings, with O(1) array lookups.
    ✅ Space Complexity: O(1)
    - Two arrays of size 256 → constant space.
*/

class ArrayApproach
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        // Initialize 2 mapping arrays for ASCII chars
        vector<int> s_map(256, -1);
        vector<int> t_map(256, -1);

        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i], b = t[i];

            // If no mapping exists, create one
            if (s_map[a] == -1 && t_map[b] == -1)
            {
                s_map[a] = b;
                t_map[b] = a;
            }
            // If mapping exists, check consistency
            else if (s_map[a] != b || t_map[b] != a)
            {
                return false;
            }
        }
        return true;
    }
};

// ------------------------------------------------------------
// Main function for testing all approaches
// ------------------------------------------------------------
int main()
{
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    BruteForce brute;
    HashMapApproach hashmap;
    ArrayApproach array;

    cout << "\n[Approach 1: Brute Force] → "
         << (brute.isIsomorphic(s, t) ? "Isomorphic" : "Not Isomorphic") << endl;

    cout << "[Approach 2: Hash Map] → "
         << (hashmap.isIsomorphic(s, t) ? "Isomorphic" : "Not Isomorphic") << endl;

    cout << "[Approach 3: Array] → "
         << (array.isIsomorphic(s, t) ? "Isomorphic" : "Not Isomorphic") << endl;

    return 0;
}
