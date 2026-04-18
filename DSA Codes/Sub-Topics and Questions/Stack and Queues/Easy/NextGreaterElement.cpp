#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
        NEXT GREATER ELEMENT – COMPLETE C++ INTERVIEW FILE
===============================================================================

FILE NAME: NextGreaterElement_CompleteGuide.cpp
PROBLEM NUMBER: Common Interview Problem (Used in LC #496, #739, #1019)
TOPIC: Stack / Monotonic Stack
DIFFICULTY: Easy–Medium

===============================================================================
1. PROBLEM DESCRIPTION
===============================================================================

Given an array A, for each element find the NEXT GREATER ELEMENT:
The **next greater element** for A[i] is the first element to the **right**
that is strictly greater than A[i]. If none exists → return -1.

A circular version also exists: the array wraps around (clockwise). This is
similar to LeetCode 503 (Next Greater Element II).

-------------------------------------------------------------------------------
Examples (Normal, Non-Circular):

Input:  [2, 1, 2, 4, 3]
Output: [4, 2, 4, -1, -1]

Explanation:
- For 2 → next greater is 4
- For 1 → next greater is 2
- For 2 → next greater is 4
- For 4 → no greater → -1
- For 3 → no greater → -1

-------------------------------------------------------------------------------
Examples (Circular Version):

Input:  [1, 2, 1]
Output: [2, -1, 2]

Explanation:
- For first 1 → next greater is 2
- For 2 → no greater → -1
- For last 1 → we wrap around → next greater is 2

===============================================================================
2. BRUTE FORCE SOLUTION (O(n²))
===============================================================================

ALGORITHM:
- For each element nums[i], scan nums[i+1 → end].
- If a greater element is found → record it.
- Otherwise → answer is -1.

PSEUDOCODE:
for i in 0..n-1:
    ans = -1
    for j in i+1..n-1:
        if nums[j] > nums[i]:
            ans = nums[j]
            break
    result[i] = ans

TIME COMPLEXITY:  O(n²)
SPACE COMPLEXITY: O(1)

===============================================================================
3. OPTIMAL SOLUTION USING MONOTONIC STACK (O(n))
===============================================================================

INTUITION:
We traverse **right to left** and maintain a stack that stores elements in a
strictly decreasing order. For each nums[i]:

- Pop all smaller or equal elements → they cannot be next greater.
- If stack empty → next greater = -1
- Else → next greater = stack.top()
- Push nums[i] onto the stack.

PSEUDOCODE:
stack st
for i from n-1 downto 0:
    while st not empty AND st.top() <= nums[i]:
        st.pop()

    if st empty: res[i] = -1
    else:        res[i] = st.top()

    st.push(nums[i])

TIME COMPLEXITY:  O(n)
SPACE COMPLEXITY: O(n)

===============================================================================
4. CIRCULAR ARRAY VERSION (Clockwise Next Greater)
===============================================================================

This is the optimal solution for the circular version.

TRICK:
→ Traverse the array **twice** (simulate circular behavior).
→ Use i % n to map back into array.

PSEUDOCODE:
stack st
for i from 2*n-1 downto 0:
    val = nums[i % n]

    while st not empty AND st.top() <= val:
        st.pop()

    if i < n:
        if st empty: res[i] = -1
        else:        res[i] = st.top()

    st.push(val)

TIME COMPLEXITY:  O(n)
SPACE COMPLEXITY: O(n)

===============================================================================
5. FULL C++ IMPLEMENTATIONS
===============================================================================
*/

// ---------------- BRUTE FORCE ----------------------------------------------
vector<int> nextGreaterBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                res[i] = nums[j];
                break;
            }
        }
    }
    return res;
}

// ---------------- OPTIMAL MONOTONIC STACK ----------------------------------
vector<int> nextGreaterStack(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        res[i] = st.empty() ? -1 : st.top();

        st.push(nums[i]);
    }
    return res;
}

// ----------- CIRCULAR (CLOCKWISE) VERSION ----------------------------------
vector<int> nextGreaterCircular(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int val = nums[i % n];

        while (!st.empty() && st.top() <= val)
            st.pop();

        if (i < n)
            res[i] = st.empty() ? -1 : st.top();

        st.push(val);
    }
    return res;
}

/*
===============================================================================
7. TIME & SPACE COMPLEXITY (DETAILED)
===============================================================================

───────────────────────────────────────────────────────────────────────────────
A) BRUTE FORCE (nextGreaterBrute)
───────────────────────────────────────────────────────────────────────────────
TIME COMPLEXITY:
    O(n²)
    - For each element i (n times), we scan all elements j to the right.
    - Worst case: strictly decreasing array → full scan every time.

SPACE COMPLEXITY:
    O(1)
    - No extra data structure except output array.
    - Does not use stack or additional memory.


───────────────────────────────────────────────────────────────────────────────
B) OPTIMAL MONOTONIC STACK (nextGreaterStack)
───────────────────────────────────────────────────────────────────────────────
TIME COMPLEXITY:
    O(n)
    - Each element is pushed once and popped at most once.
    - Total operations ≤ 2n → O(n)

SPACE COMPLEXITY:
    O(n)
    - Uses a stack that may hold up to n elements in worst case.
    - Output array also size n (ignored in SC unless interviewer includes it).


───────────────────────────────────────────────────────────────────────────────
C) CIRCULAR NEXT GREATER ELEMENT (nextGreaterCircular)
───────────────────────────────────────────────────────────────────────────────
TIME COMPLEXITY:
    O(n)
    - We loop from 2n → 0 (exactly 2n iterations).
    - Each element pushed/popped at most once.
    - Overall complexity remains O(n), NOT O(2n).

SPACE COMPLEXITY:
    O(n)
    - Stack contains at most n elements.
    - Output array size n.

===============================================================================
*/

/*
===============================================================================
6. TEST MAIN() – RUN IN VS CODE
===============================================================================
*/

int main()
{
    vector<int> nums = {2, 1, 2, 4, 3};

    cout << "Input:  ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n\n";

    // Brute Force
    auto brute = nextGreaterBrute(nums);
    cout << "Brute Force Output:          ";
    for (int x : brute)
        cout << x << " ";
    cout << "\n";

    // Optimal Stack
    auto opt = nextGreaterStack(nums);
    cout << "Optimal Stack Output:        ";
    for (int x : opt)
        cout << x << " ";
    cout << "\n";

    // Circular Version
    auto circ = nextGreaterCircular(nums);
    cout << "Circular Version Output:     ";
    for (int x : circ)
        cout << x << " ";
    cout << "\n";

    return 0;
}
