/*
================================================================================
====================== LEETCODE 977 : MASTER INTERVIEW NOTE ====================
================================================================================

Platform      : LeetCode [web:12][web:17]
Problem Number: 977 [web:12][web:17]
Problem Name  : Squares of a Sorted Array [web:12][web:17]
Difficulty    : Easy [web:17]
Company Tags  : Meta, ByteDance (commonly associated in public solution metadata) [web:18]
Pattern Tags  : Array, Two Pointers, Sorted Array, Fill From End, Compare Extremes [web:12][web:17]

File Name     : 977_MASTER.cpp
Purpose       : Self-sufficient C++ interview-preparation handbook
Audience      : Beginner to intermediate interview candidate
Style         : VS Code friendly, richly documented, compilable C++ file

================================================================================
================================ PROBLEM STATEMENT ==============================
================================================================================

You are given an integer array nums sorted in non-decreasing order.
Return an array of the squares of each number also sorted in non-decreasing order. [web:12][web:17]

--------------------------------------------------------------------------------
Example description from the official style of the problem:
- Input is already sorted.
- Squaring may break the sorted order because negative numbers can become large
  positive values after squaring.
- We must return the squared values in sorted order. [web:12][web:17]
--------------------------------------------------------------------------------

================================================================================
================================== CONSTRAINTS =================================
================================================================================

The common published constraints for this problem are: [web:12][web:17]

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.

Important interview implications:
- Array length is large enough that an O(n log n) solution is accepted, but the
  follow-up mindset strongly prefers O(n).
- Values can be negative, zero, or positive.
- Because input is sorted, structure exists and should be exploited.
- Squaring values up to 10^4 fits safely in 32-bit int because 10^8 is within
  int range.

================================================================================
=================================== EXAMPLES ===================================
================================================================================

EXAMPLE 1 [web:12][web:17]
Input : nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation:
Squares become [16,1,0,9,100].
That is not sorted.
After sorting, result is [0,1,9,16,100].

EXAMPLE 2 [web:12][web:17]
Input : nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
Explanation:
Squares become [49,9,4,9,121].
Sorting gives [4,9,9,49,121].

EXAMPLE 3
Input : nums = [0]
Output: [0]
Explanation:
Only one element exists, and 0^2 = 0.

EXAMPLE 4
Input : nums = [-5,-4,-3,-2,-1]
Output: [1,4,9,16,25]
Explanation:
All numbers are negative.
Their squares appear in reverse relative importance by absolute value.
The leftmost element has the largest square initially.

EXAMPLE 5
Input : nums = [1,2,3,4,5]
Output: [1,4,9,16,25]
Explanation:
All numbers are already non-negative.
Squaring preserves the sorted order here.

EXAMPLE 6
Input : nums = [-2,-2,0,2,2]
Output: [0,4,4,4,4]
Explanation:
Duplicate values and symmetric absolute values produce repeated squares.

EXAMPLE 7
Input : nums = [-10000,10000]
Output: [100000000,100000000]
Explanation:
Both values have equal absolute value.
Both squares are equal.

================================================================================
==================== WHAT IS THE PROBLEM ACTUALLY ASKING? ======================
================================================================================

This problem is not merely asking us to square numbers.
That part is trivial.

The real question is:

"Can you exploit the fact that the original array is already sorted,
 even though squaring destroys the order around zero?"

Why order breaks:

    nums = [-4, -1, 0, 3, 10]

    sorted by value:
    -4 < -1 < 0 < 3 < 10

    after squaring:
    16, 1, 0, 9, 100

The issue is that negative values with large absolute magnitude move to the end
of the squared order.

So the interview is often testing whether you recognize this pattern:

- The largest square must come from one of the two ends.
- Because the input is sorted, the largest absolute value is always at either
  the left end or the right end.
- That means we can compare extremes and build the answer intelligently.

================================================================================
========================= UNDERSTANDING THE PROBLEM =============================
================================================================================

Let us slow this down carefully.

We are given:
- A sorted array.
- Negative numbers may exist.
- We need sorted squares.

If the array had only non-negative numbers:
- We could square each element in place.
- The order would remain sorted.

If the array had only negative numbers:
- The squares would come out in reverse order of the original list.

If the array mixes negative and positive numbers:
- The smallest values by actual number are on the left.
- But the largest values by absolute magnitude can be on either side.

That observation is everything.

Consider:

    [-9, -2, 0, 2, 3]

Absolute values:

    [ 9,  2, 0, 2, 3]

The largest absolute value is 9, at the left end.
After squaring, 81 must go near the end of the answer.

Now consider:

    [-3, -2, 0, 2, 9]

Absolute values:

    [ 3,  2, 0, 2, 9]

Now the largest absolute value is 9, at the right end.
Again, the largest square comes from an end.

So the problem is really about comparing magnitudes, not comparing signed values.

================================================================================
======================== INTERVIEW THINKING PROCESS =============================
================================================================================

A strong interview thought process may sound like this:

1. "The naive thing is to square every value and then sort."
2. "That works, but sorting costs O(n log n)."
3. "Because the original array is already sorted, maybe I can avoid sorting."
4. "After squaring, the largest value must come from the largest absolute value."
5. "In a sorted array, the largest absolute value must lie at one of the ends."
6. "So I can compare nums[left]^2 and nums[right]^2."
7. "Whichever is larger belongs at the current end of the output array."
8. "Then move that pointer inward and repeat."
9. "This builds the answer in O(n)."

This is the pattern interviewers want to see:

- Recognize structure in sorted input.
- Convert a sorting problem into a merging / two-pointer problem.
- Fill output from the back because we discover the largest square first.

================================================================================
============================= KEY OBSERVATIONS =================================
================================================================================

OBSERVATION 1
The square of a number depends on its absolute value, not its sign.

    x^2 = (-x)^2 in magnitude terms.

OBSERVATION 2
In a sorted array, the element with the largest absolute value must be at either
end of the array.

Reason:
- Values increase from left to right.
- The most negative value is at the far left.
- The most positive value is at the far right.
- Any middle value cannot beat both ends in absolute magnitude.

OBSERVATION 3
If we repeatedly select the larger square from the two ends, we discover the
result in descending order.

Therefore:
- Either store in a separate array from back to front, or
- Push into a list and reverse later.

OBSERVATION 4
This is conceptually similar to merge behavior.

Interpretation:
- Negative part, when squared, becomes decreasing if read left to right.
- Non-negative part, when squared, remains increasing.
- We can merge those two monotonic behaviors.

OBSERVATION 5
Because output size equals input size, O(n) extra result storage is natural and
expected unless the interviewer explicitly asks for in-place transformation.

================================================================================
==================== WHY THE OBVIOUS APPROACH IS NOT IDEAL =====================
================================================================================

The obvious approach is:
- Square each element.
- Sort the array.

Why it works:
- Squaring computes the right values.
- Sorting restores the required order.

Why it is not ideal:
- We are ignoring the fact that the input is already sorted.
- Sorting again costs O(n log n).
- The problem is designed to reward recognition of the sorted structure.

In an interview, this approach is acceptable as a starting point.
But stopping there misses the main insight.

================================================================================
====================== SOLUTION 1 : BRUTE FORCE / DIRECT ========================
================================================================================

INTUITION
---------
Do the simplest correct thing first:
1. Square every number.
2. Sort the result.

This is often the best way to start in an interview because:
- It proves correctness quickly.
- It gives a baseline solution.
- It creates a bridge to optimization.

DETAILED THINKING
-----------------
Suppose:

    nums = [-7,-3,2,3,11]

After squaring:

    [49,9,4,9,121]

This array is not sorted.
So sort it:

    [4,9,9,49,121]

Done.

This approach does not care about the original sorted order.
It treats the problem as:

    transform + generic sort

STEP-BY-STEP ALGORITHM
----------------------
1. Create an empty result array or reuse the existing array.
2. For each element x in nums, compute x*x.
3. Store the squared value.
4. Sort the squared array.
5. Return it.

ASCII DIAGRAM
-------------
Original:

    index:  0   1  2  3   4
    nums : [-4,-1, 0, 3, 10]

Square each:

    sq   : [16, 1, 0, 9,100]

Sort:

    ans  : [ 0, 1, 9,16,100]

DRY RUN 1
---------
Input:

    [-4,-1,0,3,10]

Pass 1: square all

    i=0 -> 16
    i=1 -> 1
    i=2 -> 0
    i=3 -> 9
    i=4 -> 100

Intermediate:

    [16,1,0,9,100]

Sort result:

    [0,1,9,16,100]

DRY RUN 2
---------
Input:

    [-5,-4,-3,-2,-1]

Squares:

    [25,16,9,4,1]

Sort:

    [1,4,9,16,25]

DRY RUN 3
---------
Input:

    [1,2,3]

Squares:

    [1,4,9]

Sort:

    [1,4,9]

Even though sorting is unnecessary here, brute force still works.

WHY IT WORKS
------------
Because sorting guarantees the final order regardless of how squaring disturbed it.

WHY IT IS CALLED BRUTE FORCE
----------------------------
Because it does not exploit the given sorted property of the input.
It uses a general-purpose sorting hammer.

COMPLEXITY ANALYSIS
-------------------
Time Complexity : O(n log n)
Space Complexity:
- O(n) if using a separate vector for squared values.
- Sorting itself may use additional stack/implementation space depending on STL.

C++ CODE
--------
class BruteForceSolution {
public:
    vector<int> sortedSquares(vector<int> nums) {
        for (int &x : nums) {
            x = x * x;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

================================================================================
==================== SOLUTION 2 : BETTER APPROACH (DIVIDE-MERGE) ===============
================================================================================

INTUITION
---------
This is a powerful intermediate approach that many candidates skip.
But understanding it deepens the optimal method.

Key idea:
- Split the array around the first non-negative element.
- Negative numbers, after squaring, appear in decreasing order if traversed from
  left to right.
- If we traverse the negative side backward, their squares become increasing.
- The non-negative side, after squaring, is already increasing.
- Then simply merge the two sorted streams.

This is why the user requested divide-and-merge explanation for two-pointer
problems whenever meaningful.
Here it is very meaningful.

DIVIDE-AND-MERGE INTERPRETATION
-------------------------------
Consider:

    nums = [-9,-2,-1,0,3,5]

Divide around the first non-negative:

    negative part   = [-9,-2,-1]
    non-negative    = [0,3,5]

If squared directly:

    negative squares from left to right = [81,4,1]   (decreasing overall if read as abs shrinks)
    non-negative squares                = [0,9,25]  (increasing)

But if we walk negative part backward:

    [-1,-2,-9] -> [1,4,81]  (increasing)

Now we have two sorted lists to merge:

    A = [1,4,81]
    B = [0,9,25]

Merge => [0,1,4,9,25,81]

That is exactly the answer.

OPTIMIZATION IDEA
-----------------
Instead of sorting all squared values globally, create two already-sorted streams
and merge them in linear time.

This resembles merge step of merge sort.

STEP-BY-STEP ALGORITHM
----------------------
1. Find the first index p such that nums[p] >= 0.
2. Set i = p - 1, which points to the last negative number.
3. Set j = p, which points to the first non-negative number.
4. Create an empty answer vector.
5. While i >= 0 and j < n:
   - Compare nums[i]^2 and nums[j]^2.
   - Push the smaller one.
   - Move the corresponding pointer.
6. Append leftover negative-side squares.
7. Append leftover non-negative-side squares.
8. Return the answer.

ASCII DIAGRAM
-------------
Example:

    nums = [-7,-3,2,3,11]

                   split
                     |
                     v
    index:   0   1   2  3   4
    nums :  [-7,-3,  2, 3, 11]
                  i   j

negative side backward squares:
    -3 -> 9
    -7 -> 49

non-negative side forward squares:
     2 -> 4
     3 -> 9
    11 -> 121

Merge sorted streams:
    [9,49]
    [4,9,121]

Result:
    [4,9,9,49,121]

MULTIPLE DRY RUNS
-----------------

DRY RUN 1
Input:

    [-4,-1,0,3,10]

Find first non-negative:

    p = 2 (nums[2] = 0)
    i = 1  -> nums[i] = -1
    j = 2  -> nums[j] = 0

Compare:
- (-1)^2 = 1
- (0)^2  = 0
Take 0, move j

ans = [0]
    i=1, j=3

Compare:
- 1
- 9
Take 1, move i

ans = [0,1]
    i=0, j=3

Compare:
- 16
- 9
Take 9, move j

ans = [0,1,9]
    i=0, j=4

Compare:
- 16
- 100
Take 16, move i

ans = [0,1,9,16]
    i=-1, j=4

Left negative exhausted.
Append remainder from non-negative side: 100

final = [0,1,9,16,100]

DRY RUN 2
Input:

    [-5,-4,-3]

First non-negative does not exist.
So p = n.
    i = 2
    j = 3

Only negative side remains, but traversed backward:
- (-3)^2 = 9
- (-4)^2 = 16
- (-5)^2 = 25

final = [9,16,25]

Wait.
That seems wrong if we append blindly from i backward after split logic?
No, it is actually correct because traversing negatives backward yields increasing
squares:

    [-5,-4,-3]
    backward => -3, -4, -5
    squares  =>  9, 16, 25

So final = [9,16,25]
But compare with true answer:

    squares sorted = [9,16,25]

Correct.

DRY RUN 3
Input:

    [0,2,4]

p = 0
i = -1
j = 0

Only non-negative stream remains:
0,4,16

final = [0,4,16]

WHY IT WORKS
------------
Because it explicitly converts the problem into merging two sorted squared sequences.

PROOF INTUITION
---------------
- Negative numbers become larger in square as their absolute value grows.
- On the negative side, absolute values shrink as we move right.
- Therefore, traversing the negative side from right to left yields squares in
  increasing order.
- The non-negative side from left to right already yields increasing squares.
- Merging two sorted sequences is correct and linear.

COMPLEXITY ANALYSIS
-------------------
Time Complexity : O(n)
Space Complexity: O(n)

C++ CODE
--------
class BetterApproachSolution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        int p = 0;
        while (p < n && nums[p] < 0) p++;

        int i = p - 1;
        int j = p;
        vector<int> ans;
        ans.reserve(n);

        while (i >= 0 && j < n) {
            int leftSq = nums[i] * nums[i];
            int rightSq = nums[j] * nums[j];
            if (leftSq <= rightSq) {
                ans.push_back(leftSq);
                i--;
            } else {
                ans.push_back(rightSq);
                j++;
            }
        }

        while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }

        while (j < n) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;
    }
};

================================================================================
==================== SOLUTION 3 : OPTIMAL APPROACH (TWO POINTERS) ==============
================================================================================

INTUITION
---------
This is the classic interview-optimal solution.

We know the largest absolute value is always at one of the ends.
Therefore the largest square among the remaining elements must come from either:
- nums[left], or
- nums[right]

If we compare their squares, we can place the larger one at the end of the result.
Then move the corresponding pointer inward.

This is repeated until the result is fully built.

INTERVIEW THOUGHT PROCESS
-------------------------
A polished explanation in an interview could be:

"Because the array is sorted, the maximum absolute value among the unprocessed
 elements must be at either end. The largest square should therefore be placed at
 the current last open position in the answer. After placing it, I shrink the
 corresponding side. This gives a linear-time two-pointer solution."

WHY FILL FROM THE END?
----------------------
Because each comparison reveals the largest remaining square, not the smallest.

If we tried to fill from the front, we would need the smallest remaining square,
which is not always easy to identify from the two ends alone.

So we reverse the construction direction.

POINTER MODEL
-------------

    left  -> start of array
    right -> end of array
    pos   -> end of answer array

At each step:
- Compare abs(nums[left]) and abs(nums[right]), or compare their squares.
- Place the larger square into ans[pos].
- Move left or right accordingly.
- Decrement pos.

ASCII POINTER DIAGRAM 1
-----------------------
Example:

    nums = [-7,-3,2,3,11]

    left                          right
      v                             v
    [-7, -3, 2, 3, 11]
                          ans = [_, _, _, _, _]
                                   pos = 4

Compare:
- left square  = 49
- right square = 121
Take 121, place at ans[4]
Move right leftward.

    [-7, -3, 2, 3, 11]
      v                      v
    right now at index 3
    ans = [_, _, _, _, 121]
                    pos = 3

ASCII POINTER DIAGRAM 2
-----------------------
Compare again:
- left square  = 49
- right square = 9
Take 49, place at ans[3]
Move left rightward.

    [-7, -3, 2, 3, 11]
          v          v
    ans = [_, _, _, 49, 121]
                 pos = 2

Continue until all positions are filled.

MULTIPLE DRY RUNS
-----------------

DRY RUN 1
Input:

    nums = [-4,-1,0,3,10]

Initial:
    left = 0  -> -4
    right = 4 -> 10
    pos = 4
    ans = [_,_,_,_,_]

Step 1:
    leftSq  = 16
    rightSq = 100
    rightSq larger
    ans[4] = 100
    right--
    pos--

State:
    left = 0, right = 3, pos = 3
    ans = [_,_,_,_,100]

Step 2:
    compare 16 vs 9
    take 16
    ans[3] = 16
    left++
    pos--

State:
    left = 1, right = 3, pos = 2
    ans = [_,_,_,16,100]

Step 3:
    compare 1 vs 9
    take 9
    ans[2] = 9
    right--
    pos--

State:
    left = 1, right = 2, pos = 1
    ans = [_,_,9,16,100]

Step 4:
    compare 1 vs 0
    take 1
    ans[1] = 1
    left++
    pos--

State:
    left = 2, right = 2, pos = 0
    ans = [_,1,9,16,100]

Step 5:
    compare 0 vs 0
    take either
    ans[0] = 0

Final:
    [0,1,9,16,100]

DRY RUN 2
Input:

    nums = [-7,-3,2,3,11]

Initial:
    left=0, right=4, pos=4
    ans=[_,_,_,_,_]

1) compare 49 and 121 -> place 121
    ans=[_,_,_,_,121]
    right=3, pos=3

2) compare 49 and 9 -> place 49
    ans=[_,_,_,49,121]
    left=1, pos=2

3) compare 9 and 9 -> place 9
    choose left on >=
    ans=[_,_,9,49,121]
    left=2, pos=1

4) compare 4 and 9 -> place 9
    ans=[_,9,9,49,121]
    right=2, pos=0

5) compare 4 and 4 -> place 4
    ans=[4,9,9,49,121]

DRY RUN 3
Input:

    nums = [-5,-4,-3,-2,-1]

All negative.
Largest square always comes from left side first because leftmost negative has
largest absolute value.

Steps:
- 25 goes to end
- 16 goes next
- 9 goes next
- 4 goes next
- 1 goes next

final = [1,4,9,16,25]

DRY RUN 4
Input:

    nums = [1,2,3,4]

All non-negative.
Largest square always comes from right side.

Steps:
- 16 at end
- 9
- 4
- 1

final = [1,4,9,16]

DRY RUN 5
Input:

    nums = [-2,-2,0,2,2]

Initial:
    leftSq = 4, rightSq = 4
    choose one side consistently.

Possible placement sequence from back:
- 4
- 4
- 4
- 4
- 0

final = [0,4,4,4,4]

EXPLAIN EVERY POINTER MOVEMENT
------------------------------
Why do we move left?
- Because nums[left]^2 was chosen.
- That means left element has been fully processed.
- It will never be needed again.

Why do we move right?
- Because nums[right]^2 was chosen.
- That element is consumed.

Why do we move pos backward every time?
- Because exactly one output position is finalized on every iteration.
- We always place the current largest remaining square.

Why can we trust the unprocessed middle region?
- Because any future largest square must still be at one of the new ends of that
  smaller region.

WHY IT WORKS
------------
At any time, consider the subarray nums[left...right].
Because this subarray is sorted, the largest absolute value in it is at left or
right. Therefore the largest square in the unprocessed region is also at left or
right. By placing that square into ans[pos], we correctly finalize the last
remaining position. Repeating this shrinks the problem by one element each time.

PROOF INTUITION
---------------
We can think inductively.

Base case:
- If one element remains, its square must occupy the only remaining slot.

Inductive step:
- Assume for the current unprocessed range [left...right], the largest square is
  at one of the ends.
- Place that largest square at ans[pos].
- Remove that end from consideration.
- The remaining subarray is still sorted.
- The same argument applies again.

Thus, by induction, all positions are filled correctly.

FORMAL-STYLE INVARIANT
----------------------
Before each iteration:
- ans[pos+1 ... n-1] already contains the largest processed squares in correct
  sorted order.
- nums[left ... right] is the unprocessed region.

After each iteration:
- One largest remaining square is placed at ans[pos].
- Invariant remains true for the next smaller problem.

EDGE CASES
----------
1. Single element
   - Example: [0]
   - Works naturally.

2. All negatives
   - Largest absolute values start on the left.

3. All non-negatives
   - Largest values start on the right.

4. Duplicates
   - Equal squares are fine.

5. Zeros present
   - Zero square is zero, handled naturally.

6. Symmetric values
   - Example: [-3,3]
   - Both squares are equal.

ASCII DIAGRAM : FULL WALKTHROUGH
--------------------------------

    nums = [-6,-4,-1,2,5]

    left                                  right
      v                                     v
    [-6, -4, -1, 2, 5]
    ans = [_, _, _, _, _]
                      ^
                     pos

Step 1:
    36 vs 25 -> place 36

    [-6, -4, -1, 2, 5]
          v          v
    ans = [_, _, _, _, 36]
                   ^
                  pos

Step 2:
    16 vs 25 -> place 25

    [-6, -4, -1, 2, 5]
          v      v
    ans = [_, _, _, 25, 36]
                ^
               pos

Step 3:
    16 vs 4 -> place 16

    [-6, -4, -1, 2, 5]
              v  v
    ans = [_, _, 16, 25, 36]
             ^
            pos

Step 4:
    1 vs 4 -> place 4

    [-6, -4, -1, 2, 5]
              v
              v
    ans = [_, 4, 16, 25, 36]
          ^
         pos

Step 5:
    1 vs 1 -> place 1

    ans = [1, 4, 16, 25, 36]

COMPLEXITY ANALYSIS
-------------------
Time Complexity : O(n)
Space Complexity: O(n) for the output array

Note on space discussion:
- Since the problem asks us to return an array, many interviewers do not count
  the returned output as extra space in the same way auxiliary temporary memory
  is counted.
- Still, the implementation physically uses a result vector of size n.

PRODUCTION-QUALITY C++ CODE
---------------------------
class OptimalSolution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                ans[pos] = leftSq;
                left++;
            } else {
                ans[pos] = rightSq;
                right--;
            }
            pos--;
        }

        return ans;
    }
};

================================================================================
=============================== COMPARISON TABLE ================================
================================================================================

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force: square then sort | O(n log n) | O(n) or implementation-dependent | Easiest to explain, ignores sorted input |
| Better: split and merge | O(n) | O(n) | Great conceptual bridge, explicit divide-and-merge view |
| Optimal: two pointers from ends | O(n) | O(n) | Best interview answer, simple and elegant |

================================================================================
========================== LEETCODE SUBMISSION CODE =============================
================================================================================

The following is the clean submission version with no comments, exactly as one
might submit on LeetCode.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, pos = n - 1;
        while (left <= right) {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a > b) {
                ans[pos--] = a;
                left++;
            } else {
                ans[pos--] = b;
                right--;
            }
        }
        return ans;
    }
};

================================================================================
============================== COMMON MISTAKES =================================
================================================================================

1. Forgetting that negative numbers can produce larger squares than positive
   numbers near the middle.

2. Filling the answer from left to right instead of right to left.
   The two-end comparison naturally reveals the largest remaining square, not the
   smallest.

3. Comparing nums[left] and nums[right] directly instead of comparing squares or
   absolute values.

   Wrong mindset:
       -7 < 3, so maybe 3 is bigger.
   Correct mindset:
       |-7| = 7 > 3, so 49 is bigger.

4. Using abs carelessly with integer edge cases in other problems.
   Here values are small enough, but in general comparing squares directly can be
   safer for bounded input.

5. Forgetting to decrement pos after writing into ans.

6. Moving the wrong pointer after choosing a square.

7. Mishandling equal squares.
   Equal values are fine; pick either side consistently.

8. Returning squared-but-unsorted intermediate array.

9. Overcomplicating with extra data structures when a simple vector is enough.

10. Mixing up the divide-and-merge approach and the end-filling approach.
    Both are linear, but their mechanics differ.

================================================================================
============================== INTERVIEW NOTES =================================
================================================================================

How to present this in interview:

1. Start with the brute force.
   "I can square every value and sort. That is O(n log n)."

2. Then optimize using the sorted property.
   "Because the input is sorted, the largest absolute value must be at one of the
    ends."

3. Explain construction direction.
   "Since I discover the largest remaining square first, I will fill the answer
    from the back."

4. State invariant.
   "After each step, the suffix of the answer is finalized and sorted."

5. Mention edge cases briefly.
   "All negatives, all positives, duplicates, zero."

6. Only then code.

What interviewers often evaluate here:
- Can you move beyond brute force?
- Do you recognize the two-pointer pattern?
- Can you justify correctness clearly?
- Can you write clean pointer logic without off-by-one errors?

================================================================================
============================ PATTERN RECOGNITION ================================
================================================================================

HOW TO IDENTIFY THIS PATTERN IN INTERVIEWS
------------------------------------------
Look for these signals:

- The input array is already sorted.
- A transformation is applied to each element.
- The transformed values are no longer obviously sorted.
- The extreme answer candidates come from the ends.
- You are asked to produce sorted output without wasting the original structure.

KEYWORDS THAT HINT TOWARD THIS PATTERN
--------------------------------------
Common hints include:
- "sorted array"
- "non-decreasing order"
- "return sorted result after transformation"
- "absolute value"
- "largest/smallest must be near the ends"
- "linear time"
- "follow-up: can you do better than sorting?"

SIMILAR SITUATIONS
------------------
This style of thinking appears when:
- Merging two monotonic regions.
- Comparing extremes in a sorted array.
- Building result from outside inward.
- Using left and right pointers to avoid re-sorting.

MENTAL MODEL
------------
Ask yourself:

"Is the difficult part really just that a transformation breaks order around a
 pivot, while each side still has structure?"

If yes, then think about:
- split + merge, or
- compare both ends and fill output accordingly.

================================================================================
============================= SIMILAR PROBLEMS =================================
================================================================================

1. Two Sum II - Input Array Is Sorted
   - Sorted input
   - Two pointers on ends
   - Exploits order directly

2. Merge Sorted Array
   - Fill from the back
   - Very similar direction-of-construction insight

3. 3Sum
   - Sorting + two pointers after fixing one element

4. Sort Transformed Array
   - A more advanced variant where transformed values can still be handled via
     two-end comparisons depending on quadratic behavior

5. Container With Most Water
   - Two pointers and end comparisons, though objective differs

6. Remove Duplicates from Sorted Array
   - Sorted-array pointer discipline

================================================================================
============================== REVISION SHEET ==================================
================================================================================

ONE-PAGE RECAP
--------------
Problem:
- Given sorted nums, return sorted squares.

Core issue:
- Squaring breaks order because negatives become positive.

Core observation:
- Largest absolute value is always at one of the ends.

Best approach:
- Two pointers at left and right.
- Compare squares.
- Place larger square at answer[pos] from the back.
- Move chosen pointer.
- Decrement pos.

KEY FORMULAS / FACTS
--------------------
- Square depends on magnitude: x^2 compares by |x|
- For sorted nums[left...right], max square is at left or right

KEY OBSERVATIONS
----------------
- Negative side and non-negative side each have hidden monotonic structure.
- Split-and-merge is a valid linear approach.
- End-filling is the cleanest optimal implementation.

KEY TRICKS
----------
- Fill answer from right to left.
- Compare squares, not signed values.
- On tie, choose either side consistently.

WHEN TO USE THIS PATTERN
------------------------
- Sorted array
- Transformation disturbs order
- Extremes remain informative

================================================================================
============================== FINAL TAKEAWAYS =================================
================================================================================

1. The brute-force solution is square + sort.
2. The interview insight is that the sorted input should not be wasted.
3. The hidden structure comes from absolute values.
4. The divide-and-merge view is educational and linear.
5. The best practical answer is the two-pointer approach filling from the end.
6. Whenever a sorted array undergoes a transformation that preserves some edge
   structure, think two pointers before reaching for sort.

================================================================================
============================ FULL DRIVER PROGRAM ================================
================================================================================

Below is a complete compilable C++ program using the optimal approach.
It also includes 15+ test cases and prints expected outputs.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, pos = n - 1;
        while (left <= right)
        {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a > b)
            {
                ans[pos--] = a;
                left++;
            }
            else
            {
                ans[pos--] = b;
                right--;
            }
        }
        return ans;
    }
};

static string vecToString(const vector<int> &v)
{
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        ss << v[i];
        if (i + 1 < v.size())
            ss << ", ";
    }
    ss << "]";
    return ss.str();
}

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {-4, -1, 0, 3, 10},
        {-7, -3, 2, 3, 11},
        {0},
        {-5, -4, -3, -2, -1},
        {1, 2, 3, 4, 5},
        {-2, -2, 0, 2, 2},
        {-10000, 10000},
        {-1},
        {2},
        {-3, -1, 0},
        {0, 1, 2, 3},
        {-9, -8, -2, 0, 1},
        {-6, -4, -1, 2, 5},
        {-1, 0, 0, 0, 2},
        {-10, -5, -2, -1},
        {3, 3, 3},
        {-3, -3, -3},
        {-8, -3, -3, 1, 2, 7}};

    vector<vector<int>> expected = {
        {0, 1, 9, 16, 100},
        {4, 9, 9, 49, 121},
        {0},
        {1, 4, 9, 16, 25},
        {1, 4, 9, 16, 25},
        {0, 4, 4, 4, 4},
        {100000000, 100000000},
        {1},
        {4},
        {0, 1, 9},
        {0, 1, 4, 9},
        {0, 1, 4, 64, 81},
        {1, 4, 16, 25, 36},
        {0, 0, 0, 1, 4},
        {1, 4, 25, 100},
        {9, 9, 9},
        {9, 9, 9},
        {1, 4, 9, 9, 49, 64}};

    cout << "Running test cases for LeetCode 977 - Squares of a Sorted Array\n\n";

    for (size_t i = 0; i < tests.size(); ++i)
    {
        vector<int> input = tests[i];
        vector<int> result = sol.sortedSquares(input);
        cout << "Test " << (i + 1) << ":\n";
        cout << "Input           : " << vecToString(tests[i]) << "\n";
        cout << "Expected Output : " << vecToString(expected[i]) << "\n";
        cout << "Actual Output   : " << vecToString(result) << "\n";
        cout << "Status          : " << (result == expected[i] ? "PASS" : "FAIL") << "\n";
        cout << "------------------------------------------------------------\n";
    }

    return 0;
}

/*
================================================================================
============================= EXPECTED OUTPUTS =================================
================================================================================

A representative run prints results like these:

Test 1:
Input           : [-4, -1, 0, 3, 10]
Expected Output : [0, 1, 9, 16, 100]
Actual Output   : [0, 1, 9, 16, 100]
Status          : PASS
------------------------------------------------------------
Test 2:
Input           : [-7, -3, 2, 3, 11]
Expected Output : [4, 9, 9, 49, 121]
Actual Output   : [4, 9, 9, 49, 121]
Status          : PASS
------------------------------------------------------------
Test 3:
Input           : [0]
Expected Output : [0]
Actual Output   : [0]
Status          : PASS
------------------------------------------------------------
Test 4:
Input           : [-5, -4, -3, -2, -1]
Expected Output : [1, 4, 9, 16, 25]
Actual Output   : [1, 4, 9, 16, 25]
Status          : PASS
------------------------------------------------------------
Test 5:
Input           : [1, 2, 3, 4, 5]
Expected Output : [1, 4, 9, 16, 25]
Actual Output   : [1, 4, 9, 16, 25]
Status          : PASS
------------------------------------------------------------
Test 6:
Input           : [-2, -2, 0, 2, 2]
Expected Output : [0, 4, 4, 4, 4]
Actual Output   : [0, 4, 4, 4, 4]
Status          : PASS
------------------------------------------------------------
Test 7:
Input           : [-10000, 10000]
Expected Output : [100000000, 100000000]
Actual Output   : [100000000, 100000000]
Status          : PASS
------------------------------------------------------------
Test 8:
Input           : [-1]
Expected Output : [1]
Actual Output   : [1]
Status          : PASS
------------------------------------------------------------
Test 9:
Input           : [2]
Expected Output : [4]
Actual Output   : [4]
Status          : PASS
------------------------------------------------------------
Test 10:
Input           : [-3, -1, 0]
Expected Output : [0, 1, 9]
Actual Output   : [0, 1, 9]
Status          : PASS
------------------------------------------------------------
Test 11:
Input           : [0, 1, 2, 3]
Expected Output : [0, 1, 4, 9]
Actual Output   : [0, 1, 4, 9]
Status          : PASS
------------------------------------------------------------
Test 12:
Input           : [-9, -8, -2, 0, 1]
Expected Output : [0, 1, 4, 64, 81]
Actual Output   : [0, 1, 4, 64, 81]
Status          : PASS
------------------------------------------------------------
Test 13:
Input           : [-6, -4, -1, 2, 5]
Expected Output : [1, 4, 16, 25, 36]
Actual Output   : [1, 4, 16, 25, 36]
Status          : PASS
------------------------------------------------------------
Test 14:
Input           : [-1, 0, 0, 0, 2]
Expected Output : [0, 0, 0, 1, 4]
Actual Output   : [0, 0, 0, 1, 4]
Status          : PASS
------------------------------------------------------------
Test 15:
Input           : [-10, -5, -2, -1]
Expected Output : [1, 4, 25, 100]
Actual Output   : [1, 4, 25, 100]
Status          : PASS
------------------------------------------------------------
Test 16:
Input           : [3, 3, 3]
Expected Output : [9, 9, 9]
Actual Output   : [9, 9, 9]
Status          : PASS
------------------------------------------------------------
Test 17:
Input           : [-3, -3, -3]
Expected Output : [9, 9, 9]
Actual Output   : [9, 9, 9]
Status          : PASS
------------------------------------------------------------
Test 18:
Input           : [-8, -3, -3, 1, 2, 7]
Expected Output : [1, 4, 9, 9, 49, 64]
Actual Output   : [1, 4, 9, 9, 49, 64]
Status          : PASS
------------------------------------------------------------

================================================================================
================================ END OF FILE ===================================
================================================================================
*/