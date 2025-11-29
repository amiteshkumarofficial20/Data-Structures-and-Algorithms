/*
====================================================================================================
    FILE: InfixToPrefix.cpp
    TOPIC: Convert Infix Expression to Prefix Expression
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
You are given a valid infix expression, such as:

        (A+B)*C-D/E

Your task:
Convert this **infix** expression into a valid **prefix** expression.

Example:
    INFIX:  (A+B)*C-D/E
    PREFIX: - * + A B C / D E

Rules:
- Infix:   operand operator operand
- Prefix:  operator operand operand
- Must handle:
      • precedence
      • associativity
      • parentheses

====================================================================================================
🪓 BRUTE FORCE APPROACH (Slow & Complicated)
---------------------------------------------
Directly parse infix from left → right, recursively splitting on lowest-precedence operators.

WHY BAD?
- Requires full expression tree construction
- Hard to manage parentheses
- O(n²) time

Not recommended.

====================================================================================================
⚡ OPTIMAL APPROACH — REVERSE + INFIX→POSTFIX + REVERSE
--------------------------------------------------------

INTUITION:
To convert INFIX → PREFIX:
1️⃣ Reverse infix
2️⃣ Swap '(' ↔ ')'
3️⃣ Convert reversed infix → postfix
4️⃣ Reverse postfix → prefix

WHY WORKS?
- Prefix is mirror image of postfix
- Reversing allows postfix algorithm to be reused

DIAGRAM:

INFIX:        (A+B)*C
REVERSED:     C*(B+A)
SWAP:         C*(B+A)
POSTFIX:      CBA+*
REVERSE:      *+ABC  ← PREFIX

====================================================================================================
📊 COMPARISON TABLE
--------------------

| Conversion Type       | Easy? | Fast? | Uses Stack? |
|------------------------|--------|--------|--------------|
| Infix → Prefix         | Medium | Fast  | Yes          |
| Infix → Postfix        | Easy   | Fast  | Yes          |
| Prefix → Infix         | Easy   | Fast  | Yes          |
| Prefix → Postfix       | Easy   | Fast  | Yes          |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

INFIX → PREFIX STEPS:

1. Reverse the infix expression
2. Replace '(' with ')' and ')' with '('
3. Convert using standard infix → postfix algorithm
4. Reverse the result → PREFIX

====================================================================================================
📌 PSEUDOCODE
--------------

FUNCTION infixToPrefix(infix):
    reverse(infix)
    swap '(' and ')'
    postfix = infixToPostfix(infix)
    reverse(postfix)
    return postfix

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

TIME:  O(n)
SPACE: O(n)

====================================================================================================
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// Check if operator
bool isOperator(char c)
{
    return (!isalnum(c));
}

// Operator precedence
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

// Convert INFIX → POSTFIX
string infixToPostfix(string exp)
{
    stack<char> st;
    st.push('(');
    exp += ')';

    string output = "";

    for (char c : exp)
    {

        if (isalnum(c))
        {
            output += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            // Operator
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    return output;
}

// Convert INFIX → PREFIX
string infixToPrefix(string infix)
{
    // Step 1: Reverse
    reverse(infix.begin(), infix.end());

    // Step 2: Swap parentheses
    for (char &c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    // Step 3: Convert reversed INFIX → POSTFIX
    string postfix = infixToPostfix(infix);

    // Step 4: Reverse postfix → PREFIX
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    cout << "=== INFIX TO PREFIX CONVERSION ===\n\n";

    string tests[] = {
        "(A+B)*C",
        "A+(B*C-(D/E^F)*G)*H",
        "a+b*(c^d-e)^(f+g*h)-i"};

    for (string exp : tests)
    {
        cout << "Infix:  " << exp << endl;
        cout << "Prefix: " << infixToPrefix(exp) << endl
             << endl;
    }

    return 0;
}
