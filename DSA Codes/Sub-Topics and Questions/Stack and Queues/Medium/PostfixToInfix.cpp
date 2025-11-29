/*
====================================================================================================
    FILE: PostfixToInfix.cpp
    TOPIC: Convert Postfix Expression to Fully Parenthesized Infix Expression
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
You are given a valid postfix expression (Reverse Polish Notation).

Postfix example:
        ab+c*

Your task:
Convert it to a **fully parenthesized infix expression**, such as:
        ((a+b)*c)

Rules:
- Operands: a–z, A–Z, 0–9
- Operators: +, -, *, /
- No spaces in input or output
- Must include parentheses to preserve precedence:
        (operand1 operator operand2)

====================================================================================================
🪓 BRUTE FORCE APPROACH (Not Preferred)
----------------------------------------
Try identifying operand pairs and recursively grouping them.

WHY BAD?
- Hard to determine grouping boundaries
- Requires recursion + string slicing
- Time complexity O(n²)

NOT recommended.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK (Left → Right Scan)
------------------------------------------------

INTUITION:
Postfix expressions are evaluated left → right:
        operand1 operand2 operator

To convert postfix → infix:
        (operand1 operator operand2)

Stack helps us store partial infix expressions.

EXAMPLE:
POSTFIX: ab+c*

SCAN:
    a → push
    b → push
    + → pop b,a → "(a+b)" → push
    c → push
    * → pop c,"(a+b)" → "((a+b)*c)"

FINAL RESULT:    ((a+b)*c)

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Conversion Type       | Needs Parentheses? | Easy? | Needs Stack? |
|------------------------|--------------------|--------|---------------|
| Postfix → Infix        | YES                | Medium | YES           |
| Prefix → Infix         | YES                | Medium | YES           |
| Infix → Postfix        | No                 | Medium | YES           |
| Infix → Prefix         | No                 | Medium | YES           |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

1. Create empty stack S
2. Traverse postfix expression from left → right
3. If char is operand:
       push it as string
4. If char is operator:
       pop op2 (right)
       pop op1 (left)
       newExp = "(" + op1 + operator + op2 + ")"
       push newExp
5. Final answer = S.top()

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION postfixToInfix(postfix):
    create empty stack S

    FOR each character c in postfix:
        IF operand:
            S.push(c)
        ELSE:
            op2 = S.pop()
            op1 = S.pop()
            S.push("(" + op1 + c + op2 + ")")

    RETURN S.top()

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:  O(n) — one scan of postfix
SPACE: O(n) — stack stores partial expressions

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Convert postfix to infix
string postfixToInfix(string postfix)
{
    stack<string> st;

    for (char c : postfix)
    {

        // Operand → push directly
        if (isalnum(c))
        {
            st.push(string(1, c));
        }

        // Operator → pop two, combine with parentheses
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }

    return st.top();
}

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    cout << "=== POSTFIX TO INFIX CONVERSION ===\n\n";

    string tests[] = {
        "ab+c*",
        "abc*+",
        "ab+cd-*",
        "ABC/-AK/L-*"};

    for (string exp : tests)
    {
        cout << "Postfix: " << exp << endl;
        cout << "Infix:   " << postfixToInfix(exp) << endl
             << endl;
    }

    return 0;
}
