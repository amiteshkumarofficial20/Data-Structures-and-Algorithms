#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
        LEETCODE 503 – NEXT GREATER ELEMENT II (COMPLETE GUIDE)
===============================================================================

FILE NAME: LC503_NextGreaterElementII_CompleteGuide.cpp
PROBLEM NUMBER: 503 (LeetCode)
TOPIC: Stack / Monotonic Stack / Arrays
DIFFICULTY: Medium

===============================================================================
1. PROBLEM DESCRIPTION
===============================================================================

You are given a **circular** integer array nums.
Return an array where each element is replaced with its **next greater element**.

The next greater element for nums[i] is the first element **to its right**
(encountered in circular order) that is strictly greater than nums[i].

If none exists → return -1.

-------------------------------------------------------------------------------
Examples:

Example 1:
Input:  [1, 2, 1]
Output: [2, -1, 2]

Explanation:
- Next greater of 1 is 2
- Next greater of 2 does not exist → -1
- For last 1, circular search finds 2

Example 2:
Input:  [1, 2, 3, 4, 3]
Output: [2, 3, 4, -1, 4]

===============================================================================
2. BRUTE FORCE SOLUTION  (O(n²))
===============================================================================

ALGORITHM:
- For each index i:
    - Search the next n-1 elements circularly.
    - The first element greater than nums[i] is the answer.
    - If none, answer is -1.

PSEUDOCODE:
for i = 0 to n-1:
    ans[i] = -1
    for j = 1 to n-1:
        idx = (i + j) % n
        if nums[idx] > nums[i]:
            ans[i] = nums[idx]
            break

TIME COMPLEXITY:  O(n²)
SPACE COMPLEXITY: O(1) (not counting output array)

===============================================================================
3. OPTIMAL SOLUTION – MONOTONIC STACK (O(n))
===============================================================================

KEY IDEA:
- Traverse array **twice** to simulate circular behavior.
- Use a **monotonic decreasing stack**.
- For each element nums[i], pop all smaller elements.
- Stack top becomes next greater.
- Push nums[i].

PSEUDOCODE:
stack st
ans[n]

for i from 2*n-1 downto 0:
    val = nums[i % n]
    while st not empty and st.top() <= val:
        st.pop()
    if i < n:
        ans[i] = st.empty() ? -1 : st.top()
    st.push(val)

TIME COMPLEXITY:  O(n)
SPACE COMPLEXITY: O(n)

Why O(n)?
- Each element is pushed once and popped once → 2n operations.

/*
===============================================================================
4. FULL C++ IMPLEMENTATION (BRUTE + OPTIMAL)
===============================================================================
*/

/*
===============================================================================
2. BRUTE FORCE SOLUTION (O(n²))
===============================================================================

Approach:
- For each element nums[i], look forward circularly through the array.
- Check (i + 1), (i + 2), …, (i + n – 1) using modulo arithmetic.
- The first element greater than nums[i] is the next greater element.
- If none is found, answer is -1.

This method is simple but very inefficient for large arrays.

===============================================================================
3. BRUTE FORCE IMPLEMENTATION (WITH COMMENTS)
===============================================================================
*/

vector<int> nextGreaterBrute(vector<int> &nums)
{
    int n = nums.size();

    // Initialize all answers to -1 (default when no greater exists)
    vector<int> ans(n, -1);

    // For each element, search for next greater
    for (int i = 0; i < n; i++)
    {

        // Scan next n-1 elements circularly
        for (int j = 1; j < n; j++)
        {

            // Circular index using modulo
            int idx = (i + j) % n;

            // If found a greater element → store & break
            if (nums[idx] > nums[i])
            {
                ans[i] = nums[idx];
                break;
            }
        }
    }
    return ans;
}

/*
====================================================================================
4. OPTIMAL SOLUTION USING MONOTONIC STACK (O(n))
====================================================================================

🏆 Key Idea:
----------------
To handle the **circular array**, we simulate traversal twice:
    - Traverse from index = 2*n - 1 down to 0.
    - Use i % n to wrap around.

We maintain a **monotonic decreasing stack**:
    - Stack stores ONLY elements (not indices!)
    - Always decreasing top → bottom.
    - Why decreasing?
        → Because when we see a new element, we want to quickly remove useless
          smaller elements (they can't be next greater).

💡 Why traverse backwards?
--------------------------
Because:
    - We want the stack to represent "future" elements to the right.
    - Backward traversal lets the stack behave like "next greater" behavior.

Algorithm:
----------
For i = 2*n - 1 down to 0:
    1. Let `val = nums[i % n]`
       (wrap around, circular indexing)

    2. While stack top <= val → pop
       (they cannot be next greater elements)

    3. If i < n:
            → this is the first traversal
            → store answer for nums[i]

    4. Push val into stack

====================================================================================
5. OPTIMAL IMPLEMENTATION (BEST SOLUTION)
====================================================================================
*/

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();

    // Initialize result array with all -1
    vector<int> ans(n, -1);

    // Stack will store future candidate values
    stack<int> st;

    // Traverse circular array backward from 2n-1 to 0
    for (int i = 2 * n - 1; i >= 0; i--)
    {

        int val = nums[i % n]; // circular index

        // Maintain decreasing stack
        while (!st.empty() && st.top() <= val)
        {
            st.pop(); // useless elements
        }

        // For the FIRST pass only (i < n), store answer
        if (i < n)
        {
            if (st.empty())
                ans[i] = -1; // no greater element exists
            else
                ans[i] = st.top(); // next greater element found
        }

        // Push current value for future elements
        st.push(val);
    }

    return ans;
}

/*
====================================================================================
6. TIME & SPACE COMPLEXITY SUMMARY
====================================================================================

A) BRUTE FORCE:
----------------
TIME   = O(n²)
SPACE  = O(1)

B) OPTIMAL MONOTONIC STACK:
---------------------------
TIME   = O(n)
         - Each element pushed once, popped once → O(2n) → O(n)
SPACE  = O(n)
         - Worst-case stack stores all elements

====================================================================================
7. MAIN() FOR TESTING IN VS CODE
====================================================================================
*/

int main()
{
    vector<int> nums = {1, 2, 1};

    cout << "Input:  ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n\n";

    // Brute Force Output
    auto brute = nextGreaterBrute(nums);
    cout << "Brute Force Output:          ";
    for (int x : brute)
        cout << x << " ";
    cout << "\n";

    // Optimal Output
    auto opt = nextGreaterElements(nums);
    cout << "Optimal Stack Output:        ";
    for (int x : opt)
        cout << x << " ";
    cout << "\n";

    return 0;
}
