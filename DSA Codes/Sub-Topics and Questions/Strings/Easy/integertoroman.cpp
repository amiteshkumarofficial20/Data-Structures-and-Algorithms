/*
LeetCode Problem: 12. Integer to Roman
Difficulty: Medium
Topics: Math, String, Simulation
Companies: Amazon, Microsoft, Google, Adobe

Problem Statement:
Given an integer, convert it to a Roman numeral.
Roman numerals are represented by symbols: I(1), V(5), X(10), L(50), C(100), D(500), M(1000).
Subtractive forms: IV(4), IX(9), XL(40), XC(90), CD(400), CM(900)
1 <= num <= 3999

Example 1:
Input: num = 3
Output: "III"

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: 50 = L, 8 = VIII

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: 1000 = M, 900 = CM, 90 = XC, 4 = IV
*/

/*
LeetCode Problem: 12. Integer to Roman
Difficulty: Medium
Topics: Math, String, Simulation
Companies: Amazon, Microsoft, Google, Adobe

Problem Statement:
Given an integer, convert it to a Roman numeral.
Roman numerals symbols: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
Subtractive forms: IV(4), IX(9), XL(40), XC(90), CD(400), CM(900)
1 <= num <= 3999

Example 1:
Input: num = 3
Output: "III"

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: 50 = L, 8 = VIII

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: 1000 = M, 900 = CM, 90 = XC, 4 = IV
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // =======================
    // 1. Brute-force Approach
    // Explicit handling of each decimal place (thousands, hundreds, tens, ones)
    // =======================
    string bruteIntToRoman(int num)
    {
        string res;

        // Thousands
        int t = num / 1000;
        for (int i = 0; i < t; ++i)
            res += 'M';
        num %= 1000;

        // Hundreds
        int h = num / 100;
        if (h == 9)
            res += "CM";
        else if (h >= 5)
        {
            res += 'D';
            for (int i = 0; i < h - 5; ++i)
                res += 'C';
        }
        else if (h == 4)
            res += "CD";
        else
            for (int i = 0; i < h; ++i)
                res += 'C';
        num %= 100;

        // Tens
        int te = num / 10;
        if (te == 9)
            res += "XC";
        else if (te >= 5)
        {
            res += 'L';
            for (int i = 0; i < te - 5; ++i)
                res += 'X';
        }
        else if (te == 4)
            res += "XL";
        else
            for (int i = 0; i < te; ++i)
                res += 'X';
        num %= 10;

        // Ones
        int o = num;
        if (o == 9)
            res += "IX";
        else if (o >= 5)
        {
            res += 'V';
            for (int i = 0; i < o - 5; ++i)
                res += 'I';
        }
        else if (o == 4)
            res += "IV";
        else
            for (int i = 0; i < o; ++i)
                res += 'I';

        return res;
    }

    /*
    Brute-force:
    Time Complexity: O(1) -> only 4 digits, loops max 3 iterations each
    Space Complexity: O(1) extra (excluding output string)
    */

    // =======================
    // 2. Digit-mapping Approach (Better)
    // Precompute strings for each place value
    // =======================
    string mapIntToRoman(int num)
    {
        vector<string> thousands = {"", "M", "MM", "MMM"};
        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return thousands[num / 1000] +
               hundreds[(num % 1000) / 100] +
               tens[(num % 100) / 10] +
               ones[num % 10];
    }

    /*
    Digit-mapping:
    Time Complexity: O(1) -> fixed 4 array lookups
    Space Complexity: O(1) extra -> 4 arrays
    */

    // =======================
    // 3. Greedy Approach (Optimal)
    // Use value-symbol pairs, subtract largest possible repeatedly
    // =======================
    string intToRoman(int num)
    {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        for (int i = 0; i < val.size(); i++)
        {
            int count = num / val[i]; // How many times current symbol fits
            num %= val[i];            // Reduce remaining number
            while (count--)
                res += sym[i]; // Append symbol 'count' times
        }
        return res;
    }

    /*
    Greedy:
    Time Complexity: O(1) -> max 13 symbols, at most ~15 appends
    Space Complexity: O(1) extra -> 2 arrays + output string
    */
};

// =======================
// Test all three approaches
// =======================
int main()
{
    Solution sol;
    vector<int> testCases = {3, 4, 9, 58, 1994, 3749};

    cout << "==== Brute-force ====" << endl;
    for (int n : testCases)
        cout << n << " -> " << sol.bruteIntToRoman(n) << endl;

    cout << "\n==== Digit-mapping ====" << endl;
    for (int n : testCases)
        cout << n << " -> " << sol.mapIntToRoman(n) << endl;

    cout << "\n==== Greedy (Optimal) ====" << endl;
    for (int n : testCases)
        cout << n << " -> " << sol.intToRoman(n) << endl;

    return 0;
}

/*
Sample Output:
==== Brute-force ====
3    -> III
4    -> IV
9    -> IX
58   -> LVIII
1994 -> MCMXCIV
3749 -> MMMDCCXLIX

==== Digit-mapping ====
3    -> III
4    -> IV
9    -> IX
58   -> LVIII
1994 -> MCMXCIV
3749 -> MMMDCCXLIX

==== Greedy (Optimal) ====
3    -> III
4    -> IV
9    -> IX
58   -> LVIII
1994 -> MCMXCIV
3749 -> MMMDCCXLIX
*/

/*
Detailed Notes Summary for Integer to Roman Conversion:

1. Brute-force Approach:
   - Approach:
       * Explicitly handle each decimal place separately: thousands, hundreds, tens, ones.
       * For each place, check special cases first:
           - 9: Use subtractive form (e.g., 900 -> "CM")
           - 5-8: Use 5-symbol + repeat 1-symbol (e.g., 700 -> "DCC")
           - 4: Use subtractive form (e.g., 400 -> "CD")
           - 1-3: Repeat 1-symbol as needed (e.g., 300 -> "CCC")
       * Concatenate results from thousands → hundreds → tens → ones.
   - Time Complexity: O(1)
       * Maximum input is 3999 → 4 digits only.
       * Loops iterate at most 3 times per digit place.
   - Space Complexity: O(1) extra
       * Only a string for result is used; no extra data structures.
   - Pros:
       * Good for learning the rules of Roman numerals step by step.
       * Shows a clear understanding of how each digit contributes to the Roman numeral.
   - Cons:
       * Verbose and repetitive code.
       * Hard to maintain and prone to mistakes.
       * Not elegant or scalable.
   - Usage:
       * Educational purposes or when learning the basics.
       * Rarely recommended in interviews.

2. Digit-mapping Approach (Better):
   - Approach:
       * Precompute arrays for each digit place:
           - Thousands: ["", "M", "MM", "MMM"]
           - Hundreds: ["", "C", "CC", ..., "CM"]
           - Tens: ["", "X", "XX", ..., "XC"]
           - Ones: ["", "I", "II", ..., "IX"]
       * Index directly into arrays using division and modulus operations.
       * Concatenate the results for final Roman numeral.
   - Time Complexity: O(1)
       * Only 4 array lookups and concatenations.
   - Space Complexity: O(1) extra
       * Four small arrays + output string.
   - Pros:
       * Very clean, concise, and easy to read.
       * Avoids multiple if/else conditions and loops.
       * Easy to implement quickly.
   - Cons:
       * Slightly less flexible if rules of numerals change.
   - Usage:
       * Recommended for coding tests and practical implementations.
       * Quick, reliable, and readable.

3. Greedy Approach (Optimal):
   - Approach:
       * Maintain a list of all value-symbol pairs sorted in descending order:
         [(1000,"M"), (900,"CM"), (500,"D"), ..., (1,"I")]
       * Iterate through the list:
           - Determine how many times the current value fits into the number.
           - Append the corresponding symbol that many times.
           - Reduce the number accordingly.
       * Automatically handles subtractive forms like IV, IX, XL, etc.
   - Time Complexity: O(1)
       * Fixed number of value-symbol pairs (13 pairs), input <= 3999.
   - Space Complexity: O(1) extra
       * Two arrays + output string.
   - Pros:
       * Elegant and canonical solution.
       * Handles subtractive forms naturally without extra logic.
       * Easy to explain in interviews.
       * Scales well if extended to other numeral systems.
   - Cons:
       * Slightly more memory (arrays) than digit-mapping, but negligible.
   - Usage:
       * Most common solution in interviews.
       * Preferred for its readability, elegance, and flexibility.

Key Idea / Summary:
- All three approaches produce the same correct Roman numeral for any input in range 1..3999.
- Choice depends on:
    * Brute-force → Learning rules, step-by-step understanding.
    * Digit-mapping → Short, clean, and suitable for quick coding.
    * Greedy → Optimal, canonical, interview-friendly, scalable.
- Time & Space Complexity Comparison:
    * All approaches: O(1) time and O(1) extra space due to bounded input.
- Recommendation:
    * Use Greedy for interviews.
    * Use Digit-mapping for coding tests.
    * Use Brute-force only for educational purposes.
*/
