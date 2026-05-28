#include <bits/stdc++.h>
using namespace std;

/*

#######################################################################
#                                                                     #
#            LEETCODE 167 — TWO SUM II (INPUT ARRAY SORTED)           #
#                                                                     #
#######################################################################

========================================================================
PROBLEM STATEMENT
========================================================================

Given a 1-indexed array of integers `numbers`
that is already sorted in non-decreasing order,
find two numbers such that:

numbers[index1] + numbers[index2] == target

Return:
[index1, index2]

IMPORTANT CONDITIONS:
----------------------
1. Exactly one solution exists.
2. You may NOT use the same element twice.
3. Return answer in 1-based indexing.

========================================================================
EXAMPLE 1
========================================================================

Input:
-------
numbers = [2,7,11,15]
target = 9

Output:
--------
[1,2]

Explanation:
-------------
2 + 7 = 9

========================================================================
EXAMPLE 2
========================================================================

Input:
-------
numbers = [2,3,4]
target = 6

Output:
--------
[1,3]

Explanation:
-------------
2 + 4 = 6

========================================================================
EXAMPLE 3
========================================================================

Input:
-------
numbers = [-1,0]
target = -1

Output:
--------
[1,2]

========================================================================
CONSTRAINTS
========================================================================

2 <= numbers.length <= 3 * 10^4

-1000 <= numbers[i] <= 1000

numbers is sorted in non-decreasing order.

-1000 <= target <= 1000

Exactly one solution exists.

========================================================================
VERY IMPORTANT OBSERVATION
========================================================================

The array is SORTED.

This single line completely changes the solution.

Because the array is sorted:
--------------------------------

Small values are on left side.
Large values are on right side.

This allows:
--------------
Two Pointer Optimization

========================================================================
APPROACH 1 — BRUTE FORCE
========================================================================

IDEA:
------
Try every possible pair.

Use:
-----
Nested loops

Check:
-------
numbers[i] + numbers[j] == target

========================================================================
VISUALIZATION
========================================================================

Array:
------
[2,7,11,15]

Possible Pairs:
----------------

2 + 7
2 + 11
2 + 15

7 + 11
7 + 15

11 + 15

========================================================================
BRUTE FORCE CODE
========================================================================
*/

class BruteForceSolution
{

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        for (int i = 0; i < numbers.size(); i++)
        {

            for (int j = i + 1; j < numbers.size(); j++)
            {

                if (numbers[i] + numbers[j] == target)
                {

                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
};

/*

========================================================================
DRY RUN — BRUTE FORCE
========================================================================

numbers = [2,7,11,15]
target = 9

Step 1:
--------
i = 0 -> 2

j = 1 -> 7

2 + 7 = 9

Answer Found:
--------------
[1,2]

========================================================================
TIME COMPLEXITY
========================================================================

O(n²)

WHY?
-----
Because:
-------
Nested loops

========================================================================
SPACE COMPLEXITY
========================================================================

O(1)

No extra space used.

========================================================================
APPROACH 2 — BETTER APPROACH (HASH MAP)
========================================================================

IDEA:
------

Instead of checking every pair,
store previously visited elements.

For every element:

required = target - current

Check:
-------
Does required already exist?

If YES:
--------
Answer found

========================================================================
EXAMPLE
========================================================================

numbers = [2,7,11,15]
target = 9

Current:
---------
2

Required:
----------
7

Store:
-------
2 in map

Next:
------
7

Required:
----------
2

2 already exists.

Answer Found.

========================================================================
BETTER APPROACH CODE
========================================================================
*/

class BetterSolution
{

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        unordered_map<int, int> mp;

        for (int i = 0; i < numbers.size(); i++)
        {

            int required = target - numbers[i];

            if (mp.find(required) != mp.end())
            {

                return {mp[required] + 1, i + 1};
            }

            mp[numbers[i]] = i;
        }

        return {};
    }
};

/*

========================================================================
TIME COMPLEXITY
========================================================================

O(n)

========================================================================
SPACE COMPLEXITY
========================================================================

O(n)

Because hashmap is used.

========================================================================
APPROACH 3 — OPTIMAL APPROACH (TWO POINTER)
========================================================================

MOST IMPORTANT OBSERVATION:
----------------------------

Array is SORTED.

========================================================================
WHY TWO POINTER WORKS
========================================================================

Suppose:

numbers = [2,7,11,15]

Left side:
-----------
Small values

Right side:
------------
Large values

========================================================================
POINTER MOVEMENT
========================================================================

low ---> <--- high

========================================================================
MAIN LOGIC
========================================================================

CASE 1:
--------

If current sum is SMALL:

Need bigger value.

Move:
------
low++

========================================================================
CASE 2:
--------

If current sum is LARGE:

Need smaller value.

Move:
------
high--

========================================================================
CASE 3:
--------

If current sum == target

Answer found.

========================================================================
VERY IMPORTANT THEORY
========================================================================

Why:
----
high = numbers.size() - 1

NOT:
----
numbers.size()

========================================================================
EXPLANATION
========================================================================

Example:

numbers = [2,7,11,15]

Size:
------
4

Indices:
---------
0 1 2 3

Last valid index:
------------------
3

Which is:
----------
size - 1

If you use:

numbers[4]

then:
-----
OUT OF BOUNDS ERROR

========================================================================
WHY RETURN low+1 and high+1 ?
========================================================================

Because problem uses:

1-based indexing

Internally:
------------
0 1 2 3

Expected Output:
-----------------
1 2 3 4

Therefore:

return {low + 1, high + 1};

========================================================================
OPTIMAL CODE
========================================================================
*/

class OptimalSolution
{

public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int low = 0;

        int high = numbers.size() - 1;

        while (low < high)
        {

            int sum = numbers[low] + numbers[high];

            /*
            ==========================================
            CASE 1:
            Sum is small
            ==========================================
            */

            if (sum < target)
            {

                low++;
            }

            /*
            ==========================================
            CASE 2:
            Sum is large
            ==========================================
            */

            else if (sum > target)
            {

                high--;
            }

            /*
            ==========================================
            CASE 3:
            Answer found
            ==========================================
            */

            else
            {

                return {low + 1, high + 1};
            }
        }

        return {};
    }
};

/*

========================================================================
DETAILED DRY RUN
========================================================================

numbers = [2,7,11,15]
target = 9

========================================================================
INITIAL STATE
========================================================================

low = 0 -> 2

high = 3 -> 15

========================================================================
STEP 1
========================================================================

sum = 2 + 15

sum = 17

17 > 9

Need smaller value.

Move:
------
high--

========================================================================
STEP 2
========================================================================

low = 0 -> 2

high = 2 -> 11

sum = 2 + 11

sum = 13

13 > 9

Need smaller value.

Move:
------
high--

========================================================================
STEP 3
========================================================================

low = 0 -> 2

high = 1 -> 7

sum = 2 + 7

sum = 9

Answer Found.

Return:
--------
[1,2]

========================================================================
TIME COMPLEXITY
========================================================================

O(n)

WHY?
-----
Each pointer moves at most once.

========================================================================
SPACE COMPLEXITY
========================================================================

O(1)

No extra space used.

========================================================================
COMPARISON TABLE
========================================================================

| Approach        | Time Complexity | Space Complexity |
|----------------|-----------------|------------------|
| Brute Force    | O(n²)           | O(1)             |
| Hash Map       | O(n)            | O(n)             |
| Two Pointer    | O(n)            | O(1)             |

========================================================================
WHICH APPROACH IS BEST?
========================================================================

Optimal Two Pointer Approach

Because:
---------
1. Array is sorted
2. O(n) time
3. O(1) space

========================================================================
GENERIC TWO POINTER TEMPLATE
========================================================================

int low = 0;
int high = n - 1;

while (low < high) {

    int sum = arr[low] + arr[high];

    if (sum < target) {
        low++;
    }

    else if (sum > target) {
        high--;
    }

    else {
        // answer found
    }
}

========================================================================
UTILITY FUNCTION
========================================================================
*/

void printAnswer(vector<int> ans)
{

    cout << "[";

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i];

        if (i != ans.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]";
}

/*

========================================================================
MAIN FUNCTION WITH MULTIPLE TEST CASES
========================================================================
*/

int main()
{

    OptimalSolution obj;

    /*
    ================================================================
    TEST CASE 1
    ================================================================
    */

    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> ans1 = obj.twoSum(numbers1, target1);

    cout << "Test Case 1" << endl;

    cout << "Input: [2,7,11,15], target = 9" << endl;

    cout << "Output: ";

    printAnswer(ans1);

    cout << endl
         << endl;

    /*
    ================================================================
    TEST CASE 2
    ================================================================
    */

    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;

    vector<int> ans2 = obj.twoSum(numbers2, target2);

    cout << "Test Case 2" << endl;

    cout << "Input: [2,3,4], target = 6" << endl;

    cout << "Output: ";

    printAnswer(ans2);

    cout << endl
         << endl;

    /*
    ================================================================
    TEST CASE 3
    ================================================================
    */

    vector<int> numbers3 = {-1, 0};
    int target3 = -1;

    vector<int> ans3 = obj.twoSum(numbers3, target3);

    cout << "Test Case 3" << endl;

    cout << "Input: [-1,0], target = -1" << endl;

    cout << "Output: ";

    printAnswer(ans3);

    cout << endl
         << endl;

    /*
    ================================================================
    TEST CASE 4
    ================================================================
    */

    vector<int> numbers4 = {1, 2, 3, 4, 4, 9};
    int target4 = 8;

    vector<int> ans4 = obj.twoSum(numbers4, target4);

    cout << "Test Case 4" << endl;

    cout << "Input: [1,2,3,4,4,9], target = 8" << endl;

    cout << "Output: ";

    printAnswer(ans4);

    cout << endl
         << endl;

    /*
    ================================================================
    TEST CASE 5
    ================================================================
    */

    vector<int> numbers5 = {1, 5, 6, 10, 12};
    int target5 = 11;

    vector<int> ans5 = obj.twoSum(numbers5, target5);

    cout << "Test Case 5" << endl;

    cout << "Input: [1,5,6,10,12], target = 11" << endl;

    cout << "Output: ";

    printAnswer(ans5);

    cout << endl
         << endl;

    /*
    ================================================================
    TEST CASE 6
    ================================================================
    */

    vector<int> numbers6 = {-10, -5, 0, 3, 8, 12};
    int target6 = 7;

    vector<int> ans6 = obj.twoSum(numbers6, target6);

    cout << "Test Case 6" << endl;

    cout << "Input: [-10,-5,0,3,8,12], target = 7" << endl;

    cout << "Output: ";

    printAnswer(ans6);

    cout << endl
         << endl;

    return 0;
}
