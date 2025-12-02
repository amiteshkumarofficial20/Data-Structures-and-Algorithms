/*
====================================================================================================
    LEETCODE PROBLEM: 20 — Valid Parentheses
    TOPIC: Stack, Strings
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Given a string s containing only characters:
        '(', ')', '{', '}', '[', ']'

Return TRUE if the parentheses string is:

    ✔ Balanced
    ✔ Properly nested
    ✔ Correctly ordered

Examples:
    "()"       → true
    "()[]{}"   → true
    "(]"       → false
    "([)]"     → false
    "{[]}"     → true

Rules:
1. Every opening bracket must have a matching closing bracket.
2. Closing bracket must match MOST RECENT opening bracket.
3. Order must be correct (Stack LIFO behavior).

====================================================================================================
🪓 BRUTE FORCE APPROACH (Not Optimal)
--------------------------------------
Repeatedly locate a pair "()", "{}", "[]" and remove them from the string.

Steps:
    While string contains any pair:
         replace "()", "{}", "[]" by empty string
    If final string is empty → valid

Problems:
    • Removing substrings = expensive
    • Takes O(n²) time
    • Not scalable for large inputs

Do NOT use this for coding interviews.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK (LIFO)
----------------------------------

INTUITION:
Parentheses must follow "last opened → first closed".
This is exactly how a **stack** behaves.

We push all opening brackets.
When a closing bracket comes:
    • Check if stack is empty → invalid
    • Check top element = matching opening → pop
    • Else → invalid

In the end:
    ✔ Stack must be empty for valid parentheses.

DIAGRAM:

Input:  (  [  ]  )
Stack: (
        ([
        (
        empty → valid!

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Approach          | Time    | Space | Works For Large Inputs? |
|-------------------|---------|-------|---------------------------|
| Brute Force       | O(n²)   | O(1)  | ❌ No                    |
| Stack Approach    | O(n)    | O(n)  | ✔ Yes                    |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

1. Create empty stack
2. Traverse each character:
       If opening bracket → push
       If closing bracket:
            If stack empty → false
            If top NOT matching → false
            Else pop
3. After full traversal:
       If stack empty → true
       Else → false

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION isValid(s):

    create empty stack st

    FOR each char c in s:

        IF c is '(', '{', '[':
            st.push(c)

        ELSE:
            IF st is empty:
                return false

            top = st.pop()

            IF c == ')' AND top != '(':
                return false
            IF c == ']' AND top != '[':
                return false
            IF c == '}' AND top != '{':
                return false

    return st is empty

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:  O(n) — each character pushed & popped once
SPACE: O(n) — stack stores open brackets

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {

            // Opening brackets → push
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                // Closing bracket but no opening one
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Matching rules
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    Solution sol;

    cout << "=== VALID PARENTHESES (LC20) ===\n\n";

    string tests[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "((((((",
        "",
    };

    for (string s : tests)
    {
        cout << "Input:  " << s << endl;
        cout << "Valid?: " << (sol.isValid(s) ? "true" : "false") << endl;
        cout << "-------------------------------------\n";
    }

    return 0;
}