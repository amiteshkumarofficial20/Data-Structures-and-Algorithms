#include <bits/stdc++.h>
using namespace std;

/*
    ------------------------------------------------------
    LeetCode 8. String to Integer (atoi)
    ------------------------------------------------------
    Problem:
    Implement the function `myAtoi(string s)` that converts
    a string to a 32-bit signed integer.

    Rules:
    1. Ignore leading whitespaces.
    2. Optional '+' or '-' for sign.
    3. Read digits until non-digit encountered.
    4. Clamp result to INT_MIN (-2^31) or INT_MAX (2^31-1).
    5. If no valid conversion, return 0.

    Example:
        Input: "   -42"
        Output: -42

        Input: "4193 with words"
        Output: 4193

        Input: "words and 987"
        Output: 0

    ------------------------------------------------------
    ✅ Brute Force Approach (Using string + stoll)
    ------------------------------------------------------
    - Step 1: Skip leading whitespaces.
    - Step 2: Handle sign if '+' or '-'.
    - Step 3: Collect digits into a temporary string.
    - Step 4: Convert collected string into a number using stoll.
    - Step 5: Multiply by sign, and clamp if overflow.

    ------------------------------------------------------
    Time Complexity:
    ----------------
    - O(n) to scan string and build digit string.
    - Conversion (stoll) is O(k), where k = number of digits.
    - Total: O(n).

    Space Complexity:
    -----------------
    - O(k) for storing the digit substring.
    - Otherwise O(1).
*/

class SolutionBrute
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return 0; // string empty after spaces

        // Step 2: Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Collect digits into a string
        string numStr = "";
        while (i < n && isdigit(s[i]))
        {
            numStr.push_back(s[i]);
            i++;
        }

        // Step 4: If no digits found
        if (numStr.empty())
            return 0;

        // Step 5: Convert string → long long
        long long num = stoll(numStr) * sign;

        // Step 6: Clamp result
        if (num < INT_MIN)
            return INT_MIN;
        if (num > INT_MAX)
            return INT_MAX;

        return (int)num;
    }
};

/*
 ------------------------------------------------------
    ✅ Better Approach (Digit-by-digit conversion with overflow check)
    ------------------------------------------------------
    - Instead of building a temporary string and then converting
      (Brute Force), we directly build the number digit by digit.
    - At every step, we check for overflow before multiplying by 10.

    Steps:
    1. Skip leading spaces.
    2. Handle sign (+ or -).
    3. Traverse digits and update result.
    4. Before updating, check if `num * 10 + digit` would overflow.
       - If it would, clamp to INT_MAX or INT_MIN.
    5. Multiply by sign and return.

    ------------------------------------------------------
    Example:
        Input: "   -42"
        Process: skip spaces → sign = -1 → digits "42"
        Result = -42

        Input: "4193 with words"
        Process: digits "4193" then stop
        Result = 4193

        Input: "-91283472332"
        Process: number too small → clamp to INT_MIN

    ------------------------------------------------------
    Time Complexity:
    ----------------
    - O(n), where n = length of input string
      (we scan string once, each character processed once).

    Space Complexity:
    -----------------
    - O(1), only a few variables used.

    ------------------------------------------------------
    This is more efficient and safer than Brute Force
    (no extra string, no stoll usage).
*/

class SolutionBetter
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return 0;

        // Step 2: Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Parse digits into num
        long num = 0; // using long to detect overflow
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // Step 4: Check overflow before multiplying
            if (num > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return (int)(num * sign);
    }
};

/*
    ------------------------------------------------------
    ✅ Optimal Approach (Direct digit parsing with constant-time overflow check)
    ------------------------------------------------------
    - We don’t use extra strings (unlike Brute Force).
    - We don’t use `long long` except temporarily (like Better).
    - Instead, we directly check overflow using INT_MAX and INT_MIN limits.

    Key Overflow Logic:
    -------------------
    If current `num` > INT_MAX / 10 OR
       (num == INT_MAX / 10 AND digit > 7)   // because INT_MAX = 2147483647
       → Overflow occurs.

    - For positive → return INT_MAX
    - For negative → return INT_MIN

    ------------------------------------------------------
    Time Complexity:
    ----------------
    - O(n), where n = length of string
      (each character visited at most once).

    Space Complexity:
    -----------------
    - O(1), only variables used (num, sign, index).

    ------------------------------------------------------
    This is the most efficient and clean solution.
*/
class SolutionOptimal
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.size();
        long num = 0; // result under construction
        int sign = 1;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Handle sign
        if (i < n)
        {
            if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            else if (s[i] == '+')
            {
                i++;
            }
        }

        // Step 3: Parse digits directly
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // Step 4: Overflow detection trick
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return (int)(num * sign);
    }
};

// ============================================================================
// Driver Code for Testing All 3 Approaches
// ============================================================================
int main()
{
    vector<string> testCases = {
        "42",              // 42
        "   -42",          // -42
        "4193 with words", // 4193
        "words and 987",   // 0
        "-91283472332",    // INT_MIN
        "2147483648",      // INT_MAX
        "-2147483649"      // INT_MIN
    };

    cout << "----- Brute Force -----" << endl;
    SolutionBrute brute;
    for (auto &s : testCases)
    {
        cout << "Input: \"" << s << "\" -> Output: " << brute.myAtoi(s) << endl;
    }

    cout << "\n----- Better -----" << endl;
    SolutionBetter better;
    for (auto &s : testCases)
    {
        cout << "Input: \"" << s << "\" -> Output: " << better.myAtoi(s) << endl;
    }

    cout << "\n----- Optimal -----" << endl;
    SolutionOptimal optimal;
    for (auto &s : testCases)
    {
        cout << "Input: \"" << s << "\" -> Output: " << optimal.myAtoi(s) << endl;
    }

    return 0;
}
