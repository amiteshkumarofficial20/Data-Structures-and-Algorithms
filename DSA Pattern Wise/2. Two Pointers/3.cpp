
/*
################################################################################
#                                                                              #
#                 LEETCODE 80 - REMOVE DUPLICATES FROM SORTED ARRAY II         #
#                                                                              #
#                     EXTREMELY DETAILED BEGINNER-FRIENDLY NOTES               #
#                                                                              #
#                         Interview + Revision + VS Code Notes                 #
#                                                                              #
################################################################################

===============================================================================
1. PROBLEM STATEMENT
===============================================================================

Given an integer array nums sorted in non-decreasing order, remove some
duplicates in-place such that each unique element appears AT MOST TWICE.

The relative order of the elements must remain the same.

Since the array must be modified in-place, we cannot return a new array.

Return k such that:

- The first k elements of nums contain the final answer.
- Remaining elements are irrelevant.
- Each distinct value appears at most two times.

-------------------------------------------------------------------------------
EXAMPLE 1
-------------------------------------------------------------------------------

Input:
nums = [1,1,1,2,2,3]

Output:
k = 5

Modified nums:
[1,1,2,2,3,_]

Explanation:

1 appears 3 times.
Only first 2 occurrences are allowed.

Final array:
[1,1,2,2,3]

-------------------------------------------------------------------------------
EXAMPLE 2
-------------------------------------------------------------------------------

Input:
nums = [0,0,1,1,1,1,2,3,3]

Output:
k = 7

Final:
[0,0,1,1,2,3,3]

===============================================================================
2. CONSTRAINTS
===============================================================================

1 <= nums.length <= 30000

-10000 <= nums[i] <= 10000

nums is sorted in non-decreasing order.

===============================================================================
3. IMPORTANT OBSERVATIONS
===============================================================================

Observation 1
-------------

Array is SORTED.

This is the most important clue.

Example:

1 1 1 2 2 3 3 3

Notice:

Duplicates stay together.

Observation 2
-------------

We are allowed:

✓ First occurrence
✓ Second occurrence

Not allowed:

✗ Third occurrence
✗ Fourth occurrence
✗ Fifth occurrence

Observation 3
-------------

Final answer must contain:

At most two copies of every distinct value.

Example:

Original:
1 1 1 1 2 2 2 3

Required:
1 1 2 2 3

Observation 4
-------------

Because the array is sorted, we never need to search for duplicates.

Duplicates are already adjacent.

===============================================================================
APPROACH 1 : BRUTE FORCE
(TEMP VECTOR + CONSECUTIVE COUNT)
===============================================================================

INTUITION
---------

Since duplicates occur together, we can count how many times the current
number has appeared consecutively.

If count <= 2:
    keep it

Otherwise:
    ignore it

Store valid elements in a temporary vector.

Finally copy everything back.

-------------------------------------------------------------------------------
VISUALIZATION
-------------------------------------------------------------------------------

nums:

1 1 1 2 2 3

temp:

Initially:

[1]

count = 1

Second 1:

count = 2

Allowed

temp = [1,1]

Third 1:

count = 3

Not allowed

temp = [1,1]

-------------------------------------------------------------------------------
STEP-BY-STEP ALGORITHM
-------------------------------------------------------------------------------

Step 1:
Create temp vector.

Step 2:
Insert first element.

Step 3:
count = 1

Step 4:
Traverse from index 1.

Step 5:
If current == previous:

    count++

    If count <= 2:
        push element

Step 6:
Else:

    count = 1
    push element

Step 7:
Copy temp back into nums.

Step 8:
Return temp.size()

-------------------------------------------------------------------------------
DETAILED DRY RUN
-------------------------------------------------------------------------------

nums = [1,1,1,2,2,3]

temp = [1]

count = 1

------------------------------------------------

i = 1

nums[1] = 1
nums[0] = 1

Same

count = 2

count <= 2

push

temp = [1,1]

------------------------------------------------

i = 2

nums[2] = 1

Same

count = 3

count > 2

skip

temp = [1,1]

------------------------------------------------

i = 3

nums[3] = 2

Different

count = 1

push

temp = [1,1,2]

------------------------------------------------

i = 4

nums[4] = 2

Same

count = 2

push

temp = [1,1,2,2]

------------------------------------------------

i = 5

nums[5] = 3

Different

count = 1

push

temp = [1,1,2,2,3]

------------------------------------------------

Final:

temp = [1,1,2,2,3]

k = 5

-------------------------------------------------------------------------------
WHY DOES THIS WORK?
-------------------------------------------------------------------------------

Because:

count always stores the frequency of the CURRENT consecutive block.

Example:

1 1 1 1

count becomes:

1
2
3
4

We allow only when count <= 2.

Therefore no value appears more than twice.

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

Traversal = O(n)

Copy = O(n)

Overall:

O(n)

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

temp vector stores answer.

O(n)

-------------------------------------------------------------------------------
WHY IS THE NEXT APPROACH BETTER?
-------------------------------------------------------------------------------

Brute force depends on consecutive counting.

HashMap approach is more general.

It explicitly stores frequency information.

===============================================================================
APPROACH 2 : BETTER APPROACH
(HASHMAP + TEMP VECTOR)
===============================================================================

INTUITION
---------

Store frequency of every element inside a HashMap.

Whenever frequency becomes:

1 or 2

Keep the element.

When frequency becomes:

3 or more

Ignore it.

-------------------------------------------------------------------------------
VISUALIZATION
-------------------------------------------------------------------------------

nums:

1 1 1 2 2 3

HashMap:

1 -> 0

Read first 1

1 -> 1

Keep

Read second 1

1 -> 2

Keep

Read third 1

1 -> 3

Skip

-------------------------------------------------------------------------------
ALGORITHM
-------------------------------------------------------------------------------

1. Create unordered_map frequency.

2. Create temp vector.

3. Traverse nums.

4. Increase frequency.

5. If frequency <= 2:
       push element

6. Copy temp back.

7. Return temp size.

-------------------------------------------------------------------------------
DRY RUN
-------------------------------------------------------------------------------

nums = [1,1,1,2,2,3]

freq = {}

temp = {}

Read 1

freq[1] = 1

push

temp = [1]

----------------------------------

Read 1

freq[1] = 2

push

temp = [1,1]

----------------------------------

Read 1

freq[1] = 3

skip

----------------------------------

Read 2

freq[2] = 1

push

temp = [1,1,2]

----------------------------------

Read 2

freq[2] = 2

push

temp = [1,1,2,2]

----------------------------------

Read 3

freq[3] = 1

push

temp = [1,1,2,2,3]

Answer = 5

-------------------------------------------------------------------------------
WHY DOES THIS WORK?
-------------------------------------------------------------------------------

HashMap always stores exact frequency.

Example:

freq[5] = 3

means 5 already appeared three times.

Therefore we reject it.

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

O(n)

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

HashMap = O(n)

Temp Vector = O(n)

Overall = O(n)

-------------------------------------------------------------------------------
WHY IS THE OPTIMAL APPROACH BETTER?
-------------------------------------------------------------------------------

Problems:

1. HashMap uses memory.
2. Temp vector uses memory.
3. Array is already sorted.

Since duplicates are adjacent, HashMap is unnecessary.

We can solve in-place.

===============================================================================
APPROACH 3 : OPTIMAL APPROACH
(TWO POINTERS + k-2 TECHNIQUE)
===============================================================================

MOST IMPORTANT IDEA
-------------------

The first two elements are ALWAYS valid.

Why?

Because every value is allowed to appear at most two times.

Example:

[1]
Valid

[1,1]
Still valid

Therefore:

Start with:

k = 2

===============================================================================
THE k-2 TRICK
===============================================================================

Suppose current valid array is:

1 1

k = 2

New element = 1

Compare with:

nums[k-2]

nums[0] = 1

Same

Reject

Because adding it would create:

1 1 1

Three copies

Not allowed.

-------------------------------------------------------------------------------

Suppose:

Valid:

1 1

Current = 2

Compare:

2 vs nums[0]

2 vs 1

Different

Accept

Valid becomes:

1 1 2

===============================================================================
VISUAL UNDERSTANDING
===============================================================================

Current valid portion:

Index:

0 1

Value:

1 1

k = 2

Current value = 1

Compare with:

nums[k-2]

nums[0]

1 == 1

Reject

-------------------------------------------------------------------------------

Current value = 2

Compare:

2 != 1

Accept

===============================================================================
ALGORITHM
===============================================================================

If size <= 2

Return size

----------------------------------

k = 2

----------------------------------

For i from 2 to n-1

If nums[i] != nums[k-2]

    nums[k] = nums[i]

    k++

----------------------------------

Return k

===============================================================================
COMPLETE DRY RUN
===============================================================================

nums:

[1,1,1,2,2,3]

n = 6

k = 2

Current valid:

1 1

-------------------------------------------------------------------------------

i = 2

nums[i] = 1

Compare:

nums[k-2]

nums[0] = 1

Same

Reject

k = 2

-------------------------------------------------------------------------------

i = 3

nums[i] = 2

Compare:

nums[0] = 1

Different

Place at nums[2]

Array:

1 1 2

k = 3

-------------------------------------------------------------------------------

i = 4

nums[i] = 2

Compare:

nums[1] = 1

Different

Place at nums[3]

Array:

1 1 2 2

k = 4

-------------------------------------------------------------------------------

i = 5

nums[i] = 3

Compare:

nums[2] = 2

Different

Place at nums[4]

Array:

1 1 2 2 3

k = 5

-------------------------------------------------------------------------------

Answer:

k = 5

===============================================================================
WHY THE OPTIMAL APPROACH WORKS (PROOF INTUITION)
===============================================================================

The valid part always contains at most two copies of every value.

When processing nums[i], we check:

nums[i] != nums[k-2]

Case 1:

Equal

Example:

Valid:

1 1

Current:

1

Adding it would create:

1 1 1

Three copies

Reject

----------------------------------

Case 2:

Different

Current value has not yet occupied both allowed positions.

Safe to include.

Therefore:

The condition automatically prevents a third occurrence.

===============================================================================
COMPLEXITY ANALYSIS
===============================================================================

Brute Force

Time  : O(n)
Space : O(n)

----------------------------------

HashMap

Time  : O(n)
Space : O(n)

----------------------------------

Optimal

Time  : O(n)
Space : O(1)

===============================================================================
INTERVIEW NOTES
===============================================================================

Pattern:

Allow at most m copies.

General Rule:

if(nums[i] != nums[k-m])

then accept.

----------------------------------

For LeetCode 26:

Allow only one occurrence.

Condition:

nums[i] != nums[k-1]

----------------------------------

For LeetCode 80:

Allow two occurrences.

Condition:

nums[i] != nums[k-2]

----------------------------------

Very common interview pattern.

===============================================================================
*/
// == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
//     APPROACH 1 : BRUTE FORCE(TEMP VECTOR + COUNT) == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==

//                  Intuition : Since the array is sorted,
//     duplicates appear consecutively.Maintain a count of consecutive occurrences and keep only first two copies.

//         Time Complexity : O(n)
//                               Space Complexity : O(n)

//         == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
//         CODE : BRUTE FORCE
//                == ==
//                == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == ==
//                */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SolutionBrute
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.empty())
            return 0;

        vector<int> temp;

        temp.push_back(nums[0]);

        int count = 1;

        for (int i = 1; i < (int)nums.size(); i++)
        {

            if (nums[i] == nums[i - 1])
            {

                count++;

                if (count <= 2)
                    temp.push_back(nums[i]);
            }
            else
            {

                count = 1;
                temp.push_back(nums[i]);
            }
        }

        for (int i = 0; i < (int)temp.size(); i++)
            nums[i] = temp[i];

        return (int)temp.size();
    }
};

/*
================================================================================
APPROACH 2 : BETTER (HASHMAP)
================================================================================

Intuition:
Store frequency of every element.
Insert into temporary vector only while frequency <= 2.

Time Complexity : O(n)
Space Complexity: O(n)

================================================================================
CODE : BETTER APPROACH
================================================================================
*/

class SolutionBetter
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        unordered_map<int, int> freq;

        vector<int> temp;

        for (int x : nums)
        {

            freq[x]++;

            if (freq[x] <= 2)
                temp.push_back(x);
        }

        for (int i = 0; i < (int)temp.size(); i++)
            nums[i] = temp[i];

        return (int)temp.size();
    }
};

/*
================================================================================
APPROACH 3 : OPTIMAL (TWO POINTERS)
================================================================================

Key Idea:

First two elements are always valid.

Let k be size of valid portion.

For every element from index 2:

If nums[i] != nums[k-2]

accept element.

This prevents any value from appearing more than twice.

Time Complexity : O(n)
Space Complexity: O(1)

================================================================================
CODE : OPTIMAL APPROACH
================================================================================
*/

class SolutionOptimal
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int n = nums.size();

        if (n <= 2)
            return n;

        int k = 2;

        for (int i = 2; i < n; i++)
        {

            if (nums[i] != nums[k - 2])
            {

                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
================================================================================
LEETCODE SUBMISSION CODE
================================================================================
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int n = nums.size();

        if (n <= 2)
            return n;

        int k = 2;

        for (int i = 2; i < n; i++)
        {

            if (nums[i] != nums[k - 2])
            {

                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
================================================================================
DRIVER CODE
================================================================================
*/

void runTest(vector<int> nums)
{

    SolutionOptimal obj;

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << "\n";
    cout << "Modified Array : ";

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << "\n----------------------------------------\n";
}

int main()
{

    runTest({1, 1, 1, 2, 2, 3});

    runTest({0, 0, 1, 1, 1, 1, 2, 3, 3});

    runTest({1, 1});

    runTest({1});

    runTest({1, 1, 1, 1, 1});

    runTest({1, 1, 2, 2, 3, 3});

    runTest({1, 2, 3, 4, 5});

    return 0;
}