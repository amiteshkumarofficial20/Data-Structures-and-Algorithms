#include <bits/stdc++.h>
using namespace std;

/*
 ============================================================================
 LeetCode 13 — Roman to Integer
 ----------------------------------------------------------------------------
 Problem:
   Convert a Roman numeral string into an integer.

 Roman Numeral Rules:
   - Symbols: I=1, V=5, X=10, L=50, C=100, D=500, M=1000
   - Normally, values are summed left to right.
   - Special subtractive rules:
       IV = 4, IX = 9
       XL = 40, XC = 90
       CD = 400, CM = 900
   - Input is guaranteed valid.

 Example:
   Input : "MCMXCIV"
   Output: 1994
   Explanation:
     M   = 1000
     CM  = 900
     XC  = 90
     IV  = 4
     Total = 1994

 ----------------------------------------------------------------------------*/
/*
 ✅ Brute Force Approach (this implementation):
   1. Create a list of all valid Roman numeral tokens, including
      both **subtractive pairs** (like "CM", "IV") and **single letters**.
   2. Always put subtractive pairs BEFORE single characters, so they
      get matched first (e.g., "IV" instead of "I" + "V").
   3. Traverse the string left to right with index i:
        - At each step, try to match the longest possible token
          starting at i (first check "CM","IV", then single letters).
        - If a token matches, add its integer value and advance i
          by token length (1 or 2).
   4. Continue until the entire string is processed.

 Why is this called "brute force"?
   - Because we hardcode all possible tokens (6 subtractive + 7 singles).
   - We sequentially check against this token list at every step.
   - More elegant solutions use hash maps and lookahead subtraction rules.

 ----------------------------------------------------------------------------
 ⏱ Time Complexity:
   - Let n = length of string s.
   - For each character, in the worst case we try up to 13 tokens.
   - Each token check is O(1) (string compare of length ≤ 2).
   - So total = O(13 * n) ≈ O(n).

 💾 Space Complexity:
   - O(1) auxiliary space.
   - Token list is constant-sized (13 items).
   - No extra memory depends on input size.

 ============================================================================
*/

class SolutionBrute
{
public:
    int romanToInt(const string &s)
    {
        int n = s.size();

        // Define all Roman symbols in order (two-char subtractive BEFORE single-char)
        vector<pair<string, int>> tokens = {
            {"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40}, {"IX", 9}, {"IV", 4}, {"M", 1000}, {"D", 500}, {"C", 100}, {"L", 50}, {"X", 10}, {"V", 5}, {"I", 1}};

        int i = 0, result = 0;

        while (i < n)
        {
            bool matched = false;
            // Try to match current substring with all tokens
            for (auto &p : tokens)
            {
                string sym = p.first;
                int len = sym.size();

                // If match found, add its value and move index
                if (i + len <= n && s.substr(i, len) == sym)
                {
                    result += p.second;
                    i += len;
                    matched = true;
                    break;
                }
            }
            // Safety: move forward in case of invalid input (should not happen in valid Roman numerals)
            if (!matched)
                i++;
        }

        return result;
    }
};

// BRUTE-FORCE IDEA (for intuition)
//   --------------------------------
//   - One naive / brute-force way is to check every position and:
//       * First test if a two-character subtractive pair (like "IV") starts at this index.
//       * If yes, add its value and skip two characters.
//       * Otherwise add the single-character value (like 'I'→1) and advance one.
//   - That approach is what many simple solutions implement; it's already O(n).
//   - The code below implements a slightly cleaner / more maintainable version:
//       we store a lookup (unordered_map) of **all** valid tokens (both singles and pairs)
//       and at each step try to match a 2-char token first, then fall back to 1-char.

//   WHY THIS IS "BETTER"
//   ---------------------
//   - The `unordered_map` makes lookups easy and expressive: we don't have long if/else chains.
//   - We attempt the 2-character lookup first (covers subtractive pairs), then the single-char.
//   - This yields clean code that is easy to extend and reason about.

//   COMPLEXITY (summary)
//   --------------------
//   - Let n = s.length().
//   - For each step we perform at most:
//       * one substring of length 2 (O(1) time since small constant length),
//       * an unordered_map lookup (average O(1)).
//   - The pointer advances by 1 or 2 each loop iteration, so overall we do O(n) iterations.
//   - --> **Time Complexity (average)**: O(n)
//   - **Space Complexity (auxiliary)**: O(1) (map size is constant — 13 tokens)

class SolutionBetter
{
public:
    int romanToInt(const string &s)
    {
        // Map Roman symbols to their integer values (both 1-char & 2-char)
        unordered_map<string, int> mp = {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

        int n = s.size();
        int i = 0, ans = 0;

        while (i < n)
        {
            // Try to match two-character symbols first
            if (i + 1 < n)
            {
                string two = s.substr(i, 2);
                auto it = mp.find(two);
                if (it != mp.end())
                {
                    ans += it->second;
                    i += 2;
                    continue;
                }
            }

            // Fallback to single-character symbols
            string one = s.substr(i, 1);
            ans += mp[one];
            i++;
        }

        return ans;
    }
};

/*
============================================================================
✅ Optimal Approach Explanation:
----------------------------------------------------------------------------
Problem:
- Convert a Roman numeral string `s` to its integer equivalent.
- Roman numerals sometimes use subtractive notation:
    e.g., IV = 4 (I before V), IX = 9, XL = 40, etc.

Key Idea (Optimal Single Pass):
1. Map each Roman character to its integer value using an ASCII-indexed array.
2. Traverse the string from left to right:
   - If the current character is **less than the next character**, it's part of a subtractive pair → subtract current value.
   - Else → add current value normally.
3. This handles all cases (additive and subtractive) in a single pass.
4. No need to hardcode all subtractive pairs explicitly.

----------------------------------------------------------------------------
Step-by-Step Example:
s = "MCMXCIV"
Index | Char | Next Char | Action | Accumulator
0     | M    | C         | Add    | 1000
1     | C    | M         | Sub    | 1000 - 100 = 900
2     | M    | X         | Add    | 900 + 1000 = 1900
3     | X    | C         | Sub    | 1900 - 10 = 1890
4     | C    | I         | Add    | 1890 + 100 = 1990
5     | I    | V         | Sub    | 1990 - 1 = 1989
6     | V    | -         | Add    | 1989 + 5 = 1994

----------------------------------------------------------------------------
Time Complexity:
- O(n), where n = length of the input string.
- Each character is visited exactly once.

Space Complexity:
- O(1) auxiliary space:
  - Fixed-size array of 256 integers for lookup.
  - No dynamic memory usage depending on input size.
============================================================================
*/
class SolutionOptimal
{
public:
    int romanToInt(const string &s)
    {
        // Step 1: Create ASCII-indexed lookup array for O(1) access
        int val[256] = {0};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int n = s.size();
        int ans = 0;

        // Step 2: Single pass left-to-right
        for (int i = 0; i < n; ++i)
        {
            // Subtractive case: if current < next → subtract
            if (i + 1 < n && val[(unsigned char)s[i]] < val[(unsigned char)s[i + 1]])
                ans -= val[(unsigned char)s[i]];
            else
                ans += val[(unsigned char)s[i]]; // Normal addition
        }

        return ans;
    }
    // Time Complexity: O(n) → single traversal
    // Space Complexity: O(1) → fixed array size 256
};

// ===========================
// Main Function for Testing
// ===========================
int main()
{
    vector<string> tests = {"III", "LVIII", "MCMXCIV"};

    SolutionBrute brute;
    SolutionBetter better;
    SolutionOptimal optimal;

    cout << "=== Brute Force Results ===\n";
    for (auto &t : tests)
        cout << t << " -> " << brute.romanToInt(t) << "\n";

    cout << "\n=== Better Approach Results ===\n";
    for (auto &t : tests)
        cout << t << " -> " << better.romanToInt(t) << "\n";

    cout << "\n=== Optimal Approach Results ===\n";
    for (auto &t : tests)
        cout << t << " -> " << optimal.romanToInt(t) << "\n";

    return 0;
}
