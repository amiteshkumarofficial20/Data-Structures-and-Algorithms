/*
📘 FULL PROBLEM STATEMENT
-------------------------
You are given a mathematical **infix expression** such as:

        (A+B)*C-D/E

Your task is to convert it into a **postfix expression** (Reverse Polish Notation), such as:

        AB+C*DE/-

Rules:
    • Infix form → operator written BETWEEN operands (A + B)
    • Postfix form → operator written AFTER operands (AB+)
    • No parentheses are required in postfix notation
    • Must correctly handle:
            - operator precedence
            - associativity
            - parentheses

====================================================================================================
🪓 BRUTE FORCE APPROACH
------------------------
Try evaluating infix directly by scanning expression and applying precedence rules manually.

WHY BAD?
    - Too complex
    - Hard to handle parentheses
    - Requires multiple passes

TIME: O(n²)
NOT preferred.

====================================================================================================
⚡ OPTIMAL APPROACH — STACK BASED (SHUNTING YARD ALGORITHM)
-----------------------------------------------------------

INTUITION:
    We scan the infix expression:
        • Operands → directly placed in output
        • Operators → pushed on stack (based on precedence/associativity)
        • '(' → pushed on stack
        • ')' → pop until '(' is found

STACK ensures correct precedence.

DIAGRAM:

    INFIX:  A + B * C
    SCAN:   A → output
            + → push
            B → output
            * → higher precedence → push
            C → output

Stack: +  *
Output: A B C

Pop all:
Output: A B C * +

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Expression Type | Human-Friendly | Machine-Friendly | Needs Parentheses |
|-----------------|----------------|------------------|-------------------|
| Infix           | Yes            | No               | Yes               |
| Postfix         | No             | Yes              | No                |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

1. Scan expression from left → right
2. If char is operand → append to output
3. If '(' → push to stack
4. If ')':
        pop until '(' appears
        discard '('
5. If operator:
        while stack not empty AND
              precedence(current) ≤ precedence(top):
                pop to output
        push operator
6. After full scan:
        pop all remaining operators

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION infixToPostfix(exp):

    FOR each character ch in exp:
        IF ch is operand:
            add to output
        ELSE IF ch is '(':
            push to stack
        ELSE IF ch is ')':
            WHILE top of stack != '(':
                output += pop()
            pop '('
        ELSE IF ch is operator:
            WHILE stack NOT empty AND prec(ch) <= prec(stack.top()):
                output += pop()
            push(ch)

    WHILE stack NOT empty:
        output += pop()

    RETURN output

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:
    O(n) — each element scanned once, each pushed/popped once

SPACE:
    O(n) — stack + output string

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Get operator precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Convert infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";

    for (char c : s)
    {

        // Operand → add directly
        if (isalnum(c))
        {
            result += c;
        }
        // '(' → push
        else if (c == '(')
        {
            st.push(c);
        }
        // ')' → pop until '('
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

// ============================================================================
//                                    MAIN
// ============================================================================
int main()
{

    cout << "=== INFIX TO POSTFIX CONVERSION ===\n\n";

    // Multiple Test Cases
    string tests[] = {
        "A+B*C",
        "(A+B)*C",
        "A+(B*C-(D/E^F)*G)*H",
        "a+b*(c^d-e)^(f+g*h)-i"};

    for (string exp : tests)
    {
        cout << "Infix:   " << exp << endl;
        cout << "Postfix: " << infixToPostfix(exp) << endl
             << endl;
    }

    return 0;
}
