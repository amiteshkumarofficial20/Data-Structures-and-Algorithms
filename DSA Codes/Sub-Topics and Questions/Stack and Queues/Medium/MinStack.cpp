/***************************************************************
    PROBLEM: LeetCode 155 - Min Stack
****************************************************************/

#include <bits/stdc++.h>
using namespace std;

/***************************************************************
======================= PROBLEM STATEMENT ======================

Design a stack that supports the following operations in O(1):

    • push(int val)
    • pop()
    • top()
    • getMin()

All operations must run in constant time.

Example:
--------
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[ [],[-2],[0],[-3],[],[],[],[] ]

Output:
[null,null,null,null,-3,null,0,-2]

****************************************************************/

/***************************************************************
================================================================
                 BRUTE FORCE APPROACH (O(2N))
================================================================

INTUITION:
----------
For every pushed element, store:
    (value, minimum_at_time_of_push)

This allows:
    - O(1) min lookup
    - O(1) top lookup
    - O(1) push/pop

Uses more memory (2N space).

---------------------------------------------------------------
ASCII DIAGRAM:
(value, min)
-----------------------------------
| 5,5 | 3,3 | 7,3 | 2,2 |
-----------------------------------
                      ↑ top
---------------------------------------------------------------

****************************************************************/

/********************* STEP-BY-STEP ALGORITHM ******************

push(x):
    if stack empty:
        push (x, x)
    else:
        min_so_far = st.top().min
        push (x, min(x, min_so_far))

pop():
    st.pop()

top():
    return st.top().value

getMin():
    return st.top().min

***************************************************************/

/*************************** PSEUDOCODE *************************

class MinStack:
    stack<pair<int,int>> st

    push(x):
        if st is empty:
            st.push({x, x})
        else:
            mn = st.top().second
            st.push({x, min(x, mn)})

    pop():
        st.pop()

    top():
        return st.top().first

    getMin():
        return st.top().second

***************************************************************/

class MinStackBrute
{
private:
    stack<pair<int, int>> st;

public:
    MinStackBrute() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int mn = st.top().second;
            st.push({val, min(val, mn)});
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/***************************************************************
================================================================
                 OPTIMAL APPROACH (O(N) SPACE)
================================================================

INTUITION:
----------
We store ONE value per push and maintain ONE variable "mini".

IF val >= mini:
        push normally
ELSE:
        encode value:
                encoded = 2*val - mini
        push encoded
        update mini = val

To decode previous minimum:
    oldMin = 2*mini - encoded

---------------------------------------------------------------
ENCODING DIAGRAM:
---------------------------------------------------------------
Initial mini = 5

push(2):
    encoded = 2*2 - 5 = -1
Stack: [5, -1]
mini = 2

Pop -> -1 < mini → encoded
restore mini = 2*2 - (-1) = 5
---------------------------------------------------------------

This method saves 50% space vs brute force.

****************************************************************/

/********************* STEP-BY-STEP ALGORITHM ******************

push(val):
    if empty:
        st.push(val)
        mini = val

    else if val >= mini:
        st.push(val)

    else:
        encoded = 2*val - mini
        st.push(encoded)
        mini = val

pop():
    if top < mini:
        mini = 2*mini - top (decode previous min)
    pop stack

top():
    if st.top() >= mini:
        return st.top()
    else:
        return mini  // encoded case

getMin():
    return mini

***************************************************************/

/*************************** PSEUDOCODE *************************

class MinStack:

    stack st
    int mini

    push(x):
        if st empty:
            st.push(x)
            mini = x
        else if x >= mini:
            st.push(x)
        else:
            encoded = 2*x - mini
            st.push(encoded)
            mini = x

    pop():
        t = st.top()
        st.pop()
        if t < mini:
            mini = 2*mini - t

    top():
        if st.top() >= mini:
            return st.top()
        else:
            return mini

    getMin():
        return mini

***************************************************************/

class MinStackOptimal
{
private:
    stack<int> st;
    int mini;

public:
    MinStackOptimal() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if (val >= mini)
        {
            st.push(val);
        }
        else
        {
            int encoded = 2 * val - mini;
            st.push(encoded);
            mini = val;
        }
    }

    void pop()
    {
        int t = st.top();
        st.pop();

        if (t < mini)
        { // encoded value!
            mini = 2 * mini - t;
        }
    }

    int top()
    {
        int t = st.top();
        return (t >= mini) ? t : mini;
    }

    int getMin()
    {
        return mini;
    }
};

/***************************************************************
================================================================
                        COMPARISON TABLE
================================================================

| Feature                | Brute Force      | Optimal (Encoded) |
|------------------------|------------------|--------------------|
| push()                 | O(1)             | O(1)               |
| pop()                  | O(1)             | O(1)               |
| top()                  | O(1)             | O(1)               |
| getMin()               | O(1)             | O(1)               |
| Extra Space            | O(2N)            | O(N)               |
| Implementation         | Very Easy        | Medium             |
| Memory Efficient?      | ❌ No            | ✔ Yes              |

***************************************************************/

/***************************************************************
================================================================
                        TEST CASES
================================================================
****************************************************************/

int main()
{

    cout << "===== Testing BRUTE FORCE MinStack =====\n";
    MinStackBrute b;
    b.push(-2);
    b.push(0);
    b.push(-3);

    cout << "Min: " << b.getMin() << "\n"; // -3
    b.pop();

    cout << "Top: " << b.top() << "\n";    // 0
    cout << "Min: " << b.getMin() << "\n"; // -2

    cout << "\n===== Testing OPTIMAL MinStack =====\n";
    MinStackOptimal o;

    o.push(5);
    o.push(1);
    cout << "Min: " << o.getMin() << "\n"; // 1

    o.push(3);
    o.pop();

    cout << "Min: " << o.getMin() << "\n"; // 1
    cout << "Top: " << o.top() << "\n";    // 1

    o.push(-2);
    cout << "Min: " << o.getMin() << "\n"; // -2

    return 0;
}
