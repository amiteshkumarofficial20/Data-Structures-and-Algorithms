/*
================================================================================
                    LEETCODE 26 - REMOVE DUPLICATES FROM SORTED ARRAY
================================================================================

Platform   : LeetCode
Problem No : 26
Difficulty : Easy
Topics     : Array, Two Pointers

================================================================================
1. COMPLETE PROBLEM STATEMENT
================================================================================

Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once.

The relative order of the elements should be kept the same.

Return the number of unique elements k.

The first k elements of nums should contain the unique elements.

The remaining elements beyond k are not important.

You must solve this using O(1) extra space.

================================================================================
2. EXAMPLES
================================================================================

Example 1
---------

Input:
nums = [1,1,2]

Output:
2

Modified Array:
[1,2,_]

Explanation:
Unique elements are:
1, 2

Therefore k = 2

--------------------------------------------------------------------------------

Example 2
---------

Input:
nums = [0,0,1,1,1,2,2,3,3,4]

Output:
5

Modified Array:
[0,1,2,3,4,_,_,_,_,_]

Explanation:
Unique elements are:
0,1,2,3,4

================================================================================
3. CONSTRAINTS
================================================================================

1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order

================================================================================
4. WHAT DOES THE QUESTION ACTUALLY ASK?
================================================================================

Many beginners misunderstand this problem.

The question DOES NOT ask:

"Create a new array containing unique elements."

The question asks:

"Modify the same array in-place."

This means:

Allowed:
--------
Overwrite elements inside nums.

Not Preferred:
--------------
Creating another array of size N.

================================================================================
5. KEY OBSERVATIONS
================================================================================

Observation 1
-------------
Array is already sorted.

Example:

[1,1,1,2,2,3,3,4]

Duplicates are adjacent.

Observation 2
-------------
If array were NOT sorted:

[3,1,3,2,1]

Duplicate detection becomes harder.

Observation 3
-------------
Sorted property is the biggest clue.

Whenever interviewer gives:

1. Sorted Array
2. In-place
3. Remove duplicates

Think:

TWO POINTERS

================================================================================
6. PATTERN RECOGNITION
================================================================================

Keywords:

Sorted Array
+
Unique Elements
+
In-place Modification

=> Two Pointer Pattern

================================================================================
7. APPROACH 1 : BRUTE FORCE (TEMP VECTOR)
================================================================================

INTUITION
---------

Store all unique elements inside another vector.

Since duplicates are adjacent:

Compare current element with previous element.

If different:
Store it.

ALGORITHM
---------

1. Create temp vector.
2. Insert first element.
3. Traverse array.
4. If nums[i] != nums[i-1]
   add nums[i].
5. Copy temp back.
6. Return temp.size()

VISUALIZATION
-------------

nums:

1 1 2 2 3

temp:

1

Skip 1

Add 2

temp:

1 2

Skip 2

Add 3

temp:

1 2 3

DRY RUN
-------

Input:

[1,1,2,2,3]

temp = [1]

i=1 => duplicate

i=2 => unique => temp=[1,2]

i=3 => duplicate

i=4 => unique => temp=[1,2,3]

Answer = 3

TIME COMPLEXITY
---------------

Traversal     : O(N)
Copy Back     : O(N)

Total         : O(N)

SPACE COMPLEXITY
----------------

O(N)

CODE
----

int removeDuplicates(vector<int>& nums)
{
    vector<int> temp;

    temp.push_back(nums[0]);

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] != nums[i-1])
        {
            temp.push_back(nums[i]);
        }
    }

    for(int i=0;i<temp.size();i++)
    {
        nums[i] = temp[i];
    }

    return temp.size();
}

================================================================================
8. APPROACH 2 : BETTER (SET)
================================================================================

INTUITION
---------

Set automatically stores unique values.

Insert all values.

Copy back into array.

ALGORITHM
---------

1. Insert into set.
2. Copy set values into nums.
3. Return set size.

DRY RUN
-------

nums:

1 1 2 2 3

set:

1

duplicate ignored

2 inserted

duplicate ignored

3 inserted

set:

1 2 3

TIME COMPLEXITY
---------------

Insertion:

N * logN

Total:

O(N logN)

SPACE COMPLEXITY
----------------

O(N)

WHY THIS IS NOT OPTIMAL?
------------------------

Uses extra memory.

Also slower than O(N).

================================================================================
9. APPROACH 3 : OPTIMAL (TWO POINTERS)
================================================================================

MOST IMPORTANT APPROACH

INTUITION
---------

Because duplicates are adjacent,

we only need to track:

1. Last unique element
2. Current scanning element

Let:

slow = last unique position
fast = scanning pointer

================================================================================
10. THEORY BEHIND TWO POINTERS
================================================================================

Imagine:

[1,1,2,2,3]

Initially:

slow
 |
[1,1,2,2,3]
  |
 fast

Everything from index 0 to slow
is unique.

Unique Region:

[1]

Now fast moves.

If duplicate:
Skip

If new value:
Expand unique region.

================================================================================
11. INVARIANT
================================================================================

Before every iteration:

nums[0...slow]

contains all unique elements discovered so far.

This statement remains true throughout the algorithm.

================================================================================
12. WHY THE OPTIMAL APPROACH WORKS
================================================================================

Because array is sorted.

If:

nums[fast] != nums[slow]

Then nums[fast] must be a brand-new unique value.

So we place it after slow.

slow++

nums[slow] = nums[fast]

This expands unique region.

================================================================================
13. OPTIMAL ALGORITHM
================================================================================

if array empty
    return 0

slow = 0

for fast = 1 to n-1

    if nums[fast] != nums[slow]

        slow++

        nums[slow] = nums[fast]

return slow + 1

================================================================================
14. COMPLETE DRY RUN #1
================================================================================

nums = [1,1,2]

Initial

slow=0

fast=1

1 == 1

Skip

fast=2

2 != 1

slow=1

nums[1]=2

Array:

[1,2,2]

Answer:

k=2

================================================================================
15. COMPLETE DRY RUN #2
================================================================================

nums:

0 0 1 1 1 2 2 3 3 4

slow=0

fast=1

duplicate

------------------------------------------------

fast=2

unique

slow=1

0 1 1 1 1 2 2 3 3 4

------------------------------------------------

fast=5

unique

slow=2

0 1 2 1 1 2 2 3 3 4

------------------------------------------------

fast=7

unique

slow=3

0 1 2 3 1 2 2 3 3 4

------------------------------------------------

fast=9

unique

slow=4

0 1 2 3 4 2 2 3 3 4

Final:

k = 5

================================================================================
16. PROOF OF CORRECTNESS
================================================================================

Claim:

After processing every element,

nums[0...slow]

contains all unique values exactly once.

Proof:

Base Case:

Initially:

nums[0]

is unique.

Claim true.

Inductive Step:

Assume claim true before iteration.

Case 1:

nums[fast] == nums[slow]

Duplicate.

Skip.

Claim remains true.

Case 2:

nums[fast] != nums[slow]

New unique element.

Place after slow.

Unique region expands.

Claim remains true.

Thus by induction:

Algorithm is correct.

================================================================================
17. TIME COMPLEXITY ANALYSIS
================================================================================

fast traverses array once.

Total operations:

N

Time:

O(N)

================================================================================
18. SPACE COMPLEXITY ANALYSIS
================================================================================

Only variables:

slow
fast

Extra Space:

O(1)

================================================================================
19. COMMON INTERVIEW QUESTIONS
================================================================================

Q1.
Why does sorting help?

Duplicates become adjacent.

------------------------------------------------

Q2.
Can we solve unsorted version?

Yes.
Using hash set.

------------------------------------------------

Q3.
Why not nested loops?

O(N²)

------------------------------------------------

Q4.
Best solution?

Two Pointers.

================================================================================
20. COMMON MISTAKES
================================================================================

Mistake 1

Comparing wrong indices.

------------------------------------------------

Mistake 2

Returning slow instead of slow+1.

------------------------------------------------

Mistake 3

Forgetting single-element case.

================================================================================
21. EDGE CASES
================================================================================

Case 1

[5]

Answer = 1

------------------------------------------------

Case 2

[2,2,2,2]

Answer = 1

------------------------------------------------

Case 3

[1,2,3,4]

Answer = 4

------------------------------------------------

Case 4

[-3,-3,-2,-1]

Answer = 3

================================================================================
22. LEETCODE SUBMISSION CODE
================================================================================
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};

/*
================================================================================
23. FULLY WORKING MAIN FUNCTION
================================================================================
*/

void testCase(vector<int> nums)
{
    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << "\n";

    cout << "Unique Elements: ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\n---------------------------------\n";
}

int main()
{
    testCase({1, 1, 2});

    testCase({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});

    testCase({5});

    testCase({2, 2, 2, 2});

    testCase({1, 2, 3, 4});

    testCase({-3, -3, -2, -1});

    testCase({1, 1, 1, 1, 1, 1});

    testCase({1, 2, 2, 3, 4, 4, 5});

    return 0;
}

/*
================================================================================
24. QUICK REVISION SHEET
================================================================================

Pattern:
--------
Two Pointers

Keywords:
---------
Sorted Array
Remove Duplicates
In-place

Optimal Idea:
-------------

slow -> last unique index

fast -> scanning index

If new value found:

slow++
nums[slow] = nums[fast]

Complexities:
-------------

Brute Force:
Time O(N)
Space O(N)

Set:
Time O(NlogN)
Space O(N)

Optimal:
Time O(N)
Space O(1)

Most Important Line:
--------------------

Because the array is sorted, every new value discovered by the fast pointer
is guaranteed to be the next unique value.

================================================================================
END OF HANDBOOK
================================================================================
*/
