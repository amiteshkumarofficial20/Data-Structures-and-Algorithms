#include <bits/stdc++.h>
using namespace std;

/*
    --------------------------------------------------------------------
    LeetCode 1781. Sum of Beauty of All Substrings
    --------------------------------------------------------------------
    Problem:
    - For a given string s, calculate the "beauty" of each substring.
    - The beauty of a substring = (maximum frequency of any character)
                                  - (minimum frequency of any character).
    - Only consider characters with frequency > 0 for min frequency.
    - Return the sum of beauty of all substrings.

    Example:
    Input: s = "aabcb"
    Substrings and beauties:
        "a"       -> max=1, min=1 -> beauty=0
        "aa"      -> max=2, min=2 -> beauty=0
        "aab"     -> max=2, min=1 -> beauty=1
        "aabc"    -> max=2, min=1 -> beauty=1
        "aabcb"   -> max=2, min=1 -> beauty=1
        ...
    Total beauty = 5

    --------------------------------------------------------------------
    Brute Force Approach:
    - Generate every substring s[i..j].
    - For each substring, calculate frequency of characters.
    - Find maximum and minimum frequency in that substring.
    - Add (max - min) to the total.

    Steps:
    1. Outer loop: fix start index i
    2. Inner loop: fix end index j
    3. Another loop: count frequencies in substring s[i..j]
    4. Find max and min frequency among non-zero entries
    5. Add to answer

    --------------------------------------------------------------------
    Time Complexity:
    - There are O(n^2) substrings.
    - For each substring, we count frequencies → O(n).
    - So overall = O(n^3), where n = length of string.
    - Works only for small n (up to ~200).

    Space Complexity:
    - O(26) = O(1), since frequency array size is fixed (26 lowercase letters).

    --------------------------------------------------------------------
    This is the pure brute force approach (inefficient but simple).
*/

class BruteForceSolution
{
public:
    int beautySum(const string &s)
    {
        int n = (int)s.size();
        long long total = 0;

        // For every possible substring s[i..j]
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                // Count frequencies from scratch for substring s[i..j]
                int freq[26] = {0};
                for (int k = i; k <= j; ++k)
                {
                    freq[s[k] - 'a']++;
                }

                // Find max and min among characters that appear
                int mx = 0;
                int mn = INT_MAX;
                for (int t = 0; t < 26; ++t)
                {
                    if (freq[t] > 0)
                    {
                        mx = max(mx, freq[t]);
                        mn = min(mn, freq[t]);
                    }
                }

                // Add beauty for this substring
                if (mn != INT_MAX)
                    total += (mx - mn);
            }
        }

        return (int)total;
    }
};

/* =========================================================================
   This "Better" solution:
    - For every starting index i, we expand the end j from i..n-1.
    - Maintain a frequency array freq[26] for substring s[i..j] incrementally:
        when j increases by 1, only update freq[s[j]]++.
    - At each extension (for fixed i and current j) compute:
        mx = max(freq[0..25]) among >0 entries
        mn = min(freq[0..25]) among >0 entries
      and add (mx - mn) to the running total.
    - This avoids recomputing the entire frequency table from scratch for each substring,
      unlike the O(n^3) brute force which recounts characters for each substring.

  Complexity:
    - Time: O(n^2 * 26) = O(n^2) (26 is constant; for each pair (i,j) we scan 26 letters to get mx/mn)
    - Space: O(26) = O(1) (fixed-size frequency array)

  Notes:
    - Good compromise between simplicity and performance for typical constraints (n up to few thousands).
    - For very large n further micro-optimizations or advanced techniques are required.
*/
class BetterSolution
{
public:
    int beautySum(const string &s)
    {
        int n = (int)s.size();
        long long total = 0;

        // Fix start index i and expand j
        for (int i = 0; i < n; ++i)
        {
            int freq[26] = {0}; // freq for substring s[i..j]
            for (int j = i; j < n; ++j)
            {
                // Increment character included at position j
                freq[s[j] - 'a']++;

                // Compute current max and min among present characters
                int mx = 0;
                int mn = INT_MAX;
                for (int c = 0; c < 26; ++c)
                {
                    int f = freq[c];
                    if (f > 0)
                    {
                        mx = max(mx, f);
                        mn = min(mn, f);
                    }
                }

                // Add beauty of s[i..j]
                if (mn != INT_MAX)
                    total += (mx - mn);
            }
        }

        return (int)total;
    }
};

/* =========================================================================
    ------------------------------------------------
  🔹 Optimal Approach (using multiset for dynamic min/max tracking):

  - For every starting index i:
      * Initialize a frequency array freq[26] = {0}.
      * Also maintain a multiset<int> freqSet to store nonzero frequencies.
      * Expand end index j = i..n-1:
          - Increase frequency of s[j].
          - Update freqSet accordingly:
              • If freq[c] was >0, remove old freq before increment.
              • Insert updated freq[c].
          - Then beauty = (*rbegin(freqSet) - *begin(freqSet)).
          - Add this to total.

  Why is this better?
  - No need to rescan 26 characters for each extension.
  - Multiset always gives O(1) min and max access, O(log 26) insertion/removal.
  - Since alphabet size is fixed small (26), it’s effectively constant overhead.

  ------------------------------------------------
  Time Complexity:
    - Outer loop: O(n) start positions.
    - Inner loop: O(n) extensions.
    - Each update in multiset: O(log 26) ≈ O(1).
    - Total: O(n^2).

  Space Complexity:
    - O(26) for frequency array.
    - O(26) for multiset (max 26 distinct chars).
    - Overall O(1) auxiliary space.
*/

class OptimalSolution
{
public:
    int beautySum(const string &s)
    {
        int n = (int)s.size();
        long long total = 0;

        for (int i = 0; i < n; ++i)
        {
            int freq[26] = {0};
            multiset<int> freqSet; // keeps current non-zero frequencies sorted

            for (int j = i; j < n; ++j)
            {
                int idx = s[j] - 'a';

                // If character had a previous (nonzero) frequency, erase one instance from multiset
                if (freq[idx] > 0)
                {
                    auto it = freqSet.find(freq[idx]);
                    // it should be found (we only remove when >0)
                    if (it != freqSet.end())
                        freqSet.erase(it);
                }

                // Increase freq and insert updated value
                freq[idx]++;
                freqSet.insert(freq[idx]);

                // freqSet contains frequencies of characters that have appeared in current substring.
                // min = *begin(), max = *rbegin()
                // Safety: freqSet must not be empty because j >= i => at least one character present
                int mn = *freqSet.begin();
                int mx = *freqSet.rbegin();

                total += (mx - mn);
            }
        }

        return (int)total;
    }
};

/* =========================================================================
   Driver / Test harness
   - Runs the three approaches on sample inputs and prints results.
   - Note: BruteForceSolution will be slow for n beyond small values (e.g. > 150-200).
   ------------------------------------------------------------------------- */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Sample test cases
    vector<string> tests = {
        "aabcb",   // expected 5
        "aabcbaa", // another sample to compare
        "abc",     // small example
        "aaaa"     // all same char -> all beauties 0
    };

    cout << "LeetCode 1781 — Sum of Beauty of All Substrings\n";
    cout << "------------------------------------------------\n\n";

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution opt;

    for (auto &s : tests)
    {
        cout << "Input: \"" << s << "\"\n";

        // Brute: warn that it is slow if s is large
        if (s.size() <= 10)
        { // keep brute for only tiny strings in demo
            cout << "  [Brute Force]   beautySum = " << brute.beautySum(s)
                 << "    (Time: O(n^3), Space: O(1))\n";
        }
        else
        {
            cout << "  [Brute Force]   SKIPPED (too slow for n = " << s.size() << ")\n";
        }

        cout << "  [Better]        beautySum = " << better.beautySum(s)
             << "    (Time: O(n^2 * 26) ≈ O(n^2), Space: O(1))\n";

        cout << "  [Optimal]       beautySum = " << opt.beautySum(s)
             << "    (Time: O(n^2 * log k) ≈ O(n^2), Space: O(1))\n";

        cout << "\n";
    }

    cout << "Notes:\n";
    cout << "- Brute is easiest to understand but only for tiny inputs (n small).\n";
    cout << "- Better reuses freq[] per start index i and scans 26 letters each extension.\n";
    cout << "- Optimal keeps a multiset of nonzero frequencies to retrieve min/max instantly.\n";
    cout << "- For lowercase English letters both Better and Optimal are effectively O(n^2).\n";

    return 0;
}
