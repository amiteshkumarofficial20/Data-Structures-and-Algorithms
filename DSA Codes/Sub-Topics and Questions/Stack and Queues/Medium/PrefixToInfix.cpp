/*
====================================================================================================
    FILE: PrefixToInfix.cpp
    TOPIC: Convert Prefix Expression to Fully Parenthesized Infix Expression
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
You are given a valid arithmetic expression written in **prefix notation**.

Prefix Example:
        +AB
Meaning:
        A + B

Your task:
✔ Convert the prefix expression into a **fully parenthesized infix expression**, such as:
        (A+B)

Rules:
- Prefix notation places operator BEFORE operands
- Infix notation places operator BETWEEN operands
- Output must be fully parenthesized: (operand operator operand)

Example:
PREFIX:   *+AB-CD
INFIX:    ((A+B)*(C-D))

====================================================================================================
🪓 BRUTE FORCE APPROACH
------------------------
Try scanning prefix and trying to recursively reconstruct expression from left to right.

WHY BAD?
- Difficult to know operand boundaries
- Requires backtracking and recursion
- Hard to maintain correctness

Time: O(n²)

Not recommended.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK (RIGHT → LEFT SCAN)
------------------------------------------------

INTUITION:
Prefix expression is built like:
        op operand1 operand2

If we scan from **right to left**:
- First we meet operand2 → push
- Then operand1 → push
- Then operator → pop 2 operands → combine

So stack will hold partial infix expressions.

DIAGRAM:

PREFIX:   *+AB-CD

SCAN RIGHT → LEFT:
    D → push
    C → push
    - → pop C,D → "(C-D)" push
    B → push
    A → push
    + → pop A,B → "(A+B)" push
    * → pop (A+B),(C-D) → "((A+B)*(C-D))"

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Notation | Easy for Humans | Easy for Computers | Needs Parentheses |
|----------|------------------|--------------------|-------------------|
| Prefix   | Medium          | Easy               | No                |
| Infix    | Easy            | Hard               | Yes               |
| Postfix  | Hard            | Easy               | No                |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------
1. Create empty stack of strings
2. Scan prefix expression from **right → left**
3. If character is operand:
       push it to stack
4. Else (character is operator):
       pop op1
       pop op2
       create "(op1 operator op2)"
       push back to stack
5. Final stack top contains the infix expression

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION prefixToInfix(prefix):

    stack = empty

    FOR i = len(prefix)-1 → 0:
        c = prefix[i]

        IF c is operand:
            push(c)
        ELSE:
            op1 = pop()
            op2 = pop()
            expression = "(" + op1 + c + op2 + ")"
            push(expression)

    RETURN stack.top()

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:
    O(n) — single scan, each char pushed/popped once

SPACE:
    O(n) — stack holds intermediate expressions

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Convert prefix to infix
string prefixToInfix(string prefix)
{
    stack<string> st;

    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];

        // Operand → push to stack
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        // Operator → pop 2 operands & combine
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
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

    cout << "=== PREFIX TO INFIX CONVERSION ===\n\n";

    string tests[] = {
        "*+AB-CD",
        "+AB",
        "-+A*BCD",
        "*-A/BC-/AKL"};

    for (string exp : tests)
    {
        cout << "Prefix: " << exp << endl;
        cout << "Infix:  " << prefixToInfix(exp) << endl
             << endl;
    }

    return 0;
}
