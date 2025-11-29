/*
====================================================================================================
    FILE: PrefixToPostfix.cpp
    TOPIC: Convert Prefix Expression to Postfix Expression
   AUTHOR: ChatGPT
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
You are given a valid arithmetic **prefix expression** consisting of:
    • Single-character operands (a, b, c, 1, 2, 3…)
    • Binary operators (+, -, *, /, ^)

Your task:
Convert this prefix expression **into a valid postfix expression**, ensuring the operator comes after
its two operands.

Example:
PREFIX:   *+AB-CD
POSTFIX:  AB+CD-*

Definitions:
    Prefix  → operator BEFORE operands    (e.g., +AB)
    Postfix → operator AFTER operands     (e.g., AB+)

Goal:
    Convert prefix → postfix using a stack-based algorithm.

====================================================================================================
🪓 BRUTE FORCE APPROACH (Not Recommended)
-----------------------------------------
Approach:
    Recursively detect operator/operand boundaries and expand substrings.

Problems:
    • Hard to detect boundaries with single-character tokens
    • Requires recursion with heavy string manipulation
    • Very inefficient

TIME: O(n²)

Not practical.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK (Right → Left Scan)
------------------------------------------------

INTUITION:
Prefix expression builds as:
        op operand1 operand2

So scanning from **right → left** ensures:
    - We encounter operand2 first → push
    - Then operand1 → push
    - Then operator → pop 2 operands → combine

STACK will hold partial postfix expressions.

DIAGRAM:

PREFIX:  *+AB-CD

SCAN RIGHT → LEFT:
    D → push
    C → push
    - → pop C,D → push "CD-"
    B → push
    A → push
    + → pop A,B → push "AB+"
    * → pop "AB+" and "CD-" → push "AB+CD-*"

FINAL POSTFIX:   AB+CD-*

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Conversion Type       | Easy? | Needs Stack? | Naive Works? |
|------------------------|--------|--------------|---------------|
| Prefix → Postfix       | Yes    | Yes          | No            |
| Prefix → Infix         | Yes    | Yes          | No            |
| Postfix → Infix        | Yes    | Yes          | No            |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

1. Create an empty stack of strings
2. Traverse prefix string from **right → left**
3. For each character:
       If operand → push as string
       If operator:
            pop op1
            pop op2
            merge = op1 + op2 + operator
            push merge
4. After finishing scan, top of stack = postfix expression

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION prefixToPostfix(prefix):

    stack S

    FOR i from len(prefix)-1 down to 0:
        c = prefix[i]

        IF c is operand:
            S.push(c)

        ELSE:
            op1 = S.pop()
            op2 = S.pop()
            result = op1 + op2 + c
            S.push(result)

    RETURN S.top()

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:   O(n) — single scan of prefix
SPACE:  O(n) — stack stores partial strings

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Convert prefix to postfix
string prefixToPostfix(string prefix)
{
    stack<string> st;

    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(op1 + op2 + c);
        }
    }

    return st.top();
}

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    cout << "=== PREFIX TO POSTFIX CONVERSION ===\n\n";

    string tests[] = {
        "*+AB-CD",
        "+AB",
        "-+A*BCD",
        "*-A/BC-/AKL"};

    for (string exp : tests)
    {
        cout << "Prefix:  " << exp << endl;
        cout << "Postfix: " << prefixToPostfix(exp) << endl
             << endl;
    }

    return 0;
}
