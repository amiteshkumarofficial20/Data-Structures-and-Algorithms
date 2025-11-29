/*
====================================================================================================
    FILE: PostfixToPrefix.cpp
    TOPIC: Convert Postfix Expression to Prefix Expression
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
You are given a valid **postfix expression** consisting of:
    • single-character operands: a–z, A–Z, 0–9
    • binary operators: +, -, *, /

Your task:
➡ Convert the postfix expression into a **prefix expression**, also without spaces.

Example:
    POSTFIX: ab+c*
    PREFIX:  *+abc

Postfix (Reverse Polish Notation)
    → operator AFTER operands
        Example: ab+ (means a+b)

Prefix (Polish Notation)
    → operator BEFORE operands
        Example: +ab

Goal:
Convert postfix → prefix using stack.

====================================================================================================
🪓 BRUTE FORCE APPROACH
------------------------
Attempt recursive parsing from right → left or left → right.

WHY BAD?
    • Difficult to determine operand grouping
    • Requires string slicing and recursion
    • Easily leads to errors
    • Runs in O(n²)

NOT recommended.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK (Left → Right Scan)
------------------------------------------------

INTUITION:
Postfix expression is built like:
        operand1 operand2 OP

To reverse this into prefix:
        OP operand1 operand2

Algorithm idea:
    • Scan postfix from left → right
    • Push operands to stack
    • When operator appears:
            pop op2
            pop op1
            create prefix: operator + op1 + op2
            push result to stack

DIAGRAM:

POSTFIX: ab+c*

SCAN:
    a → push
    b → push
    + → pop b,a → "+ab" → push
    c → push
    * → pop c,"+ab" → "*+abc" → push

FINAL: *+abc

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Conversion Type       | Stack Needed? | Easy? |
|------------------------|----------------|--------|
| Postfix → Prefix       | Yes            | Yes    |
| Postfix → Infix        | Yes            | Medium |
| Prefix → Postfix       | Yes            | Easy   |
| Prefix → Infix         | Yes            | Easy   |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

1. Initialize empty stack S
2. Traverse postfix expression from left → right
3. If operand:
       push to S
4. If operator:
       pop op2
       pop op1
       newExpr = operator + op1 + op2
       push newExpr
5. End loop
6. Final result = S.top()

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION postfixToPrefix(postfix):

    stack S

    FOR each character c in postfix:
        IF c is operand:
            S.push(c)
        ELSE:
            op2 = S.pop()
            op1 = S.pop()
            result = c + op1 + op2
            S.push(result)

    RETURN S.top()

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:  O(n) — single left-to-right scan
SPACE: O(n) — stack stores partial expressions

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Convert postfix to prefix
string postfixToPrefix(string postfix)
{
    stack<string> st;

    for (char c : postfix)
    {

        // Operand → push directly
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        // Operator → pop two operands & form prefix
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push(c + op1 + op2);
        }
    }

    return st.top();
}

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    cout << "=== POSTFIX TO PREFIX CONVERSION ===\n\n";

    string tests[] = {
        "ab+c*",
        "abc*+",
        "ab+cd-*",
        "ABC/-AK/L-*"};

    for (string exp : tests)
    {
        cout << "Postfix: " << exp << endl;
        cout << "Prefix:  " << postfixToPrefix(exp) << endl
             << endl;
    }

    return 0;
}
